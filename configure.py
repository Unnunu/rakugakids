#!/usr/bin/env python3
"""
Configure build for a specific ROM version.
Usage: ./configure.py --version jp (or eu)
"""
import argparse
import os
import shutil
import sys
from pathlib import Path

import ninja_syntax
import requests
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent
BASENAME = "rakugakids"
TOOLS_DIR = ROOT / "tools"

COMMON_INCLUDES = "-I include -I build/include -I ultralib/include -I ultralib/include/PR -I ultralib/src -I ultralib/include/compiler/ido"
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C -DNDEBUG -D_FINALROM"

CROSS = "mips-linux-gnu-"
CROSS_AS = f"{CROSS}as"
CROSS_CPP = f"{CROSS}cpp"
CROSS_LD = f"{CROSS}ld"
CROSS_STRIP = f"{CROSS}strip"
CROSS_OBJCOPY = f"{CROSS}objcopy"

INCLUDES = "-I include"
AS_FLAGS = f"-EB -march=vr4300 -mtune=vr4300 -G 0 {INCLUDES}"
O32_TOOL = ROOT / "ultralib/tools/set_o32abi_bit.py"
IDO_53_CC = TOOLS_DIR / "ido5.3" / "cc"
IDO_71_CC = TOOLS_DIR / "ido7.1" / "cc"
CC_CMD = f"python3 tools/asm-processor/build.py {IDO_71_CC} -- {CROSS_AS} {AS_FLAGS} -- -G 0 -non_shared -fullwarn -woff 649,838,654 -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul $flags -mips2 {COMMON_INCLUDES} {IDO_DEFS} $version -c -o $out $in"
LIBULTRA_CC_CMD = f"{IDO_53_CC} -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 -Xcpluscomm -nostdinc $flags {COMMON_INCLUDES} {IDO_DEFS} $version -c -o $out $in && {O32_TOOL} $out"
LIBULTRA_AS_CMD = f"{IDO_53_CC} -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 $flags {COMMON_INCLUDES} -D_FINALROM -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out && {CROSS_STRIP} $out -N asdasdasdasd"

def clean():
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)
    for f in Path(".").glob("build.ninja.*"):
        f.unlink()
    if Path(".splache").exists():
        Path(".splache").unlink()

def obtain_ido_recomp(version: str):
    download_dir = TOOLS_DIR / f"ido{version}"

    if download_dir.exists():
        print(
            f"IDO {version} already exists at {download_dir}, removing and re-downloading"
        )
        shutil.rmtree(download_dir)

    IDO_RECOMP_VERSION = "v1.1"

    if sys.platform == "darwin":
        ido_os = "macos"
    elif sys.platform == "linux":
        ido_os = "linux"
    elif sys.platform == "win32":
        ido_os = "windows"
    else:
        print(f"Unsupported platform {sys.platform}")
        sys.exit(1)

    ido_tar_name = f"ido-{version}-recomp-{ido_os}.tar.gz"
    url = f"https://github.com/decompals/ido-static-recomp/releases/download/{IDO_RECOMP_VERSION}/{ido_tar_name}"
    target_path = TOOLS_DIR / ido_tar_name

    print(f"Downloading IDO {version}: {url}")
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Failed to download IDO tarball from {url}")
        sys.exit(1)
    with open(target_path, "wb") as f:
        f.write(response.content)

    shutil.unpack_archive(target_path, download_dir)
    os.remove(target_path)

def setup():
    obtain_ido_recomp("5.3")
    obtain_ido_recomp("7.1")
    print("Setup complete!")


def create_build_script(linker_entries: list[LinkerEntry], version: str):
    built_objects: Set[Path] = set()

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    os.makedirs("build", exist_ok=True)

    ninja_file = f"build.ninja"
    ninja = ninja_syntax.Writer(open(ninja_file, "w"), width=9999)

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {INCLUDES} $in | {CROSS_AS} {AS_FLAGS} -o $out",
    )
    ninja.rule(
        "as_libultra",
        description="as $in",
        command=f"{LIBULTRA_AS_CMD}",
    )
    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{CC_CMD}",
    )
    ninja.rule(
        "cc_libultra",
        description="cc $in",
        command=f"{LIBULTRA_CC_CMD}",
    )
    ninja.rule(
        "bin",
        description="bin $in",
        command=f"{CROSS_LD} -r -b binary $in -o $out",
    )
    ninja.rule(
        "ld",
        description="link $out",
        command=f"{CROSS_LD} -T ver/{version}/undefined_syms.txt -Map $mapfile -T $in -o $out",
    )
    ninja.rule(
        "z64",
        description="rom $out",
        command=f"{CROSS_OBJCOPY} $in $out -O binary",
    )
    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.n64.header.N64SegHeader):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            s_path = entry.src_paths[0]

            if "ultralib" in str(s_path):
                opt_level = "-O2"

                if "/os/" in str(s_path):
                    opt_level = "-O1"

                if s_path.stem in ["exceptasm"]:
                    mips = "-mips3 -32"
                else:
                    mips = "-mips2 -o32"

                build(
                    entry.object_path,
                    entry.src_paths,
                    "as_libultra",
                    variables={"flags": f"{opt_level} {mips}"},
                )
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            c_path = entry.src_paths[0]

            if "ultralib" not in str(c_path):
                build(entry.object_path, entry.src_paths, "cc", variables={"flags": f"-O2", "version":"-DBUILD_VERSION=VERSION_I"})
            else:
                opt_level = "-O2"
                mips = "-mips2"
                libultra_version = "-DBUILD_VERSION=VERSION_I"

                if "ultralib/src/os" in str(c_path):
                    opt_level = "-O1"
                if "ultralib/src/io" in str(c_path):
                    opt_level = "-O1"
                    if "ultralib/src/io/pfs" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/contpfs" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/contramwrite" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/contramread" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/crc" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/sirawdma" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "leointerrupt" in str(c_path):
                        opt_level = "-O2"
                    if "ultralib/src/io/contreaddata" in str(c_path):
                        opt_level = "-O2"
                    if "ultralib/src/io/pimgr" in str(c_path):
                        opt_level = "-O2"
                    if "ultralib/src/io/leo" in str(c_path):
                        opt_level = "-O2"
                    if "ultralib/src/io/viswapcontext" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/vimgr" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/vitbl" in str(c_path):
                        opt_level = "-O2"
                        libultra_version = "-DBUILD_VERSION=VERSION_J"
                    if "ultralib/src/io/pfsisplug" in str(c_path):
                        opt_level = "-O1"
                        
                if "ultralib/src/gu" in str(c_path):
                    opt_level = "-O3"
                if "ultralib/src/audio" in str(c_path):
                    opt_level = "-O3"

                if "ultralib/src/libc" in str(c_path):
                    opt_level = "-O3"
                    mips = "-mips2 -o32"

                    if c_path.stem in ["ll", "llbit", "llcvt"]:
                        opt_level = "-O1"
                        mips = "-mips3 -32"

                build(entry.object_path, entry.src_paths, "cc_libultra",
                        variables={"flags": f"{opt_level} {mips}", "version": f"{libultra_version}"})
        elif isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin):
            if seg.sibling is None:
                build(entry.object_path, entry.src_paths, "as")
            elif seg.get_linker_section() == ".text":
                # Only build the .text section file for a textbin with siblings
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.bin.CommonSegBin):
            build(entry.object_path, entry.src_paths, "bin")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ld_path = f"{BASENAME}.{version}.ld"
    map_path = f"build/{BASENAME}.{version}.map"
    elf_path = f"build/{BASENAME}.{version}.elf"
    z64_path = f"build/{BASENAME}.{version}.z64"
    ok_path = f"build/{BASENAME}.{version}.ok"
    checksum_file = f"ver/{version}/checksum.sha1"

    ninja.build(
        elf_path,
        "ld",
        ld_path,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": map_path},
    )

    ninja.build(z64_path, "z64", elf_path)

    ninja.build(ok_path, "sha1sum", checksum_file, implicit=[z64_path])

    ninja.default(ok_path)

    print(f"Build configured for version '{version}'. Run 'ninja' to build.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument("-v", "--version", choices=["eu", "jp"], default="jp",
                        help="ROM region (eu, jp)")
    parser.add_argument("-c", "--clean", action="store_true", help="Clean build artifacts for the selected version")
    parser.add_argument("-s", "--setup", action="store_true", help="Download and extract IDO compiler")
    args = parser.parse_args()

    version = args.version

    if args.clean:
        clean()

    if args.setup:
        setup()
        sys.exit(0)

    baserom = Path(f"ver/{version}/baserom.z64")
    yaml_file = Path(f"ver/{version}/{BASENAME}.yaml")

    if not baserom.exists():
        print(f"Error: {baserom} not found!")
        sys.exit(1)

    split.main([yaml_file], modes=["all"], verbose=False)

    create_build_script(split.linker_writer.entries, version)
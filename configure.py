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
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent
BASENAME = "rakugakids"

CROSS = "mips-linux-gnu-"
CROSS_AS = f"{CROSS}as"
CROSS_CPP = f"{CROSS}cpp"
CROSS_LD = f"{CROSS}ld"
CROSS_OBJCOPY = f"{CROSS}objcopy"

INCLUDES = "-I include"
AS_FLAGS = f"-EB -march=vr4300 -mtune=vr4300 -G 0 {INCLUDES}"


def clean():
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)
    for f in Path(".").glob("build.ninja.*"):
        f.unlink()
    if Path(".splache").exists():
        Path(".splache").unlink()


def create_build_script(linker_entries: list[LinkerEntry], version: str):
    os.makedirs("build", exist_ok=True)

    ninja_file = f"build.ninja"
    ninja = ninja_syntax.Writer(open(ninja_file, "w"), width=9999)

    ninja.rule(
        "as",
        description="as $in",
        command=f"cpp {INCLUDES} $in | {CROSS_AS} {AS_FLAGS} -o $out",
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

    built_objects = []

    for entry in linker_entries:
        if entry.object_path is None:
            continue

        seg = entry.segment
        if seg.type[0] == ".":
            continue

        src = entry.src_paths[0]
        obj = entry.object_path

        if src.suffix == ".s":
            ninja.build(str(obj), "as", str(src))
            built_objects.append(str(obj))
        elif src.suffix == ".bin":
            ninja.build(str(obj), "bin", str(src))
            built_objects.append(str(obj))

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
        implicit=built_objects,
        variables={"mapfile": map_path},
    )

    ninja.build(z64_path, "z64", elf_path)

    ninja.build(ok_path, "sha1sum", checksum_file, implicit=[z64_path])

    ninja.default(ok_path)

    print(f"Build configured for version '{version}'. Run 'ninja' to build.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the build for a specific ROM version")
    parser.add_argument("-v", "--version", choices=["eu", "jp"], default="jp",
                        help="ROM region (eu, jp)")
    parser.add_argument("-c", "--clean", action="store_true", help="Clean build artifacts for the selected version")
    args = parser.parse_args()

    version = args.version

    if args.clean:
        clean()

    baserom = Path(f"ver/{version}/baserom.z64")
    yaml_file = Path(f"ver/{version}/{BASENAME}.yaml")

    if not baserom.exists():
        print(f"Error: {baserom} not found!")
        sys.exit(1)

    split.main([yaml_file], modes=["all"], verbose=False)

    create_build_script(split.linker_writer.entries, version)
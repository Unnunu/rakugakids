#!/usr/bin/env python3
import json
from pathlib import Path

units = [{
    "name": str(f.relative_to(".").with_suffix("")),
    "target_path": f"expected/build/{f.relative_to('.').with_suffix('.o')}",
    "base_path": f"build/{f.relative_to('.').with_suffix('.o')}",
} for f in list(Path("src").rglob("*.c")) + list(Path("ultralib").rglob("*.c"))]

json.dump({
    "custom_make": "ninja",
    "build_base": True,
    "watch_patterns": ["*.c", "*.h", "*.s", "*.S", "*.inc"],
    "units": sorted(units, key=lambda x: x["name"])
}, open("objdiff.json", "w"), indent=2)

print(f"Generated objdiff.json with {len(units)} units")
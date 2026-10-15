#!/usr/bin/env python3
"""Parse RK3588 TRM Table 1-1 (Address Mapping) into readable Markdown and CSV.

The PDF table is two-column; pdftotext emits each cell on its own line, so the
text is a stream of (module, start address, size) triples with page headers
interleaved. We match triples by their exact token shape rather than by position.
"""

import csv
import os
import re

SRC = "/workspace/rk3588/part1/Chapter_1_System_Overview.txt"
OUT_DIR = "/workspace/rk3588"

HEX_RE = re.compile(r"^[0-9A-F]{8}$")
SIZE_RE = re.compile(r"^(\d+)(KB|MB|GB)$")
SIZE_MULT = {"KB": 1 << 10, "MB": 1 << 20, "GB": 1 << 30}
SKIP_RE = re.compile(r"^(Module|Start Address|Size|RK3588 TRM-Part1|Copyright.*|\d+)$")

with open(SRC, "r", encoding="utf-8", errors="ignore") as f:
    lines = [ln.strip() for ln in f]

start = next(i for i, ln in enumerate(lines) if ln.startswith("Table 1-1 Address Mapping"))
end = next(i for i, ln in enumerate(lines) if i > start and ln.startswith("Table 1-2 Address Remapping"))

tokens = [ln for ln in lines[start + 1:end] if ln and not SKIP_RE.match(ln)]

entries = []
i = 0
while i < len(tokens) - 2:
    name, addr, size = tokens[i], tokens[i + 1], tokens[i + 2]
    if HEX_RE.match(addr) and SIZE_RE.match(size) and not HEX_RE.match(name) and not SIZE_RE.match(name):
        entries.append((name, addr, size))
        i += 3
    else:
        i += 1

def end_addr(addr, size):
    m = SIZE_RE.match(size)
    span = int(m.group(1)) * SIZE_MULT[m.group(2)]
    last = int(addr, 16) + span - 1
    return f"{last:08X}"

rows = [(n, a, s, end_addr(a, s)) for n, a, s in entries]

# Sanity check: entries should be in ascending address order and non-overlapping.
rows_sorted = sorted(rows, key=lambda r: int(r[1], 16))
overlaps = []
for prev, cur in zip(rows_sorted, rows_sorted[1:]):
    if int(cur[1], 16) <= int(prev[3], 16):
        overlaps.append((prev, cur))
print(f"Parsed {len(rows)} entries; overlaps detected: {len(overlaps)}")
for p, c in overlaps[:10]:
    print(f"  OVERLAP: {p} vs {c}")

os.makedirs(OUT_DIR, exist_ok=True)

with open(os.path.join(OUT_DIR, "address_mapping.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["Module", "Start Address", "End Address", "Size"])
    for n, a, s, e in rows:
        w.writerow([n, "0x" + a, "0x" + e, s])

md_path = os.path.join(OUT_DIR, "address_mapping.md")
with open(md_path, "w", encoding="utf-8") as f:
    f.write("# RK3588 Address Mapping (TRM Part 1, Chapter 1, Table 1-1)\n\n")
    f.write("Source: Rockchip RK3588 TRM V1.0-Part1 (2022-03-09), Chapter 1 System Overview.\n")
    f.write("Table lists the physical address range of each module on the SoC bus.\n")
    f.write("End Address is inclusive and computed from Start Address + Size - 1.\n\n")
    f.write(f"Total entries: {len(rows)}\n\n")
    f.write("| # | Module | Start Address | End Address | Size |\n")
    f.write("|---:|--------|---------------|-------------|------|\n")
    for idx, (n, a, s, e) in enumerate(rows, 1):
        f.write(f"| {idx} | {n} | 0x{a} | 0x{e} | {s} |\n")

print(f"Wrote {md_path}")
print(f"Wrote {os.path.join(OUT_DIR, 'address_mapping.csv')}")

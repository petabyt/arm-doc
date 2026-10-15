#!/usr/bin/env python3
"""Parse the AM62x TRM Table 2-1 (Memory Map) into readable Markdown and CSV.

The PDF table extracts as a cell-per-line stream:

    Table 2-1. Memory Map
    Region
    Start
    End
    Size
    PSRAMECC0_RAM
    0x0000000000
    0x0000000400
    1 KB
    ...

Rows are recovered by token shape: a (name, hex-start, hex-end, size) group.
Sanity checks (ascending addresses, End == Start + Size - 1) are reported.

Inputs : chapters/Chapter_02_Memory_Map.txt   (from extract_am62x_trm.py)
Outputs: memory_map.csv, memory_map.md
"""

import csv
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.join(HERE, "chapters", "Chapter_02_Memory_Map.txt")
OUT_CSV = os.path.join(HERE, "memory_map.csv")
OUT_MD = os.path.join(HERE, "memory_map.md")

HEX_RE = re.compile(r"^0x[0-9A-Fa-f]{4,}$")
SIZE_RE = re.compile(r"^([\d.]+)\s*(B|KB|MB|GB)$")
SIZE_MULT = {"B": 1, "KB": 1 << 10, "MB": 1 << 20, "GB": 1 << 30}
SKIP_RE = re.compile(r"^(Region|Start|End|Size|continued|=== Page \d+ ==="
                     r"|Table 2-1\. Memory Map.*|2\.2 SoC Address Aliasing.*"
                     r"|In general.*|there are some exceptions.*"
                     r"|The I/D RAM.*|is more than.*|of this SoC.*|)$")

with open(SRC, encoding="utf-8") as f:
    lines = [ln.strip() for ln in f]

# locate Table 2-1 body
start = next(i for i, ln in enumerate(lines) if ln.startswith("Table 2-1. Memory Map"))
end = next(i for i, ln in enumerate(lines) if i > start and ln.startswith("Table 2-2."))
tokens = [ln for ln in lines[start + 1:end] if not SKIP_RE.match(ln)]

rows = []
i = 0
while i < len(tokens) - 3:
    name, a, e, sz = tokens[i:i + 4]
    if (HEX_RE.match(a) and HEX_RE.match(e) and SIZE_RE.match(sz)
            and not HEX_RE.match(name) and not SIZE_RE.match(name)):
        rows.append((name, a.upper(), e.upper(), sz))
        i += 4
    else:
        i += 1

if not rows:
    raise SystemExit("no rows parsed - table format changed?")

# ---- sanity checks ----
def size_bytes(s):
    m = SIZE_RE.match(s)
    return float(m.group(1)) * SIZE_MULT[m.group(2)]

bad_span, non_asc = [], []
for k, (name, a, e, sz) in enumerate(rows):
    span = int(e, 16) - int(a, 16) + 1
    if abs(span - size_bytes(sz)) > max(1, 0.001 * size_bytes(sz)):
        bad_span.append((name, a, e, sz, span))
for prev, cur in zip(rows, rows[1:]):
    if int(cur[1], 16) < int(prev[1], 16):
        non_asc.append((prev[0], prev[1], cur[0], cur[1]))

print(f"Parsed {len(rows)} memory-map rows from Table 2-1")
print(f"  Start/End vs Size mismatches: {len(bad_span)}")
for r in bad_span[:6]:
    print("    ", r)
print(f"  Non-ascending start addresses: {len(non_asc)}")
for r in non_asc[:6]:
    print("    ", r)

with open(OUT_CSV, "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["Region", "Start Address", "End Address", "Size"])
    for name, a, e, sz in rows:
        w.writerow([name, "0x" + a.removeprefix("0X"), "0x" + e.removeprefix("0X"), sz])

with open(OUT_MD, "w", encoding="utf-8") as f:
    f.write("# AM62x Memory Map (TRM Chapter 2, Table 2-1)\n\n")
    f.write("Source: AM62x Sitara Processors TRM (SPRUIV7B, Rev. B), Chapter 2 *Memory Map*,\n")
    f.write("Table 2-1 (TRM pages 32-46).  The SoC-level memory map uses 36-bit physical\n")
    f.write("addresses with peripherals on 64 KB-aligned boundaries.  Start/End are copied\n")
    f.write("verbatim from the table; End is inclusive.\n\n")
    f.write(f"Total regions: {len(rows)}\n\n")
    if bad_span:
        f.write(f"Note: {len(bad_span)} rows where End - Start + 1 differs from the stated Size\n")
        f.write("(values kept verbatim from the document).\n\n")
    f.write("| # | Region | Start Address | End Address | Size |\n")
    f.write("|--:|--------|---------------|-------------|------|\n")
    for k, (name, a, e, sz) in enumerate(rows, 1):
        f.write(f"| {k} | {name} | 0x{a[2:]} | 0x{e[2:]} | {sz} |\n")

print(f"Wrote {OUT_CSV}")
print(f"Wrote {OUT_MD}")
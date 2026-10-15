#!/usr/bin/env python3
"""Extract the AM62x TRM (SPRUIV7B, Rev. B, "noRegisters" variant) into clean text.

Why this is not a plain pdftotext-style dump
--------------------------------------------
The PDF's body fonts are re-encoded Arial subsets (AH XSL Formatter): glyph
codes are stored as ``ASCII - 0x1D`` (e.g. "5HDG7KLV" = "Read This"), and the
fonts carry no usable ToUnicode CMap.  A second family of subsets (figure
labels, ...) *is* normally encoded, so text must be decoded per font, not per
document.  pymupdf's ``rawdict`` mode hands us per-character data together
with the owning span's font name (which includes the unique subset tag, e.g.
"AOGBCK+ArialMT"), which is what makes font-aware decoding possible.

Decode rules
------------
* Type3 fonts (names like "T6", "T27" - chapter title art) are dropped.
* Fonts classified as "shifted" (histogram: encoded space 0x03 dominates, no
  ASCII space): codes 0x03..0x61 -> +0x1D; a handful of higher codes map to
  punctuation/symbols via SHIFT_SPECIALS (identified from context); anything
  else is kept as-is (those are characters pymupdf already resolved).
* Fonts classified as "junk" (diagram-label fonts such as Calibri whose
  sampled characters are mostly control codes and cannot be decoded) are
  dropped entirely - their content is tiny in-diagram label text that is
  duplicated by the surrounding prose.
* All other fonts: kept as-is, plus CHAR_FIXUPS for a few fallback glyphs
  that resolve to obviously-wrong code points (e.g. U+020D shown for ohm).

Outputs (next to this script):
  am62x_trm_full.txt   full decoded dump, one "=== Page N ===" marker per page,
                       headers/footers stripped
  chapters.json        detected chapter start pages (printed TOC cross-checked
                       against body evidence)
  headings.json        detected bold numbered headings (level >= 2) with pages
"""

import json
import os
import re
import sys
from collections import Counter, defaultdict

import pymupdf

HERE = os.path.dirname(os.path.abspath(__file__))
PDF = os.path.join(HERE, "AM62x_TRM_SPRUIV7B_noRegisters.pdf")
OUT_TXT = os.path.join(HERE, "am62x_trm_full.txt")
OUT_CHAPTERS = os.path.join(HERE, "chapters.json")
OUT_HEADINGS = os.path.join(HERE, "headings.json")

# ---------------------------------------------------------------- constants

TYPE3_RE = re.compile(r"^T\d+$")  # Type3 fonts: chapter title art, no text

# Raw codes >= 0x62 inside shifted fonts (context-verified meanings).
SHIFT_SPECIALS = {
    "\x81": "ü",   # German "für" (OSPI chapter quote)
    "\x83": "°",   # "0°C to 95°C" temperature grades
    "\x87": "•",   # feature bullets
    "\x8a": "®",   # "Arm®", "Thumb®"
    "\x8b": "©",   # footer "Copyright © 2024"
    "\x8c": "™",   # "TI E2E™"
    "\x8f": "×",   # "×1 MSC Mode" (boot mode table)
    "\x91": "φ",   # DSS hue adjustment cos/sin
    "\x93": "±",   # "10-kΩ ±1% resistor"
    "\x94": "—",   # "Word size — Slot size"
    "\x95": "≥",   # "ELSEIF write_count ≥ 1"
    "\x97": "µ",   # "Number of µs before bus recovery"
    "\x9f": "Ω",   # "Remove 22-Ω resistor requirement"
    "\xb2": "—",   # "design help — straight from the experts"
    "\xb3": "„",   # German low quote
    "\xb4": "“",   # German high quote
    "\xb6": "’",   # "HSM’s I/D RAM"
    "\xb7": "•",   # bullets
    "\xa6": "L",   # "LFSR (x) = ..."
}

# Chars pymupdf resolves via fallback-font cmaps to obviously-wrong code
# points (identified from context; applies to any font).
CHAR_FIXUPS = {
    "ȍ": "Ω",   # "internal 10-kΩ resistors"
    "ȝ": "µ",   # "100µs pre-divider"
    "ȿ": "E",   # "Each transaction"
    "Ɉ": "O",   # "Power-On Reset"
    "ɚ": "a",   # "Generates a 1-ms tick"
    "ɸ": "φ",   # "φ2=120°" (EPWM phase diagram)
    "ǻ": "Δ",   # "Δf is the deviation from the center frequency"
    "î": "×",   # "Only 16× and 12× oversampling"
    "¦": "L",   # "LFSR length"
    "ᅚ": "✓",   # module-allocation table marks (Korean-font fallback)
    "«": "…",   # speed-designator table row gap
    "ௗ": "≠",   # "ECC_CORRECTABLE is ≠1"
}

FOOTER_RE = [
    re.compile(r"^SPRUIV7B\b.*\d{4}\b.*\bREVISED\b"),
    re.compile(r"^Submit Document(ation)? Feedback$"),
    re.compile(r"^AM62x Processors Silicon Revision"),
    re.compile(r"^Texas Instruments Families of Products$"),
    re.compile(r"^Copyright\b.*Texas Instruments Incorporated$"),
    re.compile(r"^This page intentionally left blank\.?$"),
    re.compile(r"^www\.ti\.com$"),
]
FOOTER_Y_MIN = 745    # footer lines start at y=752; body content reaches y=742
PAGE_NUM_RE = re.compile(r"^\d{1,4}$")

HEADING_RE = re.compile(r"^(\d{1,2}\.\d{1,2}(?:\.\d{1,2})*)\s+(\S.*)$")
MINITOC_RE = re.compile(r"^(\d{1,2})(\.\d{1,2}(?:\.\d{1,2})*)\s+.*\.{4,}\s*=*\d*\s*$")
TOC_ENTRY_RE = re.compile(r"^(\d{1,2}(?:\.\d{1,2})*)\s+(\S.*?)\.{3,}\s*=*(\d+)\s*$")
TOC_LEVEL1_RE = re.compile(r"^(\d{1,2})\s+(\S.*?)\.{3,}\s*=*(\d+)\s*$")
BULLET_RE = re.compile(r"^±(?!\s*[\d.])")

# ------------------------------------------------------------- font classes

def classify_fonts(doc, sample_step=1):
    """Return (shifted, junk) font-name sets.

    Font names include the subset tag ("AOGBCK+ArialMT") because
    pymupdf.TOOLS.set_subset_fontnames(True) is set before extraction; that is
    what distinguishes the re-encoded TTF body fonts from the identically
    named, normally encoded CFF fonts used for figure labels/legends.

    A full pass over all pages is used: rare code-font subsets (a few pages)
    must be classified too, or their text would stay encoded.

    shifted: body fonts using the ASCII-0x1D re-encoding (emitted characters
             are raw codes; encoded space 0x03 dominates).
    junk:    diagram-label fonts whose emitted characters are mostly control
             codes and cannot be decoded (tiny in-diagram labels; their
             content is duplicated by the surrounding prose).
    """
    hist = defaultdict(Counter)
    for pno in range(0, doc.page_count, sample_step):
        for block in doc[pno].get_text("rawdict")["blocks"]:
            for line in block.get("lines", []):
                for span in line["spans"]:
                    fn = span["font"]
                    if TYPE3_RE.match(fn):
                        continue
                    for ch in span["chars"]:
                        hist[fn][ch["c"]] += 1
    shifted, junk = set(), set()
    for fn, h in hist.items():
        total = sum(h.values())
        if total < 10:
            continue
        ctrl = sum(n for c, n in h.items() if ord(c) < 0x20 or 0x7F <= ord(c) <= 0x9F)
        n_enc_space = h.get("\x03", 0)      # encoded space (shifted scheme)
        n_ascii_space = h.get(" ", 0)       # real space (normal encoding)
        top = [ord(c) for c, _ in h.most_common(8)]
        # English-letter signature of the shifted scheme: e,t,r,i,o,a,n,s,p,m
        english = len(set(top) & {0x48, 0x57, 0x55, 0x4C, 0x52, 0x44, 0x51,
                                  0x56, 0x53, 0x50})
        if ctrl * 2 > total:
            junk.add(fn)
        elif n_enc_space > n_ascii_space and n_enc_space >= 10 and english >= 3:
            shifted.add(fn)
    return shifted, junk


def decode_char(c, font, shifted):
    if font in shifted:
        o = ord(c)
        if 0x03 <= o <= 0x61:
            return chr(o + 0x1D)
        return SHIFT_SPECIALS.get(c, c)
    return c


# -------------------------------------------------------------- page dumps

def extract_page(page, shifted, junk, unknown, dropped):
    """Decode one page into (lines, heading candidates, minitoc prefixes)."""
    raw = page.get_text("rawdict")
    out = []
    headings = []
    minitoc = []
    for block in raw["blocks"]:
        for line in block.get("lines", []):
            pieces = []
            bold_chars = 0
            total_chars = 0
            prev_x1 = None
            size = 10.0
            skip = False
            for span in line["spans"]:
                font = span["font"]
                if TYPE3_RE.match(font):
                    continue
                if font in junk:
                    skip = True
                    continue
                is_bold = bool(span.get("flags", 0) & 16) or "Bold" in font
                size = span.get("size", size) or size
                for ch in span["chars"]:
                    c = ch["c"]
                    d = decode_char(c, font, shifted)
                    if font in shifted:
                        o = ord(c)
                        if o >= 0x62 and c not in SHIFT_SPECIALS:
                            unknown[c] += 1
                    if prev_x1 is not None:
                        gap = ch["bbox"][0] - prev_x1
                        if gap > 0.45 * size:
                            pieces.append(" ")
                    # no legitimate document character is a control code or a
                    # C1 code: whatever survives decoding in that range is
                    # residue from undecodable diagram fonts
                    if 0x20 <= ord(d) < 0x7F or ord(d) >= 0xA0:
                        pieces.append(CHAR_FIXUPS.get(d, d))
                    else:
                        dropped[ord(d)] += 1
                    prev_x1 = ch["bbox"][2]
                    total_chars += 1
                    if is_bold:
                        bold_chars += 1
            if skip and not pieces:
                continue
            text = BULLET_RE.sub("•", "".join(pieces)).strip()
            if not text:
                continue
            # dotted TOC lines: the hyperlink page-number font encodes a real
            # space at 0x20 which the shifted decode turns into '='; drop it
            if re.search(r"\.{4,}", text):
                text = re.sub(r"=+(\d{1,5})\s*$", r"\1", text)
            y0 = line["bbox"][1]
            if y0 < 65:                      # running header zone
                continue
            if y0 > FOOTER_Y_MIN:            # footer zone (doc ID, page no, ...)
                continue
            if any(rx.match(text) for rx in FOOTER_RE):
                continue
            out.append((text, y0))
            m = MINITOC_RE.match(text)
            if m:
                minitoc.append(int(m.group(1)))
            m = HEADING_RE.match(text)
            if m and len(text) <= 100 and "..." not in text and bold_chars == total_chars:
                headings.append({"page": page.number + 1, "num": m.group(1),
                                 "title": m.group(2).strip()})
    return out, headings, minitoc


# ------------------------------------------------------------- TOC parsing

def parse_printed_toc(page_lines):
    """Level-1 entries from the printed TOC (already-decoded dump lines)."""
    entries, titles = {}, {}
    pending = []          # wrapped title fragments
    for lines in page_lines:
        for text, _y0 in lines:
            m = TOC_LEVEL1_RE.match(text)
            if m:
                num = int(m.group(1))
                title = re.sub(r"\s+", " ", " ".join(pending + [m.group(2)])).strip()
                page = int(m.group(3))
                pending = []
                titles[num] = title
                if num not in entries and 8 <= page <= 2031:
                    entries[num] = page
            elif re.match(r"^\d{1,2}\.\d", text) or "..." in text:
                pending = []           # deeper-level entry: reset
            elif re.match(r"^[A-Z(]", text) and not text.endswith("."):
                pending.append(text)
            else:
                pending = []
    return entries, titles


# --------------------------------------------------------------------- main

def main():
    # Keep subset tags ("AOGBCK+ArialMT") in reported font names so that the
    # re-encoded TTF body fonts can be told apart from the identically named
    # normally-encoded CFF fonts (figure labels / legends).
    pymupdf.TOOLS.set_subset_fontnames(True)
    doc = pymupdf.open(PDF)
    n = doc.page_count
    print(f"Opened {PDF} ({n} pages)")

    shifted, junk = classify_fonts(doc)
    print("Shifted-encoding fonts:", sorted(f.split("+")[-1] + "[" + f.split("+")[0] + "]"
                                            for f in shifted))
    print("Junk (dropped) fonts:", sorted(junk))

    unknown = Counter()
    dropped = Counter()   # control/C1 residue from undecodable diagram fonts
    all_headings = []
    page_lines = []
    for pno in range(n):
        lines, headings, _ = extract_page(doc[pno], shifted, junk, unknown, dropped)
        page_lines.append(lines)
        all_headings.extend(headings)
        if (pno + 1) % 400 == 0:
            print(f"  ... extracted page {pno + 1}")

    # ---- printed TOC (dump pages 3..9) ----
    toc_pages, toc_titles = parse_printed_toc(page_lines[2:9])
    print("Printed-TOC chapter starts:", toc_pages)
    print("Printed-TOC titles:", {k: toc_titles.get(k) for k in sorted(toc_titles)})

    # ---- chapter start detection ----
    # signal 1: pages whose first line starts with "This chapter"
    this_chapter = [p + 1 for p, lines in enumerate(page_lines)
                    if lines and lines[0][0].startswith("This chapter")]
    # signal 2: mini-TOC votes (pages after the TOC, unique chapter prefix, >=2 lines)
    votes = defaultdict(dict)
    for pno in range(10, n):
        nums = [num for num in _minitoc_prefixes(t for t, _y in page_lines[pno])]
        if nums and len(set(nums)) == 1 and len(nums) >= 2:
            votes[nums[0]][pno + 1] = len(nums)

    starts = {}
    # a) TOC anchors validated by a body signal within +-3 pages
    for num, page in sorted(toc_pages.items()):
        ok = page in this_chapter or page in votes.get(num, {})
        if ok:
            starts[num] = page
    # b) remaining "This chapter" pages fill the gaps, in order
    todo = [p for p in this_chapter if p not in starts.values()]
    used_nums = set(starts)
    for p in todo:
        prev_pages = [v for k, v in sorted(starts.items()) if v < p]
        next_pages = [v for k, v in sorted(starts.items()) if v > p]
        lo = max(prev_pages) if prev_pages else 0
        hi = min(next_pages) if next_pages else n
        cands = [k for k in votes if k not in used_nums
                 and lo < p < hi and any(lo < v < hi for v in votes[k])]
        if cands:
            num = min(cands, key=lambda k: min(abs(v - p) for v in votes[k]))
            starts[num] = p
            used_nums.add(num)
    # c) chapters still missing that have clean mini-TOC votes
    for num in sorted(votes):
        if num not in starts and num not in used_nums:
            lo_hi = [(v, k) for k, v in sorted(starts.items())]
            best = max(votes[num].items(), key=lambda kv: kv[1])
            starts[num] = best[0]
    # d) chapter 15: "Revision History" heading page after ch13
    if 15 not in starts:
        for p in range(2016, n):
            if page_lines[p] and page_lines[p][0][0].strip() == "Revision History":
                starts[15] = p + 1
                break

    print("Detected chapter starts:", dict(sorted(starts.items())))

    # build ordered chapter list
    order = sorted(starts)
    chapters = []
    for i, num in enumerate(order):
        start = starts[num]
        end = (starts[order[i + 1]] - 1) if i + 1 < len(order) else n - 1
        chapters.append({"num": num, "title": toc_titles.get(num, f"Chapter {num}"),
                         "start": start, "end": end})

    # ---- strip running headers: lines in the top zone were already dropped
    # during extraction (y < 65); nothing else needed here.

    # ---- write dump ----
    with open(OUT_TXT, "w", encoding="utf-8") as out:
        for pno, lines in enumerate(page_lines):
            out.write(f"=== Page {pno + 1} ===\n")
            for text, _y0 in lines:
                out.write(text + "\n")
            out.write("\n")

    with open(OUT_CHAPTERS, "w", encoding="utf-8") as f:
        json.dump({"chapters": chapters, "total_pages": n}, f, indent=1)
    with open(OUT_HEADINGS, "w", encoding="utf-8") as f:
        json.dump(all_headings, f, indent=1)

    # ---- validation report ----
    print(f"\nWrote {OUT_TXT}")
    print(f"Wrote {OUT_CHAPTERS} ({len(chapters)} chapters)")
    print(f"Wrote {OUT_HEADINGS} ({len(all_headings)} headings)")
    print("\nChapter map:")
    for c in chapters:
        print(f"  ch{c['num']:>2} pp{c['start']:>4}-{c['end']:>4}  {c['title']}")
    lvl2 = Counter(h["num"].split(".")[0] for h in all_headings
                   if re.match(r"^\d+\.\d+$", h["num"]))
    print("\nLevel-2 headings per chapter:", dict(sorted(lvl2.items(), key=lambda x: int(x[0]))))
    print("Kept-unknown codes (shifted fonts):", dict(unknown.most_common(12)) or "none")
    print("Dropped control/C1 residue chars:", sum(dropped.values()))
    return 0


def _minitoc_prefixes(lines):
    nums = []
    for text in lines:
        m = MINITOC_RE.match(text)
        if m:
            nums.append(int(m.group(1)))
    return nums


if __name__ == "__main__":
    sys.exit(main())
# AM62x Sitara Processors TRM (SPRUIV7B, Rev. B — "noRegisters" edition)

Texas Instruments **AM62x Sitara Processors Technical Reference Manual, Rev. B**
(literature number SPRUIV7B; *May 2022 – Revised September 2023*), 2,031 pages,
in the **noRegisters** edition — the variant without the per-module register
descriptions (chapter 14 *Registers* is listed in the table of contents but its
body was replaced by pointers to TI's online register supplements).

- Source PDF: `AM62x_TRM_SPRUIV7B_noRegisters.pdf`
- Authoritative reference: the PDF; everything in this directory is derived.

## Contents

```
.
├── AM62x_TRM_SPRUIV7B_noRegisters.pdf   # source document
├── extract_am62x_trm.py                 # PDF → decoded text dump + toc inputs
├── split_am62x.py                       # dump → chapters/ + sections/ + toc.md
├── parse_memory_map.py                  # Table 2-1 → memory_map.md / .csv
├── am62x_trm_full.txt                   # full decoded dump (~4.3 MB, 186k lines)
├── toc.md                               # section map with file links
├── chapters.json / headings.json        # machine-readable split metadata
├── memory_map.md / memory_map.csv       # SoC memory map, 515 regions (Table 2-1)
├── 00_Cover_and_TOC.txt                 # pp. 1-10 (cover, printed TOC)
├── 01_Front_Matter.txt                  # p. 11 (About / Glossary / Support / Export)
├── 99_Important_Notice.txt              # p. 2031 (TI legal notice)
├── chapters/                            # one file per chapter (complete text)
└── sections/                            # level-2 splits of the large chapters
    ├── Chapter_04/…  (Module Integration, 16 sections)
    ├── Chapter_06/…  (Device Configuration, 4 sections)
    ├── Chapter_07/…  (Processors and Accelerators, 4 sections)
    ├── Chapter_11/…  (Data Movement Architecture, 3 sections)
    └── Chapter_12/…  (Peripherals, 9 sections — the ~1000-page chapter)
```

Printed TRM page numbers equal PDF page numbers; every extracted file keeps
`=== Page N ===` markers so text can be traced back to the PDF.

## The text-extraction problem (why a custom extractor)

The body fonts are re-encoded TrueType subsets with **no usable ToUnicode
CMap**: glyph codes are stored as `ASCII - 0x1D` (e.g. the raw text `5HDG7KLV`
means `Read This`).  Meanwhile identically named CFF subsets used for figure
labels/legends *are* normally encoded, and TOC page numbers use yet another
variant.  Plain `pdftotext`-style extraction therefore produces mojibake, and a
document-wide decode is impossible — decoding must be **per font, per
character**:

1. `pymupdf.TOOLS.set_subset_fontnames(True)` keeps the subset tags
   (`AOGBCK+ArialMT`), which is what distinguishes the shifted TTF body fonts
   from the properly encoded CFF figure-label fonts.
2. Fonts are classified by sampled character histograms:
   - *shifted* — encoded space `0x03` dominates, no ASCII space: codes
     `0x03..0x61` are shifted `+0x1D`; a small set of higher codes map to
     `® ™ © ° µ Ω • — ’ „ “ ü ± φ × ≥` (identified from context).
   - *junk* — diagram-label fonts (Calibri flowchart labels, SymbolMT arrows)
     whose characters are undecodable control codes; **dropped** (their content
     is duplicated by the surrounding prose).
   - everything else is kept as extracted.
3. Running headers (fixed y-band) and footers (`SPRUIV7B … REVISED …`,
   `Submit Document Feedback`, copyright, bare page numbers) are stripped.
4. Feature bullets arrive via three different broken encodings (`0x87`,
   `0xb7`, and a glyph that resolves to `±`); all are normalised to `•`.

`split_am62x.py` derives chapter boundaries from the printed table of contents
(whose page numbers match this PDF's pagination exactly) cross-checked against
body evidence ("This chapter describes…" intro pages and per-chapter mini-TOCs),
and splits sections using detected bold headings.

## Regenerating

```sh
pip install pymupdf
python3 extract_am62x_trm.py    # → am62x_trm_full.txt, chapters.json, headings.json
python3 split_am62x.py          # → 00_*/*_Front_Matter, chapters/, sections/, toc.md
python3 parse_memory_map.py     # → memory_map.md, memory_map.csv
```

## Known limitations

- Chapter 14 *Registers* has no body in this edition;
  `chapters/Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt` is a stub.
- In-figure label text is omitted.  Diagram/figure fonts (~60k characters on
  122 figure-heavy pages: flowchart box labels, callout arrows, block-diagram
  labels) use first-use glyph-order encodings with no character map, which are
  mechanically undecodable; their content is duplicated by the surrounding
  prose (verified for the boot-flow and ESM-routing figures).
- A handful of ultra-rare fallback glyphs (~50 occurrences, all inside
  figures) could not be identified and are kept as extracted: `ĸ ĺ Ļ Ĺ ò ௗ`.
- The `✓` marks in the module-allocation tables were inferred from context
  (the glyph arrives via a Korean-font fallback).
- A few figure diagrams are page-wide graphics; their embedded text is
  extracted but visual layout (arrows, positions) is not reproduced.

## Quick navigation

- Start from [`toc.md`](toc.md) for the chapter/section map with file links.
- Bus/memory addresses: [`memory_map.md`](memory_map.md) (CSV for tooling).
- Boot: `chapters/Chapter_05_Initialization.txt`; clocks/reset/power:
  `sections/Chapter_06/`; interrupts: `chapters/Chapter_10_Interrupts.txt`;
  peripherals: `sections/Chapter_12/`.
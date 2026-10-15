# AGENTS.md

Guidance for AI coding agents working in this repository.

## What this repository is

A reference-documentation corpus — **no build system, no tests, no application code**.
It contains ARM A-profile architecture XML references plus two SoC TRM corpora
(Rockchip RK3588 and TI AM62x) with derived, plain-text artifacts optimized for
lookup by agents and humans.

## Layout

```
.
├── AGENTS.md                        # this file
├── ISA_A64_xml_A_profile-2026-09/   # A64 instruction set, ~2,322 XML files
├── SysReg_xml_A_profile-2026-09/    # A-profile system registers, ~1,971 XML files
├── rk3588/                          # Rockchip RK3588: PDFs + text extractions + tools
├── am62x/                           # TI AM62x TRM (SPRUIV7B) + text extractions + tools
└── DAI0527A_baremetal_boot_code_for_ARMv8_A_processors.pdf
```

## Where to find things

### ISA_A64_xml_A_profile-2026-09/ — A64 instruction set (2026-09 release)

- One XML file per instruction **encoding variant**: `add.xml`, plus suffixed files for
  multi-encoding instructions (`add_addsub_imm.xml`, `add_addsub_shift.xml`, `adc.xml`).
- Encoding diagrams, assembly syntax, and architectural pseudocode are inside each file.
- Indexes: `instructions.xml`, `func_index.xml`, `enc_index.xml`, `architecture_info.xml`.
- Support: `iform.dtd`/`iform.xsl`, `insn.css`, `build-manifest.json`,
  `Unallocated-A64.log` (unallocated encodings), 7 `A64.*.svg` diagrams.
- `diff-from-ISA_A64_xml_A_profile-2026-06/` — pre-rendered HTML diff vs the previous
  release; use it for "what changed between releases" questions.

### SysReg_xml_A_profile-2026-09/ — system registers (2026-09 release)

- Core registers: `AArch64-<register>.xml` (894 files, e.g. `AArch64-ttbr0_el1.xml`) and
  `AArch32-<register>.xml`, covering EL0–EL3, translation, debug, trace, PMU.
- Grouped register sets (dot prefix): `amu.*`, `pmu.*`, and GIC frames
  `irs_config_frame.*`, `irs_setlpi_frame.*`, `its_config_frame.*`,
  `its_translate_frame.*`, `iwb_config_frame.*`, `gic_pmu_frame.*`.
- Top-level indexes: `architecture_info.xml`, `enc_index.xml`, `instructions.xml`,
  `func_index.xml`, `notice.xml`.
- `xhtml/` — pre-rendered HTML of every register file (easier to skim than raw XML).
- `diff-from-SysReg_xml_A_profile-2026-06/` — HTML diff vs the previous release.

### rk3588/ — Rockchip RK3588

- Source PDFs (authoritative): `RK3588 Brief Datasheet.pdf`,
  `Rockchip RK3588 TRM V1.0-Part1-20220309.pdf`, `Rockchip RK3588 TRM V1.0-Part2 20220309.pdf`.
- Full text dumps: `rockchip_rk3588_trm_part1.txt`, `rockchip_rk3588_trm_part2.txt`,
  `rk3588_datasheet.txt` (pdftotext-style, pages separated by form feeds).
- Per-chapter splits: `part1/` (Chapters 1–39), `part2/` (Chapters 1–20), e.g.
  `part1/Chapter_19_UART.txt`, `part2/Chapter_11_PCIe_Controller.txt`.
- `address_mapping.md` / `address_mapping.csv` — SoC bus address map
  (Module, Start, End, Size), extracted from part 1 chapter 1 Table 1-1. **Start here for
  "where is peripheral X mapped" questions.**
- Generators: `split_chapters.py`, `parse_address_mapping.py`.
- Boot ROM: `rk3588_bootrom.bin` + `rk3588_bootrom.c`.

### am62x/ — TI AM62x (Sitara) TRM SPRUIV7B Rev. B, "noRegisters" edition

- Source PDF (authoritative): `AM62x_TRM_SPRUIV7B_noRegisters.pdf` (2,031 pages; register
  chapters replaced by links to TI's online register supplements — chapter 14 is a stub).
- **Do not re-extract the PDF with pdftotext or naive tooling.** The body fonts store
  glyph codes as `ASCII − 0x1D` with no usable ToUnicode maps, several identically-named
  font subsets use different encodings, and figure-label fonts are glyph-order encoded.
  The custom extractor `extract_am62x_trm.py` (see its header docstring and
  `am62x/README.md`) handles all of this; `am62x_trm_full.txt` is its output.
- `toc.md` — section map for chapters 1–15 with file links. **Start here to navigate.**
- `chapters/` — one complete text file per chapter (`Chapter_01_Introduction.txt` …
  `Chapter_15_Revision_History.txt`); `sections/` — level-2 splits of the large chapters
  (4, 6, 7, 11, 12), e.g. `sections/Chapter_12/12.4_Memory_Interfaces.txt`.
- `memory_map.md` / `memory_map.csv` — 515 memory regions (Region, Start, End, Size) from
  chapter 2 Table 2-1, validated (End = Start + Size − 1, addresses ascending).
- Regenerate: `pip install pymupdf` then, in `am62x/`, run `extract_am62x_trm.py` →
  `split_am62x.py` → `parse_memory_map.py` (total ~10 s).
- Known limitations are listed in `am62x/README.md`: in-figure label text is omitted
  (undecodable glyph-order fonts), `✓` marks in module-allocation tables are inferred,
  a few ultra-rare fallback glyphs inside figures are left as extracted.

## Working conventions

- **PDFs are authoritative.** The extracted text is derived and may contain small
  artifacts; verify against the PDF when precision matters (bit fields, timing values).
- TRM text files carry `=== Page N ===` markers. Printed TRM page numbers equal PDF page
  numbers in both TRMs; use the markers to trace quotes back to the source.
- The dumps are large (`am62x_trm_full.txt` ≈ 4.3 MB, `Chapter_12_Peripherals.txt` ≈ 2 MB).
  Prefer the section map / per-section files and targeted `grep` over reading dumps whole.
- All text outputs are UTF-8 plain text. Don't hand-edit generated artifacts
  (`am62x_trm_full.txt`, `chapters/`, `sections/`, `toc.md`, `memory_map.*`,
  `chapters.json`, `headings.json`, `address_mapping.*`, rk3588 dumps) — edit the
  generator script and re-run it instead.
- To add a new documentation corpus, follow the established pattern: source PDF inside a
  per-topic directory, an extractor script documenting any format quirks, per-chapter /
  per-section splits, a parsed "map" artifact where the document has one, and an entry in
  this file.
- Git: the repository currently has **no commits** (nothing tracked). Don't assume
  history, remotes, or a commit convention; don't run destructive git operations.

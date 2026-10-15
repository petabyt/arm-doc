#!/usr/bin/env python3
"""Split the AM62x TRM text dump into readable per-chapter / per-section files.

Inputs (produced by extract_am62x_trm.py):
  am62x_trm_full.txt   full decoded dump with "=== Page N ===" markers
  chapters.json        chapter list (num, title, start/end pages)
  headings.json        bold numbered headings (level >= 2) with pages

Outputs:
  00_Cover_and_TOC.txt       cover, blank page, printed table of contents
  01_Front_Matter.txt        About This Manual / Glossary / Related Docs / ...
  chapters/Chapter_NN_Title.txt      one file per chapter (complete)
  sections/Chapter_NN/N.N_Title.txt  level-2 splits for chapters > 100 pages
  chapters/Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt   stub
  99_Important_Notice.txt    TI's legal notice (last page)
  toc.md                     human-readable section map with file links
"""

import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
DUMP = os.path.join(HERE, "am62x_trm_full.txt")
CHAPTERS_JSON = os.path.join(HERE, "chapters.json")
HEADINGS_JSON = os.path.join(HERE, "headings.json")

PAGE_RE = re.compile(r"^=== Page (\d+) ===$")

SECTION_SPLIT_MIN_PAGES = 100     # chapters longer than this get level-2 splits


def sanitize(title):
    name = re.sub(r"[^A-Za-z0-9 ]", " ", title)
    name = re.sub(r"\s+", " ", name).strip().replace(" ", "_")
    return name or "Untitled"


def read_dump():
    pages = {}          # page -> list of lines
    cur = None
    with open(DUMP, encoding="utf-8") as f:
        for ln in f:
            ln = ln.rstrip("\n")
            m = PAGE_RE.match(ln)
            if m:
                cur = int(m.group(1))
                pages[cur] = []
            elif cur is not None and ln.strip():
                pages[cur].append(ln)
    return pages


def main():
    with open(CHAPTERS_JSON, encoding="utf-8") as f:
        meta = json.load(f)
    with open(HEADINGS_JSON, encoding="utf-8") as f:
        headings = json.load(f)
    pages = read_dump()
    n = meta["total_pages"]
    chapters = meta["chapters"]

    # group headings per chapter number
    headings_by_ch = {}
    for h in headings:
        top = int(h["num"].split(".")[0])
        if re.match(r"^\d+\.\d+$", h["num"]):
            headings_by_ch.setdefault(top, []).append(h)
    for lst in headings_by_ch.values():
        lst.sort(key=lambda h: (h["page"], [int(x) for x in h["num"].split(".")], h["num"]))

    out_files = []       # (relpath, first_page, last_page, lines)

    def write(relpath, text_lines):
        path = os.path.join(HERE, relpath)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", encoding="utf-8") as f:
            f.write("\n".join(text_lines) + "\n")
        out_files.append(relpath)

    def page_range_lines(a, b):
        out = []
        for p in range(a, b + 1):
            out.append(f"=== Page {p} ===")
            out.extend(pages.get(p, []))
            out.append("")
        return out

    # ---- cover + TOC (pages 1..10) and front matter (page 11) ----
    first_ch = chapters[0]["start"]
    toc_end = first_ch - 2                     # page before front matter
    write("00_Cover_and_TOC.txt", page_range_lines(1, toc_end))
    write("01_Front_Matter.txt", page_range_lines(toc_end + 1, first_ch - 1))

    # ---- chapters ----
    for ch in chapters:
        num, title = ch["num"], ch["title"]
        fname = f"chapters/Chapter_{num:02d}_{sanitize(title)}.txt"
        lines = page_range_lines(ch["start"], ch["end"])
        write(fname, lines)

        # level-2 section splits for oversized chapters
        if ch["end"] - ch["start"] + 1 > SECTION_SPLIT_MIN_PAGES:
            secs = headings_by_ch.get(num, [])
            if not secs:
                print(f"  WARNING: ch{num} flagged for split but no level-2 headings found")
                continue
            # locate each level-2 heading line inside the chapter text
            # (skip the dotted mini-TOC copies on the chapter start page and
            # any table cell that merely starts with the same number, e.g.
            # "12.5 MHz": the title text must match as well)
            marks = []
            for sec in secs:
                tag = sec["num"] + " "
                prefix = re.sub(r"\s+", " ", sec["title"])[:16]
                for i, ln in enumerate(lines):
                    rest = re.sub(r"\s+", " ", ln[len(tag):]) if ln.startswith(tag) else ""
                    if rest and "..." not in ln and rest.startswith(prefix[:len(prefix)]):
                        marks.append((i, sec))
                        break
                else:
                    print(f"  WARNING: heading {sec['num']} ({prefix!r}) not located in {fname}")
            # slice sections; text before the first section belongs to no file
            bounds = [i for i, _ in marks] + [len(lines)]
            for (i, sec), nxt in zip(marks, bounds[1:]):
                rel = f"sections/Chapter_{num:02d}/{sec['num']}_{sanitize(sec['title'])}.txt"
                body = []
                for ln in lines[i:nxt]:
                    if ln.startswith("=== Page "):
                        body.append(ln)
                    elif ln.strip():
                        body.append(ln)
                write(rel, body)

    # ---- chapter 14 stub (Registers: not part of the noRegisters variant) ----
    stub = ("Chapter 14 - Registers\n"
            "======================\n\n"
            "This chapter is NOT present in the \"noRegisters\" variant of the AM62x TRM\n"
            "(SPRUIV7B).  Register descriptions were removed from this edition; the\n"
            "body text refers the reader to TI's online register supplements, e.g.\n"
            "  https://www.ti.com/lit/pdf/registers  (AM62x register reference)\n\n"
            "The printed table of contents still lists chapter 14 subsections\n"
            "(14.1 ... 14.8.x) with page numbers from the full TRM (with registers);\n"
            "those page numbers do not apply to this document.\n")
    with open(os.path.join(HERE, "chapters", "Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt"),
              "w", encoding="utf-8") as f:
        f.write(stub)
    out_files.append("chapters/Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt")

    # ---- back matter: notice page(s) after the last chapter ----
    last = chapters[-1]
    if last["end"] < n:
        write("99_Important_Notice.txt", page_range_lines(last["end"] + 1, n))

    # ---- toc.md ----
    md = ["# AM62x Sitara Processors TRM - Section Map",
          "",
          "Source: `AM62x_TRM_SPRUIV7B_noRegisters.pdf` (Texas Instruments SPRUIV7B, Rev. B,",
          "September 2023 - the *noRegisters* edition, 2031 pages).  Text extracted with",
          "`extract_am62x_trm.py` (the PDF body fonts use a broken `ASCII - 0x1D` glyph",
          "encoding; see the script header and README for details).",
          "",
          "Printed TRM page numbers equal PDF page numbers, and `=== Page N ===` markers in",
          "every file refer to them.",
          ""]
    md += ["## Front matter", "",
           f"| Pages | File | Contents |",
           f"|-------|------|----------|",
           f"| 1-{toc_end} | [`00_Cover_and_TOC.txt`](00_Cover_and_TOC.txt) | Cover, blank page, printed table of contents |",
           f"| {toc_end + 1}-{first_ch - 1} | [`01_Front_Matter.txt`](01_Front_Matter.txt) | About This Manual, Glossary pointers, Related Documentation, Support Resources, Export Control Notice |",
           ""]
    md += ["## Chapters", "",
           "| Ch | Title | TRM pages | File |", "|----|-------|-----------|------|"]
    for ch in chapters:
        if ch["num"] == 14:
            continue
        fname = f"chapters/Chapter_{ch['num']:02d}_{sanitize(ch['title'])}.txt"
        md.append(f"| {ch['num']} | {ch['title']} | {ch['start']}-{ch['end']} | "
                  f"[`{os.path.basename(fname)}`]({fname}) |")
    md.append("| 14 | Registers | (absent) | [stub](chapters/Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt) - "
              "not included in the noRegisters variant |")
    md.append("")
    for ch in chapters:
        secs = headings_by_ch.get(ch["num"], [])
        if ch["end"] - ch["start"] + 1 <= SECTION_SPLIT_MIN_PAGES or not secs:
            continue
        md.append(f"### Chapter {ch['num']} - {ch['title']} sections")
        md.append("")
        md.append("| Sec | Title | TRM page | File |")
        md.append("|-----|-------|----------|------|")
        for sec in secs:
            rel = f"sections/Chapter_{ch['num']:02d}/{sec['num']}_{sanitize(sec['title'])}.txt"
            md.append(f"| {sec['num']} | {sec['title']} | {sec['page']} | "
                      f"[`{os.path.basename(rel)}`]({rel}) |")
        md.append("")
    md += ["## Back matter", "",
           f"| Pages | File | Contents |", f"|-------|------|----------|",
           f"| {chapters[-1]['end'] + 1}-{n} | [`99_Important_Notice.txt`](99_Important_Notice.txt) | TI Important Notice and Disclaimer |",
           ""]
    with open(os.path.join(HERE, "toc.md"), "w", encoding="utf-8") as f:
        f.write("\n".join(md))

    # ---- report ----
    total_lines = sum(1 for p in pages for _ in pages[p])
    print(f"Dump: {n} pages, {total_lines} content lines")
    print(f"Wrote {len(out_files)} split files + toc.md:")
    for rel in out_files:
        path = os.path.join(HERE, rel)
        print(f"  {rel:60s} {os.path.getsize(path):>9,} B")
    print("Wrote toc.md")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
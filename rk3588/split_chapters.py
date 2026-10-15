#!/usr/bin/env python3
import os
import re

part1_file = "/workspace/rockchip_rk3588_trm_part1.txt"
part2_file = "/workspace/rockchip_rk3588_trm_part2.txt"
OUT_ROOT = "/workspace/rk3588"

def extract_chapters(file_path, chapter_info, output_dir):
    """Extract chapters based on known line numbers."""
    os.makedirs(output_dir, exist_ok=True)
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()
    
    chapter_files = []
    for idx, (chap_name, start_line) in enumerate(chapter_info):
        # start_line is 1-indexed from grep, convert to 0-indexed
        start = start_line - 1
        if idx + 1 < len(chapter_info):
            end = chapter_info[idx + 1][1] - 1  # next chapter start - 1
        else:
            end = len(lines)
        
        chapter_lines = lines[start:end]
        # Clean up chapter name for filename
        chapter_name = re.sub(r'[^\w\s-]', '', chap_name).strip()
        chapter_name = re.sub(r'[-\s]+', '_', chapter_name)
        filename = os.path.join(output_dir, f"{chapter_name}.txt")
        
        with open(filename, 'w', encoding='utf-8') as cf:
            cf.writelines(chapter_lines)
        chapter_files.append(filename)
        print(f"  Created: {filename} ({len(chapter_lines)} lines)")
    
    return chapter_files

# Known chapter start line numbers from grep (1-indexed)
# Part 1
part1_chapters = [
    ("Chapter 1 System Overview", 755),
    ("Chapter 2 CRU", 6221),
    ("Chapter 3 CPU", 41987),
    ("Chapter 4 Graphics Process Unit (GPU)", 42176),
    ("Chapter 5 VPU", 42301),
    ("Chapter 6 General Register Files (GRF)", 81094),
    ("Chapter 7 Power Management Unit (PMU)", 120209),
    ("Chapter 8 MMU600", 140153),
    ("Chapter 9 MCU Subsystem", 140419),
    ("Chapter 10 Timer", 143037),
    ("Chapter 11 GIC600", 144004),
    ("Chapter 12 DMA Controller (DMAC)", 144150),
    ("Chapter 13 SDMMC_BUFFER", 149689),
    ("Chapter 14 Temperature-Sensor ADC (TS-ADC)", 149764),
    ("Chapter 15 Debug", 151981),
    ("Chapter 16 Mailbox", 152159),
    ("Chapter 17 Watchdog Timer(WDT)", 152684),
    ("Chapter 18 Pulse Width Modulation (PWM)", 153005),
    ("Chapter 19 UART", 155981),
    ("Chapter 20 GPIO", 159261),
    ("Chapter 21 I2C Interface", 161572),
    ("Chapter 22 I2S", 163421),
    ("Chapter 23 SPDIF Transmitter", 168002),
    ("Chapter 24 SPDIF Receiver", 169047),
    ("Chapter 25 Gigabit Media Access Controller (GMAC)", 170403),
    ("Chapter 26 SAR-ADC", 191379),
    ("Chapter 27 Digital Audio Codec", 193506),
    ("Chapter 28 Voice Activity Detect (VAD)", 195115),
    ("Chapter 29 CAN", 196609),
    ("Chapter 30 Flexible Serial Peripheral Interface (FSPI )", 199492),
    ("Chapter 31 Serial Peripheral Interface (SPI)", 201875),
    ("Chapter 32 SPINLOCK", 204079),
    ("Chapter 33 KEYLAD", 204151),
    ("Chapter 34 Share Memory", 205618),
    ("Chapter 35 DECOM", 206169),
    ("Chapter 36 RKNN", 207339),
    ("Chapter 37 Video Capture (VICAP)", 216511),
    ("Chapter 38 FishEye Correction(FEC)", 241599),
    ("Chapter 39 Pulse Density Modulation Interface Controller", 243876),
]

# Part 2
part2_chapters = [
    ("Chapter 1 Interconnect", 778),
    ("Chapter 2 Dynamic Memory Interface (DMC)", 5136),
    ("Chapter 3 Mobile Storage Host Controller", 52907),
    ("Chapter 4 eMMC Host Controller", 58176),
    ("Chapter 5 Raster Graphic Acceleration 3 (RGA3)", 63766),
    ("Chapter 6 Raster Graphic Acceleration(RGA2)", 69205),
    ("Chapter 7 Video Output Processor (VOP)", 72436),
    ("Chapter 8 Image Enhancement Processor（IEP", 100131),
    ("Chapter 9 DisplayPort Transmitter Controller (DPTX)", 103931),
    ("Chapter 10 CRYPTO", 108252),
    ("Chapter 11 PCIe Controller", 112427),
    ("Chapter 12 USB2.0 Host & PHY", 183198),
    ("Chapter 13 USB3 Controller", 183455),
    ("Chapter 14 USBDP COMBO PHY", 187723),
    ("Chapter 15 SATA Host", 192888),
    ("Chapter 16 Multiple Protocol PHY Subsystem", 196409),
    ("Chapter 17 Process-Voltage-Temperature Monitor (PVTM)", 201085),
    ("Chapter 18 PVTPLL", 201894),
    ("Chapter 19 MIPI CSI HOST", 202449),
    ("Chapter 20 MIPI CSI DPHY", 204076),
]

# Extract Part 1
print("Extracting Part 1 chapters...")
extract_chapters(part1_file, part1_chapters, os.path.join(OUT_ROOT, "part1"))

# Extract Part 2
print("\nExtracting Part 2 chapters...")
extract_chapters(part2_file, part2_chapters, os.path.join(OUT_ROOT, "part2"))

print("\nDone!")
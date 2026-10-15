# AM62x Sitara Processors TRM - Section Map

Source: `AM62x_TRM_SPRUIV7B_noRegisters.pdf` (Texas Instruments SPRUIV7B, Rev. B,
September 2023 - the *noRegisters* edition, 2031 pages).  Text extracted with
`extract_am62x_trm.py` (the PDF body fonts use a broken `ASCII - 0x1D` glyph
encoding; see the script header and README for details).

Printed TRM page numbers equal PDF page numbers, and `=== Page N ===` markers in
every file refer to them.

## Front matter

| Pages | File | Contents |
|-------|------|----------|
| 1-10 | [`00_Cover_and_TOC.txt`](00_Cover_and_TOC.txt) | Cover, blank page, printed table of contents |
| 11-11 | [`01_Front_Matter.txt`](01_Front_Matter.txt) | About This Manual, Glossary pointers, Related Documentation, Support Resources, Export Control Notice |

## Chapters

| Ch | Title | TRM pages | File |
|----|-------|-----------|------|
| 1 | Introduction | 12-30 | [`Chapter_01_Introduction.txt`](chapters/Chapter_01_Introduction.txt) |
| 2 | Memory Map | 31-69 | [`Chapter_02_Memory_Map.txt`](chapters/Chapter_02_Memory_Map.txt) |
| 3 | System Interconnect | 70-96 | [`Chapter_03_System_Interconnect.txt`](chapters/Chapter_03_System_Interconnect.txt) |
| 4 | Module Integration | 97-469 | [`Chapter_04_Module_Integration.txt`](chapters/Chapter_04_Module_Integration.txt) |
| 5 | Initialization | 470-526 | [`Chapter_05_Initialization.txt`](chapters/Chapter_05_Initialization.txt) |
| 6 | Device Configuration | 527-641 | [`Chapter_06_Device_Configuration.txt`](chapters/Chapter_06_Device_Configuration.txt) |
| 7 | Processors and Accelerators | 642-785 | [`Chapter_07_Processors_and_Accelerators.txt`](chapters/Chapter_07_Processors_and_Accelerators.txt) |
| 8 | Interprocessor Communication (IPC) | 786-800 | [`Chapter_08_Interprocessor_Communication_IPC.txt`](chapters/Chapter_08_Interprocessor_Communication_IPC.txt) |
| 9 | Memory Controllers | 801-818 | [`Chapter_09_Memory_Controllers.txt`](chapters/Chapter_09_Memory_Controllers.txt) |
| 10 | Interrupts | 819-865 | [`Chapter_10_Interrupts.txt`](chapters/Chapter_10_Interrupts.txt) |
| 11 | Data Movement Architecture | 866-1022 | [`Chapter_11_Data_Movement_Architecture.txt`](chapters/Chapter_11_Data_Movement_Architecture.txt) |
| 12 | Peripherals | 1023-2014 | [`Chapter_12_Peripherals.txt`](chapters/Chapter_12_Peripherals.txt) |
| 13 | On-Chip Debug | 2015-2028 | [`Chapter_13_On_Chip_Debug.txt`](chapters/Chapter_13_On_Chip_Debug.txt) |
| 15 | Revision History | 2029-2030 | [`Chapter_15_Revision_History.txt`](chapters/Chapter_15_Revision_History.txt) |
| 14 | Registers | (absent) | [stub](chapters/Chapter_14_Registers_NOT_IN_THIS_VARIANT.txt) - not included in the noRegisters variant |

### Chapter 4 - Module Integration sections

| Sec | Title | TRM page | File |
|-----|-------|----------|------|
| 4.1 | Memory Controllers | 98 | [`4.1_Memory_Controllers.txt`](sections/Chapter_04/4.1_Memory_Controllers.txt) |
| 4.2 | Processors and Accelerators | 100 | [`4.2_Processors_and_Accelerators.txt`](sections/Chapter_04/4.2_Processors_and_Accelerators.txt) |
| 4.3 | Interprocessor Communication | 110 | [`4.3_Interprocessor_Communication.txt`](sections/Chapter_04/4.3_Interprocessor_Communication.txt) |
| 4.4 | Device Configuration | 115 | [`4.4_Device_Configuration.txt`](sections/Chapter_04/4.4_Device_Configuration.txt) |
| 4.5 | Data Movement Architecture | 119 | [`4.5_Data_Movement_Architecture.txt`](sections/Chapter_04/4.5_Data_Movement_Architecture.txt) |
| 4.6 | Audio | 122 | [`4.6_Audio.txt`](sections/Chapter_04/4.6_Audio.txt) |
| 4.7 | General Connectivity | 126 | [`4.7_General_Connectivity.txt`](sections/Chapter_04/4.7_General_Connectivity.txt) |
| 4.8 | High-speed Serial Interfaces | 146 | [`4.8_High_speed_Serial_Interfaces.txt`](sections/Chapter_04/4.8_High_speed_Serial_Interfaces.txt) |
| 4.9 | Memory Interfaces | 151 | [`4.9_Memory_Interfaces.txt`](sections/Chapter_04/4.9_Memory_Interfaces.txt) |
| 4.10 | Industrial and Control Interfaces | 158 | [`4.10_Industrial_and_Control_Interfaces.txt`](sections/Chapter_04/4.10_Industrial_and_Control_Interfaces.txt) |
| 4.11 | Camera Subsystem | 169 | [`4.11_Camera_Subsystem.txt`](sections/Chapter_04/4.11_Camera_Subsystem.txt) |
| 4.12 | Timer Modules | 172 | [`4.12_Timer_Modules.txt`](sections/Chapter_04/4.12_Timer_Modules.txt) |
| 4.13 | Internal Diagnostic Modules | 190 | [`4.13_Internal_Diagnostic_Modules.txt`](sections/Chapter_04/4.13_Internal_Diagnostic_Modules.txt) |
| 4.14 | Graphics Processing Unit (GPU) | 466 | [`4.14_Graphics_Processing_Unit_GPU.txt`](sections/Chapter_04/4.14_Graphics_Processing_Unit_GPU.txt) |
| 4.15 | Display Subsystem (DSS) | 467 | [`4.15_Display_Subsystem_DSS.txt`](sections/Chapter_04/4.15_Display_Subsystem_DSS.txt) |
| 4.16 | Spinlock | 469 | [`4.16_Spinlock.txt`](sections/Chapter_04/4.16_Spinlock.txt) |

### Chapter 6 - Device Configuration sections

| Sec | Title | TRM page | File |
|-----|-------|----------|------|
| 6.1 | Memory Mapped Control Register Modules (CTRL_MMR) | 528 | [`6.1_Memory_Mapped_Control_Register_Modules_CTRL_MMR.txt`](sections/Chapter_06/6.1_Memory_Mapped_Control_Register_Modules_CTRL_MMR.txt) |
| 6.2 | Power | 533 | [`6.2_Power.txt`](sections/Chapter_06/6.2_Power.txt) |
| 6.3 | Reset | 569 | [`6.3_Reset.txt`](sections/Chapter_06/6.3_Reset.txt) |
| 6.4 | Clocking | 614 | [`6.4_Clocking.txt`](sections/Chapter_06/6.4_Clocking.txt) |

### Chapter 7 - Processors and Accelerators sections

| Sec | Title | TRM page | File |
|-----|-------|----------|------|
| 7.1 | Arm Cortex-A53 Subsystem (A53SS) | 643 | [`7.1_Arm_Cortex_A53_Subsystem_A53SS.txt`](sections/Chapter_07/7.1_Arm_Cortex_A53_Subsystem_A53SS.txt) |
| 7.2 | Device Manager Cortex R5F Subsystem (WKUP_R5FSS) | 652 | [`7.2_Device_Manager_Cortex_R5F_Subsystem_WKUP_R5FSS.txt`](sections/Chapter_07/7.2_Device_Manager_Cortex_R5F_Subsystem_WKUP_R5FSS.txt) |
| 7.3 | Cortex-M4F Subsystem (MCU_M4FSS) | 684 | [`7.3_Cortex_M4F_Subsystem_MCU_M4FSS.txt`](sections/Chapter_07/7.3_Cortex_M4F_Subsystem_MCU_M4FSS.txt) |
| 7.4 | Programmable Real-Time Unit Subsystem (PRUSS) | 698 | [`7.4_Programmable_Real_Time_Unit_Subsystem_PRUSS.txt`](sections/Chapter_07/7.4_Programmable_Real_Time_Unit_Subsystem_PRUSS.txt) |

### Chapter 11 - Data Movement Architecture sections

| Sec | Title | TRM page | File |
|-----|-------|----------|------|
| 11.1 | Data Movement Architecture Overview | 867 | [`11.1_Data_Movement_Architecture_Overview.txt`](sections/Chapter_11/11.1_Data_Movement_Architecture_Overview.txt) |
| 11.2 | Data Movement Subsystem (DMSS) | 928 | [`11.2_Data_Movement_Subsystem_DMSS.txt`](sections/Chapter_11/11.2_Data_Movement_Subsystem_DMSS.txt) |
| 11.3 | Peripheral DMA (PDMA) | 958 | [`11.3_Peripheral_DMA_PDMA.txt`](sections/Chapter_11/11.3_Peripheral_DMA_PDMA.txt) |

### Chapter 12 - Peripherals sections

| Sec | Title | TRM page | File |
|-----|-------|----------|------|
| 12.1 | Audio Peripherals | 1024 | [`12.1_Audio_Peripherals.txt`](sections/Chapter_12/12.1_Audio_Peripherals.txt) |
| 12.2 | General Connectivity Peripherals | 1098 | [`12.2_General_Connectivity_Peripherals.txt`](sections/Chapter_12/12.2_General_Connectivity_Peripherals.txt) |
| 12.3 | High-speed Serial Interfaces | 1243 | [`12.3_High_speed_Serial_Interfaces.txt`](sections/Chapter_12/12.3_High_speed_Serial_Interfaces.txt) |
| 12.4 | Memory Interfaces | 1351 | [`12.4_Memory_Interfaces.txt`](sections/Chapter_12/12.4_Memory_Interfaces.txt) |
| 12.5 | Industrial and Control Interfaces | 1578 | [`12.5_Industrial_and_Control_Interfaces.txt`](sections/Chapter_12/12.5_Industrial_and_Control_Interfaces.txt) |
| 12.6 | Camera Subsystem | 1731 | [`12.6_Camera_Subsystem.txt`](sections/Chapter_12/12.6_Camera_Subsystem.txt) |
| 12.7 | Timer Modules | 1762 | [`12.7_Timer_Modules.txt`](sections/Chapter_12/12.7_Timer_Modules.txt) |
| 12.8 | Internal Diagnostics Modules | 1808 | [`12.8_Internal_Diagnostics_Modules.txt`](sections/Chapter_12/12.8_Internal_Diagnostics_Modules.txt) |
| 12.9 | Display Subsystem (DSS) and Peripherals | 1923 | [`12.9_Display_Subsystem_DSS_and_Peripherals.txt`](sections/Chapter_12/12.9_Display_Subsystem_DSS_and_Peripherals.txt) |

## Back matter

| Pages | File | Contents |
|-------|------|----------|
| 2031-2031 | [`99_Important_Notice.txt`](99_Important_Notice.txt) | TI Important Notice and Disclaimer |

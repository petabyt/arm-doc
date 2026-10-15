#define 124 0x7c
#define 2001 0x7d1
#define 24 0x18

typedef unsigned char   undefined;

typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef struct BootMethod BootMethod, *PBootMethod;

typedef uint uint32_t;

struct BootMethod {
    void *func1;
    void *func2;
    void *func3;
    void *optional_func4;
    void *func5;
    uint32_t dat0;
    uint32_t dat1;
};



int *DAT_ffff00e0;
uint *DAT_ffff00e8;
undefined8 DAT_ffff00d8;
undefined8 DAT_ffff00d0;
undefined4 DAT_DEADBEAF;
undefined DAT_ff000010;
undefined DAT_ff000020;
undefined1 DAT_ffff4d9b;
undefined1 DAT_ffff4d9a;
undefined1 DAT_ffff4d99;
undefined1 DAT_ffff4d98;
undefined1 DAT_ffff4d9f;
undefined1 DAT_ffff4d9e;
undefined1 DAT_ffff4d9d;
undefined1 DAT_ffff4d9c;
undefined DAT_ff000014;
undefined DAT_ff0003e0;
undefined DAT_ff00009a;
undefined DAT_ff000098;
undefined DAT_ff0000f2;
undefined DAT_ff0000f0;
undefined DAT_ff000248;
undefined1 DAT_ff000250;
undefined DAT_ff000220;
undefined DAT_ff000224;
char DAT_ff000250;
undefined DAT_ff000508;
undefined DAT_ff000254;
undefined1 DAT_ff00024c;
undefined DAT_ff000000;
BootMethod[8] boot_methods;
undefined UNK_fe3a0020;
undefined DAT_fd7d030c;
undefined DAT_fd5f809c;
undefined DAT_fd5f8098;
undefined DAT_fd58a3b0;
undefined DAT_fd5f0004;
undefined DAT_ff0003e8;
undefined UNK_fe2c0000;
undefined DAT_fe2e0000;
undefined UNK_fe2c0200;
undefined DAT_fe2e0200;
undefined DAT_ff000228;
undefined DAT_ff00022c;
undefined DAT_fd7c0434;
undefined DAT_fd5f805c;
undefined DAT_fd5f8058;
undefined DAT_fe0300a8;
undefined DAT_fe0380a8;
undefined DAT_fd5f8040;
undefined DAT_fe2e002e;
undefined DAT_fe2e002c;
undefined DAT_fe2e0029;
undefined DAT_fe2e0034;
undefined DAT_fe2e000e;
undefined DAT_fe2e000c;
undefined DAT_fe2e0008;
undefined DAT_fe2e0028;
undefined DAT_fe2e0006;
undefined DAT_fe2e0004;
undefined DAT_fe2e0024;
undefined DAT_fe2e0010;
undefined DAT_fe2e0020;
undefined DAT_fe2e0030;
undefined DAT_fe2e002f;
undefined DAT_fe2e003e;
undefined DAT_fd5f804c;
undefined DAT_fd5f8048;
undefined DAT_fd5f8044;
undefined DAT_fd5f8064;
undefined DAT_fd5f8074;
undefined DAT_fd5f8060;
undefined DAT_fe0300ac;
undefined DAT_fe0380ac;
undefined DAT_fe2b0000;
undefined DAT_fe2b0008;
undefined DAT_fe2b0018;
undefined DAT_fe2b0028;
undefined DAT_fe2b0108;
undefined DAT_fe2b0020;
undefined DAT_fe2b0080;
undefined DAT_fe2b0100;
undefined DAT_fe2b0024;
undefined DAT_fe2b0084;
undefined DAT_fe2b0104;
undefined DAT_fd7c0438;
byte DAT_ff000230;
undefined DAT_ff000238;
undefined DAT_ff000234;
undefined DAT_ffff4b87;
undefined DAT_ffff4b84;
undefined DAT_ff000240;
undefined DAT_ff000230;
undefined DAT_ff000231;
undefined DAT_ffff4b90;
undefined4 UNK_ff00023c;
undefined DAT_ff00001c;
undefined1 DAT_ffff4be7;
char DAT_ff00024c;
byte DAT_ff0002db;
undefined DAT_ff0002dc;
undefined DAT_ff0002d8;
undefined DAT_ff0004f0;
undefined DAT_ff000298;
undefined DAT_ffff4ba8;
undefined DAT_ffff4bc8;
undefined DAT_ffff4bdc;
undefined DAT_ff000488;
undefined DAT_ff0004f4;
byte DAT_ff0004a5;
undefined1 DAT_ff0004a4;
undefined DAT_ff000480;
undefined DAT_ff0004a0;
undefined DAT_ff0004e0;
undefined DAT_ff0004ec;
undefined DAT_ff000478;
undefined DAT_ff0002c8;
undefined DAT_ff0002d0;
undefined DAT_ff0002b8;
undefined DAT_ff0002c0;
undefined DAT_ff0002a8;
undefined DAT_ff0002b0;
undefined DAT_ff0002a0;
undefined DAT_ff0004d0;
undefined DAT_ff0004d8;
undefined DAT_ff0004c0;
undefined DAT_ff0004c8;
undefined DAT_ff000288;
undefined DAT_ff000290;
undefined DAT_ff000278;
undefined DAT_ff000280;
undefined DAT_ff000268;
undefined DAT_ff000270;
undefined DAT_ff000258;
undefined DAT_ff000260;
undefined DAT_ff000408;
undefined DAT_ff000410;
undefined DAT_ff0003f8;
undefined DAT_ff000400;
undefined DAT_ff0003f0;
undefined DAT_ff000418;
undefined DAT_ff000430;
undefined DAT_ff000438;
undefined DAT_ff000420;
undefined DAT_ff000428;
undefined1 DAT_ff0002d8;
undefined1 DAT_ff0002d9;
undefined1 DAT_ff0002da;
undefined1 DAT_ff0002db;
undefined DAT_ff000490;
undefined DAT_ff000494;
undefined DAT_ff0004e8;
undefined DAT_ff0004f8;
undefined DAT_ff000500;
undefined UNK_fc00c100;
undefined UNK_fe3903a0;
undefined DAT_ff000520;
undefined DAT_ff000528;
undefined DAT_ff000510;
undefined DAT_ff000518;
undefined DAT_ff00052c;

void FUN_ffff0000(void)

{
  ulong uVar1;
  
  uVar1 = mpidr_el1;
  if ((uVar1 & 0xffff) != 0) {
    *DAT_ffff00e0 = 1;
    do {
      WaitForEvent();
    } while (*DAT_ffff00e0 != DAT_DEADBEAF);
                    // WARNING: Could not recover jumptable at 0xffff003c. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)(ulong)*DAT_ffff00e8)();
    return;
  }
  vbar_el3 = DAT_ffff00d8;
  entry(0,DAT_ffff00d8,0,0,0,0,0,0,0);
  return;
}



int FUN_ffff00f8(uint *param_1,uint *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      param_3 = param_3 - 4;
      uVar1 = *param_1;
      uVar2 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if (uVar1 != uVar2) {
        iVar3 = (uVar1 & 0xff) - (uVar2 & 0xff);
        if (((iVar3 == 0) && (iVar3 = (uVar1 & 0xffff) - (uVar2 & 0xffff), iVar3 == 0)) &&
           (iVar3 = (uVar1 & 0xffffff) - (uVar2 & 0xffffff), iVar3 == 0)) {
          iVar3 = (uVar1 >> 0x18) - (uVar2 >> 0x18);
        }
        return iVar3;
      }
    }
  }
  if (param_3 != 0) {
    if ((param_3 & 1) == 0) goto LAB_ffff019c;
    param_3 = param_3 + 1;
    puVar4 = param_1;
    puVar5 = param_2;
    while( true ) {
      param_1 = (uint *)((long)puVar4 + 1);
      param_2 = (uint *)((long)puVar5 + 1);
      iVar3 = (uint)(byte)*puVar4 - (uint)(byte)*puVar5;
      if (iVar3 != 0) {
        return iVar3;
      }
      param_3 = param_3 - 2;
      if (param_3 == 0) break;
LAB_ffff019c:
      puVar4 = (uint *)((long)param_1 + 1);
      puVar5 = (uint *)((long)param_2 + 1);
      iVar3 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    return 0;
  }
  return 0;
}



undefined8 FUN_ffff01d0(undefined8 param_1)

{
  FUN_ffff02b4();
  return param_1;
}



undefined8 FUN_ffff01fc(undefined8 ptr,uint param_2,undefined8 size)

{
  search_bitfield_(ptr,size,(param_2 & 0xff) * 0x1010101);
  return ptr;
}



void thunk_FUN_ffff0260(undefined4 *param_1,undefined4 *param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  for (; 0xf < param_3; param_3 = param_3 - 0x10) {
    uVar1 = param_2[1];
    uVar3 = param_2[2];
    uVar2 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar3;
    param_1[3] = uVar2;
    param_1 = param_1 + 4;
    param_2 = param_2 + 4;
  }
  if (7 < param_3) {
    uVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    param_3 = param_3 - 8;
  }
  if (3 < param_3) {
    *param_1 = *param_2;
    param_3 = param_3 - 4;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  while (param_3 = param_3 - 1, param_3 != 0xffffffffffffffff) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((long)param_1 + 1);
    param_2 = (undefined4 *)((long)param_2 + 1);
  }
  return;
}



void FUN_ffff0260(undefined4 *param_1,undefined4 *param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  for (; 0xf < param_3; param_3 = param_3 - 0x10) {
    uVar1 = param_2[1];
    uVar3 = param_2[2];
    uVar2 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar3;
    param_1[3] = uVar2;
    param_1 = param_1 + 4;
    param_2 = param_2 + 4;
  }
  if (7 < param_3) {
    uVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    param_3 = param_3 - 8;
  }
  if (3 < param_3) {
    *param_1 = *param_2;
    param_3 = param_3 - 4;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  while (param_3 = param_3 - 1, param_3 != 0xffffffffffffffff) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((long)param_1 + 1);
    param_2 = (undefined4 *)((long)param_2 + 1);
  }
  return;
}



void FUN_ffff02b4(uint *param_1,undefined1 *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  if (3 < param_3) {
    puVar5 = param_1;
    puVar7 = param_2;
    uVar4 = param_3;
    if (((ulong)param_1 & 3) != 0) {
      puVar5 = (uint *)((long)param_1 + 1);
      *(undefined1 *)param_1 = *param_2;
      puVar7 = param_2 + 1;
      uVar4 = param_3 - 1;
      if (((ulong)puVar5 & 3) != 0) {
        puVar6 = (uint *)((long)param_1 + 2);
        *(undefined1 *)puVar5 = param_2[1];
        puVar5 = puVar6;
        puVar7 = param_2 + 2;
        uVar4 = param_3 - 2;
        if (((ulong)puVar6 & 3) != 0) {
          puVar7 = param_2 + 3;
          puVar5 = (uint *)((long)param_1 + 3);
          *(undefined1 *)puVar6 = param_2[2];
          uVar4 = param_3 - 3;
        }
      }
    }
    param_3 = uVar4;
    uVar1 = (uint)puVar7 & 3;
    if (((ulong)puVar7 & 3) == 0) {
      thunk_FUN_ffff0260();
      return;
    }
    puVar6 = (uint *)(puVar7 + -(ulong)uVar1);
    uVar3 = uVar1 * -8 + 0x20;
    uVar8 = *puVar6;
    param_1 = puVar5;
    for (; puVar6 = puVar6 + 1, 3 < param_3; param_3 = param_3 - 4) {
      uVar2 = uVar8 >> (ulong)(uVar1 * 8);
      uVar8 = *puVar6;
      *param_1 = uVar8 << (ulong)(uVar3 & 0x1f) | uVar2;
      param_1 = param_1 + 1;
    }
    param_2 = (undefined1 *)((long)puVar6 - (ulong)(uVar3 >> 3));
  }
  if (-1 < (long)(param_3 - 1)) {
    *(undefined1 *)param_1 = *param_2;
    if (-1 < (long)(param_3 - 2)) {
      *(undefined1 *)((long)param_1 + 1) = param_2[1];
      if (-1 < (long)(param_3 - 3)) {
        *(undefined1 *)((long)param_1 + 2) = param_2[2];
      }
    }
  }
  return;
}



void thunk_FUN_ffff0394(undefined4 *ptr,ulong param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  for (; 3 < param_2; param_2 = param_2 - 4) {
    *ptr = param_3;
    ptr = ptr + 1;
  }
  puVar1 = ptr;
  if ((param_2 & 2) != 0) {
    puVar1 = (undefined4 *)((long)ptr + 2);
    *(short *)ptr = (short)param_3;
  }
  if ((param_2 & 1) != 0) {
    *(char *)puVar1 = (char)param_3;
  }
  return;
}



void FUN_ffff0394(undefined4 *ptr,ulong param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  for (; 3 < param_2; param_2 = param_2 - 4) {
    *ptr = param_3;
    ptr = ptr + 1;
  }
  puVar1 = ptr;
  if ((param_2 & 2) != 0) {
    puVar1 = (undefined4 *)((long)ptr + 2);
    *(short *)ptr = (short)param_3;
  }
  if ((param_2 & 1) != 0) {
    *(char *)puVar1 = (char)param_3;
  }
  return;
}



void search_bitfield_(undefined2 *ptr,ulong size,undefined2 param_3)

{
  undefined2 *ptr1;
  undefined2 *ptr2;
  
  ptr1 = ptr;
  if ((size != 0) && (((ulong)ptr & 1) != 0)) {
    ptr1 = (undefined2 *)((long)ptr + 1);
    *(char *)ptr = (char)param_3;
    size = size - 1;
  }
  ptr2 = ptr1;
  if ((1 < size) && (((ulong)ptr1 & 2) != 0)) {
    ptr2 = ptr1 + 1;
    *ptr1 = param_3;
    size = size - 2;
  }
  thunk_FUN_ffff0394(ptr2,size);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void init_saradc(void)

{
  int iVar1;
  uint saradc_tmp;
  
  Ram00000000fd7c03a0 = 0x3fc00740;
  sleep_us(1);
                    // saradc:
                    // - select channel 0
                    // - single_pd_mode on
  Ram00000000fec10000 = 0x2f0020;
                    // t_as_soc = 0xc
  Ram00000000fec1000c = 0xc;
                    // t_pd_soc = 0x20
  Ram00000000fec10004 = 0x20;
                    // start_adc = 1
  Ram00000000fec10000 = 0x100010;
  sleep_us(10);
  saradc_tmp = Ram00000000fec1010c;
                    // wait until saradc status is idle
  if ((saradc_tmp & 1) != 0) {
    iVar1 = 2001;
    do {
      iVar1 = iVar1 + -1;
      if (iVar1 < 1) {
        return;
      }
      sleep_us(1);
      saradc_tmp = Ram00000000fec1010c;
    } while ((saradc_tmp & 1) != 0);
  }
                    // read data0
  saradc_tmp = Ram00000000fec10120;
  saradc_tmp = saradc_tmp & 0xffff;
  if (saradc_tmp < 0xeab) {
    if (saradc_tmp < 0xc00) {
      if (saradc_tmp < 0x955) {
        if (saradc_tmp < 0x6ab) {
          if (saradc_tmp < 0x400) {
            _DAT_ff000010 = 5;
            if (saradc_tmp < 0x156) {
              _DAT_ff000010 = 10;
            }
          }
          else {
            _DAT_ff000010 = 2;
          }
        }
        else {
          _DAT_ff000010 = 3;
        }
      }
      else {
        _DAT_ff000010 = 4;
      }
    }
    else {
      _DAT_ff000010 = 6;
    }
  }
  else {
    _DAT_ff000010 = 0;
  }
  return;
}



undefined8 FUN_ffff0504(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined1 auStack_30 [32];
  
  if ((*(byte *)(param_1 + 0xd) >> 6 & 1) == 0) {
    uVar1 = FUN_ffff4618(param_2,(ulong)*(ushort *)(param_3 + 2) << 9,auStack_30);
    if ((int)uVar1 == 0) {
      uVar1 = FUN_ffff00f8(param_3 + 0x18,auStack_30,0x20);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint FUN_ffff0560(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xffff;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar4 = 0x80;
    do {
      uVar2 = (uVar3 & 0xffff) << 1;
      if ((uVar3 & 0x8000) != 0) {
        uVar2 = uVar2 ^ 0x1021;
      }
      uVar1 = uVar4 & *param_1;
      uVar4 = uVar4 >> 1;
      uVar3 = uVar2;
      if (uVar1 != 0) {
        uVar3 = uVar2 ^ 0x1021;
      }
    } while (uVar4 != 0);
    param_1 = param_1 + 1;
  }
  return uVar3;
}



// fd81: DDRPHY0_CRU
// fd7c: CRU_NS
// fd7d: SEC_SCRU

void cru_ddrphy_setup(void)

{
  Ram00000000fd7c0398 = 0x1f0000;
  Ram00000000fd7c0324 = 0x3c003c0;
  Ram00000000fd7c0594 = 0xf0c0f0c;
  Ram00000000fd7c0320 = 0x1800100;
  Ram00000000fd7d8300 = 0x1f0000;
  Ram00000000fd818310 = 0x19f0100;
  Ram00000000fd7d0304 = 0x3ff02ff;
  Ram00000000fd818318 = 0x1f0000;
  return;
}



void firewall_config(void)

{
  uint uVar1;
  
  uVar1 = Ram00000000fe038078;
  Ram00000000fe038078 = uVar1 & 0xffff0000;
  uVar1 = Ram00000000fe030078;
  Ram00000000fe030078 = uVar1 & 0xffff0000;
  return;
}



void FUN_ffff063c(int msleep)

{
  for (; msleep != 0; msleep = msleep + -1) {
    sleep_us(1000);
  }
  return;
}



void sleep_us(int n)

{
  int iVar1;
  int cpu_speed_;
  
  cpu_speed_ = get_sram_of_0();
  iVar1 = cpu_speed_ * n * 124;
  if (cpu_speed_ != 24) {
    iVar1 = cpu_speed_ * n * 0x80;
  }
  if (iVar1 + 0x3ffU >> 10 != 0) {
    busy_cycles();
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff06a0_guess_validate(long param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  uint uVar6;
  int local_64;
  
  _DAT_ff000020 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar6 = 0;
    uVar1 = CONCAT11(DAT_ffff4d9b,DAT_ffff4d9a);
    uVar2 = CONCAT11(DAT_ffff4d99,DAT_ffff4d98);
    uVar3 = CONCAT11(DAT_ffff4d9f,DAT_ffff4d9e);
    uVar4 = CONCAT11(DAT_ffff4d9d,DAT_ffff4d9c);
    do {
      uVar5 = (**(code **)(param_1 + 0x10))(uVar6,&DAT_ff000020,&local_64);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      if ((int)uVar5 == 0) {
        if ((CONCAT22(uVar1,uVar2) == _DAT_ff000020) || (CONCAT22(uVar3,uVar4) == _DAT_ff000020)) {
          _DAT_ff000010 = *(undefined4 *)(param_1 + 0x2c);
          _DAT_ff000014 = local_64;
          _DAT_ff0003e0 = param_1;
          if (*(code **)(param_1 + 0x20) != (code *)0x0) {
            (**(code **)(param_1 + 0x20))(0xff000050);
          }
          if ((uint)_DAT_ff00009a * 0x200 - 0xfff000 < 0xff100001) {
            uVar5 = (**(code **)(_DAT_ff0003e0 + 8))
                              (_DAT_ff000014 + (uint)_DAT_ff000098,0xff001000,
                               (ulong)_DAT_ff00009a << 9);
            if (((int)uVar5 == 0) &&
               (uVar5 = FUN_ffff0504(&DAT_ff000020,0xff001000,&DAT_ff000098), (int)uVar5 == 0)) {
              ic_isb();
              uVar5 = (*(code *)0xff001000)(0xff000078,8);
              if (((int)uVar5 == 0) &&
                 ((uVar5 = (**(code **)(_DAT_ff0003e0 + 8))
                                     (_DAT_ff000014 + (uint)_DAT_ff0000f0,0,
                                      (ulong)_DAT_ff0000f2 << 9), (int)uVar5 == 0 &&
                  (uVar5 = FUN_ffff0504(&DAT_ff000020,0,&DAT_ff0000f0), (int)uVar5 == 0)))) {
                ic_isb();
                uVar5 = (*(code *)0x0)(0xff000078,8);
              }
            }
          }
          else {
            uVar5 = 0xffffffff;
          }
        }
        else {
          uVar5 = 0;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0x28));
  }
  return uVar5;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void dwc3_usb_spin(void)

{
  reset_all_clocks();
  _DAT_ff000248 = 0xffffffff;
  FUN_ffff01fc(&DAT_ff000020,0,0x200);
  dwc3_init();
  do {
    usb_run_loop();
  } while( true );
}



void thunk_FUN_ffff17f8(void)

{
  FUN_ffff17f8();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool emmc_init(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint local_28;
  undefined4 local_24;
  
  emmc_reset();
  local_28 = 0;
  DAT_ff000250 = 0;
  _DAT_ff000220 = 0;
  _DAT_ff000224 = 0;
  iVar1 = FUN_ffff1c44(0,0,0);
  if (iVar1 == 0) {
    sleep_us(100);
    uVar3 = 0;
    do {
      iVar1 = FUN_ffff1c44(0x102,0x40ff8000,&local_28);
      if (iVar1 != 0) goto LAB_ffff0984;
      if ((int)local_28 < 0) {
        if ((local_28 | 0x80) == 0x80ff8080) {
          uVar2 = 0x40;
        }
        else {
          if ((local_28 | 0x80) != 0xc0ff8080) goto LAB_ffff0984;
          uVar2 = 0x20;
        }
        goto LAB_ffff0990;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 >> 6 < 0x7d);
    if (uVar3 == 8000) {
LAB_ffff0984:
      iVar1 = 0x2000;
    }
    else {
      uVar2 = 0;
LAB_ffff0990:
      iVar1 = FUN_ffff1c44(0x209,0,0);
      if (iVar1 == 0) {
        _DAT_ff000220 = 2;
        iVar1 = FUN_ffff1c44(0x31a,0x20000,0);
        if ((((iVar1 == 0) && (iVar1 = FUN_ffff1d08(25000000), iVar1 == 0)) &&
            (iVar1 = FUN_ffff1c44(0x71b,(ulong)_DAT_ff000220 << 0x10,&local_28), iVar1 == 0)) &&
           (iVar1 = FUN_ffff1c44(0x101a,0x200,&local_28), iVar1 == 0)) {
          local_24 = 0;
          iVar1 = FUN_ffff1c44(0x61b,0x3b70200,&local_24);
          if (((iVar1 == 0) && (-1 < (char)local_24)) &&
             ((iVar1 = FUN_ffff1c44(0xd1a,(ulong)_DAT_ff000220 << 0x10,&local_24), iVar1 == 0 &&
              (-1 < (char)local_24)))) {
            FUN_ffff1c54(8);
          }
          iVar1 = 0;
          _DAT_ff000224 = uVar2;
        }
      }
    }
  }
  return iVar1 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool FUN_ffff0a68(int param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((_DAT_ff000224 & 0x24) == 0) {
    uVar3 = 9;
  }
  uVar1 = 0x10123a;
  if (param_3 < 0x201) {
    uVar1 = 0x10113a;
  }
  iVar2 = FUN_ffff191c(uVar1,param_1 << (ulong)uVar3,0,0x200,param_3,param_2);
  return iVar2 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff0b34(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_4;
  
  local_4 = 0;
  iVar1 = FUN_ffff1c44(0x61b,0x3b90100,&local_4);
  if ((((iVar1 == 0) && (-1 < (char)local_4)) &&
      (iVar1 = FUN_ffff1c44(0xd1a,(ulong)_DAT_ff000220 << 0x10,&local_4), iVar1 == 0)) &&
     (-1 < (char)local_4)) {
    uVar2 = FUN_ffff1ccc(1);
    if ((int)uVar2 == 0) {
      uVar2 = FUN_ffff1d08(50000000);
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



undefined8 FUN_ffff0ba8(int *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0x434d4d45 && DAT_ff000250 != '\x01') {
    uVar1 = FUN_ffff0b34();
    if ((int)uVar1 == 0) {
      DAT_ff000250 = '\x01';
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff0bf4(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  iVar1 = *param_1;
  piVar2 = _DAT_ff000508;
  if ((iVar1 == 0x524f4e53 || iVar1 == 0x4e414e53) && (_DAT_ff000508 == (int *)0x0)) {
    if ((iVar1 == 0x524f4e53) && (_DAT_ff000254 == 0)) {
      uVar3 = FUN_ffff27a4(param_1);
      piVar2 = param_1;
      if ((int)uVar3 != 0) {
        uVar3 = 0xffffffff;
        piVar2 = _DAT_ff000508;
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((iVar1 == 0x4e414e53) && (_DAT_ff000254 == 1)) {
        if (*(char *)((long)param_1 + 0xe) == '\x02') {
          DAT_ff00024c = 1;
        }
        uVar3 = 0;
        piVar2 = param_1;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  _DAT_ff000508 = piVar2;
  return uVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 get_sram_of_0(void)

{
  return _DAT_ff000000;
}



ulong FUN_ffff0cbc(byte *param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = 0x47c6a7e6;
  if (param_2 != 0) {
    uVar2 = (ulong)param_2;
    do {
      uVar2 = uVar2 - 1;
      uVar1 = (ulong)((int)(uVar1 >> 2) + (uint)uVar1 * 0x20 + (uint)*param_1 ^ (uint)uVar1);
      param_1 = param_1 + 1;
    } while (uVar2 != 0);
  }
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void entry(void)

{
  set_u32_in_sram_0x0(0x18);
  cru_ddrphy_setup();
  _DAT_ff000010 = 0;
  FUN_ffff0dc8();
  reset_all_clocks();
  crypto_reset();
  init_saradc_();
                    // _DAT_ff000010 must be the boot method
  if (_DAT_ff000010 != 10) {
    try_boot_methods();
  }
  dwc3_usb_spin();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int try_boot_methods(void)

{
  code *func1;
  long struct_offset;
  undefined8 *func1_of;
  int rc;
  
  struct_offset = 0;
  rc = -1;
  do {
    func1_of = (undefined8 *)((long)&boot_methods[0].func1 + struct_offset);
    if (_DAT_ff000010 == 0) {
      func1 = (code *)*func1_of;
      rc = *(int *)((long)&boot_methods[0].dat1 + struct_offset);
LAB_ffff0d78:
      rc = (*func1)(rc);
      if (rc == 0) {
        rc = FUN_ffff06a0_guess_validate(func1_of);
      }
      else {
        func1 = *(code **)((long)&boot_methods[0].optional_func4 + struct_offset);
        if (func1 != (code *)0x0) {
          (*func1)(*(undefined4 *)((long)&boot_methods[0].dat1 + struct_offset));
        }
      }
    }
    else if (*(int *)((long)&boot_methods[0].dat1 + struct_offset) == _DAT_ff000010) {
      func1 = *(code **)((long)&boot_methods[0].func1 + struct_offset);
      rc = _DAT_ff000010;
      goto LAB_ffff0d78;
    }
    struct_offset = struct_offset + 0x30;
    if ((int)struct_offset == 0x180) {
      return rc;
    }
  } while( true );
}



int FUN_ffff0dc8(void)

{
  dword dVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int extraout_w1;
  uint uVar5;
  undefined4 local_24;
  dword local_18;
  uint local_14;
  
  local_18 = 0;
  local_14 = 0;
  iVar3 = otp_stuff_2(&local_14,1,1);
  if ((-1 < iVar3) && (iVar3 = otp_stuff_2(&local_18,0x17,1), -1 < iVar3)) {
                    // PMU0_SGRF is undocumented
    dVar1 = DWORD_fd586214;
    if ((local_14 == dVar1) && (dVar1 = DWORD_fd58621c, local_18 == dVar1)) {
      iVar3 = bitmask_stuff(local_14 & 0xff,0x5a);
      if (iVar3 < 3) {
        local_14 = 1;
      }
      else {
        local_14 = 0;
        iVar3 = otp_s_stuff(1,0x5a);
        if (iVar3 < 0) goto LAB_ffff0efc;
      }
      iVar3 = bitmask_stuff((undefined1)local_18,0xa5);
      if (iVar3 < 3) {
        bVar2 = false;
        local_18 = 1;
      }
      else {
        local_18 = 0;
        iVar3 = otp_s_stuff(0x17,0xa5);
        if (iVar3 < 0) goto LAB_ffff0efc;
        bVar2 = local_18 == 0;
      }
      if ((local_14 != 0) && (!bVar2)) {
        local_24 = 0;
        iVar3 = otp_stuff_2(&local_24,8,1);
        if (-1 < iVar3) {
          iVar4 = bitmask_stuff((undefined1)local_24,0xff);
          if (4 < iVar4) {
            Ram00000000fd587030 = 0x1f001f;
            return iVar3;
          }
        }
      }
    }
    else {
      local_18 = 0;
      local_14 = 0;
    }
  }
LAB_ffff0efc:
  iVar3 = die();
  if (extraout_w1 != 0) {
    Ram00000000fe3a0004 = iVar3 << 0x10 | 2;
    Ram00000000fe3a0010 = extraout_w1;
    Ram00000000fe3a0008 = 1;
    uVar5 = Ram00000000fe3a0084;
    if ((uVar5 >> 3 & 1) == 0) {
      iVar3 = -0x2711;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == 0) {
          return -1;
        }
        sleep_us(1);
        uVar5 = Ram00000000fe3a0084;
      } while ((uVar5 >> 3 & 1) == 0);
    }
    Ram00000000fe3a0084 = uVar5;
  }
  return 0;
}



undefined8 otp_s_stuff(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
                    // OTP
  if (param_2 != 0) {
    Ram00000000fe3a0004 = param_1 << 0x10 | 2;
    Ram00000000fe3a0010 = param_2;
    Ram00000000fe3a0008 = 1;
    uVar1 = Ram00000000fe3a0084;
    if ((uVar1 >> 3 & 1) == 0) {
      iVar2 = -0x2711;
      do {
        iVar2 = iVar2 + 1;
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        sleep_us(1);
        uVar1 = Ram00000000fe3a0084;
      } while ((uVar1 >> 3 & 1) == 0);
    }
    Ram00000000fe3a0084 = uVar1;
  }
  return 0;
}



undefined8 undocumented_secure_otp_stuff(undefined4 *param_1,int param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  int iVar5;
  
  if (param_3 < 0x11) {
                    // fe3a: OTP_S
    Ram00000000fe3a0004 = param_3 << 8 | param_2 << 0x10;
    Ram00000000fe3a0008 = 1;
    uVar2 = Ram00000000fe3a0084;
    if ((uVar2 >> 1 & 1) == 0) {
      iVar5 = -0x2711;
      do {
        iVar5 = iVar5 + 1;
        if (iVar5 == 0) goto LAB_ffff0f90;
        sleep_us(1);
        uVar2 = Ram00000000fe3a0084;
      } while ((uVar2 >> 1 & 1) == 0);
    }
    uVar1 = 0;
    Ram00000000fe3a0084 = uVar2;
    if ((param_1 != (undefined4 *)0x0) && (param_3 != 0)) {
      uVar3 = (ulong)param_3;
      puVar4 = &UNK_fe3a0020;
      do {
        *param_1 = *(undefined4 *)((ulong)puVar4 & 0xfffffffc);
        uVar3 = uVar3 - 1;
        puVar4 = puVar4 + 4;
        param_1 = param_1 + 1;
      } while (uVar3 != 0);
      uVar1 = 0;
    }
  }
  else {
LAB_ffff0f90:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



undefined8 otp_stuff_2(long param_1,int param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    do {
      uVar2 = param_3;
      if (0xf < param_3) {
        uVar2 = 0x10;
      }
      uVar1 = undocumented_secure_otp_stuff(param_1,param_2,uVar2);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      param_1 = param_1 + (ulong)uVar2 * 4;
      param_3 = param_3 - uVar2;
      param_2 = uVar2 + param_2;
    } while (param_3 != 0);
  }
  return uVar1;
}



ulong otp_s_stuff(undefined4 param_1,uint param_2)

{
  ulong uVar1;
  uint local_14;
  
  local_14 = 0;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = undocumented_secure_otp_stuff(&local_14,param_1,1);
    if ((((int)uVar1 == 0) &&
        (uVar1 = otp_s_stuff(param_1,param_2 & (local_14 ^ 0xffffffff)), (int)uVar1 == 0)) &&
       (uVar1 = undocumented_secure_otp_stuff(&local_14,param_1,1), (int)uVar1 == 0)) {
      uVar1 = (ulong)-(uint)((param_2 & (local_14 ^ 0xffffffff)) != 0);
    }
  }
  return uVar1;
}



void die(void)

{
  Ram00000000fd5fb14c = 0xc000c00;
  FUN_ffff063c(2);
  Ram00000000fd7c0c08 = 0xfdb9;
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void sec_scru(int param_1)

{
  if (param_1 != 0) {
    return;
  }
  Ram00000000fd7d030c = 0x3fc027c0;
  return;
}



void pmu_sgrf_stuff(int param_1)

{
  if (param_1 != 0) {
    return;
  }
  Ram00000000fd58a3b0 = 2;
  Ram00000000fd5f0004 = 0xff0021;
  Ram00000000fd5f8098 = 0xffff1111;
  Ram00000000fd5f809c = 0xff0011;
  sleep_us(2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff1210(int type)

{
  int iVar1;
  undefined4 *base;
  
  base = (undefined4 *)&UNK_fe2c0000;
  if (type != 0) {
    base = (undefined4 *)&DAT_fe2e0000;
  }
  sec_scru();
  pmu_sgrf_stuff(type);
  _DAT_ff0003e8 = type;
  base[1] = (uint)(type == 3);
  sleep_us(1000);
  *base = 3;
  sleep_us(100);
  base[2] = 0;
  base[4] = 1;
  base[0xb] = 0x80202000;
  if ((int)base[0xb] < 0) {
    iVar1 = 10000;
    do {
      sleep_us(1);
      if (iVar1 < 2) break;
      iVar1 = iVar1 + -1;
    } while ((int)base[0xb] < 0);
  }
  sleep_us(500);
  base[5] = 0xffffff40;
  base[0x13] = 0x307f0080;
  base[0x11] = 0xffffffff;
  return 0;
}



undefined8
FUN_ffff12d8(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5,
            uint param_6,undefined4 *param_7)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_44;
  
  puVar2 = &UNK_fe2c0000;
  if (param_1 != 0) {
    puVar2 = &DAT_fe2e0000;
  }
  puVar3 = (undefined4 *)&UNK_fe2c0200;
  if (param_1 != 0) {
    puVar3 = (undefined4 *)&DAT_fe2e0200;
  }
  if (((param_2 >> 0xd & 1) == 0) || ((*(uint *)(puVar2 + 0x48) >> 9 & 1) == 0)) {
    if (-1 < *(int *)(puVar2 + 0x2c)) {
      FUN_ffff14e0(puVar2);
      if ((param_2 >> 9 & 1) != 0) {
        *(undefined4 *)(puVar2 + 0x1c) = param_5;
        *(uint *)(puVar2 + 0x20) = param_6;
      }
      *(undefined4 *)(puVar2 + 0x28) = param_3;
      iVar4 = FUN_ffff1554(puVar2,param_2 & 0x5ffeffff | 0xa0000000);
      if (iVar4 == 0) {
        local_44 = 1000;
        while (((*(uint *)(puVar2 + 0x44) >> 2 & 1) == 0 && (0 < local_44))) {
          sleep_us(1);
          local_44 = local_44 + -1;
        }
        *(undefined4 *)(puVar2 + 0x44) = 4;
        if ((param_2 >> 0xe & 1) != 0) {
          FUN_ffff14e0(puVar2);
        }
        if ((*(uint *)(puVar2 + 0x44) >> 8 & 1) != 0) {
          *(undefined4 *)(puVar2 + 0x44) = 0xffffffff;
          return 0x20;
        }
        if ((param_2 >> 9 & 1) != 0) {
          param_6 = param_6 >> 2;
          local_44 = 0;
          do {
            if (param_6 == 0) break;
            if ((*(uint *)(puVar2 + 0x44) & 0xa280) != 0) goto LAB_ffff145c;
            puVar6 = param_7;
            if ((*(uint *)(puVar2 + 0x48) >> 2 & 1) == 0) {
              do {
                uVar7 = param_6;
                param_7 = puVar6 + 1;
                *puVar6 = *puVar3;
                local_44 = 0;
                param_6 = uVar7 - 1;
                if (param_6 == 0) break;
                puVar6 = param_7;
              } while ((*(uint *)(puVar2 + 0x48) >> 2 & 1) == 0);
              if (uVar7 == 1) {
                if ((*(uint *)(puVar2 + 0x44) & 0xa280) == 0) break;
                goto LAB_ffff145c;
              }
            }
            sleep_us(1);
            bVar1 = 100000 < local_44;
            local_44 = local_44 + 1;
            if (bVar1) {
LAB_ffff145c:
              *(undefined4 *)(puVar2 + 0x44) = 0xffffffff;
              return 0x800000;
            }
          } while( true );
        }
        *(undefined4 *)(puVar2 + 0x44) = 0xffffffff;
        if ((param_2 >> 0x10 & 1) == 0) {
LAB_ffff14c0:
          uVar5 = 0;
        }
        else {
          local_44 = 0;
          do {
            if ((*(uint *)(puVar2 + 0x48) >> 9 & 1) == 0) goto LAB_ffff14c0;
            sleep_us(1);
            bVar1 = local_44 < 0x3d091;
            local_44 = local_44 + 1;
          } while (bVar1);
          uVar5 = 0x400;
        }
        if ((param_2 >> 6 & 1) == 0) {
          return uVar5;
        }
        if (param_4 == (undefined4 *)0x0) {
          return uVar5;
        }
        *param_4 = *(undefined4 *)(puVar2 + 0x30);
        return uVar5;
      }
    }
    uVar5 = 0x1000;
  }
  else {
    uVar5 = 0x400;
  }
  return uVar5;
}



void FUN_ffff14e0(uint *param_1)

{
  bool bVar1;
  int local_4;
  
  if ((param_1[0x12] >> 2 & 1) == 0) {
    *param_1 = *param_1 | 2;
    local_4 = 5000;
    do {
      if ((*param_1 >> 1 & 1) == 0) {
        return;
      }
      bVar1 = 0 < local_4;
      local_4 = local_4 + -1;
    } while (bVar1);
  }
  return;
}



void FUN_ffff1524(void)

{
  FUN_ffff12d8();
  return;
}



void FUN_ffff1534(int param_1)

{
  if (param_1 != 0) {
    return;
  }
  Ram00000000fd7d030c = 0x3fc02000;
  return;
}



long FUN_ffff1554(long param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_14;
  
  local_14 = 1000;
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  while (*(int *)(param_1 + 0x2c) < 0) {
    iVar2 = local_14 + -1;
    bVar1 = local_14 < 1;
    local_14 = iVar2;
    if (bVar1) break;
    sleep_us(1);
  }
  return (ulong)(local_14 == 0) << 0xc;
}



undefined4 FUN_ffff15ac(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = &UNK_fe2c0000;
  if (param_1 != 0) {
    puVar1 = &DAT_fe2e0000;
  }
  *(undefined4 *)(puVar1 + 0x10) = 0;
  iVar2 = FUN_ffff1554(puVar1,0x80202000);
  uVar3 = 0x1000;
  if (iVar2 == 0) {
    FUN_ffff1534(param_1,param_2);
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 1;
    iVar2 = FUN_ffff1554(puVar1,0x80202000);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0x1000;
    }
  }
  return uVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff1630(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  short sVar5;
  uint uVar6;
  undefined4 local_24;
  
  uVar6 = 0;
  uVar4 = 0x40ff8000;
  if (param_2 != 1) {
    uVar4 = 0xff8000;
  }
  local_24 = 0;
  while( true ) {
    iVar2 = FUN_ffff1f70(param_1,0x2069,uVar4,&local_24);
    if (iVar2 != 0) {
      return 1;
    }
    if ((int)local_24 < 0) break;
    uVar6 = uVar6 + 1;
    if (0x7f7 < uVar6) {
      if (uVar6 == 0x7f8) {
        uVar3 = 0x2000;
      }
      else {
        sVar5 = 0;
LAB_ffff16ec:
        uVar3 = FUN_ffff1524(param_1,0x21c2,0,0);
        if (((int)uVar3 == 0) && (uVar3 = FUN_ffff1524(param_1,0x2143,0,&local_24), (int)uVar3 == 0)
           ) {
          _DAT_ff000228 = local_24._2_2_;
          uVar3 = FUN_ffff15ac(param_1,25000000);
          if (((int)uVar3 == 0) &&
             (((uVar3 = FUN_ffff1524(param_1,0x12147,(ulong)_DAT_ff000228 << 0x10,0),
               (int)uVar3 == 0 && (uVar3 = FUN_ffff1524(param_1,0x2150,0x200,0), (int)uVar3 == 0))
              && (uVar3 = FUN_ffff1f70(param_1,0x216a,0,0), (int)uVar3 == 0)))) {
            iVar2 = FUN_ffff1f70(param_1,0x2146,2,0);
            if (iVar2 == 0) {
              puVar1 = &UNK_fe2c0000;
              if (param_1 != 0) {
                puVar1 = &DAT_fe2e0000;
              }
              *(undefined4 *)(puVar1 + 0x18) = 1;
            }
            uVar3 = 0;
            _DAT_ff00022c = sVar5;
          }
        }
      }
      return uVar3;
    }
  }
  if (param_2 == 1) {
    if ((local_24 | 0x80) == 0xc0ff8080) {
      sVar5 = 4;
    }
    else {
      sVar5 = (ushort)((local_24 | 0x80) == 0x80ff8080) << 3;
    }
  }
  else {
    sVar5 = 0x10;
  }
  goto LAB_ffff16ec;
}



void FUN_ffff17e0(void)

{
  Ram00000000fd7c0434 = 0xff00bf00;
  return;
}



void FUN_ffff17f8(void)

{
  uint uVar1;
  
  Ram00000000fd5f8040 = 0xffff0000;
  Ram00000000fd5f8058 = 0xffff0000;
  Ram00000000fd5f805c = 0xffff0000;
  uVar1 = Ram00000000fe0380a8;
  Ram00000000fe0380a8 = uVar1 | 0xffff0000;
  uVar1 = Ram00000000fe0300a8;
  Ram00000000fe0300a8 = uVar1 | 0xffff0000;
  return;
}



void FUN_ffff1838(void)

{
  uint uVar1;
  
  Ram00000000fd5f8040 = 0xffff1111;
  Ram00000000fd5f8058 = 0xffff1111;
  Ram00000000fd5f805c = 0xffff1111;
  uVar1 = Ram00000000fe0380a8;
  Ram00000000fe0380a8 = uVar1 & 0xffff;
  uVar1 = Ram00000000fe0300a8;
  Ram00000000fe0300a8 = uVar1 & 0xffff;
  return;
}



undefined8 emmc_reset(void)

{
  ushort uVar1;
  int iVar2;
  
  FUN_ffff1bec(1);
  FUN_ffff17e0();
  FUN_ffff1838();
  DAT_fe2e0029 = 0xb;
  sleep_us(1000);
  Ram00000000fe2e002c = 0;
  sleep_us(10);
  Ram00000000fe2e002c = 1;
  uVar1 = Ram00000000fe2e002c;
  if ((uVar1 >> 1 & 1) == 0) {
    iVar2 = -0x4e21;
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0) {
        return 0x1000;
      }
      sleep_us(1);
      uVar1 = Ram00000000fe2e002c;
    } while ((uVar1 >> 1 & 1) == 0);
  }
  Ram00000000fe2e002c = uVar1 | 4;
  sleep_us(500);
  DAT_fe2e002e = 0xe;
  Ram00000000fe2e0034 = 0xff003b;
  return 0;
}



// WARNING: Type propagation algorithm not settling

int FUN_ffff191c(uint param_1,undefined4 param_2,undefined4 *param_3,uint param_4,uint param_5,
                undefined4 *param_6)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  bool bVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  undefined4 *puVar12;
  uint unaff_w29;
  
  uVar8 = 3;
  if ((param_1 & 0x23) == 0) {
    uVar8 = 1;
  }
  if ((param_1 & 0xc0) != 0) {
    uVar8 = 1;
  }
  iVar7 = FUN_ffff1d7c(uVar8);
  if (iVar7 != 0) goto LAB_ffff1974;
  uVar2 = param_1 & 3;
  if ((param_1 >> 5 & 1) == 0) {
    if (uVar2 != 0) {
      DAT_fe2e002e = 0xe;
    }
  }
  else {
    if (param_5 == 0) {
      return 4;
    }
    if (param_5 < param_4) {
      return 4;
    }
    if (((ulong)param_6 & 7) != 0) {
      return 4;
    }
    unaff_w29 = param_5 >> 9;
    uVar11 = 0x26;
    if (param_5 < 0x400) {
      uVar11 = 2;
    }
    Ram00000000fe2e0000 = (int)param_6;
    Ram00000000fe2e0004 = (ushort)param_4 & 0xfff | 0x7000;
    Ram00000000fe2e0006 = (short)unaff_w29;
    Ram00000000fe2e000c = (ushort)(param_1 >> 0x10) & 0x10 | uVar11 | 1;
  }
  Ram00000000fe2e0008 = param_2;
  Ram00000000fe2e000e = (short)param_1;
  uVar9 = Ram00000000fe2e0030;
  uVar10 = uVar9 & 0xf0001;
  if (uVar10 == 0) {
    iVar7 = -0x2711;
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == 0) {
        return 0x20;
      }
      sleep_us(1);
      uVar9 = Ram00000000fe2e0030;
      uVar10 = uVar9 & 0xf0001;
    } while (uVar10 == 0);
  }
  Ram00000000fe2e0030 = uVar10;
  if ((uVar9 & 0xf0000) != 0) {
    iVar7 = 0x1000000;
    goto LAB_ffff1974;
  }
  if ((param_1 >> 5 & 1) != 0) {
    uVar10 = 0;
    bVar3 = DAT_fe2e0028;
    bVar4 = false;
    iVar7 = 1000000;
    DAT_fe2e0028 = bVar3 & 0xe7;
    puVar12 = param_6;
LAB_ffff1a7c:
    do {
      uVar9 = Ram00000000fe2e0030;
      if ((uVar9 >> 0xf & 1) != 0) {
        iVar7 = -5;
LAB_ffff1bdc:
        Ram00000000fe2e0030 = 0xffffffff;
        goto LAB_ffff1974;
      }
      if ((bVar4) || ((uVar9 & 0x30) == 0)) {
LAB_ffff1b0c:
        if ((!bVar4) && ((uVar9 >> 3 & 1) != 0)) {
          uVar1 = (int)param_6 + 0x80000U & 0xfff80000;
          param_6 = (undefined4 *)(ulong)uVar1;
          Ram00000000fe2e0030 = 8;
          Ram00000000fe2e0000 = uVar1;
        }
        if (iVar7 == 0) {
          iVar7 = -0x6e;
          goto LAB_ffff1bdc;
        }
        iVar7 = iVar7 + -1;
        sleep_us(5);
        if ((uVar9 >> 1 & 1) != 0) break;
        goto LAB_ffff1a7c;
      }
      uVar1 = Ram00000000fe2e0024;
      if ((uVar1 & 0xc00) == 0) {
        bVar4 = false;
      }
      else {
        Ram00000000fe2e0030 = 0x30;
        uVar1 = -(param_4 >> 2);
        puVar5 = puVar12;
        uVar6 = param_4 >> 2;
        if ((param_1 >> 0x14 & 1) == 0) {
          while (uVar6 != 0) {
            uVar1 = uVar1 + 1;
            Ram00000000fe2e0020 = *puVar5;
            puVar5 = puVar5 + 1;
            uVar6 = uVar1;
          }
        }
        else {
          while (uVar6 != 0) {
            uVar8 = Ram00000000fe2e0020;
            *puVar5 = uVar8;
            uVar1 = uVar1 + 1;
            puVar5 = puVar5 + 1;
            uVar6 = uVar1;
          }
        }
        puVar12 = (undefined4 *)((long)puVar12 + (ulong)param_4);
        uVar10 = uVar10 + 1;
        if (uVar10 < unaff_w29) goto LAB_ffff1b0c;
        bVar4 = true;
      }
    } while ((uVar9 >> 1 & 1) == 0);
  }
  if (uVar2 == 3) {
    iVar7 = FUN_ffff1d7c(2);
LAB_ffff1b60:
    if (param_3 != (undefined4 *)0x0) {
      uVar8 = Ram00000000fe2e0010;
      *param_3 = uVar8;
    }
  }
  else {
    iVar7 = 0;
    if (uVar2 != 0) goto LAB_ffff1b60;
  }
  Ram00000000fe2e0030 = 0xffffffff;
  if (iVar7 == 0) {
    return 0;
  }
LAB_ffff1974:
  FUN_ffff1bec(2);
  FUN_ffff1bec(4);
  return iVar7;
}



void FUN_ffff1bec(byte param_1)

{
  byte bVar1;
  int iVar2;
  
  DAT_fe2e002f = param_1;
  bVar1 = DAT_fe2e002f;
  if ((bVar1 & param_1) != 0) {
    iVar2 = -19999;
    do {
      sleep_us(1);
      bVar1 = DAT_fe2e002f;
      if (iVar2 == 0) {
        return;
      }
      iVar2 = iVar2 + 1;
    } while ((bVar1 & param_1) != 0);
  }
  return;
}



void FUN_ffff1c44(void)

{
  FUN_ffff191c();
  return;
}



undefined8 FUN_ffff1c54(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = DAT_fe2e0028;
  bVar1 = bVar1 & 0xdd;
  bVar2 = bVar1;
  if (param_1 == 8) {
    bVar2 = bVar1 | 0x20;
  }
  bVar1 = bVar1 | 2;
  if (param_1 != 4) {
    bVar1 = bVar2;
  }
  DAT_fe2e0028 = bVar1;
  return 0;
}



void FUN_ffff1c8c(int param_1)

{
  uint uVar1;
  
  if (param_1 == 25000000) {
    uVar1 = 0x8000;
  }
  else {
    if (param_1 != 50000000) {
      return;
    }
    uVar1 = 0xb00;
  }
  Ram00000000fd7c0434 = uVar1 | 0xff000000;
  return;
}



undefined8 FUN_ffff1ccc(int param_1)

{
  byte bVar1;
  ushort uVar2;
  
  if (param_1 == 1) {
    bVar1 = DAT_fe2e0028;
    DAT_fe2e0028 = bVar1 | 4;
    uVar2 = Ram00000000fe2e003e;
    Ram00000000fe2e003e = uVar2 & 0xfff8 | 1;
    return 0;
  }
  return 1;
}



undefined8 FUN_ffff1d08(undefined4 param_1)

{
  ushort uVar1;
  int iVar2;
  
  Ram00000000fe2e002c = 0;
  sleep_us(10);
  FUN_ffff1c8c(param_1);
  Ram00000000fe2e002c = 1;
  uVar1 = Ram00000000fe2e002c;
  if ((uVar1 >> 1 & 1) == 0) {
    iVar2 = -0x4e21;
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0) {
        return 0x1000;
      }
      sleep_us(1);
      uVar1 = Ram00000000fe2e002c;
    } while ((uVar1 >> 1 & 1) == 0);
  }
  Ram00000000fe2e002c = uVar1 | 4;
  return 0;
}



undefined8 FUN_ffff1d7c(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Ram00000000fe2e0024;
  if ((uVar1 & param_1) != 0) {
    iVar2 = -0x7a121;
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0) {
        return 0x400;
      }
      sleep_us(1);
      uVar1 = Ram00000000fe2e0024;
    } while ((uVar1 & param_1) != 0);
  }
  return 0;
}



bool sdmmc_setup(void)

{
  int iVar1;
  
  FUN_ffff1210(0);
  iVar1 = FUN_ffff1dfc(0);
  return iVar1 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulong FUN_ffff1dfc(ulong param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = param_1 & 0xffffffff;
  _DAT_ff000228 = 0;
  _DAT_ff00022c = 0;
  uVar1 = FUN_ffff1524(param_1,0x8100,0,0);
  uVar3 = (ulong)uVar1;
  if (uVar1 == 0) {
    sleep_us(100);
    iVar2 = FUN_ffff1524(uVar4,0x2148,0x1aa,0);
    uVar3 = 1;
    if (iVar2 == 0) {
LAB_ffff1e88:
      uVar3 = FUN_ffff1630(uVar4,uVar3);
      return uVar3;
    }
    if (iVar2 == 0x20) {
      iVar2 = FUN_ffff1524(uVar4,0x2177,0,0);
      if (iVar2 == 0) {
        uVar3 = 0;
        goto LAB_ffff1e88;
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool FUN_ffff1e98(int param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  if ((_DAT_ff00022c & 0x24) == 0) {
    uVar1 = 9;
  }
  uVar2 = 0x2351;
  if (0x200 < param_3) {
    uVar2 = 0x2352;
  }
  uVar1 = FUN_ffff12d8(_DAT_ff0003e8,uVar2,param_1 << (ulong)uVar1,0,0x200,param_3,param_2);
  if ((0x200 < param_3) && ((uVar1 | 0x800000) == 0x800000)) {
    FUN_ffff1524(_DAT_ff0003e8,0x1414c,0,0);
  }
  return uVar1 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff1f70(ulong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined4 local_24;
  
  local_24 = 0;
  uVar1 = FUN_ffff1524(param_1,0x2177,(ulong)_DAT_ff000228 << 0x10,&local_24);
  if ((int)uVar1 == 0) {
    if (((byte)local_24 >> 5 & 1) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_ffff1524(param_1 & 0xffffffff,param_2,param_3,param_4);
    }
  }
  return uVar1;
}



void FUN_ffff1fe0(int param_1)

{
  uint uVar1;
  
  if (param_1 == 4) {
    Ram00000000fd5f8044 = 0xff000000;
    Ram00000000fd5f8048 = 0xf0ff0000;
    Ram00000000fd5f804c = 0xf0000;
  }
  else if (param_1 == 6) {
    Ram00000000fd5f8060 = 0xffff0000;
    Ram00000000fd5f8064 = 0xf00000;
    Ram00000000fd5f8074 = 0xf0000;
  }
  else {
    Ram00000000fd5f8040 = 0xf0000;
    Ram00000000fd5f8058 = 0xffff0000;
    Ram00000000fd5f805c = 0xf000000;
  }
  uVar1 = Ram00000000fe0380ac;
  Ram00000000fe0380ac = uVar1 | 0xffff;
  uVar1 = Ram00000000fe0300ac;
  Ram00000000fe0300ac = uVar1 | 0xffff;
  return;
}



void config_sys_stuff(int param_1)

{
  uint uVar1;
  
  if (param_1 == 4) {
                    // pmu0_sgrf
    Ram00000000fd5f8044 = 0xff003300;
    Ram00000000fd5f8048 = 0xf0ff3033;
    Ram00000000fd5f804c = 0xf0003;
  }
  else if (param_1 == 6) {
    Ram00000000fd5f8060 = 0xffff5555;
    Ram00000000fd5f8064 = 0xf00050;
    Ram00000000fd5f8074 = 0xf0002;
  }
  else {
    Ram00000000fd5f8040 = 0xf0002;
    Ram00000000fd5f8058 = 0xffff2222;
    Ram00000000fd5f805c = 0xf000200;
  }
  sleep_us(1);
                    // firewall
  uVar1 = Ram00000000fe0380ac;
  Ram00000000fe0380ac = uVar1 & 0xffff0000;
  uVar1 = Ram00000000fe0300ac;
  Ram00000000fe0300ac = uVar1 & 0xffff0000;
  return;
}



undefined8 reset_fspi(undefined4 param_1)

{
  CRU_NS_undocumented(0);
  config_sys_stuff(param_1);
  fspi_wait_reg(&DAT_fe2b0000);
  return 0;
}



undefined4 fspi_do_thing(uint param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  ulong uVar9;
  int local_34;
  
  local_34 = 0;
  uVar7 = Ram00000000fe2b0020;
  if ((((uVar7 >> 1 & 1) == 0) || (uVar7 = Ram00000000fe2b0020, (uVar7 >> 2 & 1) == 0)) ||
     (uVar7 = Ram00000000fe2b0024, (uVar7 & 1) != 0)) {
    fspi_wait_reg(&DAT_fe2b0000);
  }
  uVar7 = param_1 >> 0xe & 3;
  if (uVar7 == 3) {
    uVar7 = param_2 >> 0x10 & 0x1f;
    if (uVar7 == 0) {
      return 0xfffffffe;
    }
    Ram00000000fe2b0018 = uVar7 - 1;
    Ram00000000fe2b0000 = param_2 | 2;
    Ram00000000fe2b0100 = param_1;
LAB_ffff21d4:
    Ram00000000fe2b0104 = param_3;
  }
  else {
    Ram00000000fe2b0000 = param_2 | 2;
    Ram00000000fe2b0100 = param_1;
    if (uVar7 != 0) goto LAB_ffff21d4;
  }
  uVar7 = param_1 >> 0x10 & 0x3fff;
  if (uVar7 == 0) {
    uVar8 = 0;
  }
  else if ((param_2 >> 0xe & 1) == 0) {
    if ((param_1 >> 0xc & 1) == 0) {
      uVar3 = param_1 >> 0x10 & 3;
      uVar9 = (ulong)uVar3;
      uVar7 = uVar7 >> 2;
      do {
        if (uVar7 == 0) {
          uVar8 = 0;
          puVar6 = param_4;
          goto LAB_ffff2280;
        }
        while (uVar5 = Ram00000000fe2b0020, puVar6 = param_4, (uVar5 & 0x1f0000) != 0) {
          uVar4 = uVar7;
          if ((uVar7 < (uVar5 >> 0x10 & 0x1f)) || (uVar4 = uVar5 >> 0x10 & 0x1f, uVar4 != 0)) {
            puVar6 = param_4 + (ulong)(uVar4 - 1) + 1;
            uVar5 = uVar4;
            do {
              uVar8 = Ram00000000fe2b0108;
              *param_4 = uVar8;
              uVar5 = uVar5 - 1;
              param_4 = param_4 + 1;
            } while (uVar5 != 0);
            uVar7 = uVar7 - uVar4;
            uVar8 = 0;
            if (uVar7 == 0) goto LAB_ffff2280;
          }
          local_34 = 0;
          param_4 = puVar6;
        }
        sleep_us(1);
        bVar1 = local_34 < 0x2711;
        local_34 = local_34 + 1;
      } while (bVar1);
      uVar8 = 0xfffffffc;
LAB_ffff2280:
      local_34 = 0;
      if (uVar3 != 0) {
LAB_ffff228c:
        uVar7 = Ram00000000fe2b0020;
        if ((uVar7 & 0x1f0000) == 0) goto code_r0xffff22a0;
        uVar3 = Ram00000000fe2b0108;
        uVar7 = 0;
        do {
          *(char *)puVar6 = (char)(uVar3 >> (ulong)(uVar7 & 0x1f));
          uVar9 = uVar9 - 1;
          uVar7 = uVar7 + 8;
          puVar6 = (undefined4 *)((long)puVar6 + 1);
        } while (uVar9 != 0);
      }
    }
    else {
      uVar7 = uVar7 + 3 >> 2;
      do {
        while (uVar3 = Ram00000000fe2b0020, (uVar3 & 0x1f00) != 0) {
          uVar5 = uVar7;
          if ((uVar3 >> 8 & 0x1f) <= uVar7) {
            uVar5 = uVar3 >> 8 & 0x1f;
          }
          puVar6 = param_4;
          if (uVar5 != 0) {
            puVar6 = param_4 + (ulong)(uVar5 - 1) + 1;
            uVar3 = uVar5;
            do {
              uVar3 = uVar3 - 1;
              Ram00000000fe2b0108 = *param_4;
              param_4 = param_4 + 1;
            } while (uVar3 != 0);
            uVar7 = uVar7 - uVar5;
          }
          uVar8 = 0;
          if (uVar7 == 0) goto LAB_ffff23e4;
          local_34 = 0;
          param_4 = puVar6;
        }
        sleep_us(1);
        bVar1 = local_34 < 0x2711;
        local_34 = local_34 + 1;
      } while (bVar1);
      uVar8 = 0xfffffffd;
    }
  }
  else {
    Ram00000000fe2b0008 = 0xffffffff;
    Ram00000000fe2b0084 = (int)param_4;
    Ram00000000fe2b0080 = 1;
    local_34 = uVar7 * 10;
    while ((uVar7 = Ram00000000fe2b0028, (uVar7 >> 7 & 1) == 0 &&
           (iVar2 = local_34 + -1, bVar1 = 0 < local_34, local_34 = iVar2, bVar1))) {
      sleep_us(1);
    }
    Ram00000000fe2b0008 = 0xffffffff;
    uVar8 = 0xfffffffb;
    if (0 < local_34) {
      uVar8 = 0;
    }
  }
LAB_ffff23e4:
  local_34 = 0;
  do {
    uVar7 = Ram00000000fe2b0024;
    if ((uVar7 & 1) == 0) goto LAB_ffff2418;
    sleep_us(1);
    bVar1 = local_34 < 0x186a1;
    local_34 = local_34 + 1;
  } while (bVar1);
  uVar8 = 0xfffffffa;
LAB_ffff2418:
  sleep_us(1);
  return uVar8;
code_r0xffff22a0:
  sleep_us(1);
  bVar1 = 10000 < local_34;
  local_34 = local_34 + 1;
  if (bVar1) goto code_r0xffff22bc;
  goto LAB_ffff228c;
code_r0xffff22bc:
  uVar8 = 0xfffffffc;
  goto LAB_ffff23e4;
}



void fspi_wait_reg(undefined4 *param_1)

{
  int iVar1;
  
  param_1[4] = 1;
  if (param_1[4] == 1) {
    iVar1 = 1000;
    do {
      sleep_us(1);
      if (iVar1 < 2) break;
      iVar1 = iVar1 + -1;
    } while (param_1[4] == 1);
  }
  param_1[2] = 0xffffffff;
  *param_1 = 0;
  return;
}



void CRU_NS_undocumented(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x3fc002c0;
  if (param_1 == '\0') {
    uVar1 = 0x3fc02000;
  }
  Ram00000000fd7c0438 = uVar1;
  return;
}



undefined8 FUN_ffff24bc(int param_1,uint param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    param_1 = param_1 << 9;
    do {
      uVar2 = param_2;
      if (0x1fff < param_2) {
        uVar2 = 0x2000;
      }
      uVar1 = FUN_ffff251c(param_1,param_3,uVar2);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      param_2 = param_2 - uVar2;
      param_1 = uVar2 + param_1;
      param_3 = param_3 + (ulong)uVar2;
    } while (param_2 != 0);
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_ffff251c(uint param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint local_8;
  uint local_4;
  
  uVar3 = 0xfffff0ff;
  puVar4 = &local_4;
  uVar1 = (uint)DAT_ff000230 | (param_3 & 0x3fff) << 0x10;
  local_4 = uVar1 | 0x4000;
  local_8 = (_DAT_ff000238 & 3) << 0xc | 0x4000;
  uVar2 = DAT_ff000230 - 0x3b;
  uVar5 = local_4;
  if (((0x31 < uVar2) || ((1L << ((ulong)uVar2 & 0x3f) & 0x3000000000001U) == 0)) &&
     (DAT_ff000230 != 0xb)) {
    if (DAT_ff000230 != 0xeb) goto LAB_ffff25bc;
    param_1 = param_1 << 8 | 0xff;
    local_4 = uVar1 | 0x8400;
    uVar3 = 0xfffff3ff;
    puVar4 = &local_8;
    uVar5 = local_8;
  }
  *puVar4 = uVar5 & uVar3 | 0x800;
LAB_ffff25bc:
  if (_DAT_ff000234 == 1) {
    local_4 = local_4 & 0xffff3fff | 0x8000;
  }
  fspi_do_thing(local_4,local_8,param_1,param_2);
  return;
}



undefined8 FUN_ffff25f0(void)

{
  undefined8 uVar1;
  uint uVar2;
  byte local_14 [4];
  
  uVar2 = 0;
  while( true ) {
    uVar1 = fspi_do_thing(0x10005,0,0,local_14);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    if ((local_14[0] & 1) == 0) break;
    sleep_us(1);
    uVar2 = uVar2 + 1;
    if (0x270 < uVar2 >> 4) {
      return 0xfffffffa;
    }
  }
  return 0;
}



void FUN_ffff2650(uint param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_14 [4];
  
  local_14[0] = param_2;
  fspi_do_thing(6,0,0,0);
  iVar1 = fspi_do_thing((byte)(&DAT_ffff4b87)[param_1] | 0x11000,0,0,local_14);
  if (iVar1 == 0) {
    FUN_ffff25f0();
  }
  return;
}



void FUN_ffff26b0(uint param_1,undefined1 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStack_4 [4];
  
  pbVar1 = &DAT_ffff4b84;
  if (param_1 == 0) {
    pbVar1 = (byte *)0xffff4b85;
  }
  bVar2 = *pbVar1;
  auStack_4[param_1] = param_2;
  iVar3 = fspi_do_thing(bVar2 | 0x10000,0,0,(ulong)auStack_4 | (ulong)(param_1 == 0));
  if (iVar3 == 0) {
    fspi_do_thing(6,0,0,0);
    iVar3 = fspi_do_thing(0x21001,0,0,auStack_4);
    if (iVar3 == 0) {
      FUN_ffff25f0();
    }
  }
  return;
}



void FUN_ffff272c(uint param_1,undefined1 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  bVar1 = (&DAT_ffff4b84)[(ulong)(param_1 == 0) * 2];
  auStack_4[param_1] = param_2;
  iVar2 = fspi_do_thing(bVar1 | 0x10000,0,0,(ulong)auStack_4 | (ulong)(param_1 == 0) << 1);
  if (iVar2 == 0) {
    fspi_do_thing(6,0,0,0);
    iVar2 = fspi_do_thing(0x21001,0,0,auStack_4);
    if (iVar2 == 0) {
      FUN_ffff25f0();
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff27a4(long param_1)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte local_24 [4];
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar3 = *(ushort *)(param_1 + 8);
    if (0x17 < uVar3) {
      uVar3 = 0x18;
    }
    iVar4 = FUN_ffff0cbc(param_1 + 10,uVar3);
    if (iVar4 != *(int *)(param_1 + 4)) {
      return 0xffffffff;
    }
  }
  _DAT_ff000240 = (code *)0x0;
  _DAT_ff000238 = 0;
  bVar2 = *(byte *)(param_1 + 0x13);
  _DAT_ff000230 = (ulong)CONCAT11(bVar2,*(undefined1 *)(param_1 + 0xc));
  uVar1 = *(byte *)(param_1 + 0x12) & 3;
  if (uVar1 != 3) {
    _DAT_ff000240 = *(code **)(&DAT_ffff4b90 + (ulong)uVar1 * 8);
  }
  if ((*(byte *)(param_1 + 0x12) >> 2 & 1) != 0) {
    if (bVar2 != 0) {
      iVar4 = fspi_do_thing((byte)(&DAT_ffff4b84)[(uint)(bVar2 >> 3)] | 0x10000,0,0,local_24);
      if (iVar4 != 0) goto LAB_ffff2898;
      uVar1 = 1 << (ulong)(bVar2 & 7);
      if ((uVar1 & local_24[0]) == 0) {
        local_24[0] = (byte)uVar1 | local_24[0];
        iVar4 = (*_DAT_ff000240)((uint)(bVar2 >> 3));
        if (iVar4 != 0) goto LAB_ffff2898;
      }
    }
    _DAT_ff000238 = CONCAT44(DAT_ff000238_4,2);
    _DAT_ff000230 = CONCAT71(_DAT_ff000231,*(undefined1 *)(param_1 + 0xe));
  }
LAB_ffff2898:
  if ((*(byte *)(param_1 + 0x17) >> 1 & 1) != 0) {
    CRU_NS_undocumented(1);
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool FUN_ffff28c4(undefined8 param_1,long param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  
  iVar3 = FUN_ffff293c(param_1,param_2,0x20);
  if (iVar3 == 0) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (((*(char *)(param_2 + uVar4) == 'R') && (*(char *)(param_2 + uVar4 + 1) == 'K')) &&
         (iVar1 = iVar3, *(char *)(param_2 + uVar4 + 3) == 'S')) break;
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 8;
      iVar1 = _DAT_ff00001c;
    } while (uVar4 < 0x1d);
    _DAT_ff00001c = iVar1;
    bVar2 = 0x1c < (uint)uVar4;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulong FUN_ffff293c(int param_1,long param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  
  if (_DAT_ff000254 < 2) {
    if (_DAT_ff000254 == 1) {
      if (param_3 != 0) {
        while( true ) {
          uVar3 = param_3;
          if (0x7ff < param_3) {
            uVar3 = 0x800;
          }
          uVar2 = FUN_ffff2ba0(param_1,param_2,uVar3);
          if ((int)uVar2 != 0) break;
          param_1 = param_1 + (uVar3 >> 9);
          param_3 = param_3 - uVar3;
          param_2 = param_2 + (ulong)uVar3;
          if (param_3 == 0) {
            return 0;
          }
        }
        return uVar2;
      }
    }
    else {
      if (_DAT_ff000508 != 0) {
        iVar1 = FUN_ffff24bc(param_1,param_3,param_2);
        return (ulong)(iVar1 != 0);
      }
      if (param_3 != 0) {
        while( true ) {
          uVar3 = param_3;
          if (0x1fff < param_3) {
            uVar3 = 0x2000;
          }
          uVar2 = fspi_do_thing((_DAT_ff00001c & 0xf) << 8 | uVar3 << 0x10 | 0x4003,0,param_1 << 9,
                                param_2);
          if ((int)uVar2 != 0) break;
          param_1 = param_1 + (uVar3 >> 9);
          param_3 = param_3 - uVar3;
          param_2 = param_2 + (ulong)uVar3;
          if (param_3 == 0) {
            return uVar2;
          }
        }
      }
    }
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff2a38(int param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  param_1 = param_1 << 7;
  _DAT_ff00001c = 0;
  iVar1 = FUN_ffff28c4(param_1);
  if (iVar1 != 0) {
    if (_DAT_ff000254 != 0 || param_1 != 0) {
      return 1;
    }
    param_1 = 0x40;
    iVar1 = FUN_ffff28c4(0x40,param_2);
    if (iVar1 != 0) {
      return 1;
    }
  }
  uVar2 = FUN_ffff293c(param_1,param_2,0x200);
  if ((int)uVar2 != 0) {
    return 1;
  }
  *param_3 = param_1;
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 fspi_stuff(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char local_14;
  char local_13;
  
  DAT_ff00024c = 0;
  fspi_do_thing(0xff,0,0,0);
  FUN_ffff063c(1);
  sleep_us(200);
  iVar1 = fspi_do_thing(0x3c09f,0x80000,0,&local_14);
  if (iVar1 != 0) {
    return 1;
  }
  if (local_14 == '\0') {
    if (local_13 == '\0') {
      return 1;
    }
  }
  else if ((local_14 == -1) && (local_13 == -1)) {
    return 1;
  }
  uVar2 = 0;
  pcVar3 = &DAT_ffff4be7;
  while ((local_14 != pcVar3[-1] || (local_13 != *pcVar3))) {
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 2;
    if (3 < uVar2) {
      _DAT_ff000254 = 1;
      return 0;
    }
  }
  DAT_ff00024c = 1;
  _DAT_ff000254 = 1;
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulong FUN_ffff2ba0(uint param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  byte local_34 [4];
  
  if ((_DAT_ff000254 == 1) && (iVar1 = fspi_do_thing(0x4013,0,param_1 >> 2,0), iVar1 == 0)) {
    iVar1 = -1;
    do {
      uVar2 = fspi_do_thing(0x1c00f,0x80000,0xc0,local_34);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if ((local_34[0] & 1) == 0) {
        iVar1 = (param_1 & 0x100) << 4;
        if (DAT_ff00024c == '\0') {
          iVar1 = 0;
        }
        iVar1 = fspi_do_thing(_DAT_ff00001c * 0x100 + 0x800U & 0xf00 | (param_3 & 0x3fff) << 0x10 |
                              0xc003,0x100000,iVar1,param_2);
        return (ulong)(iVar1 != 0);
      }
      sleep_us(2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 999);
    _DAT_ff000254 = 2;
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff2c98(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char local_14;
  char local_13;
  char local_12;
  
  reset_fspi();
  DAT_ff00024c = 0;
  _DAT_ff000254 = 2;
  _DAT_ff000508 = 0;
  fspi_do_thing(0x66,0,0,0);
  fspi_do_thing(0x99,0,0,0);
  sleep_us(200);
  iVar1 = fspi_do_thing(0x3009f,0,0,&local_14);
  if (iVar1 == 0) {
    if (local_12 == '\0') {
      if (local_13 != '\0') goto LAB_ffff2d3c;
    }
    else if ((local_12 != -1) || (local_13 != -1)) {
LAB_ffff2d3c:
      _DAT_ff000254 = (uint)(local_14 == -1);
      if (local_14 == -1) {
        uVar2 = 0;
        pcVar3 = &DAT_ffff4be7;
        do {
          if ((local_13 == pcVar3[-1]) && (local_12 == *pcVar3)) {
            DAT_ff00024c = 1;
            return 0;
          }
          uVar2 = uVar2 + 1;
          pcVar3 = pcVar3 + 2;
        } while (uVar2 < 4);
      }
      return 0;
    }
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 init_saradc_(void)

{
  uint uVar1;
  int iVar2;
  uint local_4;
  
  local_4 = 0;
  iVar2 = otp_stuff_2(&local_4,100,1);
  if (-1 < iVar2) {
    uVar1 = local_4 & 0xf;
    if (4 < (local_4 & 0xf) - 2) {
      uVar1 = _DAT_ff000010;
    }
    _DAT_ff000010 = uVar1;
    if (_DAT_ff000010 == 0 && (local_4 & 0x100) == 0) {
      init_saradc();
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void set_u32_in_sram_0x0(undefined4 param_1)

{
  _DAT_ff000000 = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff2e18(short param_1,int *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  
  iVar3 = param_3 - ((param_3 & 0xfff) == 1);
  uVar1 = *(undefined1 *)((long)param_2 + (ulong)(iVar3 - 2));
  uVar2 = *(undefined1 *)((long)param_2 + (ulong)(iVar3 - 1));
  uVar4 = FUN_ffff0560(param_2);
  if ((uint)CONCAT11(uVar1,uVar2) != ((uint)uVar4 & 0xffff)) {
    return uVar4;
  }
  _DAT_ff000010 = 10;
  if (param_1 == 0x471) {
    if ((CONCAT22(CONCAT11(DAT_ffff4d9b,DAT_ffff4d9a),CONCAT11(DAT_ffff4d99,DAT_ffff4d98)) ==
         *param_2) ||
       (CONCAT22(CONCAT11(DAT_ffff4d9f,DAT_ffff4d9e),CONCAT11(DAT_ffff4d9d,DAT_ffff4d9c)) ==
        *param_2)) {
      uVar4 = FUN_ffff01d0(&DAT_ff000020,param_2,0x200);
      return uVar4;
    }
    pcVar5 = (code *)0xff001000;
  }
  else {
    if (param_1 != 0x472) {
      _DAT_ff000010 = 10;
      return uVar4;
    }
    pcVar5 = (code *)0x0;
  }
  if (((int)pcVar5 == -0xfff000) || ((int)pcVar5 == 0)) {
    ic_isb();
    uVar4 = (*pcVar5)(0xff000078,8);
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



void configure_all_usb_dp_phy(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  DWORD_fd5c8004 = 0x40004000;
  Ram00000000fd7c0a08 = 0xf000f00;
  Ram00000000fd7c0b20 = 0x40004;
  DWORD_fd5c8004 = 0x20002000;
  Ram00000000fd7c0b20 = 0x40000;
  Ram00000000fd7c0a08 = 0x8000000;
  Ram00000000fed88090 = 0x68;
  Ram00000000fed88094 = 0x68;
  Ram00000000fed88128 = 0x24;
  Ram00000000fed8812c = 0x44;
  Ram00000000fed88130 = 0x3f;
  Ram00000000fed88134 = 0x44;
  Ram00000000fed8815c = 0xa9;
  Ram00000000fed88160 = 0x71;
  Ram00000000fed88164 = 0x71;
  Ram00000000fed88168 = 0xa9;
  Ram00000000fed88174 = 0xa9;
  Ram00000000fed88178 = 0x71;
  Ram00000000fed8817c = 0x71;
  Ram00000000fed88180 = 0xa9;
  Ram00000000fed8818c = 0x41;
  Ram00000000fed88190 = 0;
  Ram00000000fed88194 = 5;
  Ram00000000fed881ac = 0x2a;
  Ram00000000fed881b0 = 0x17;
  Ram00000000fed881b4 = 0x17;
  Ram00000000fed881b8 = 0x2a;
  Ram00000000fed881c8 = 4;
  Ram00000000fed881cc = 8;
  Ram00000000fed881d0 = 8;
  Ram00000000fed881d4 = 4;
  Ram00000000fed881d8 = 0x20;
  Ram00000000fed881dc = 1;
  Ram00000000fed881e0 = 9;
  Ram00000000fed881e4 = 3;
  Ram00000000fed881f0 = 0x29;
  Ram00000000fed881f4 = 2;
  Ram00000000fed881f8 = 2;
  Ram00000000fed881fc = 0x29;
  Ram00000000fed88208 = 0x2a;
  Ram00000000fed8820c = 0x17;
  Ram00000000fed88210 = 0x17;
  Ram00000000fed88214 = 0x2a;
  Ram00000000fed88224 = 0x20;
  Ram00000000fed883f0 = 0xd;
  Ram00000000fed883f4 = 9;
  Ram00000000fed883f8 = 9;
  Ram00000000fed883fc = 0xd;
  Ram00000000fed88404 = 0xe;
  Ram00000000fed88408 = 0x14;
  Ram00000000fed8840c = 0x14;
  Ram00000000fed88410 = 0x3b;
  Ram00000000fed88a3c = 0xd0;
  Ram00000000fed88a44 = 0xd0;
  Ram00000000fed88a48 = 1;
  Ram00000000fed88a4c = 0xd;
  Ram00000000fed88a54 = 0xe0;
  Ram00000000fed88a5c = 0xe0;
  Ram00000000fed88a64 = 0xa8;
  Ram00000000fed89a3c = 0xd0;
  Ram00000000fed89a44 = 0xd0;
  Ram00000000fed89a48 = 1;
  Ram00000000fed89a4c = 0xd;
  Ram00000000fed89a54 = 0xe0;
  Ram00000000fed89a5c = 0xe0;
  Ram00000000fed89a64 = 0xa8;
  Ram00000000fed8828c = 0x14;
  Ram00000000fed88854 = 4;
  Ram00000000fed89054 = 4;
  iVar2 = 0x186a1;
  Ram00000000fed89854 = 6;
  Ram00000000fed8a054 = 6;
  Ram00000000fd7c0a08 = 0x1000000;
  sleep_us(1);
  iVar3 = 0x186a1;
  Ram00000000fd7c0a08 = 0x6000000;
  do {
    uVar1 = Ram00000000fed88350;
    if ((uVar1 & 0xc0) != 0) break;
    sleep_us(1);
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  do {
    uVar1 = Ram00000000fed88b84;
    if ((uVar1 & 1) != 0) {
      return;
    }
    sleep_us(1);
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  return;
}



void configure_etc_usb(void)

{
  uint uVar1;
  
  configure_all_usb_dp_phy();
  Ram00000000fd5d0010 = 0xc000c;
  uVar1 = Ram00000000fe03809c;
  Ram00000000fe03809c = uVar1 & 0xffff0000;
  uVar1 = Ram00000000fe03009c;
  Ram00000000fe03009c = uVar1 & 0xffff0000;
  return;
}



void reset_all_clocks(void)

{
  uint uVar1;
  
  uVar1 = get_sram_of_0();
  if (199 < uVar1) {
                    // BIGCORE0_CRU
                    // CRU stuff
    return;
  }
  Ram00000000fd7c01c4 = 0x1c00080;
  Ram00000000fd7c01a4 = 0x1c00080;
  Ram00000000fd7d8224 = 0x1c000c0;
  Ram00000000fd818044 = 0x1c00080;
  Ram00000000fd818300 = 0x3f803080;
  Ram00000000fd7c0304 = 0x1f0005;
  Ram00000000fd7c0398 = 0x1f0002;
  Ram00000000fd7d8300 = 0x1f0006;
  Ram00000000fd818310 = 0x19f0002;
  Ram00000000fd818280 = 0x30001;
  Ram00000000fd818318 = 0x1f0001;
  Ram00000000fd818314 = 0xc0008000;
  Ram00000000fd7c0280 = 0x30c0104;
  Ram00000000fd7d8280 = 0x30001;
  Ram00000000fd7c0324 = 0x3c00000;
  Ram00000000fd7c0594 = 0xf0c0000;
  Ram00000000fd7c0320 = 0x1800000;
  Ram00000000fd7d0304 = 0x3ff0000;
  set_u32_in_sram_0x0(0x1c2);
  return;
}



void FUN_ffff3298(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_3 & 0xffff;
  cVar3 = *(char *)(param_2 + 0x20);
  if (uVar5 == 0) {
    lVar4 = *(long *)(param_1 + 0x18);
    uVar5 = 0;
  }
  else {
    uVar1 = (uint)*(ushort *)(*(long *)(param_2 + 0x10) + 4);
    if ((uVar1 - 1 & uVar5) == 0) {
      if (cVar3 == '\0') {
        lVar4 = *(long *)(param_1 + 0x70) + (ulong)*(uint *)(param_1 + 0x68);
        goto LAB_ffff3388;
      }
    }
    else if (cVar3 == '\0') {
      if ((param_3 & 0xffff) < 0x41) {
        iVar6 = 0;
      }
      else {
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = (param_3 & 0xffff) / uVar1;
        }
        iVar6 = uVar2 * uVar1;
        FUN_ffff3cc0(param_1,0,*(long *)(param_1 + 0x70) + (ulong)*(uint *)(param_1 + 0x68),iVar6,
                     0x50,1);
      }
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = ((uVar5 - iVar6) + (uVar1 - 1)) / uVar1;
      }
      lVar4 = *(long *)(param_1 + 0x28);
      *(byte *)(param_1 + 0x65) = *(byte *)(param_1 + 0x65) | 2;
      cVar3 = *(char *)(param_2 + 0x20);
      uVar5 = uVar2 * uVar1;
      goto LAB_ffff3388;
    }
    lVar4 = *(long *)(param_1 + 0x18);
  }
LAB_ffff3388:
  FUN_ffff3cc0(param_1,cVar3,lVar4,uVar5,0x50,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff33a0(long param_1,int param_2)

{
  byte bVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  byte *pbVar5;
  long local_40;
  uint local_38;
  
  lVar4 = *(long *)(param_1 + 8);
  if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    local_38 = 0;
    local_40 = 0;
    if (*(char *)(param_1 + 0x20) == '\0') {
      uVar2 = 9;
    }
    else {
      if ((*(char *)(param_1 + 0x20) == '\x01') || ((*(byte *)(lVar4 + 0x65) >> 4 & 1) != 0))
      goto LAB_ffff3400;
      uVar2 = 0x20009;
      *(byte *)(lVar4 + 0x65) = *(byte *)(lVar4 + 0x65) | 0x10;
    }
    uVar2 = FUN_ffff43a0(lVar4,0,uVar2,&local_40);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
  }
LAB_ffff3400:
  pbVar5 = (byte *)(param_1 + 0x20);
  local_38 = (DAT_ff0002db & 3) << 1 | (uint)_DAT_ff0002dc << 3;
  if (param_2 != 0) {
    local_38 = local_38 | 0x80000000;
  }
  bVar1 = *pbVar5;
  uVar3 = 0x500;
  if ((DAT_ff0002db & 3) != 0) {
    uVar3 = 0x700;
  }
  local_40 = (ulong)(uVar3 | (uint)bVar1 << 0x19) << 0x20;
  if ((*(byte *)(param_1 + 0x23) & 1) != 0) {
    local_38 = local_38 | (bVar1 & 0xfe) << 0x10;
  }
  uVar2 = FUN_ffff43a0(lVar4,bVar1,1,&local_40);
  if ((int)uVar2 == 0) {
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      local_40 = 0;
      local_38 = 1;
      uVar2 = FUN_ffff43a0(lVar4,*pbVar5,2,&local_40);
      if ((int)uVar2 == 0) {
        *(undefined1 **)(param_1 + 0x10) = &DAT_ff0002d8;
        bVar1 = DAT_ff0002db & 3;
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
        *(byte *)(param_1 + 0x21) = bVar1;
        *(uint *)((ulong)*(uint *)(lVar4 + 0x48) + 0x620) =
             1 << (ulong)(*pbVar5 & 0x1f) | *(uint *)((ulong)*(uint *)(lVar4 + 0x48) + 0x620);
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined8 FUN_ffff350c(long param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 local_20;
  undefined4 local_18;
  
  local_18 = 0;
  local_20 = 0;
  if (param_2 == 0) {
    uVar1 = FUN_ffff43a0(*(undefined8 *)(param_1 + 8),*(undefined1 *)(param_1 + 0x20),5,&local_20);
    uVar2 = *(uint *)(param_1 + 0x18) & 0xfffffff9;
  }
  else {
    if (((param_3 == 0) && ((*(byte *)(param_1 + 0x23) & 1) != 0)) &&
       ((*(byte *)(param_1 + 0x18) >> 4 & 1) != 0)) {
      return 0xffffffff;
    }
    uVar1 = FUN_ffff43a0(*(undefined8 *)(param_1 + 8),*(undefined1 *)(param_1 + 0x20),4,&local_20);
    uVar2 = *(uint *)(param_1 + 0x18) | 2;
  }
  *(uint *)(param_1 + 0x18) = uVar2;
  return uVar1;
}



void FUN_ffff3588(long param_1,byte *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if ((*param_2 & 0x60) != 0x40) {
    return;
  }
  if ((param_2[1] & 0xf) != 0xc) {
    FUN_ffff3c68();
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x65);
  uVar3 = (uint)bVar1;
  uVar2 = *(undefined8 *)(param_1 + (ulong)(bVar1 >> 2 & 1) * 8 + 0x38);
  if ((bVar1 >> 5 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    if (*(short *)(param_2 + 4) == 0x472) {
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    else {
      if (*(short *)(param_2 + 4) != 0x471) goto LAB_ffff3600;
      *(undefined8 *)(param_1 + 0x70) = 0xff001000;
    }
    uVar3 = bVar1 | 0x20;
    *(char *)(param_1 + 0x65) = (char)uVar3;
  }
LAB_ffff3600:
  if ((uVar3 >> 5 & 1) == 0) {
    return;
  }
  *(undefined2 *)(param_1 + 0x6c) = *(undefined2 *)(param_2 + 6);
  *(undefined4 *)(param_1 + 0x5c) = 2;
  FUN_ffff3298(param_1,uVar2);
  return;
}



void FUN_ffff3628(long param_1,byte *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + (ulong)(*param_2 >> 1 & 0x1f) * 8 + 0x38);
  lVar1 = *(long *)(lVar2 + 8);
  FUN_ffff3cc0(lVar1,*(undefined1 *)(lVar2 + 0x20),*(undefined8 *)(lVar1 + 0x18),0,
               ((*(byte *)(lVar1 + 0x65) & 0x40) >> 2) + 0x30,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_ffff3660(long *param_1,uint *param_2)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  ushort uVar16;
  undefined4 *puVar17;
  undefined8 local_40;
  undefined4 local_38;
  
  uVar9 = *param_2 >> 6 & 0xf;
  if (uVar9 == 3) {
    bVar2 = *(byte *)((long)param_1 + 0x65);
    uVar9 = bVar2 | 8;
    *(char *)((long)param_1 + 0x65) = (char)uVar9;
    uVar14 = *param_2 >> 0xc & 0xf;
    if (uVar14 == 2) {
      if ((int)param_1[0xb] == 3) {
        *(undefined4 *)((long)param_1 + 0x5c) = 3;
        if (*(short *)(*param_1 + 4) != 0x471) {
          FUN_ffff3628(param_1,param_2);
          uVar9 = (uint)*(byte *)((long)param_1 + 0x65);
        }
        if (((uVar9 >> 5 & 1) != 0) && ((*(ushort *)((long)param_1 + 0x6c) & 0xfff) != 0)) {
          sVar3 = *(short *)(*param_1 + 4);
          if (sVar3 == 0x472) {
            uVar9 = *(uint *)(param_1 + 9);
            _DAT_ff0004f0 = *(uint *)((ulong)uVar9 + 0x30c) & 0xfffc;
            if (_DAT_ff0004f0 != 0) {
              iVar12 = _DAT_ff0004f0 + 4;
              do {
                iVar12 = iVar12 + -4;
                *(undefined4 *)((ulong)uVar9 + 0x30c) = 4;
              } while (4 < iVar12);
            }
          }
          FUN_ffff2e18(sVar3,param_1[0xe],(int)param_1[0xd]);
          *(byte *)((long)param_1 + 0x65) = *(byte *)((long)param_1 + 0x65) & 0xdf;
        }
        if (*(short *)(*param_1 + 4) == 0x471) {
          FUN_ffff3628(param_1,param_2);
          return;
        }
      }
    }
    else if ((uVar14 == 1) && (uVar9 = bVar2 >> 2 & 1, (*param_2 >> 1 & 0x1f) != uVar9)) {
      lVar11 = param_1[(ulong)uVar9 + 7];
      if (*(byte *)(lVar11 + 0x22) != 0) {
        local_38 = 0;
        local_40 = 0;
        FUN_ffff43a0(param_1,*(undefined1 *)(lVar11 + 0x20),
                     (uint)*(byte *)(lVar11 + 0x22) << 0x10 | 0x108,&local_40);
        *(undefined1 *)(lVar11 + 0x22) = 0;
      }
      FUN_ffff3c68(param_1);
    }
  }
  else if (uVar9 == 1) {
    lVar11 = param_1[(ulong)(*param_2 >> 1 & 0x1f) + 7];
    *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) & 0xffffffef;
    *(undefined1 *)(lVar11 + 0x22) = 0;
    bVar2 = *(byte *)((long)param_1 + 0x65);
    iVar12 = *(int *)((long)param_1 + 0x5c);
    *(byte *)((long)param_1 + 0x65) = bVar2 & 0xf7;
    if (iVar12 == 3) {
      lVar11 = param_1[3];
      uVar7 = 8;
      uVar8 = 0x20;
      uVar9 = 0;
      *(undefined4 *)((long)param_1 + 0x5c) = 1;
LAB_ffff38bc:
      FUN_ffff3cc0(param_1,uVar9,lVar11,uVar7,uVar8,0);
      return;
    }
    if (iVar12 == 2) {
      uVar4 = *param_2;
      puVar17 = (undefined4 *)param_1[7];
      *(undefined4 *)(param_1 + 0xb) = 3;
      uVar14 = *(uint *)(param_1 + 0xd);
      uVar9 = (uint)*(uint3 *)(param_1[1] + 8);
      if ((bVar2 >> 1 & 1) == 0) {
        uVar9 = *(ushort *)((long)param_1 + 0x6c) - uVar9;
      }
      else {
        lVar11 = param_1[0xe] + (ulong)uVar14;
        uVar1 = (uint)*(ushort *)(*(long *)(puVar17 + 4) + 4);
        uVar10 = (uint)*(ushort *)((long)param_1 + 0x6c);
        if (uVar10 < 0x41) {
          iVar12 = 0;
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          if (uVar1 != 0) {
            uVar15 = uVar10 / uVar1;
          }
          iVar12 = uVar15 * uVar1;
          uVar15 = iVar12 - uVar9;
          *(uint *)(param_1 + 0xd) = uVar15 + uVar14;
          lVar11 = lVar11 + (ulong)uVar15;
          uVar9 = (uint)*(uint3 *)(param_1[1] + 0x18);
          *puVar17 = 0;
        }
        uVar14 = 0;
        if (uVar1 != 0) {
          uVar14 = ((uVar1 + (uVar10 - iVar12)) - 1) / uVar1;
        }
        uVar14 = uVar14 * uVar1 - uVar9;
        uVar9 = uVar10 - uVar15;
        if (uVar14 <= uVar10 - uVar15) {
          uVar9 = uVar14;
        }
        FUN_ffff01d0(lVar11,param_1[2],uVar9);
        uVar14 = *(uint *)(param_1 + 0xd);
      }
      *(uint *)(param_1 + 0xd) = uVar9 + uVar14;
      if (((uVar4 & 2) != 0) && (uVar9 + uVar14 < (uint)*(ushort *)((long)param_1 + 0x6c)))
      goto LAB_ffff3a64;
      if (((*(byte *)((long)param_1 + 0x65) >> 1 & 1) != 0) && (*(char *)(puVar17 + 8) == '\0')) {
        *(byte *)((long)param_1 + 0x65) = *(byte *)((long)param_1 + 0x65) & 0xfd;
      }
      if (((*(ushort *)((long)param_1 + 0x6c) != 0) &&
          ((*(short *)(*(long *)(puVar17 + 4) + 4) - 1U & *(ushort *)((long)param_1 + 0x6c)) == 0))
         && ((char)param_1[0xf] != '\0')) {
        uVar9 = uVar4 >> 1 & 0x1f;
        lVar11 = param_1[3];
        uVar8 = 0x50;
        uVar7 = 0;
        *(undefined4 *)(param_1 + 0xb) = 1;
        goto LAB_ffff38bc;
      }
    }
    else if (iVar12 == 1) {
      pbVar5 = (byte *)*param_1;
      if (*(short *)(pbVar5 + 6) == 0) {
        uVar9 = bVar2 & 0xb3;
        uVar13 = 3;
      }
      else {
        *(byte *)((long)param_1 + 0x65) = bVar2 & 0xf7 | 0x40;
        uVar9 = *pbVar5 >> 5 & 4 | bVar2 & 0xf3 | 0x40;
        uVar13 = 2;
      }
      *(byte *)((long)param_1 + 0x65) = (byte)uVar9;
      *(undefined4 *)(param_1 + 0xb) = uVar13;
      if ((*pbVar5 & 0x60) != 0) {
LAB_ffff399c:
        FUN_ffff3588(param_1);
        return;
      }
      bVar2 = pbVar5[1];
      if (bVar2 == 9) {
        *(byte *)((long)param_1 + 0x65) = (byte)uVar9 & 0xef;
        sVar3 = *(short *)(pbVar5 + 2);
        if ((int)param_1[0xc] == 7) {
          FUN_ffff3588(param_1);
          if (sVar3 == 0) {
            *(undefined4 *)(param_1 + 0xc) = 6;
          }
        }
        else {
          if ((int)param_1[0xc] != 6) {
LAB_ffff3a64:
            FUN_ffff3c68(param_1);
            return;
          }
          FUN_ffff3588(param_1);
          if (sVar3 != 0) {
            *(undefined4 *)(param_1 + 0xc) = 7;
            *(uint *)((ulong)*(uint *)(param_1 + 9) + 0x604) =
                 *(uint *)((ulong)*(uint *)(param_1 + 9) + 0x604) | 0xa00;
          }
        }
      }
      else if (bVar2 == 6) {
        bVar2 = pbVar5[3];
        lVar11 = param_1[(ulong)(uVar9 >> 2 & 1) + 7];
        if (bVar2 == 6) {
          if ((uVar9 >> 6 & 1) == 0) {
            return;
          }
          uVar16 = *(ushort *)(pbVar5 + 6);
          if (9 < uVar16) {
            uVar16 = 10;
          }
          puVar6 = &DAT_ffff4bdc;
        }
        else if (bVar2 == 2) {
          if ((uVar9 >> 6 & 1) == 0) {
            return;
          }
          uVar16 = *(ushort *)(pbVar5 + 6);
          if (9 < uVar16) {
            uVar16 = 0x20;
          }
          puVar6 = &DAT_ffff4ba8;
        }
        else {
          if (bVar2 != 1) goto LAB_ffff3a64;
          if ((uVar9 >> 6 & 1) == 0) {
            return;
          }
          uVar16 = *(ushort *)(pbVar5 + 6);
          if (0x11 < uVar16) {
            uVar16 = 0x12;
          }
          puVar6 = &DAT_ffff4bc8;
        }
        FUN_ffff01d0(&DAT_ff000298,puVar6,uVar16);
        *(undefined4 *)((long)param_1 + 0x5c) = 2;
        FUN_ffff3298(param_1,lVar11,uVar16);
        *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) & 0x7fffffff;
      }
      else {
        if (bVar2 != 5) goto LAB_ffff399c;
        if ((int)param_1[0xc] == 7) goto LAB_ffff3a64;
        uVar13 = 5;
        if (*(ushort *)(pbVar5 + 2) != 0) {
          uVar13 = 6;
        }
        *(uint *)((ulong)*(uint *)(param_1 + 9) + 0x600) =
             *(uint *)((ulong)*(uint *)(param_1 + 9) + 0x600) & 0xfffffc07 |
             (uint)*(ushort *)(pbVar5 + 2) << 3;
        *(undefined4 *)(param_1 + 0xc) = uVar13;
      }
    }
  }
  return;
}



void FUN_ffff3c50(long param_1)

{
  FUN_ffff3cc0(param_1,0,*(undefined8 *)(param_1 + 0x18),8,0x20,0);
  return;
}



// WARNING: Removing unreachable block (ram,0xffff3cf0)

void FUN_ffff3c68(long param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint *puVar5;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  *(undefined4 *)(*(long *)(param_1 + 0x40) + 0x18) = 1;
  lVar4 = *(long *)(param_1 + 0x38);
  FUN_ffff350c(lVar4,1,0);
  *(undefined4 *)(lVar4 + 0x18) = 1;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x5c) = 1;
  puVar5 = *(uint **)(param_1 + 0x38);
  if (((byte)puVar5[6] >> 4 & 1) == 0) {
    puVar1 = (undefined1 *)(*(long *)(param_1 + 8) + (ulong)*puVar5 * 0x10);
    puVar1[3] = (char)((ulong)uVar3 >> 0x18);
    puVar1[2] = (char)((ulong)uVar3 >> 0x10);
    puVar1[1] = (char)((ulong)uVar3 >> 8);
    *puVar1 = (char)uVar3;
    puVar1[5] = (char)((ulong)uVar3 >> 0x28);
    puVar1[4] = (char)((ulong)uVar3 >> 0x20);
    puVar1[7] = (char)((ulong)uVar3 >> 0x38);
    puVar1[6] = (char)((ulong)uVar3 >> 0x30);
    puVar1[9] = 0;
    puVar1[8] = 8;
    puVar1[0xb] = 0;
    puVar1[10] = 0;
    puVar1[0xc] = 0x23;
    puVar1[0xf] = 0;
    puVar1[0xe] = 0;
    puVar1[0xd] = 0xc;
    uStack_30 = 0;
    uStack_2c = (undefined4)*(undefined8 *)(param_1 + 0x20);
    uStack_28 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x20) >> 0x20);
    iVar2 = FUN_ffff43a0(param_1,(char)puVar5[8],6,&uStack_30);
    if (-1 < iVar2) {
      puVar5[6] = puVar5[6] | 0x10;
      *(byte *)((long)puVar5 + 0x22) =
           (byte)((uint)*(undefined4 *)
                         ((ulong)*(uint *)(param_1 + 0x48) + (ulong)(byte)puVar5[8] * 0x10 + 0x70c)
                 >> 0x10) & 0x7f;
      *(undefined4 *)(param_1 + 0x58) = 1;
    }
  }
  return;
}



void FUN_ffff3cc0(long param_1,uint param_2,undefined8 param_3,undefined8 param_4,uint param_5,
                 int param_6)

{
  undefined1 *puVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  puVar5 = *(uint **)(param_1 + (ulong)(param_2 & 0xff) * 8 + 0x38);
  if (((byte)puVar5[6] >> 4 & 1) == 0) {
    lVar3 = *(long *)(param_1 + 8);
    uVar4 = *puVar5;
    if (param_6 != 0) {
      *puVar5 = uVar4 + 1;
    }
    puVar1 = (undefined1 *)(lVar3 + (ulong)uVar4 * 0x10);
    puVar1[3] = (char)((ulong)param_3 >> 0x18);
    puVar1[2] = (char)((ulong)param_3 >> 0x10);
    puVar1[1] = (char)((ulong)param_3 >> 8);
    *puVar1 = (char)param_3;
    puVar1[5] = (char)((ulong)param_3 >> 0x28);
    puVar1[4] = (char)((ulong)param_3 >> 0x20);
    puVar1[7] = (char)((ulong)param_3 >> 0x38);
    puVar1[6] = (char)((ulong)param_3 >> 0x30);
    puVar1[9] = (char)((ulong)param_4 >> 8);
    puVar1[8] = (char)param_4;
    uVar4 = 4;
    if (param_6 == 0) {
      uVar4 = 0x802;
    }
    uVar4 = uVar4 | param_5 | 0x401;
    puVar1[0xb] = (char)((ulong)param_4 >> 0x18);
    puVar1[10] = (char)((ulong)param_4 >> 0x10);
    puVar1[0xc] = (char)uVar4;
    puVar1[0xf] = (char)(param_5 >> 0x18);
    puVar1[0xe] = (char)(param_5 >> 0x10);
    puVar1[0xd] = (char)(uVar4 >> 8);
    if (param_6 == 0) {
      local_30 = 0;
      local_2c = (undefined4)*(undefined8 *)(param_1 + 0x20);
      uStack_28 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x20) >> 0x20);
      iVar2 = FUN_ffff43a0(param_1,(char)puVar5[8],6,&local_30);
      if (-1 < iVar2) {
        puVar5[6] = puVar5[6] | 0x10;
        *(byte *)((long)puVar5 + 0x22) =
             (byte)((uint)*(undefined4 *)
                           ((ulong)*(uint *)(param_1 + 0x48) + (ulong)(byte)puVar5[8] * 0x10 + 0x70c
                           ) >> 0x10) & 0x7f;
        *(undefined4 *)(param_1 + 0x58) = 1;
      }
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void usb_run_loop(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined8 local_70;
  undefined4 local_68;
  uint local_58 [2];
  
  uVar3 = (ulong)_DAT_ff000488;
  uVar4 = *(uint *)(uVar3 + 0x30c) & 0xfffc;
  if (uVar4 != 0) {
    _DAT_ff0004f4 = _DAT_ff0004f4 | 1;
    _DAT_ff0004f0 = uVar4;
    *(uint *)(uVar3 + 0x308) = *(uint *)(uVar3 + 0x308) | 0x80000000;
    if ((_DAT_ff0004f4 & 1) != 0) {
      if (0 < (int)_DAT_ff0004f0) {
        iVar6 = _DAT_ff0004f0 + 4;
        do {
          local_58[0] = *(uint *)(ulong)(_DAT_ff0004ec + _DAT_ff0004e0);
          if ((local_58[0] & 1) == 0) {
            uVar4 = local_58[0] >> 1 & 0x1f;
            if ((uVar4 < 2) &&
               ((*(uint *)(*(long *)(&DAT_ff000478 + (ulong)uVar4 * 8) + 0x18) & 1) != 0)) {
              FUN_ffff3660(0xff000440,local_58);
            }
          }
          else {
            if ((local_58[0] & 0xfe) != 0) goto LAB_ffff400c;
            uVar4 = local_58[0] >> 8 & 0xf;
            if (uVar4 != 2) {
              if (uVar4 == 1) {
                *(uint *)(uVar3 + 0x604) = *(uint *)(uVar3 + 0x604) & 0xffffffe1;
                lVar1 = _DAT_ff000480;
                if ((_DAT_ff000480 != 0) && ((*(uint *)(_DAT_ff000480 + 0x18) >> 1 & 1) != 0)) {
                  *(uint *)(_DAT_ff000480 + 0x18) = *(uint *)(_DAT_ff000480 + 0x18) & 0xfffffffd;
                  local_68 = 0;
                  local_70 = 0;
                  FUN_ffff43a0(0xff000440,*(undefined1 *)(lVar1 + 0x20),5,&local_70);
                  uVar3 = (ulong)_DAT_ff000488;
                }
                DAT_ff0004a5 = DAT_ff0004a5 & 0xcd;
                _DAT_ff0004a0 = 5;
                *(uint *)(uVar3 + 0x600) = *(uint *)(uVar3 + 0x600) & 0xfffffc07;
              }
              else if (uVar4 == 0) {
                uVar4 = *(uint *)(uVar3 + 0x604);
                *(uint *)(uVar3 + 0x604) = uVar4 & 0xfffffbff;
                *(uint *)(uVar3 + 0x604) = uVar4 & 0xffffebff;
                DAT_ff0004a5 = DAT_ff0004a5 & 0xe7;
              }
              goto LAB_ffff400c;
            }
            uVar4 = *(uint *)(uVar3 + 0x60c) & 7;
            DAT_ff0004a4 = (undefined1)uVar4;
            uVar5 = 0x40;
            switch(*(uint *)(uVar3 + 0x60c) & 7) {
            case 0:
            case 1:
            case 3:
              break;
            case 2:
              uVar5 = 8;
              break;
            case 4:
              uVar5 = 0x200;
              break;
            default:
              goto switchD_00003ef4_caseD_5;
            }
            _DAT_ff0002dc = uVar5;
switchD_00003ef4_caseD_5:
            if (uVar4 == 4) {
              uVar4 = 0xe0ffffff;
            }
            else {
              uVar4 = 0xe0fbffff;
              *(uint *)(uVar3 + 0x600) = *(uint *)(uVar3 + 0x600) | 0x400000;
            }
            *(uint *)(uVar3 + 0x604) = *(uint *)(uVar3 + 0x604) & uVar4;
            iVar2 = FUN_ffff33a0(_DAT_ff000478,1);
            if (iVar2 == 0) {
              FUN_ffff33a0(_DAT_ff000480,1);
            }
          }
LAB_ffff400c:
          uVar3 = (ulong)_DAT_ff000488;
          _DAT_ff0004ec = _DAT_ff0004ec + 4 & 0xff;
          iVar6 = iVar6 + -4;
          *(undefined4 *)(uVar3 + 0x30c) = 4;
        } while (4 < iVar6);
      }
      _DAT_ff0004f4 = _DAT_ff0004f4 & 0xfffffffe;
      _DAT_ff0004f0 = 0;
      *(uint *)(uVar3 + 0x308) = *(uint *)(uVar3 + 0x308) & 0x7fffffff;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_ffff4068(undefined8 *param_1)

{
  *param_1 = &DAT_ff000298;
  param_1[3] = &DAT_ff000298;
  _DAT_ff0002c8 = 0;
  _DAT_ff0002d0 = 0;
  _DAT_ff0002b8 = 0;
  _DAT_ff0002c0 = 0;
  _DAT_ff0002a8 = 0;
  _DAT_ff0002b0 = 0;
  _DAT_ff000298 = 0;
  _DAT_ff0002a0 = 0;
  param_1[1] = &DAT_ff0004c0;
  param_1[4] = &DAT_ff0004c0;
  _DAT_ff0004d0 = 0;
  _DAT_ff0004d8 = 0;
  _DAT_ff0004c0 = 0;
  _DAT_ff0004c8 = 0;
  param_1[2] = &DAT_ff000258;
  param_1[5] = &DAT_ff000258;
  _DAT_ff000288 = 0;
  _DAT_ff000290 = 0;
  _DAT_ff000278 = 0;
  _DAT_ff000280 = 0;
  _DAT_ff000268 = 0;
  _DAT_ff000270 = 0;
  _DAT_ff000258 = 0;
  _DAT_ff000260 = 0;
  _DAT_ff000400 = 0;
  _DAT_ff0003f0 = 0;
  _DAT_ff000410 = 0;
  _DAT_ff000408 = 0;
  _DAT_ff0003f8 = param_1;
  param_1[7] = &DAT_ff0003f0;
  _DAT_ff000418 = 0;
  _DAT_ff000428 = 0;
  _DAT_ff000438 = 0x1000001;
  _DAT_ff000430 = 0;
  _DAT_ff000420 = param_1;
  param_1[8] = &DAT_ff000418;
  return;
}



undefined8 FUN_ffff410c(long param_1,int param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  
  uVar2 = (ulong)*(uint *)(param_1 + 0x48);
  uVar1 = *(uint *)(uVar2 + 0x604) & 0x7ff7ffff | 0x80000000;
  if (param_2 == 0) {
    uVar1 = *(uint *)(uVar2 + 0x604) & 0x7fffffff;
  }
  iVar3 = -499;
  *(uint *)(uVar2 + 0x604) = uVar1;
  while( true ) {
    if (param_2 == 0) {
      if ((*(uint *)(uVar2 + 0x60c) >> 0x16 & 1) != 0) {
        return 0;
      }
    }
    else if ((*(uint *)(uVar2 + 0x60c) >> 0x16 & 1) == 0) {
      return 0;
    }
    if (iVar3 == 0) break;
    sleep_us(1);
    uVar2 = (ulong)*(uint *)(param_1 + 0x48);
    iVar3 = iVar3 + 1;
  }
  return 0xffffffff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_ffff4188(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  
  DAT_ff0002d8 = 7;
  DAT_ff0002d9 = 5;
  DAT_ff0002da = 0;
  DAT_ff0002db = 0;
  _DAT_ff0002dc = 0x40;
  iVar2 = *(int *)(param_1 + 0x54);
  uVar1 = *(uint *)((ulong)*(uint *)(param_1 + 0x48) + 0x600) & 0xfffffff8;
  uVar4 = uVar1;
  if (iVar2 != 3) {
    if (iVar2 == 2) {
      uVar4 = uVar1 | 3;
    }
    else {
      uVar4 = uVar1 | 4;
      if (iVar2 == 1) {
        uVar4 = uVar1 | 2;
      }
    }
  }
  *(uint *)((ulong)*(uint *)(param_1 + 0x48) + 0x600) = uVar4;
  *(byte *)(param_1 + 0x65) = *(byte *)(param_1 + 0x65) & 0xef;
  uVar3 = FUN_ffff33a0(*(undefined8 *)(param_1 + 0x38),0);
  if (((int)uVar3 == 0) &&
     (uVar3 = FUN_ffff33a0(*(undefined8 *)(param_1 + 0x40),0), (int)uVar3 == 0)) {
    *(undefined4 *)(param_1 + 0x5c) = 1;
    FUN_ffff3c50(param_1);
    uVar3 = 0;
    *(undefined4 *)((ulong)*(uint *)(param_1 + 0x48) + 0x608) = 0x1e1f;
  }
  return uVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 dwc3_init(void)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  configure_etc_usb();
  FUN_ffff01fc(0xff000440,0,0x80);
  _DAT_ff0004a0 = 0;
  _DAT_ff000488 = &UNK_fc00c100;
  _DAT_ff000490 = 1;
  _DAT_ff000494 = 3;
  _DAT_ff0004e8 = 0x100;
  _DAT_ff0004f0 = 0;
  _DAT_ff0004f8 = 0xff0002e0;
  _DAT_ff000500 = 0xff000440;
  _DAT_ff0004e0 = 0xff0002e0;
  FUN_ffff01fc(0xff0002e0,0,0x100);
  Ram00000000fc00c704 = 0x40000000;
  uVar3 = (ulong)_DAT_ff000488 & 0xffffffff;
  lVar1 = -5000;
  do {
    lVar4 = lVar1;
    if (lVar4 == 0) break;
    lVar1 = lVar4 + 1;
  } while ((*(uint *)(uVar3 + 0x604) >> 0x1e & 1) != 0);
  if (lVar4 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    *(uint *)(uVar3 + 0x10) = *(uint *)(uVar3 + 0x10) & 0xffffffc7;
    *(uint *)(uVar3 + 0x1c) = *(uint *)(uVar3 + 0x1c) | 0x4000000;
    *(uint *)(uVar3 + 0x1c0) = *(uint *)(uVar3 + 0x1c0) | 0x20000;
    *(uint *)(uVar3 + 0x100) = *(uint *)(uVar3 + 0x100) & 0xbfffc2f7 | 0x1408;
    _DAT_ff0004e8 = (ulong)_DAT_ff0004e8;
    *(undefined8 *)(uVar3 + 0x300) = 0xff0002e0;
    *(uint *)(uVar3 + 0x308) = (uint)_DAT_ff0004e8;
    *(undefined4 *)(uVar3 + 0x30c) = 0;
    *(uint *)(uVar3 + 0x10) = *(uint *)(uVar3 + 0x10) & 0xffffcfff | 0x2000;
    FUN_ffff4068(0xff000440);
    FUN_ffff4188(0xff000440);
    FUN_ffff410c(0xff000440,1);
    uVar2 = 0;
  }
  return uVar2;
}



undefined8 FUN_ffff43a0(long param_1,int param_2,uint param_3,undefined4 *param_4)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  
  param_2 = param_2 * 0x10;
  uVar1 = (ulong)*(uint *)(param_1 + 0x48);
  *(undefined4 *)(uVar1 + (param_2 + 0x708)) = param_4[2];
  *(undefined4 *)(uVar1 + (param_2 + 0x704)) = param_4[1];
  uVar2 = (ulong)(param_2 + 0x70c);
  *(undefined4 *)(uVar1 + (param_2 + 0x700)) = *param_4;
  *(uint *)(uVar1 + uVar2) = param_3 | 0x400;
  if ((*(uint *)(uVar1 + uVar2) >> 10 & 1) != 0) {
    iVar3 = -500;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      sleep_us(1);
    } while ((*(uint *)(*(uint *)(param_1 + 0x48) + uVar2) >> 10 & 1) != 0);
  }
  return 0;
}



uint bitmask_stuff(uint param_1,uint param_2)

{
  uint tmp;
  
  tmp = (param_2 ^ param_1) - ((param_2 ^ param_1) >> 1 & 0x55555555);
  tmp = (tmp & 0x33333333) + (tmp >> 2 & 0x33333333);
  return (tmp + (tmp >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18;
}



void ic_isb(void)

{
  IC_IALLUIS();
  InstructionSynchronizationBarrier();
  return;
}



undefined8 crypto_reset(void)

{
  int iVar1;
  
  firewall_config();
  Ram00000000fe390004 = 0x50005;
  do {
                    // ghidra got this completely wrong
                    // x19 is 0xff000000 from prev function (?)
                    // this ends up being fe390004 which is CRYPTO_S
                    // I think it's resetting crypto
    iVar1 = Ram00000000fe390004;
  } while (iVar1 != 0);
  return 0;
}



undefined4 FUN_ffff4498(long *param_1,long param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xfffffffe;
  if ((param_1 == (long *)0x0) || (param_2 == 0)) {
LAB_ffff45cc:
    Ram00000000fe390048 = 0xffff0000;
    if (param_1 == (long *)0x0) {
      return uVar5;
    }
  }
  else {
    if (((int)param_1[2] == 0) || ((int)param_1[1] != 0x1a1a1a1a)) {
      uVar5 = 0xfffffffe;
    }
    else if (((int)param_1[3] == 0) && (*param_1 != 0)) {
      FUN_ffff01d0(param_2,*param_1,(int)param_1[2]);
      if (param_3 == (undefined4 *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0;
        *param_3 = (int)param_1[2];
      }
    }
    else {
      do {
        uVar4 = Ram00000000fe39000c;
      } while ((uVar4 & 0x7f) == 0);
      uVar4 = Ram00000000fe39000c;
      Ram00000000fe39000c = uVar4;
      if ((uVar4 & 0x7f) != 1) {
        uVar5 = 0xffffffff;
        goto LAB_ffff45cc;
      }
      do {
        iVar2 = Ram00000000fe3903e4;
      } while (iVar2 == 0);
      if (3 < *(uint *)(param_1 + 2)) {
        uVar3 = 0;
        uVar4 = 0;
        do {
          uVar5 = *(undefined4 *)(ulong)(uVar3 + 0xfe3903a0);
          puVar1 = (undefined1 *)(param_2 + (ulong)uVar3);
          *puVar1 = (char)((uint)uVar5 >> 0x18);
          puVar1[1] = (char)((uint)uVar5 >> 0x10);
          puVar1[2] = (char)((uint)uVar5 >> 8);
          puVar1[3] = (char)uVar5;
          uVar4 = uVar4 + 1;
          uVar3 = uVar3 + 4;
        } while (uVar4 < *(uint *)(param_1 + 2) >> 2);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = (int)param_1[2];
      }
      uVar5 = 0;
      Ram00000000fe3903e4 = 1;
      Ram00000000fe390048 = 0xffff0000;
    }
    Ram00000000fe390048 = 0xffff0000;
  }
  if ((int)param_1[1] == 0x1a1a1a1a) {
    Ram00000000fe390048 = 0xffff0000;
    FUN_ffff01fc(param_1,0,0x20);
  }
  return uVar5;
}



void FUN_ffff4618(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  uStack_18 = 0;
  local_30 = 0;
  local_20 = 0x20;
  lVar3 = 0;
  do {
    lVar1 = lVar3 + 4;
    *(undefined4 *)(&UNK_fe3903a0 + lVar3) = 0;
    lVar3 = lVar1;
  } while (lVar1 != 0x40);
  Ram00000000fe390048 = 0xffff0024;
  Ram00000000fe390040 = 0x30003;
  Ram00000000fe390008 = 0;
  local_28 = 0x1a1a1a1a;
  iVar2 = FUN_ffff46b0(&local_30,param_1,param_2,1);
  if (iVar2 == 0) {
    FUN_ffff4498(&local_30,param_3,0);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_ffff46b0(long param_1,undefined4 param_2,uint param_3,char param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    Ram00000000fe390048 = 0xffff0000;
    return 0xffffffff;
  }
  if ((((param_3 == 0) || (*(int *)(param_1 + 0x10) == 0)) || ((param_3 & 3) != 0)) ||
     (*(int *)(param_1 + 8) != 0x1a1a1a1a)) {
    Ram00000000fe390048 = 0xffff0000;
LAB_ffff4744:
    if (*(int *)(param_1 + 8) == 0x1a1a1a1a) {
      Ram00000000fe390048 = 0xffff0000;
      FUN_ffff01fc(param_1,0,0x20);
      return 0xffffffff;
    }
LAB_ffff47e8:
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 1) {
      do {
        iVar1 = Ram00000000fe39000c;
      } while (iVar1 == 0);
      iVar1 = Ram00000000fe39000c;
      Ram00000000fe39000c = iVar1;
      if (iVar1 != 4) {
        Ram00000000fe390048 = 0xffff0000;
        if (param_1 != 0) goto LAB_ffff4744;
        goto LAB_ffff47e8;
      }
    }
    _DAT_ff000520 = 0;
    _DAT_ff000518 = 0;
    _DAT_ff000510 = CONCAT44(param_3,param_2);
    if (param_4 == '\0') {
      uVar2 = 0x402;
    }
    else {
      uVar2 = 0x101;
      _DAT_ff000520 = 4;
    }
    _DAT_ff000528 = CONCAT44(0xff000510,uVar2);
    if (*(int *)(param_1 + 0x18) == 0) {
      _DAT_ff000520 = _DAT_ff000520 | 3;
      *(undefined4 *)(param_1 + 0x18) = 0xff000510;
      Ram00000000fe390048 = 0x10001;
      uVar3 = 1;
      Ram00000000fe390014 = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x14) = 1;
    }
    else {
      uVar3 = 2;
    }
    Ram00000000fe390010 = uVar3 | uVar3 << 0x10;
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x18) = _DAT_ff00052c;
  }
  return uVar2;
}



void busy_cycles(long param_1)

{
  bool cond;
  
  do {
    cond = param_1 != 0;
    param_1 = param_1 + -1;
  } while (cond && param_1 != 0);
  return;
}



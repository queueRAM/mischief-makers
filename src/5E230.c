#include "common.h"

typedef void (*Actor2Func)(u16 actor_0, u16 arg1);

extern s16 D_800D5820;

extern s8 D_801782DC;
extern s16 D_801783EE;
extern s16 D_801783F0;
extern s16 D_801783F2;
extern s16 D_801783F4;
extern s16 D_801783F6;
extern s16 D_801783F8[];
extern s16 D_80178418[];
extern u16 D_80178438; // end of D_80178418
extern u16 D_8017843A;
extern u16 D_8017843C;
extern u16 D_8017843E;

extern Actor2Func D_8019B00C;
extern Actor2Func D_8019B010;
extern Actor2Func D_8019B014;

#ifdef NON_MATCHING
// https://decomp.me/scratch/Hzrpy
void func_8005D630(u16 arg0, u16 arg1) {
    D_8019B00C(arg0, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D630.s")
#endif


#ifdef NON_MATCHING
// https://decomp.me/scratch/RtXvt
void func_8005D664(u16 arg0, u16 arg1) {
    D_8019B010(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D664.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/F4HIF
void func_8005D6A0(u16 arg0, u16 arg1) {
    D_8019B014(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D6A0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D90C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005D9EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DC64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DCCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DD34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005DDFC.s")

void func_8005DE30(void) {
    for (D_801783F0 = 0; D_801783F0 < 0x10; D_801783F0++) {
        D_801783F8[D_801783F0] = D_80178418[D_801783F0] = 0;
    }
    D_801783F0 = D_801783F2 = 0;
    D_801782DC = 0;
    D_801783EE = 2;
    D_80178438 = D_8017843A = D_8017843C = D_8017843E = 0;
    D_801783F4 = -3;
    D_801783F6 = 0xC;
}

s16 func_8005DEFC(void) {
    s16 var_v1;

    var_v1 = D_80178418[0];
    if (var_v1 != 0) {
        var_v1 |= D_801783F8[0] & 0x8000;
    }
    return var_v1;
}

s16 func_8005DF30(void) {
    return D_801783F8[0];
}

void func_8005DF40(s16 arg0, s16 arg1) {
    D_801783F4 = arg0;
    D_801783F6 = arg1;
}

s32 func_8005DF5C(s32 arg0) {
   s32 var_v1;

    D_800D5820 = 0;
    D_800D5830 = 0;
    D_800D5834 = 0x46;
    for (var_v1 = 0; var_v1 < 0x10; var_v1++) {
        if (D_80178418[var_v1] == 0) {
            D_801783F8[var_v1] = 0;
            D_80178418[var_v1] = arg0;
            break;
        }
    }
    return var_v1;
}

s32 func_8005DFC8(s32 arg0) {
    s32 index;

    if (func_8005DEFC() == 0) {
        return func_8005DF5C(arg0);
    }
    index = 1;
    if (D_801783F0 == 0) {
        index = 0;
    }
    if (D_801783F0 == 1) {
        D_801783F0 = 2;
    }
    if (D_801783F0 == 2) {
        D_801783F2 = -1;
    }
    for (; index < 0x10; index++) {
        D_801783F8[index] = 0;
        D_80178418[index] = arg0;
        arg0 = 0;
    }
    if (D_801783F0 == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

void func_8005E09C(s32 arg0, s32 arg1) {
    D_801783F8[arg0] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005EC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005EE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F6D4.s")

#include "common.h"

typedef void (*Actor2Func)(u16 actor_0, u16 arg1);

extern s16 D_800D5820;

extern s8 D_801782DC;
extern s16 D_801782E0;
extern s16 D_801782E2;
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

#define D_8019B000 ((Actor2Func*)0x8019B000)
#define D_80192020 ((Actor2Func*)0x80192020)
#define D_80192030 ((Actor2Func*)0x80192030)
#define D_80192060 ((Actor2Func*)0x80192060)
#define D_801A6840 ((Actor2Func*)0x801A6840)

void func_8005EC20(s16, s16);
void func_800831D0(s16, s16, s16, s16);

void func_8005D630(u16 arg0) {
    D_8019B000[3](arg0, 0);
}

void func_8005D664(u16 arg0, u16 arg1) {
    D_8019B000[4](arg0, arg1);
}

void func_8005D6A0(u16 arg0, u16 arg1) {
    D_8019B000[5](arg0, arg1);
}

void func_8005D6DC(u16 arg0, u16 arg1) {
    D_8019B000[6](arg0, arg1);
}

void func_8005D718(u16 arg0) {
    D_80192020[3](arg0, 0);
}

void func_8005D74C(u16 arg0) {
    D_80192020[4](arg0, 0);
}

// same as func_8005D6A0
void func_8005D780(u16 arg0, u16 arg1) {
    D_8019B000[5](arg0, arg1);
}

void func_8005D7BC(u16 arg0, u16 arg1) {
    D_8019B000[6](arg0, arg1);
}

void func_8005D7F8(u16 arg0) {
    D_8019B000[7](arg0, 0);
}

void func_8005D82C(u16 arg0) {
    D_8019B000[7](arg0, 0);
}

void func_8005D860(u16 arg0) {
    D_8019B000[5](arg0, 0);
}

void func_8005D894(u16 arg0, u16 arg1) {
    D_8019B000[3](arg0, arg1);
}

void func_8005D8D0(u16 arg0, u16 arg1) {
    D_8019B000[4](arg0, arg1);
}

void func_8005D90C(u16 arg0, u16 arg1) {
    D_80192060[0](arg0, arg1); // TODO: which base? address is D_80192060
}

void func_8005D948(u16 arg0, u16 arg1) {
    D_80192060[1](arg0, arg1);
}

void func_8005D984(u16 arg0) {
    D_80192060[2](arg0, 0);
}

void func_8005D9B8(u16 arg0) {
    D_80192060[3](arg0, 0);
}

void func_8005D9EC(u16 arg0) {
    D_80192060[4](arg0, 0);
}

void func_8005DA20(u16 arg0, u16 arg1) {
    D_80192030[3](arg0, arg1);
}

void func_8005DA5C(u16 arg0, u16 arg1) {
    D_80192060[1](arg0, arg1);
}

void func_8005DA98(u16 arg0) {
    D_801A6840[1](arg0, 0);
}

void func_8005DACC(u16 arg0) {
    D_801A6840[2](arg0, 0);
}

void func_8005DB00(u16 arg0) {
    D_801A6840[3](arg0, 0);
}

void func_8005DB34(u16 arg0) {
    D_801A6840[4](arg0, 0);
}

void func_8005DB68(u16 arg0) {
    D_801A6840[5](arg0, 0);
}

void func_8005DB9C(u16 arg0) {
    D_801A6840[6](arg0, 0);
}

void func_8005DBD0(u16 arg0) {
    D_801A6840[7](arg0, 0);
}

void func_8005DC04(u16 arg0) {
    D_801A6840[8](arg0, 0);
}

void func_8005DC38(void) {
    D_801A6840[9](0, 0);
}

void func_8005DC64(u16 arg0) {
    D_801A6840[10](arg0, 0);
}

void func_8005DC98(u16 arg0) {
    D_801A6840[11](arg0, 0);
}

void func_8005DCCC(u16 arg0) {
    D_801A6840[12](arg0, 0);
}

void func_8005DD00(u16 arg0) {
    D_801A6840[13](arg0, 0);
}

void func_8005DD34(u16 arg0) {
    D_801A6840[14](arg0, 0);
}

void func_8005DD68(u16 arg0) {
    D_801A6840[15](arg0, 0);
}

void func_8005DD9C(void) {
    D_801A6840[16](0, 0);
}

void func_8005DDC8(u16 arg0) {
    D_80192020[0](arg0, 0);
}

void func_8005DDFC(u16 arg0) {
    D_80192020[2](arg0, 0);
}

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

void func_8005E0B0(s16 arg0, s16 arg1, s32 arg2) {
    if (arg2 == 2) {
        func_8005EC20(arg0, arg1);
    }
    else if (arg0 > 0) {
        if (arg0 < 0x81) {
            switch (D_801782E0) {
            case 1:
                break;
            case 2:
                arg0 += 0x7C;
                break;
            case 3:
                arg0 += 0xCD;
                break;
            }
        }
        if (arg2 != 0) {
            func_8005EC20(arg0, arg1);
        }
        else {
            func_800831D0(arg1 % 32, arg1 / 32, arg0, D_801782E2);
        }
    }
}

void func_8005E1CC(u16 actor_index, f32 arg1) {
    f32 temp_f0;

    temp_f0 = arg1 / 5.0f;
    gActors[actor_index].scaleX = arg1 + (temp_f0 * COS(gActiveFrames * 0x20));
    gActors[actor_index].scaleY = arg1 + (temp_f0 * SIN(gActiveFrames * 0x20));
}

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005E8F8.s")

void func_8005EC20(s16, s16);                   /* extern */
#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005EC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005EE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F6D4.s")

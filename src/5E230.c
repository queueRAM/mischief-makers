#include "common.h"

typedef void (*Actor2Func)(u16 actor_0, u16 arg1);

extern s32 D_800D1954[];
extern u16 D_800D5820;

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
extern s16 D_80178440;
extern s16 D_80178442;

#define D_8019B000 ((Actor2Func*)0x8019B000)
#define D_80192020 ((Actor2Func*)0x80192020)
#define D_80192030 ((Actor2Func*)0x80192030)
#define D_80192060 ((Actor2Func*)0x80192060)
#define D_801A6840 ((Actor2Func*)0x801A6840)

u16 func_8005EC20(s16, s16, s32);

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

u16 func_8005E0B0(s16 arg0, s16 arg1, s32 arg2) {
    if (arg2 == 2) {
        return func_8005EC20(arg0, arg1, arg2);
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
            return func_8005EC20(arg0, arg1, arg2);
        }
        else {
            return func_800831D0(arg1 % 32, arg1 / 32, arg0, D_801782E2);
        }
    }
}

void func_8005E1CC(u16 actor_index, f32 arg1) {
    f32 temp_f0;

    temp_f0 = arg1 / 5.0f;
    gActors[actor_index].scaleX = arg1 + (temp_f0 * COS(gActiveFrames * 0x20));
    gActors[actor_index].scaleY = arg1 + (temp_f0 * SIN(gActiveFrames * 0x20));
}

typedef struct {
    s16 unk0;
    s16 unk2;
} UnkActor_150; // TODO: could be FixedCoord if `s16 frac;`

void func_8005E260(u16 actor_index) {
    s16 index;
    u16 actor_1;

    actor_1 = gActors[actor_index].unk_0D6;
    if ((gActors[actor_index].stateLower < 2) && (gActors[actor_index].flags_098 & 0x200)) {
        gActors[actor_index].flags &= ~0x1000;
        gActors[actor_index].state = 2;
    }
    switch (gActors[actor_index].stateLower) {
    case 0:
        gActors[actor_index].graphicFlags |= 1;
        gActors[actor_index].graphicIndex = 0x134;
        gActors[actor_index].unk_0DF = 0;
        gActors[actor_index].unk_0DE = 0xD;
        gActors[actor_index].timer_110 = 0.0f;
        if (gActors[actor_index].unk_104 < 0) {
            gActors[actor_index].flags |= 0x20;
        }
        else {
            gActors[actor_index].flags &= ~0x20;
        }
        gActors[actor_index].state = 1;
        /* fallthrough */
    case 1:
        gActors[actor_index].posX.raw = gActors[actor_1].posX.raw;
        gActors[actor_index].posY.raw = gActors[actor_1].posY.raw;
        gActors[actor_index].posZ.raw = gActors[actor_1].posZ.raw;
        gActors[actor_index].posX.raw += gActors[actor_index].unk_104;
        gActors[actor_index].posY.raw += gActors[actor_index].unk_108;
        gActors[actor_index].posZ.raw += gActors[actor_index].unk_10C;
        gActors[actor_index].hitboxBX0 = gActors[actor_index].hitboxBX1 = gActors[actor_1].posX.whole - gActors[actor_index].posX.whole;
        gActors[actor_index].hitboxBY0 = gActors[actor_index].hitboxBY1 = gActors[actor_1].posY.whole - gActors[actor_index].posY.whole;
        gActors[actor_index].hitboxBX0 += gActors[actor_1].hitboxBX0;
        gActors[actor_index].hitboxBX1 += gActors[actor_1].hitboxBX1;
        gActors[actor_index].hitboxBY0 += gActors[actor_1].hitboxBY0;
        gActors[actor_index].hitboxBY1 += gActors[actor_1].hitboxBY1;
        gActors[actor_index].timer_110 += 0.05; //D_800EBF94;
        if (gActors[actor_index].timer_110 >= 1.0) {
            gActors[actor_index].timer_110 = 1.0f;
            gActors[actor_index].flags |= 0x1000;
        }
        func_8005E1CC(actor_index, gActors[actor_index].timer_110);
        if (!(gActors[actor_1].flags_098 & 0x40000)) {
            gActors[actor_index].state = 3;
        }
        break;
    case 2:
        index = 0;
        func_8005DFC8(((UnkActor_150*)(&gActors[actor_index].var_150))[index].unk2);
        index++;
        while (index < 0x10) {
            func_8005DF5C(((UnkActor_150*)(&gActors[actor_index].var_150))[index].unk2);
            index++;
        }
        gActors[actor_index].state = 3;
        break;
    case 3:
        func_8005E1CC(actor_index, gActors[actor_index].timer_110);
        if (gActors[actor_index].timer_110 > 0.0f) {
            gActors[actor_index].timer_110 -= 0.05; // D_800EBF98;
        }
        else {
            gActors[actor_index].flags = 0;
            gActors[actor_index].state = 4;
        }
        break;
    }
}

void func_8005E56C(u16 actor_index) {
    s16 index;
    u16 actor_1;

    actor_1 = gActors[actor_index].unk_0D6;
    switch (gActors[actor_index].stateLower) {
    case 0:
        gActors[actor_index].graphicFlags |= 0x11;
        gActors[actor_index].graphicIndex = 0x134;
        gActors[actor_index].colorA = 0xD8;
        gActors[actor_index].unk_0DB = 0x17;
        gActors[actor_index].health = 1;
        gActors[actor_index].damage = 0;
        gActors[actor_index].hitboxAY0 = 0xC; \
        gActors[actor_index].hitboxAY1 = -0xC;
        gActors[actor_index].unk_0DF = 0;
        gActors[actor_index].timer_110 = 0.0f;
        if (gActors[actor_index].unk_104 < 0) {
            gActors[actor_index].flags |= 0x20;
            gActors[actor_index].hitboxAX0 = -0x14; \
            gActors[actor_index].hitboxAX1 = 8;
        }
        else {
            gActors[actor_index].flags &= ~0x20;
            gActors[actor_index].hitboxAX0 = -8; \
            gActors[actor_index].hitboxAX1 = 0x14;
        }
        gActors[actor_index].state = 1;
        /* fallthrough */
    case 1:
        gActors[actor_index].posX.raw = gActors[actor_1].posX.raw;
        gActors[actor_index].posY.raw = gActors[actor_1].posY.raw;
        gActors[actor_index].posZ.raw = gActors[actor_1].posZ.raw;
        gActors[actor_index].posX.raw += gActors[actor_index].unk_104;
        gActors[actor_index].posY.raw += gActors[actor_index].unk_108;
        gActors[actor_index].posZ.raw += gActors[actor_index].unk_10C;
        gActors[actor_index].timer_110 += 0.1;
        if (gActors[actor_index].timer_110 >= 1.0) {
            gActors[actor_index].timer_110 = 1.0f;
            gActors[actor_index].flags |= 0x200;
        }
        func_8005E1CC(actor_index, gActors[actor_index].timer_110);
        if (gActors[actor_1].flags_098 & 0x40000) {
            gActors[actor_1].flags_098 |= 0x100000;
            if ((gActors[actor_index].stateLower < 2) && (D_800D5820 == 0)) {
                if (gActors[actor_index].flags_098 & 1) {
                    if ((gButtonPress & gButton_LTrig) || (gButtonPress & gButton_RTrig)) {
                        gActors[actor_index].flags &= ~0x200;
                        gActors[actor_index].state = 2;
                        Sound_PlaySfx(0x10D);
                        D_80178440 = gPlayerPosX.whole;
                        D_80178442 = gPlayerPosY.whole;
                        gActors[actor_1].flags_098 &= 0xFFEFFFFF;
                    }
                }
            }
        }
        else {
            gActors[actor_1].flags_098 &= 0xFFEFFFFF;
            gActors[actor_index].state = 3;
        }
        break;
    case 2:
        index = 0;
        func_8005DFC8(((UnkActor_150*)(&gActors[actor_index].var_150))[index].unk2);
        index++;
        while (index < 0x10) {
            func_8005DF5C(((UnkActor_150*)(&gActors[actor_index].var_150))[index].unk2);
            index++;
        }
        D_800D5820 = actor_1;
        gActors[actor_index].state = 3;
        break;
    case 3:
        func_8005E1CC(actor_index, gActors[actor_index].timer_110);
        if (gActors[actor_index].timer_110 > 0.0f) {
            gActors[actor_index].timer_110 -= 0.1;
        }
        else {
            gActors[actor_index].flags = 0;
            gActors[actor_index].state = 4;
        }
        break;
    }
}

void func_8005E8F8(u16 actor_index) {
    switch (gActors[actor_index].stateLower) {
    case 0:
        gActors[actor_index].scaleY = Math_ApproachF32(gActors[actor_index].scaleY, gActors[actor_index].unk_114, gActors[actor_index].unk_114 / 20.0f);
        if (gActors[actor_index].scaleY == gActors[actor_index].unk_114) {
            if (gActors[actor_index].graphicIndex == 0x2CE) {
                gActors[actor_index].flags |= 0x50000000;
            }
            gActors[actor_index].state = 1;
        }
        break;
    case 3:
        gActors[actor_index].scaleX = Math_ApproachF32(gActors[actor_index].scaleX, gActors[actor_index].timer_110, gActors[actor_index].timer_110 / 20.0f);
        if (gActors[actor_index].scaleX == gActors[actor_index].timer_110) {
            gActors[actor_index].stateUpper = 1;
        }
        gActors[actor_index].scaleY = Math_ApproachF32(gActors[actor_index].scaleY, gActors[actor_index].unk_114, gActors[actor_index].unk_114 / 20.0f);
        if ((gActors[actor_index].scaleY == gActors[actor_index].unk_114) && (gActors[actor_index].stateUpper == 1)) {
            gActors[actor_index].stateUpper = 2;
        }
        if (gActors[actor_index].colorR >= 9) {
            gActors[actor_index].colorR -= 6;
        }
        else {
            gActors[actor_index].colorR = 0;
            if (gActors[actor_index].stateUpper == 2) {
                gActors[actor_index].graphicFlags |= 0x10;
                gActors[actor_index].flags |= 0x30000000;
                gActors[actor_index].hitboxBX0 = 0x30;
                gActors[actor_index].hitboxBX1 = 1;
                gActors[actor_index].hitboxBY0 = 0x18;
                gActors[actor_index].hitboxBY1 = 2;
                gActors[actor_index].unk_17C = (gActors[actor_index].graphicIndex * 0x480) + 0x801A0BA8;
                gActors[actor_index].state = 4;
            }
        }
        gActors[actor_index].colorB = gActors[actor_index].colorR;
        gActors[actor_index].colorG = gActors[actor_index].colorR;
        break;
    case 2:
        if (gActors[actor_index].graphicIndex == 0x2CE) {
            gActors[actor_index].flags &= 0xAFFFFFFF;
        }
        gActors[actor_index].scaleY = Math_ApproachF32(gActors[actor_index].scaleY, 0.0f, gActors[actor_index].unk_114 / 20.0f);
        if (gActors[actor_index].scaleY == 0.0f) {
            gActors[actor_index].flags = 0;
        }
        break;
    case 5:
        gActors[actor_index].flags &= 0xCFFFFFFF;
        if (gActors[actor_index].colorR < 0x78) {
            gActors[actor_index].colorR += 6;
        }
        else {
            gActors[actor_index].colorR = 0x7F;
        }
        gActors[actor_index].colorB = gActors[actor_index].colorR;
        gActors[actor_index].colorG = gActors[actor_index].colorR;
        gActors[actor_index].scaleX += gActors[actor_index].timer_110 / 20.0f;
        gActors[actor_index].scaleY = Math_ApproachF32(gActors[actor_index].scaleY, 0.0f, gActors[actor_index].unk_114 / 20.0f);
        if (gActors[actor_index].scaleY == 0.0f) {
            gActors[actor_index].flags = 0;
        }
        break;
    case 6:
        gActors[actor_index].posY.whole = (D_801783F6 - (gActiveFrames & 0xF) / 4) - 0x26;
        break;
    default:
        break;
    }
}

u16 func_8005EC20(s16 arg0, s16 arg1, s32 arg2) {
    u16 actor_index;

    actor_index = Actor_RangeFindInactive(0x30, 0xD0);
    if (actor_index == 0) {
        return actor_index;
    }
    gActors[actor_index].actorType = 0x3A;
    func_8001E2D0(actor_index);
    gActors[actor_index].graphicFlags |= 0xB41;
    gActors[actor_index].flags |= 9;
    gActors[actor_index].unk_18C = (D_801782E2 * 8) + 0x802651F8;
    if (arg2 == 2) {
        if (arg0 < 0) {
            gActors[actor_index].graphicList = gGraphicListGem;
            gActors[actor_index].graphicTimer = 1;
            gActors[actor_index].unk_18C = D_800D1954[func_8005C6D0(arg0)];
        }
        else {
            gActors[actor_index].graphicIndex = arg0;
            gActors[actor_index].graphicFlags &= 0xFDFF;
        }
        gActors[actor_index].state = 0xA;
    }
    else {
        gActors[actor_index].graphicIndex = (arg0 * 2) + 0x372;
    }
    gActors[actor_index].scaleY = 1.0f;
    gActors[actor_index].scaleX = 1.0f;
    gActors[actor_index].posX.whole = -0x7B;
    gActors[actor_index].posY.whole = D_801783F6 + 0x13;
    gActors[actor_index].posX.whole += (arg1 % 32) * 8;
    gActors[actor_index].posY.whole -= (arg1 / 32) * 20;
    gActors[actor_index].posZ.whole = 0x400;
    gActors[actor_index].unk_188 = 0;
    gActors[actor_index].timer_110 = 0.5f;
    gActors[actor_index].unk_114 = -0.025f;
    gActors[actor_index].var_154 = D_801782E2;
    gActors[actor_index].var_158 = arg0;
    gActors[actor_index].var_15C = arg1;
    gActors[actor_index].unk_14C = D_80178418[0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005EE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5E230/func_8005F6D4.s")

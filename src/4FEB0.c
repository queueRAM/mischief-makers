#include "common.h"
#include "boot.h"

typedef struct {
    s8 unk0;
    s8 unk1;
} Unk800D410C;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
} Unk800D4130;

extern Unk800D410C* D_800D410C[];
extern Unk800D4130 D_800D4130[];
extern Unk800D4130 D_800D413C[];

extern u16 D_801373D8;

s32 func_80049040(u16);
void func_8005D370(u16, s32);
void func_8005D3D8(u16);

s32 func_8004F2B0(u16 actor_index) {
    s32 pad;

    if (!(D_801370CE & gButton_B)) {
        return 0;
    }
    gActors[actor_index].flags &= ~0x4040;
    gActors[actor_index].unk_140_u8[0] = func_80048C28(0, actor_index);
    if (!(D_801373D8 & ~0x80)) {
        return 1;
    }
    return 2;
}

s32 func_8004F35C(u16 actor_index, u32* arg1) {
    if (func_8005D418(actor_index) != 0) {
        gActors[actor_index].unk_12F_u8 = 0;
        Sound_PlaySfx(0xAD);
        return 1;
    }
    *arg1 += 1;
    if (!(*arg1 & 0x40000000)) {
        if ((*arg1 & 0x3FFFFFFF) >= 0x10) {
            if (func_8005D338(actor_index) == 0x6B) {
                Sound_PlaySfx(0xB4);
            }
            else {
                Sound_PlaySfx(0xCA);
            }
            *arg1 |= 0x40000000;
        }
    }
    if ((gActors[actor_index].unk_170_s8[0] == 0) && (gActors[actor_index].unk_170_s8[1] == 0)) {
        return 0;
    }
    if (!(*arg1 & 0x80000000)) {
        if (!(D_801370CE & gButton_B)) {
            return 0;
        }
        *arg1 |= 0x80000000;
    }
    if (!(D_801370CC & gButton_B)) {
        return 0;
    }
    gActors[actor_index].unk_170_s8[0] = 0x7F;
    *arg1 += 4;
    return 0;
}

void func_8004F514(u16 actor0, u16 actor1) {
    gActors[actor0].flags &= 0xFDFFFFFF;
    if (actor1 != 0xFFFF) {
        if (gActors[actor1].flags & 2) {
            gActors[actor1].flags_098 &= ~0x200;
        }
        if (actor0 == 0) {
            gActors[actor0].unk_140_u16[1] = gActors[actor0].unk_0D6;
            gActors[actor0].unk_140_u8[1] = 0x1E;
        }
    }
}

void func_8004F5B0(u16 actor_index) {
    switch (gActors[actor_index].unk_140_u16[1]) {
    case 0:
        gActors[actor_index].unk_140_u16[1] = 1;
        break;
    case 8:
        gActors[actor_index].unk_140_u16[1] = 2;
        break;
    default:
        gActors[actor_index].unk_140_u16[1] = 0;
        break;
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/YqmQz
void func_80059D88(u16, s32*, s32, s32);
void func_8005C520(s8, s32);
s32 func_8005C774(s32);
u16 func_8004F614(u16 actor_index, s32 arg1, s32 arg2, s16 arg3) {
    s32 var_v0;
    s32 sp34[4];
    u16 temp_s0;
    s32 temp_v0;

    var_v0 = gActors[actor_index].unk_140_u16[1];
    temp_s0 = gActors[actor_index].unk_0D6;
    if (var_v0 >= 3) {
        var_v0 = 0;
    }
    sp34[0] = 0x12;
    sp34[2] = 1;
    sp34[3] = 0x8022D4E8;
    sp34[1] = D_800D413C[var_v0].unk0;
    func_80059D88(actor_index, sp34, 0, 0x40400000);
    gActors[actor_index].flags &= 0xFDFFFFFF;
    if (temp_s0 == 0xFFFF) {
        return temp_s0;
    }
    if (!(gActors[temp_s0].flags & 2)) {
        return 0xFFFF;
    }
    func_8004F514(actor_index, temp_s0);
    gActors[temp_s0].flags_098 |= 0x400;
    gActors[temp_s0].unk_0DC = 0xC0;
    gActors[temp_s0].unk_0DD = 0x19;
    gActors[temp_s0].pendingDamage = arg3;
    if (!(gActors[actor_index].flags & 0x20)) {
        gActors[temp_s0].unk_0F8.raw = arg1;
    }
    else {
        gActors[temp_s0].unk_0F8.raw = -arg1;
    }
    gActors[temp_s0].unk_0FC.raw = arg2;
    if (temp_s0 == 0) {
        gActors[temp_s0].unk_13C_u16[1] = arg3;
        temp_v0 = func_8005C774(2);
        func_8005C520(temp_v0 + 1, 6);
    }
    return temp_s0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004F614.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/e5Q7Y
s32 func_8004F7D8(u16 actor_index) {
    u16 temp_a0;
    u16 temp_t5;
    s32 temp_a3;
    s32 pad0;
    s32 var_a1; // sp38
    s32 var_t0;
    s32 pad1;
    s32 pad2;
    s32 sp28;
    s32 pad3;

    temp_a0 = gActors[actor_index].unk_0D6;
    func_8002877C(temp_a0);
    gActors[actor_index].flags_098 |= gActors[temp_a0].flags_098 & 0xC;
    sp28 = gActors[temp_a0].flags_098 & 0xC;
    if (func_8005C6D0(((gActors[temp_a0].posX.raw + (gScreenPosCurrentX.whole << 0x10)) - (gScreenPosNextX.whole << 0x10)) - gActors[temp_a0].unk_104) >= 0x10000) {
        gActors[actor_index].posX.raw = ((gActors[actor_index].posX.raw + gActors[temp_a0].posX.raw + (gScreenPosCurrentX.whole << 0x10)) - gActors[temp_a0].unk_104) - (gScreenPosNextX.whole << 0x10);
    }
    if (((gActors[temp_a0].posY.raw + (gScreenPosCurrentY.whole << 0x10)) != ((gScreenPosNextY.whole << 0x10) + gActors[temp_a0].unk_108)) && !(gActors[actor_index].flags & 0x810000)) {
        gActors[actor_index].posY.raw = ((gActors[actor_index].posY.raw + gActors[temp_a0].posY.raw + (gScreenPosCurrentY.whole << 0x10)) - gActors[temp_a0].unk_108) - (gScreenPosNextY.whole << 0x10);
    }
    gActors[temp_a0].unk_104 = gActors[actor_index].posX.raw;
    gActors[temp_a0].unk_108 = gActors[actor_index].posY.raw;
    gActors[temp_a0].unk_10C = gActors[actor_index].posZ.raw - 0x4000;
    temp_t5 = gActors[actor_index].unk_140_u16[1];
    var_a1 = D_800D4130[temp_t5].unk0;
    var_t0 = D_800D413C[temp_t5].unk0;
    if (!(gActors[actor_index].flags & 0x20)) {
        if ((var_a1 + gActors[temp_a0].hitboxBX0) < D_800D4130[temp_t5].unk2) {
            var_a1 = D_800D4130[temp_t5].unk2 - gActors[temp_a0].hitboxBX0;
        }
    }
    else {
        var_a1 = -var_a1;
        if (-D_800D4130[temp_t5].unk2 < (var_a1 + gActors[temp_a0].hitboxBX1)) {
            var_a1 = -D_800D4130[temp_t5].unk2 - gActors[temp_a0].hitboxBX1;
        }
    }
    if ((var_t0 + gActors[temp_a0].hitboxBY1) < D_800D413C[temp_t5].unk2) {
        var_t0 = D_800D413C[temp_t5].unk2 - gActors[temp_a0].hitboxBY1;
    }

    temp_a3 = 0x40000 - (func_8005D1B0(temp_a0) << 0xE);

    if (temp_a3 >= func_8005C6D0((var_a1 << 0x10) - D_801373E0.unk_00)) {
        D_801373E0.unk_00 = (var_a1 << 0x10);
    }
    else if (D_801373E0.unk_00 < (var_a1 << 0x10)) {
        D_801373E0.unk_00 += temp_a3;
    }
    else {
        D_801373E0.unk_00 -= temp_a3;
    }

    if (temp_a3 >= func_8005C6D0((var_t0 << 0x10) - D_801373E0.unk_04)) {
        D_801373E0.unk_04 = (var_t0 << 0x10);
    }
    else if (D_801373E0.unk_04 < (var_t0 << 0x10)) {
        D_801373E0.unk_04 += temp_a3;
    }
    else {
        D_801373E0.unk_04 -= temp_a3;
    }

    gActors[temp_a0].unk_104 += D_801373E0.unk_00;
    gActors[temp_a0].unk_108 += D_801373E0.unk_04;
    return sp28;
}
#else
s32 func_8004F7D8(u16 actor_index);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004F7D8.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/JsH8K
void func_8004FB30(u16 actor_index, s32 arg1) {
    u16 index1;
    s32 temp_f16;
    Unk800D410C* temp_v0;

    temp_v0 = D_800D410C[arg1];
    if (temp_v0 != 0) {
        index1 = gActors[actor_index].unk_0D6;
        gActors[index1].unk_104 = gActors[actor_index].posX.raw;
        gActors[index1].unk_108 = gActors[actor_index].posY.raw;
        temp_f16 = gActors[0].unk_120 * (temp_v0[gActors[actor_index].unk_170_s8[1]].unk0 << 0x10);
        if (!(gActors[actor_index].flags & 0x20)) {
            gActors[index1].unk_104 += temp_f16;
        }
        else {
            gActors[index1].unk_104 -= temp_f16;
        }
        temp_f16 = gActors[0].unk_120 * (temp_v0[gActors[actor_index].unk_170_s8[1]].unk1 << 0x10);
        gActors[index1].unk_108 += temp_f16;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FB30.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/MFNFc
s32 func_8004FC68(u16 actor_index, u16 arg1) {
    s16 var_v0;
    s16 temp;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_800D4130[0].unk0;
    var_t0 =  D_800D413C[0].unk0;
    if (!(gActors[actor_index].flags & 0x20)) {
        if ((var_v0 + gActors[arg1].hitboxBX0) < D_800D4130[0].unk2) {
            var_v0 = D_800D4130[0].unk2 - gActors[arg1].hitboxBX0;
        }
        var_v0 = var_v0 + gActors[arg1].hitboxBX1;
        if (gActors[actor_index].unk_140_u8[0] != 0) {
            var_v0 -= 2;
        }
    }
    else {
        var_v0 = var_v0 * -1;
        if (-D_800D4130[0].unk2 < (var_v0 + gActors[arg1].hitboxBX1)) {
            var_v0 = -D_800D4130[0].unk2 - gActors[arg1].hitboxBX1;
        }
        var_v0 = var_v0 + gActors[arg1].hitboxBX0;
        if (gActors[actor_index].unk_140_u8[0] != 0) {
            var_v0 = var_v0 + 2;
        }
    }
    var_a3 = var_t0 + gActors[arg1].hitboxBY1;
    if (var_a3 < D_800D413C[0].unk2) {
        temp = D_800D413C[0].unk2 - gActors[arg1].hitboxBY1;
        var_a3 = temp + gActors[arg1].hitboxBY1;
    }
    if (func_8001FCA0(arg1, gActors[actor_index].posX.whole + var_v0, gActors[actor_index].posY.whole + var_a3) & 0x80) {
        return 1;
    }
    return 0;
}
#else
s32 func_8004FC68(u16 actor_index, u16 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FC68.s")
#endif

void func_8004FDF8(u16 actor_index) {
    u16 index;

    func_8004F7D8(actor_index);
    index = gActors[actor_index].unk_0D6;
    if (!(D_80137458 & 0x10000) && (func_80049040(actor_index) != 0)) {
        func_8005D370(actor_index, 0x28);
        gActors[actor_index].state = 0x1A;
    }
    else {
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
        if (gActors[actor_index].stateUpper == 0) {
            gActors[actor_index].var_150 = 0;
            gActors[actor_index].var_154 = 0;
            gActors[actor_index].unk_170 = 0x65;
            Sound_PlaySfx(0xB3);
            gActors[actor_index].stateUpper += 1;
        }
        if ((gActors[actor_index].unk_170_s8[0] == 0) && (gActors[actor_index].unk_170_s8[1] == 7)) {
            Sound_PlaySfx(0xC2);
        }
        if ((D_801373E0.unk_12 == 0) && (D_801373E0.unk_10 >= 5) && (D_801373E0.unk_10 < 0xC) && (gActors[actor_index].var_154 < 8)) {
            gActors[index].flags_098 |= 0x20000;
            gActors[actor_index].var_154 += 1;
        }
        gActors[actor_index].var_150 += gActors[actor_index].var_154;
        gActors[actor_index].unk_170_s8[0] += D_801373E0.unk_0E / (0x3E8 / ((gActiveFrames & 1) + 4));
        gActors[actor_index].var_150 = gActors[actor_index].var_150 % 4;
        if (func_8005D418(actor_index) != 0) {
            if (gActors[actor_index].var_154 != 0) {
                gActors[actor_index].var_154 -= 1;
            }
            func_8005D3D8(actor_index);
            if ((D_801373F0 < 5) || (D_801373F0 >= 0xC) || (D_801373F2 >= 0xE)) {
                gActors[actor_index].unk_170_s8[1] = 0x7F;
                gActors[actor_index].state = 4;
            }
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/V00hL
void func_800500B0(u16 actor_index) {
    u16 var_a3;
    u16 index;

    func_8004F7D8(actor_index);
    gActors[actor_index].unk_17C = 0;
    index = gActors[actor_index].unk_0D6;
    if ((D_801373D8 & 0x20) || (func_8004FC68(actor_index, index))) {
        if (gActors[index].unk_0DE != 0x16) {
            gActors[actor_index].unk_140_u8[0] = 0;
            gActors[actor_index].unk_140_u16[1] = 1;
            var_a3 = 0x10;
            if (func_8005D1B0(index) != 2) {
                var_a3 = 0xB;
            }
            if ((func_8005D338(actor_index) == 8) || (func_8005D338(actor_index) == 0xD)) {
                var_a3 = 0xE;
                if (func_8005D1B0(index) != 2) {
                    var_a3 = 9;
                }
                func_8005D370(actor_index, var_a3);
                gActors[actor_index].flags |= 0x40;
            }
        }
        else {
            goto block_12;
        }
    }
    else {
block_12:
        gActors[actor_index].unk_140_u8[0] = 4;
        gActors[actor_index].unk_140_u16[1] = 0;
        var_a3 = 0xD;
        if (func_8005D1B0(index) != 2) {
            var_a3 = 8;
        }
        if ((func_8005D338(actor_index) == 0xB) || (func_8005D338(actor_index) == 0x10)) {
            var_a3 = 0xF;
            if (func_8005D1B0(index) != 2) {
                var_a3 = 0xA;
            }
            func_8005D370(actor_index, var_a3);
            gActors[actor_index].flags |= 0x40;
        }
        if (D_801373D8 & 0x10) {
            gActors[actor_index].unk_17C = 1;
            var_a3 = 0x11;
            if (func_8005D1B0(index) != 2) {
                var_a3 = 0xC;
            }
        }
    }
    if (D_801373E0.unk_78 & 0x10000) {
        if ((D_801373E0.unk_12 == 0) && (D_801373E0.unk_11 < 0xE) && (D_801373E0.unk_10 >= 5) && (D_801373E0.unk_10 < 0xC) && (gActors[actor_index].unk_140_u16[1] == 0)) {
            gActors[actor_index].state = 0x28;
        }
        else {
            if (gActors[actor_index].flags & 0x4040) {
                if (func_8005D418(actor_index) != 0) {
                    gActors[actor_index].flags &= ~0x4040;
                }
            }
            if (!(gActors[actor_index].flags & 0x4040)) {
                if (D_801373D8 & 0x80) {
                    gActors[actor_index].flags ^= 0x20;
                }
                func_8005D370(actor_index, var_a3);
            }
        }
    }
    else {
        gActors[actor_index].unk_12C_u16[0] = 7;
        if ((gActors[actor_index].unk_0A0 & 7) == 7) {
            if (!(gActors[actor_index].unk_0A0 & 0x10)) {
                var_a3 = 0x13;
                if (!(gActors[actor_index].flags & 0x20)) {
                    var_a3 = 0x12;
                }
                gActors[actor_index].velocityX.raw = -0x6000;
            }
            else {
                var_a3 = 0x12;
                if (!(gActors[actor_index].flags & 0x20)) {
                    var_a3 = 0x13;
                }
                gActors[actor_index].velocityX.raw = 0x6000;
            }
            if (gActors[actor_index].unk_140_u16[1] == 1) {
                var_a3 += 2;
            }
            if ((var_a3 != func_8005D338(actor_index)) && !(gActors[actor_index].flags & 0x4040)) {
                func_8005D370(actor_index, var_a3);
            }
        }
        if (gActors[actor_index].velocityX.raw != 0) {
            if ((D_801373D8 & 0x80) && (func_8005C6D0(gActors[actor_index].velocityX.raw) > func_80048C94(1))) {
                gActors[actor_index].state = 0xA;
            }
            else {
                gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
                goto block_55;
            }
        }
        else {
block_55:
            if (D_801373D8 & 0x80) {
                if (gActors[actor_index].unk_140_u8[0] == 0) {
                    gActors[actor_index].unk_170 = 0x19;
                }
                else {
                    gActors[actor_index].unk_170 = 0x18;
                }
                gActors[actor_index].flags ^= 0x20;
                if (D_801373D8 & 2) {
                    gActors[actor_index].flags &= ~0x20;
                }
                if (D_801373D8 & 1) {
                    gActors[actor_index].flags |= 0x20;
                }
                gActors[actor_index].flags |= 0x4000;
            }
            if (var_a3 != func_8005D338(actor_index)) {
                if (gActors[actor_index].flags & 0x4040) {
                    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
                    if (func_8005D418(actor_index) != 0) {
                        gActors[actor_index].flags &= ~0x4040;
                    }
                }
                else if (gActors[actor_index].velocityX.raw == 0) {
                    func_8005D370(actor_index, var_a3);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800500B0.s")
#endif

void func_8005060C(u16 actor_index) {
    u16 index;

    gActors[actor_index].unk_12C_u16[0] = 7;
    index = gActors[actor_index].unk_0D6;
    func_8004F7D8(actor_index);
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
    if (gActors[actor_index].stateUpper == 0) {
        func_8005A4B0(actor_index, 1.0f);
        if (func_8005D1B0(index) != 2) {
            Sound_PlaySfx(0xAC);
        }
        else {
            Sound_PlaySfx(0xAC);
        }
        if (gActors[actor_index].unk_140_u8[0] == 0) {
            gActors[actor_index].unk_170 = 0x2C;
        }
        else {
            gActors[actor_index].unk_170 = 0x2B;
        }
        gActors[actor_index].stateUpper += 1;
    }
    if (gActors[actor_index].unk_170_s8[1] == 1) {
        gActors[actor_index].unk_170_s8[0] = 0;
        if (gActors[actor_index].var_150 == 0) {
            gActors[actor_index].unk_170_s8[1] = 2;
        }
        else {
            gActors[actor_index].var_150 = gActors[actor_index].var_150 - 1;
        }
    }
    if (func_8005D418(actor_index) != 0) {
        gActors[actor_index].state = 4;
    }
}

void func_8005074C(u16 actor_index) {
    u16 index;
    s32 var_a1;

    gActors[actor_index].unk_12C_u16[0] = 7;
    func_8004F7D8(actor_index);
    var_a1 = func_80048C94(1);
    if (gActors[actor_index].flags & 0x20) {
        var_a1 = -var_a1;
    }
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, var_a1, func_8005C6D0(var_a1) / 12);
    index = gActors[actor_index].unk_0D6;
    if (((D_801373D8 & 0x20) || ((func_8004FC68(actor_index, index) != 0))) && (gActors[index].unk_0DE != 0x16)) {
        gActors[actor_index].unk_140_u8[0] = 0;
        gActors[actor_index].unk_140_u16[1] = 1;
        if (func_8005D338(actor_index) != 0x20) {
            gActors[actor_index].unk_170_u16[1] = 0x20;
        }
    }
    else {
        gActors[actor_index].unk_140_u8[0] = 4;
        gActors[actor_index].unk_140_u16[1] = 0;
        if (func_8005D338(actor_index) != 0x1F) {
            gActors[actor_index].unk_170_u16[1] = 0x1F;
        }
    }
    if ((gActors[actor_index].unk_170_s8[0] == 0) && ((gActors[actor_index].unk_170_s8[1] == 2) || (gActors[actor_index].unk_170_s8[1] == 8))) {
        Sound_PlaySfx(0x53U);
    }
    if (!(D_801373D8 & 3) || (D_801373D8 & 0x80)) {
        gActors[actor_index].state = 4;
    }
}

void func_800508F4(u16 actor_index) {
    gActors[actor_index].unk_12C_u16[0] = 7;
    func_8004F7D8(actor_index);
    if (gActors[actor_index].stateUpper == 0) {
        if (gActors[actor_index].unk_140_u8[0] == 0) {
            gActors[actor_index].unk_170 = 0x2F;
        }
        else {
            gActors[actor_index].unk_170 = 0x2E;
        }
        gActors[actor_index].stateUpper = 1;
    }
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0) * 2);
    if (gActors[actor_index].velocityX.raw != 0) {
        gActors[actor_index].unk_180_u8[3] = 4;
    }
    else {
        gActors[actor_index].flags |= 0x4000;
        gActors[actor_index].state = 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800509C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80050F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800528F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800536CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005396C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800541B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005457C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005498C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800551F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800553EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005544C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800554AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005552C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800558F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800562EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005664C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800569AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005701C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005739C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800574B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800575C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800576A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800584D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005878C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005896C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058F9C.s")

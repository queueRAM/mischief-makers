#include "common.h"
#include "boot.h"

typedef void (*ActorFunc2)(u16, u16);

typedef struct {
    s8 pad0[0x9];
    s8 unk9;
    s8 padA[0x1];
    s8 unkB;
    s8 padC[0x2];
    s8 unkE;
} Unk800D4000;

typedef struct {
    s8 unk0;
    s8 unk1;
} Unk800D410C;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
} Unk800D4130;

extern ActorFunc2 D_800D3EB0[];
extern ActorFunc2 D_800D3F70[];
extern Unk800D4000 D_800D4000;
extern Unk800D410C* D_800D410C[];
extern Unk800D4130 D_800D4130[];
extern s16 D_800D4134;
extern s16 D_800D4138;
extern Unk800D4130 D_800D413C[];
extern s32 D_800D57E0;
extern s32 D_800E3630[]; // could be array of structs of length 0x28
extern f32 D_800EBEBC;

extern s16 D_801370D2;
extern u16 D_801373D8;
extern s32 D_801373E4;
extern s16 D_801373EE;
extern s8 D_801373F3;

s32 func_80049040(u16);
void func_80055C2C(u16, u16);
s32 func_800575C0(u16 actor_index);
void func_80058924(u16);
s32 func_8005D370(u16, u16);
void func_8005D3D8(u16);
u8 func_8001FCA0(u16 arg0, s16 arg1, s16 arg2);

s32 func_8004F2B0(u16 actor_index) {
    s32 pad;

    if (!(D_801370CE & gButton_B)) {
        return 0;
    }
    gActors[actor_index].flags &= ~0x4040;
    gActors[actor_index].unk_140_u8[0] = func_80048C28(0);
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

s32 func_8004F7D8(u16 actor_index) {
    u16 index;
    u16 temp_t5;
    s32 pad0;
    s32 var_a0;
    s32 var_a1;
    s32 var_t0;
    s32 temp_a3;
    s32 temp_2;
    s32 sp28;
    s32 temp_3;

    index = gActors[actor_index].unk_0D6;
    func_8002877C(index);
    gActors[actor_index].flags_098 |= gActors[index].flags_098 & 0xC;
    sp28 = gActors[index].flags_098 & 0xC;
    if (func_8005C6D0(((gActors[index].posX.raw + (gScreenPosCurrentX.whole << 0x10)) - (gScreenPosNextX.whole << 0x10)) - gActors[index].unk_104) >= 0x10000) {
        gActors[actor_index].posX.raw = ((gActors[actor_index].posX.raw + gActors[index].posX.raw + (gScreenPosCurrentX.whole << 0x10)) - gActors[index].unk_104) - (gScreenPosNextX.whole << 0x10);
    }
    var_a0 = gScreenPosCurrentY.whole << 0x10;\
    var_a1 = gScreenPosNextY.whole << 0x10;
    temp_2 = gActors[index].posY.raw;
    temp_3 = gActors[index].unk_108;
    if (((var_a1 + temp_3) != (temp_2 + var_a0)) && !(gActors[actor_index].flags & 0x810000)) {
        gActors[actor_index].posY.raw += ((temp_2 + var_a0) - temp_3) - var_a1;
    }
    gActors[index].unk_104 = gActors[actor_index].posX.raw;
    gActors[index].unk_108 = gActors[actor_index].posY.raw;
    gActors[index].unk_10C = gActors[actor_index].posZ.raw - 0x4000;
    // fakematch
    temp_t5 = gActors[actor_index].unk_140_u16[1] & 0xFFFF & 0xFFFF & 0xFFFF & 0xFFFF & 0xFFFF & 0xFFFF & 0xFFFF & 0xFFFF;
    var_a1 = D_800D4130[temp_t5].unk0;
    var_t0 = D_800D413C[temp_t5].unk0;
    if (!(gActors[actor_index].flags & 0x20)) {
        if ((var_a1 + gActors[index].hitboxBX0) < D_800D4130[temp_t5].unk2) {
            var_a1 = D_800D4130[temp_t5].unk2 - gActors[index].hitboxBX0;
        }
    }
    else {
        var_a1 = -var_a1;
        if ((var_a1 + gActors[index].hitboxBX1) > -D_800D4130[temp_t5].unk2) {
            var_a1 = -D_800D4130[temp_t5].unk2 - gActors[index].hitboxBX1;
        }
    }
    if ((var_t0 + gActors[index].hitboxBY1) < D_800D413C[temp_t5].unk2) {
        var_t0 = D_800D413C[temp_t5].unk2 - gActors[index].hitboxBY1;
    }

    temp_a3 = 0x40000 - (func_8005D1B0(index) << 0xE);
    var_a1 <<= 0x10;
    var_t0 <<= 0x10;
    if (temp_a3 >= func_8005C6D0(var_a1 - D_801373E0.unk_00[0].raw)) {
        D_801373E0.unk_00[0].raw = var_a1;
    }
    else if (D_801373E0.unk_00[0].raw < var_a1) {
        D_801373E0.unk_00[0].raw += temp_a3;
    }
    else {
        D_801373E0.unk_00[0].raw -= temp_a3;
    }

    if (temp_a3 >= func_8005C6D0(var_t0 - D_801373E0.unk_00[1].raw)) {
        D_801373E0.unk_00[1].raw = var_t0;
    }
    else if (D_801373E0.unk_00[1].raw < var_t0) {
        D_801373E0.unk_00[1].raw += temp_a3;
    }
    else {
        D_801373E0.unk_00[1].raw -= temp_a3;
    }

    var_a0 = D_801373E0.unk_00[0].raw;
    var_a1 = D_801373E0.unk_00[1].raw;
    gActors[index].unk_104 += var_a0;
    gActors[index].unk_108 += var_a1;
    return sp28;
}

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
void func_8004FB30(u16 actor_index, s32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FB30.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/MFNFc
s32 func_8004FC68(u16 actor_0, u16 actor_1) {
    s16 var_v0;
    s16 temp;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_800D4130[0].unk0;
    var_t0 = D_800D413C[0].unk0;
    if (!(gActors[actor_0].flags & 0x20)) {
        if ((var_v0 + gActors[actor_1].hitboxBX0) < D_800D4130[0].unk2) {
            var_v0 = D_800D4130[0].unk2 - gActors[actor_1].hitboxBX0;
        }
        var_v0 += gActors[actor_1].hitboxBX1;
        if (gActors[actor_0].unk_140_u8[0] != 0) {
            var_v0 -= 2;
        }
    }
    else {
        var_v0 = -var_v0;
        if (-D_800D4130[0].unk2 < (var_v0 + gActors[actor_1].hitboxBX1)) {
            var_v0 = -D_800D4130[0].unk2 - gActors[actor_1].hitboxBX1;
        }
        var_v0 += gActors[actor_1].hitboxBX0;
        if (gActors[actor_0].unk_140_u8[0] != 0) {
            var_v0 += 2;
        }
    }
    var_a3 = var_t0 + gActors[actor_1].hitboxBY1;
    if (var_a3 < D_800D413C[0].unk2) {
        temp = D_800D413C[0].unk2;
        temp -= gActors[actor_1].hitboxBY1;
        var_a3 = temp + gActors[actor_1].hitboxBY1;
    }
    if (func_8001FCA0(actor_1, gActors[actor_0].posX.whole + var_v0, gActors[actor_0].posY.whole + var_a3) & 0x80) {
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

void func_800500B0(u16 actor_index) {
    u16 index;
    u16 var_a3;

    func_8004F7D8(actor_index);
    gActors[actor_index].unk_17C = 0;
    index = gActors[actor_index].unk_0D6;
    if (((D_801373D8 & 0x20) || func_8004FC68(actor_index, index)) && gActors[index].unk_0DE != 0x16) {
        gActors[actor_index].unk_140_u8[0] = 0;
        gActors[actor_index].unk_140_u16[1] = 1;
        if (func_8005D1B0(index) != 2) {
            var_a3 = 0xB;
        }
        else {
            var_a3 = 0x10;
        }
        if ((func_8005D338(actor_index) == 8) || (func_8005D338(actor_index) == 0xD)) {
            if (func_8005D1B0(index) != 2) {
                var_a3 = 9;
            }
            else {
                var_a3 = 0xE;
            }
            func_8005D370(actor_index, var_a3);
            gActors[actor_index].flags |= 0x40;
        }
    }
    else {
        gActors[actor_index].unk_140_u8[0] = 4;
        gActors[actor_index].unk_140_u16[1] = 0;
        if (func_8005D1B0(index) != 2) {
            var_a3 = 8;
        }
        else {
            var_a3 = 0xD;
        }
        if ((func_8005D338(actor_index) == 0xB) || (func_8005D338(actor_index) == 0x10)) {
            if (func_8005D1B0(index) != 2) {
                var_a3 = 0xA;
            }
            else {
                var_a3 = 0xF;
            }
            func_8005D370(actor_index, var_a3);
            gActors[actor_index].flags |= 0x40;
        }
        if (D_801373D8 & 0x10) {
            gActors[actor_index].unk_17C = 1;
            if (func_8005D1B0(index) != 2) {
                var_a3 = 0xC;
            }
            else {
                var_a3 = 0x11;
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
        return;
    }

    gActors[actor_index].unk_12C_u16[0] = 7;
    if ((gActors[actor_index].unk_0A0 & 7) == 7) {
        if (!(gActors[actor_index].unk_0A0 & 0x10)) {
            if (!(gActors[actor_index].flags & 0x20)) {
                var_a3 = 0x12;
            }
            else {
                var_a3 = 0x13;
            }
            gActors[actor_index].velocityX.raw = -0x6000;
        }
        else {
            if (!(gActors[actor_index].flags & 0x20)) {
                var_a3 = 0x13;
            }
            else {
                var_a3 = 0x12;
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
            return;
        }

        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
    }

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

void func_800509C0(u16 actor_index) {
    s16 var_a0;
    u16 sp2C;
    s32 sp28;
    s32 temp2;
    s32 temp;

    sp2C = gActors[actor_index].unk_0D6;
    gActors[actor_index].unk_12C_u16[0] = 2;
    sp28 = func_8004F7D8(actor_index);
    if (gActors[actor_index].stateUpper == 0) {
        Sound_PlaySfx(0x27);
        gActors[actor_index].var_150 = 0x10;
        if (D_801373F0 == 4) {
            if (!(sp28 & 8)) {
                temp = func_80048C94(5);
                temp2 = func_80048C94(9);
                gActors[actor_index].velocityX.raw = temp + (temp2 * (D_801373EE / 100));
                if (func_80048C94(0xA) < gActors[actor_index].velocityX.raw) {
                    gActors[actor_index].velocityX.raw = func_80048C94(0xA);
                }
            }
            gActors[actor_index].stateUpper = 2;
            if (gActors[actor_index].flags & 0x20) {
                gActors[actor_index].stateUpper |= 0x80;
            }
        }
        if (D_801373F0 == 0xC) {
            if (!(sp28 & 4)) {
                temp = func_80048C94(5);
                temp2 = func_80048C94(9);
                gActors[actor_index].velocityX.raw = -(temp + (temp2 * (D_801373EE / 100)));
                if (gActors[actor_index].velocityX.raw < -func_80048C94(0xA)) {
                    gActors[actor_index].velocityX.raw = -func_80048C94(0xA);
                }
            }
            gActors[actor_index].stateUpper = 1;
            if (!(gActors[actor_index].flags & 0x20)) {
                gActors[actor_index].stateUpper |= 0x80;
            }
        }
        gActors[actor_index].unk_0DA = 0;
        gActors[actor_index].unk_0DB = 0x15;
        gActors[actor_index].damage = 0;
        gActors[actor_index].hitboxAY0 = gActors[actor_index].hitboxBY0 - 4;
        gActors[actor_index].hitboxAY1 = gActors[actor_index].hitboxBY1 + 8;
        if (!(gActors[actor_index].stateUpper & 0x80)) {
            if (!(gActors[actor_index].flags & 0x20)) {
                gActors[actor_index].hitboxAX1 = gActors[actor_index].hitboxBX1 + 1;
                if (gActors[actor_index].unk_140_u8[0] != 0) {
                    gActors[actor_index].hitboxAX1 = (gActors[actor_index].hitboxAX1 + gActors[sp2C].hitboxBX1) - gActors[sp2C].hitboxBX0;
                }
                gActors[actor_index].hitboxAX0 = 0;
            }
            else {
                gActors[actor_index].hitboxAX1 = 0;
                gActors[actor_index].hitboxAX0 = gActors[actor_index].hitboxBX0 - 1;
                if (gActors[actor_index].unk_140_u8[0] != 0) {
                    gActors[actor_index].hitboxAX0 = (gActors[actor_index].hitboxAX0 + gActors[sp2C].hitboxBX0) - gActors[sp2C].hitboxBX1;
                }
            }
            if (gActors[actor_index].unk_140_u8[0] == 0) {
                gActors[actor_index].unk_170 = 0x50;
            }
            else {
                gActors[actor_index].unk_170 = 0x4F;
            }
        }
        else {
            if (!(gActors[actor_index].flags & 0x20)) {
                gActors[actor_index].hitboxAX1 = 0;
                gActors[actor_index].hitboxAX0 = gActors[actor_index].hitboxBX0 - 1;
            }
            else {
                gActors[actor_index].hitboxAX0 = 0;
                gActors[actor_index].hitboxAX1 = gActors[actor_index].hitboxBX1 + 1;
            }
            if (gActors[actor_index].unk_140_u8[0] == 0) {
                gActors[actor_index].unk_170 = 0x53;
            }
            else {
                gActors[actor_index].unk_170 = 0x52;
            }
        }
        func_8005C098(actor_index, 1);
        gActors[actor_index].unk_17C = 0;
        gActors[actor_index].unk_17C_s8[1] = 2;
        gActors[actor_index].unk_180_u8[2] = (s8) D_801373F0;
        D_801373F2 = 0x64;
        D_801373F3 = 1;
    }
    if ((gActors[actor_index].unk_170_s8[0] == 0) && ((gActors[actor_index].unk_170_s8[1] == 0) || (gActors[actor_index].unk_170_s8[1] == 3))) {
        D_801370D2 = 0;
        func_8005C250(actor_index);
    }
    if (D_801373D8 & 0x10) {
        gActors[actor_index].state = 0xA;
        return;
    }
    gActors[actor_index].var_150--;
    if (gActors[actor_index].var_150 < 0xA) {
        gActors[actor_index].unk_12C_u16[0] |= 4;
    }
    if (gActors[actor_index].var_150 < 8) {
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
    }
    if (func_8005C6D0(gActors[actor_index].velocityX.raw) >= 0x30000) {
        temp2 = func_8005C6D0(gActors[actor_index].hitboxAX0);
        temp = func_8005C6D0(gActors[actor_index].hitboxAX1);
        if (temp2 < temp) {
            var_a0 = gActors[actor_index].posX.whole + gActors[actor_index].hitboxAX1 + 1;
        }
        else {
            var_a0 = (gActors[actor_index].posX.whole + gActors[actor_index].hitboxAX0) - 1;
        }
        if (func_80012AB4(var_a0, gActors[actor_index].posY.whole) & 0x80) {
            gActors[actor_index].velocityX.raw = (s32) (-gActors[actor_index].velocityX.raw * 0.75);
            gActors[actor_index].stateUpper = 1;
            gActors[actor_index].stateLower = 0x13;
            return;
        }
        gActors[actor_index].flags |= 0x80;
    }
    if (gActors[actor_index].var_150 == 0) {
        gActors[actor_index].flags &= ~0x80;
        gActors[actor_index].flags |= 0x40;
        gActors[actor_index].state = 4;
    }
}

void func_80050F3C(u16 actor_index) {
    s32 step;
    s32 sp28;
    u32 orig_flags;
    s32 temp_v0;

    sp28 = func_8004F7D8(actor_index);
    if (gActors[actor_index].stateUpper < 2) {
        gActors[actor_index].unk_12E_u8 |= 0x80;
        orig_flags = gActors[actor_index].flags;
        temp_v0 = func_8004F2B0(actor_index);
        if (temp_v0 == 1) {
            gActors[actor_index].state = 0x29;
            return;
        }
        else if (temp_v0 == 2) {
            gActors[actor_index].flags = orig_flags;
            gActors[actor_index].unk_140_u8[0] = 4;
            gActors[actor_index].state = 0x27;
            return;
        }
    }
    if (gActors[actor_index].stateUpper == 0) {
        gActors[actor_index].flags &= ~0x4040;
        Sound_PlaySfx(0xAE);
        Sound_PlaySfx(0xB4);
        func_8005C098(actor_index, 1);
        gActors[actor_index].damage = 0;
        gActors[actor_index].unk_0DA = 1;
        gActors[actor_index].unk_0DB = 0x16;
        gActors[actor_index].hitboxAY0 = gActors[gActors[actor_index].unk_0D6].hitboxBY0 + D_800D4000.unkE;
        gActors[actor_index].hitboxAY1 = D_800D4000.unkB;
        if (!(gActors[actor_index].flags & 0x20)) {
            gActors[actor_index].hitboxAX1 = gActors[gActors[actor_index].unk_0D6].hitboxBX1 + D_800D4000.unk9;
            gActors[actor_index].hitboxAX0 = 0;
            if (!(sp28 & 8)) {
                gActors[actor_index].velocityX.raw = func_80048C94(11);
            }
            gActors[actor_index].unk_180_u8[2] = 4;
        }
        else {
            gActors[actor_index].hitboxAX1 = 0;
            gActors[actor_index].hitboxAX0 = gActors[gActors[actor_index].unk_0D6].hitboxBX0 - D_800D4000.unk9;
            if (!(sp28 & 4)) {
                gActors[actor_index].velocityX.raw = -func_80048C94(11);
            }
            gActors[actor_index].unk_180_u8[2] = 12;
        }
        gActors[actor_index].unk_170 = 0x5D;
        gActors[actor_index].unk_17C = 2;
        gActors[actor_index].unk_140_u8[0] = 4;
        gActors[actor_index].unk_140_u16[1] = 0;
        gActors[actor_index].var_150 = 0;
        gActors[actor_index].stateUpper = 1;
    }
    if ((gActors[actor_index].flags_098 & 1) || (gActors[actor_index].var_150 != 0)) {
        if (gActors[actor_index].var_150 == 0) {
            gActors[actor_index].unk_170_u16[1] |= 0x4000;
            gActors[actor_index].unk_104 = gActors[actor_index].velocityX.raw;
            gActors[actor_index].unk_108 = gActors[actor_index].velocityY.raw;
            gActors[actor_index].velocityX.raw = 0;
            gActors[actor_index].velocityY.raw = 0;
        }
        gActors[actor_index].var_150++;
        if (gActors[actor_index].var_150 >= 5) {
            gActors[actor_index].unk_170_u16[1] &= 0xBFFF;
            gActors[actor_index].var_150 = 0;
            gActors[actor_index].velocityX.raw = gActors[actor_index].unk_104;
            gActors[actor_index].velocityY.raw = gActors[actor_index].unk_108;
        }
        else {
            return;
        }
    }
    gActors[actor_index].unk_0F8.raw = 0x30000;
    gActors[actor_index].unk_0FC.raw = 0x30000;
    if ((gActors[actor_index].flags & 0x810000) && (func_8005C6D0(gActors[actor_index].velocityX.raw) > 0x10000)) {
        gActors[actor_index].unk_180_u8[3] = 4;
    }
    if (gActors[actor_index].stateUpper == 1) {
        if ((gActors[actor_index].unk_170_s8[0] == 0) && ((gActors[actor_index].unk_170_s8[1] == 0) || (gActors[actor_index].unk_170_s8[1] == 2) || (gActors[actor_index].unk_170_s8[1] == 4))) {
            D_801370D2 = 0;
            func_8005C250(actor_index);
        }
        step = func_80048C94(0) / 8;
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, step);
        if (func_8005D418(actor_index) != 0) {
            gActors[actor_index].unk_17C = 0;
            gActors[actor_index].unk_170 = 0x5E;
            gActors[actor_index].unk_17C_s8[1] = 3;
            gActors[actor_index].stateUpper = 2;
        }
        else {
            gActors[actor_index].flags |= 0x80;
        }
    }
    else if (gActors[actor_index].stateUpper == 2) {
        step = func_80048C94(0);
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, step);
        if (func_8005D418(actor_index) != 0) {
            gActors[actor_index].unk_17C = 0;
            gActors[actor_index].unk_17C_s8[1] = 3;
            gActors[actor_index].flags |= 0x4000;
            gActors[actor_index].state = 4;
        }
        if (func_80049040(actor_index) != 0) {
            gActors[actor_index].state = 0x1A;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052004.s")

void func_80052780(s32 arg0, s32 arg1) {
}

void func_8005278C(u16 actor_0, u16 actor_1) {
    if (gActors[actor_1].unk_0DE == 0x16) {
        gActors[actor_0].unk_140_u8[0] = 4;
        gActors[actor_0].unk_140_u16[1] = 0;
    }
    func_8004F7D8(actor_0);
    if (gActors[actor_0].flags & 0x810000) {
        gActors[actor_0].unk_12C_u16[0] |= 2;
    }
    if (gActors[actor_0].stateUpper == 0) {
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].unk_170 = 0x3C;
        }
        else {
            gActors[actor_0].unk_170 = 0x3F;
        }
        if (gActors[actor_0].unk_140_u8[0] == 0) {
            gActors[actor_0].unk_170 += 1;
        }
        if (gActors[actor_0].unk_140_u8[0] == 8) {
            gActors[actor_0].unk_170 += 2;
        }
        gActors[actor_0].stateUpper = 1;
    }
    if (func_8005D418(actor_0)) {
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].state = 4;
        }
        else {
            gActors[actor_0].state = 0x1D;
        }
    }
}

s32 func_800528F4(u16 actor_0, u16 actor_1) {
    if (actor_1 == 0xFFFF) {
        return 0;
    }
    if (!(gActors[actor_1].flags & 2) || (gActors[actor_1].flags_098 & 0x200) || (gActors[actor_1].health <= 0)) {
        func_8004F514(actor_0, actor_1);
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].state = 3;
        }
        else {
            gActors[actor_0].state = 0x16;
        }
        return 1;
    }
    else {
        gActors[actor_1].flags_098 |= 0x200;
        gActors[actor_1].unk_0D6 = actor_0;
        if (!(gActors[actor_0].flags_098 & 0x10000)) {
            return 0;
        }
        gActors[actor_1].pendingDamage = 0;
        gActors[actor_1].flags_098 |= 0x400;
        func_8004F514(actor_0, actor_1);
        gActors[actor_0].velocityX.raw = gActors[actor_0].unk_0F8.raw;
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].state = 3;
        }
        else {
            gActors[actor_0].velocityY.raw = gActors[actor_0].unk_0FC.raw;
            gActors[actor_0].state = 0x16;
        }
        return 2;
    }
}

s32 func_80052A6C(u16 actor_0, u16 actor_1) {
    s32 var_v1;
    s32 temp_v0;
    s32 pad1;

    if (D_801373F2 != 0) {
        return 0;
    }

    func_8005C098(actor_0, 1);
    gActors[actor_0].unk_180_u8[2] = D_801373F0;
    switch (D_801373F0) {
        case 0:
            var_v1 = 0x55;
        break;
        case 8:
            var_v1 = 0x58;
        break;
        default:
            if (!(D_801373F0 & 8)) {
                if (!(gActors[actor_0].flags & 0x20)) {
                    var_v1 = 0x4F;
                }
                else {
                    var_v1 = 0x52;
                }
            }
            else {
                var_v1 = !(gActors[actor_0].flags & 0x20) ? 0x52 : 0x4F;
            }
        break;
    }
    if (gActors[actor_0].unk_140_u8[0] == 0) {
        var_v1 += 1;
    }
    if (gActors[actor_0].unk_140_u8[0] == 8) {
        if ((var_v1 == 0x52) || (var_v1 == 0x55)) {
            var_v1 = 0;
        }
        else {
            var_v1 += 2;
        }
    }
    if (var_v1 != 0) {
        gActors[actor_0].flags |= 0x40;
        if (!(gActors[actor_1].unk_0DF & 8) && (var_v1 == 0x58)) {
            temp_v0 = func_8005D338(actor_0);
            if (var_v1 != temp_v0) {
                Sound_PlaySfx(0xB3);
            }
        }
        gActors[actor_0].unk_170 = var_v1;
    }
    if (actor_1 == 0xFFFF) {
        return 2;
    }
    else {
        gActors[actor_1].flags_098 |= 0x20000;
        return 1;
    }
}

void func_80052C4C(u16 actor_0, u16 actor_1) {
    if (gActors[actor_1].graphicFlags & 0x800) {
        gActors[actor_0].posZ.raw = gActors[actor_1].unk_188 + 0x10000;
    }
    else {
        gActors[actor_0].posZ.raw = gActors[actor_1].posZ.raw + 0x10000;
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/tqzRX
void func_80052CD0(u16 actor_0, u16 actor_1) {
    s16 var_v0;
    s16 var_a2;
    s32 var_a0;
    s32 var_t1;
    s32 var_t0;
    s32 temp;

    if (actor_1 == 0xFFFF) {
        if (!(gActors[actor_0].flags & 0x810000)) {
            var_v0 = 0;
            if (gActors[actor_0].unk_140_u16[1] == 0) {
                var_a2 = 2;
                var_a0 = 0x10;
            }
            else {
                var_v0 = 2;
                if (gActors[actor_0].unk_140_u16[1] == 8) {
                    var_v0 = 0;
                    var_a2 = -2;
                    var_a0 = 0x20;
                }
                else {
                    var_a2 = 0;
                    var_a0 = 0xC;
                }
            }
            if (!(gActors[actor_0].flags_098 & var_a0)) {
                if (gActors[actor_0].flags & 0x20) {
                    var_v0 = -var_v0;
                }
                gActors[actor_0].velocityX.whole = var_v0;
                gActors[actor_0].velocityY.whole = var_a2;
            }
            else {
                gActors[actor_0].flags &= 0xFF3CFFFF; \
                gActors[actor_0].flags |= 0x10000;
                gActors[actor_0].velocityX.raw = gActors[actor_0].velocityY.raw = 0;
            }
        }
    }
    else {
        func_80052C4C(actor_0, actor_1);
        if (!(gActors[actor_0].unk_140_u16[1] & 7)) {
            if ((gActors[actor_0].hitboxBX0 + gActors[actor_0].posX.whole < gActors[actor_1].hitboxBX0 + gActors[actor_1].posX.whole) && 
                (gActors[actor_0].hitboxBX1 + gActors[actor_0].posX.whole < gActors[actor_1].hitboxBX1 + gActors[actor_1].posX.whole)) {
                D_801373E0.unk_00[0].raw += 0xFFFF0000;
            }
            if ((gActors[actor_1].posX.whole + gActors[actor_1].hitboxBX1 < gActors[actor_0].posX.whole + gActors[actor_0].hitboxBX1) && 
                (gActors[actor_1].posX.whole + gActors[actor_1].hitboxBX0 < gActors[actor_0].posX.whole + gActors[actor_0].hitboxBX0)) {
                D_801373E0.unk_00[0].raw += 0x10000;
            }
            var_t1 = 0;
            if (gActors[actor_0].unk_140_u16[1] == 0) {
                var_t0 = (gActors[actor_0].hitboxBY0 - gActors[actor_1].hitboxBY1) << 0x10;
            }
            else {
                var_t0 = (gActors[actor_0].hitboxBY1 - gActors[actor_1].hitboxBY0) << 0x10;
            }
        }
        else {
            if (!(gActors[actor_0].flags & 0x20)) {
                var_t1 = (gActors[actor_0].hitboxBX1 - gActors[actor_1].hitboxBX0) << 0x10;
            }
            else {
                var_t1 = (gActors[actor_0].hitboxBX0 - gActors[actor_1].hitboxBX1) << 0x10;
            }
            var_t0 = 0;
            if ((gActors[actor_0].hitboxBY1 + gActors[actor_0].posY.whole < gActors[actor_1].hitboxBY1 + gActors[actor_1].posY.whole) && 
                (gActors[actor_0].hitboxBY0 + gActors[actor_0].posY.whole < gActors[actor_1].hitboxBY0 + gActors[actor_1].posY.whole)) {
                D_801373E4 = D_801373E0.unk_00[1].raw + 0xFFFF0000;
            }
            if ((gActors[actor_1].posY.whole + gActors[actor_1].hitboxBY0 < gActors[actor_0].posY.whole + gActors[actor_0].hitboxBY0) && 
                (gActors[actor_1].posY.whole + gActors[actor_1].hitboxBY1 < gActors[actor_0].posY.whole + gActors[actor_0].hitboxBY1)) {
                D_801373E4 = D_801373E0.unk_00[1].raw + 0x10000;
            }
        }
        temp = 0x20000;
        if (var_t1 != 0) {
            if (func_8005C6D0(D_801373E0.unk_00[0].raw - var_t1) < temp) {
                D_801373E0.unk_00[0].raw = var_t1;
                gActors[actor_0].flags &= 0xFF3CFFFF; \
                gActors[actor_0].flags |= 0x10000;
            }
            else if (D_801373E0.unk_00[0].raw < var_t1) {
                D_801373E0.unk_00[0].raw += temp;
            }
            else {
                D_801373E0.unk_00[0].raw -= temp;
            }
        }
        if (var_t0 != 0) {
            if (func_8005C6D0(D_801373E0.unk_00[1].raw - var_t0) < 0x40000) {
                D_801373E0.unk_00[1].raw = var_t0;
                gActors[actor_0].flags &= 0xFF3CFFFF; \
                gActors[actor_0].flags |= 0x10000;
            }
            else if (D_801373E0.unk_00[1].raw < var_t0) {
                D_801373E4 = D_801373E0.unk_00[1].raw + temp;
            }
            else {
                D_801373E4 = D_801373E0.unk_00[1].raw - temp;
            }
        }
        gActors[actor_0].posX.raw = gActors[actor_1].posX.raw - D_801373E0.unk_00[0].raw;
        func_8002877C(actor_0);
        if (gActors[actor_0].flags_098 & 0xC) {
            gActors[actor_1].posX.raw = D_801373E0.unk_00[0].raw + gActors[actor_0].posX.raw;
            gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0xC;
        }
        var_t0 = D_801373E0.unk_00[1].raw;
        var_t0 += gActors[actor_0].posY.raw;
        if ((gActors[actor_0].flags_098 & 0x10) && 
            (var_t0 < gActors[actor_1].posY.raw)) {
            gActors[actor_1].posY.raw = var_t0;
            gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0x10;
        }
        else {
            if (!(gActors[actor_0].flags_098 & 0x20) || (gActors[actor_0].posY.raw < (gActors[actor_1].posY.raw - D_801373E0.unk_00[1].raw))) {
                gActors[actor_0].posY.raw = gActors[actor_1].posY.raw - D_801373E0.unk_00[1].raw;
            }
            var_t0 = gActors[actor_1].posY.raw;
        }
        gActors[actor_1].unk_108 = var_t0;
        gActors[actor_1].unk_104 = gActors[actor_1].posX.raw;
        gActors[actor_1].unk_10C = gActors[actor_1].posZ.raw;
    }
}
#else
void func_80052CD0(u16 actor_0, u16 actor_1);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052CD0.s")
#endif

s32 func_80053210(u16 actor_0, u16 actor_1) {
    s32 var_v0;

    var_v0 = func_8004F2B0(actor_0);
    if (var_v0 == 1) {
        func_8004F514(actor_0, actor_1);
        gActors[actor_0].unk_12F_u8 = 0;
        gActors[actor_0].state = 0x16;
        return 3;
    }
    else if (var_v0 == 2) {
        gActors[actor_0].unk_12F_u8 = 0;
        gActors[actor_0].velocityY.raw = 0;
        gActors[actor_0].velocityX.raw = 0;
        if (actor_1 == 0xFFFF) {
            gActors[actor_0].state = 0x25;
            return 2;
        }
        gActors[actor_0].state = 0x26;
        return 2;
    }
    else if (func_80048F70(actor_0, actor_1) != 0) {
        func_8004F514(actor_0, actor_1);
        gActors[actor_0].state = 0x14;
        gActors[actor_0].stateUpper = 0xA;
        return 4;
    }
    else {
        return 0;
    }
}

void func_80053358(u16 actor_0, u16 actor_1) {
    s32 temp_v0;
    s32 var_a2;

    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (gActors[actor_0].stateUpper == 0) {
        if (actor_1 != 0xFFFF) {
            if (((gActors[actor_1].hitboxBX0 + gActors[actor_1].posX.whole) >= (gActors[actor_0].hitboxBX1 + gActors[actor_0].posX.whole)) || 
                ((gActors[actor_0].posX.whole + gActors[actor_0].hitboxBX0) >= (gActors[actor_1].posX.whole + gActors[actor_1].hitboxBX1))) {
                gActors[actor_0].unk_140_u8[0] = 4;
            }
            if ((gActors[actor_1].hitboxBY1 + gActors[actor_1].posY.whole) >= (gActors[actor_0].hitboxBY0 + gActors[actor_0].posY.whole)) {
                gActors[actor_0].unk_140_u8[0] = 0;
            }
            if ((gActors[actor_0].posY.whole + gActors[actor_0].hitboxBY1) >= (gActors[actor_1].posY.whole + gActors[actor_1].hitboxBY0)) {
                gActors[actor_0].unk_140_u8[0] = 8;
            }
        }
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0];
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    var_a2 = 0x42;
    if (gActors[actor_0].unk_140_u8[0] == 0) {
        var_a2 = 0x43;
    }
    if (gActors[actor_0].unk_140_u8[0] == 8) {
        var_a2 += 2;
    }
    if (gActors[actor_0].flags & 0x4040) {
        if (func_8005D418(actor_0) != 0) {
            gActors[actor_0].flags &= ~0x4040;
        }
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, var_a2);
    }
    func_80052A6C(actor_0, actor_1);
    func_80052CD0(actor_0, actor_1);
    temp_v0 = func_80053210(actor_0, actor_1);
    if (temp_v0 == 2) {
        if (gActors[actor_0].unk_140_u16[1] != 4) {
            if (D_801373D8 & 2) {
                gActors[actor_0].flags |= 0x20;
            }
            if (D_801373D8 & 1) {
                gActors[actor_0].flags &= ~0x20;
            }
        }
        switch (gActors[actor_0].unk_140_u16[1]) {
        case 0:
            gActors[actor_0].unk_140_u8[0] &= 7;
            if (gActors[actor_0].unk_140_u8[0] == 0) {
                gActors[actor_0].unk_140_u8[0] |= 8;
            }
            if (gActors[actor_0].unk_140_u8[0] < 8) {
                gActors[actor_0].unk_140_u8[0] = 6;
            }
            break;
        case 4:
            if (gActors[actor_0].unk_140_u8[0] < 4) {
                gActors[actor_0].unk_140_u8[0] = 2;
            }
            if (gActors[actor_0].unk_140_u8[0] > 4) {
                gActors[actor_0].unk_140_u8[0] = 6;
            }
            break;
        case 8:
            gActors[actor_0].unk_140_u8[0] &= 0x7;
            if (gActors[actor_0].unk_140_u8[0] > 0) {
                gActors[actor_0].unk_140_u8[0] = 2;
            }
            break;
        }
    }
    else if (temp_v0 == 4) {
        if (gActors[actor_0].unk_140_u8[0] == 0) {
            gActors[actor_0].flags &= 0xFF3CFFFF; \
            gActors[actor_0].flags |= 0x20000;
            gActors[actor_0].stateUpper = 2;
            gActors[actor_0].unk_17C = 0;
            gActors[actor_0].stateLower = 0x16;
        }
        else if (gActors[actor_0].unk_140_u8[0] == 8) {
            gActors[actor_0].state = 0x14;
        }
        else {
            gActors[actor_0].unk_170 = 0x45;
            gActors[actor_0].state = 0x23;
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/r11VD
void func_800536CC(u16 actor_0, u16 actor_1) {
    s32 sp2C;
    s32 sp28;
    s32 step;

    step = 0x40000;
    func_80052C4C(actor_0, actor_1);
    if (!(gActors[actor_0].flags & 0x20)) {
        sp2C = (gActors[actor_0].hitboxBX1 - gActors[actor_1].hitboxBX0) << 0x10;
    }
    else {
        sp2C = (gActors[actor_0].hitboxBX0 - gActors[actor_1].hitboxBX1) << 0x10;
    }
    sp28 = ((-(gActors[actor_1].hitboxBY0 + gActors[actor_1].hitboxBY1) / 2) + D_800D413C[0].unk0) << 0x10;
    if (func_8005C6D0(D_801373E0.unk_00[0].raw - sp2C) < step) {
        D_801373E0.unk_00[0].raw = sp2C;
    }
    else if (D_801373E0.unk_00[0].raw < sp2C) {
        D_801373E0.unk_00[0].raw += step;
    }
    else {
        D_801373E0.unk_00[0].raw -= step;
    }
    if (func_8005C6D0(D_801373E0.unk_00[1].raw - sp28) < step) {
        D_801373E0.unk_00[1].raw = sp28;
    }
    else if (D_801373E0.unk_00[1].raw < sp28) {
        D_801373E4 = D_801373E0.unk_00[1].raw + step;
    }
    else {
        D_801373E4 = D_801373E0.unk_00[1].raw - step;
    }
    gActors[actor_0].posX.raw = gActors[actor_1].posX.raw - D_801373E0.unk_00[0].raw;
    func_8002877C(actor_0);
    if (gActors[actor_0].flags_098 & 0xC) {
        gActors[actor_1].posX.raw = gActors[actor_0].posX.raw + D_801373E0.unk_00[0].raw;
        sp28 = gActors[actor_0].flags_098 & 0xC;
        gActors[actor_1].flags_098 |= sp28;
    }
    step = D_801373E0.unk_00[1].raw + gActors[actor_0].posY.raw;
    if ((gActors[actor_0].flags_098 & 0x10) && (step < gActors[actor_1].posY.raw)) {
        gActors[actor_1].posY.raw = step;
        sp28 = gActors[actor_0].flags_098 & 0x10;
        gActors[actor_1].flags_098 |= sp28;
    }
    else {
        gActors[actor_0].posY.raw = gActors[actor_1].posY.raw - D_801373E0.unk_00[1].raw;
    }
    gActors[actor_1].unk_104 = gActors[actor_1].posX.raw;
    gActors[actor_1].unk_108 = gActors[actor_1].posY.raw;
    gActors[actor_1].unk_10C = gActors[actor_1].posZ.raw;
}
#else
void func_800536CC(u16 actor_0, u16 actor_1);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800536CC.s")
#endif

void func_8005396C(u16 actor_0, u16 actor_1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (D_801373D8 & 2) {
        gActors[actor_0].flags |= 0x20;
    }
    if (D_801373D8 & 1) {
        gActors[actor_0].flags &= ~0x20;
    }
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].unk_140_u8[0] = 4;
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0];
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    if (gActors[actor_0].flags & 0x4040) {
        if (func_8005D418(actor_0) != 0) {
            gActors[actor_0].flags &= ~0x4040;
        }
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, 0x3F);
    }
    func_80052A6C(actor_0, actor_1);
    func_800536CC(actor_0, actor_1);
    if (func_80053210(actor_0, actor_1) == 2) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags |= 0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags &= ~0x20;
        }
        gActors[actor_0].unk_140_u16[1] = 4;
    }
}

void func_80053B28(u16 actor_0, u16 actor_1) {
    s32 sp2C;
    s32 sp28;
    s32 step;

    func_80052C4C(actor_0, actor_1);
    sp2C = -((gActors[actor_1].hitboxBX0 + gActors[actor_1].hitboxBX1) / 2);
    if (!(gActors[actor_0].flags & 0x20)) {
        sp2C += (D_800D4138 / 2);
    }
    else {
        sp2C -= (D_800D4138 / 2);
    }
    sp2C <<= 0x10;
    sp28 = (gActors[actor_0].hitboxBY1 - gActors[actor_1].hitboxBY0) << 0x10;
    step = 0x40000;
    if (func_8005C6D0(D_801373E0.unk_00[0].raw - sp2C) < step) {
        D_801373E0.unk_00[0].raw = sp2C;
    }
    else if (D_801373E0.unk_00[0].raw < sp2C) {
        D_801373E0.unk_00[0].raw += step;
    }
    else {
        D_801373E0.unk_00[0].raw -= step;
    }
    if (func_8005C6D0(D_801373E0.unk_00[1].raw - sp28) < step) {
        D_801373E0.unk_00[1].raw = sp28;
    }
    else if (D_801373E0.unk_00[1].raw < sp28) {
        D_801373E4 = D_801373E0.unk_00[1].raw + step;
    }
    else {
        D_801373E4 = D_801373E0.unk_00[1].raw - step;
    }
    gActors[actor_0].posX.raw = gActors[actor_1].posX.raw - D_801373E0.unk_00[0].raw;
    func_8002877C(actor_0);
    if (gActors[actor_0].flags_098 & 0xC) {
        // fakematch: is D_801373E0 array?
        gActors[actor_1].posX.raw = gActors[actor_0].posX.raw + D_801373E0.unk_00[0].raw;
        gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0xC;
    }
    // fakematch: is D_801373E0 array?
    sp28 = gActors[actor_0].posY.raw + D_801373E0.unk_00[1].raw;
    if ((gActors[actor_0].flags_098 & 0x10) && (sp28 < gActors[actor_1].posY.raw)) {
        gActors[actor_1].posY.raw = sp28;
        gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0x10;
    }
    else {
        gActors[actor_0].posY.raw = gActors[actor_1].posY.raw - D_801373E0.unk_00[1].raw;
    }
    gActors[actor_1].unk_104 = gActors[actor_1].posX.raw;
    gActors[actor_1].unk_108 = gActors[actor_1].posY.raw;
    gActors[actor_1].unk_10C = gActors[actor_1].posZ.raw;
}

void func_80053DC8(u16 actor_0, u16 actor_1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0] = 8;
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    if ((gActors[actor_0].flags & 0x4040) && (func_8005D418(actor_0) != 0)) {
        gActors[actor_0].flags &= ~0x4040;
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, 0x44U);
    }
    func_80052A6C(actor_0, actor_1);
    func_80053B28(actor_0, actor_1);
    if (func_80053210(actor_0, actor_1) == 2) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags |= 0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags &= ~0x20;
        }
    }
}

void func_80053F34(u16 actor_0, u16 actor_1) {
    s32 sp2C;
    s32 temp_a2;
    s32 step;

    func_80052C4C(actor_0, actor_1);
    sp2C = -((gActors[actor_1].hitboxBX0 + gActors[actor_1].hitboxBX1) / 2);
    if (!(gActors[actor_0].flags & 0x20)) {
        sp2C += D_800D4134;
    }
    else {
        sp2C -= D_800D4134;
    }
    sp2C = sp2C << 0x10;
    step = 0x40000;
    temp_a2 = ((gActors[actor_0].hitboxBY0 - gActors[actor_1].hitboxBY1) << 0x10) + step;
    if (func_8005C6D0(D_801373E0.unk_00[0].raw - sp2C) < step) {
        D_801373E0.unk_00[0].raw = sp2C;
    }
    else if (D_801373E0.unk_00[0].raw < sp2C) {
        D_801373E0.unk_00[0].raw += step;
    }
    else {
        D_801373E0.unk_00[0].raw -= step;
    }
    if (func_8005C6D0(D_801373E0.unk_00[1].raw - temp_a2) < step) {
        D_801373E0.unk_00[1].raw = temp_a2;
    }
    else if (D_801373E0.unk_00[1].raw < temp_a2) {
        D_801373E4 = D_801373E0.unk_00[1].raw + step;
    }
    else {
        D_801373E4 = D_801373E0.unk_00[1].raw - step;
    }
    gActors[actor_0].posX.raw = gActors[actor_1].posX.raw - D_801373E0.unk_00[0].raw;
    func_8002877C(actor_0);
    if (gActors[actor_0].flags_098 & 0xC) {
        gActors[actor_1].posX.raw = gActors[actor_0].posX.raw + D_801373E0.unk_00[0].raw;
        gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0xC;
    }
    temp_a2 = gActors[actor_0].posY.raw + D_801373E0.unk_00[1].raw;
    if ((gActors[actor_0].flags_098 & 0x10) && (temp_a2 < gActors[actor_1].posY.raw)) {
        gActors[actor_1].posY.raw = temp_a2;
        gActors[actor_1].flags_098 |= gActors[actor_0].flags_098 & 0x10;
    }
    else {
        gActors[actor_0].posY.raw = gActors[actor_1].posY.raw - D_801373E0.unk_00[1].raw;
    }
    gActors[actor_1].unk_104 = gActors[actor_1].posX.raw;
    gActors[actor_1].unk_108 = gActors[actor_1].posY.raw;
    gActors[actor_1].unk_10C = gActors[actor_1].posZ.raw;
}

void func_800541B8(u16 actor_0, u16 actor_1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0] = 0;
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    if ((gActors[actor_0].flags & 0x4040) && (func_8005D418(actor_0) != 0)) {
        gActors[actor_0].flags &= ~0x4040;
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, 0x43);
    }
    func_80052A6C(actor_0, actor_1);
    func_80053F34(actor_0, actor_1);
    if (func_80053210(actor_0, actor_1) == 2) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags |= 0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags &= ~0x20;
        }
    }
}

void func_80054320(u16 actor_0, u16 actor_1) {
    s32 sp24;

    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].stateUpper = 1;
        func_8004F514(actor_0, actor_1);
        gActors[actor_1].flags_098 |= 0x10000;
        func_80058924(actor_0);
        if (!(gActors[actor_0].flags & 0x20)) {
            gActors[actor_0].unk_0F8.raw = -0x18000;
        }
        else {
            gActors[actor_0].unk_0F8.raw = 0x18000;
        }
        gActors[actor_0].unk_0FC.raw = 0x30000;
        func_8005C550(actor_0, 0x3C);
        sp24 = func_8005739C(actor_0, gActors[actor_1].damage);
        if (sp24 >= 3) {
            func_800575C0(actor_0);
            if (sp24 == 3) {
                Sound_PlaySfx(0x3C);
            }
        }
        D_800D3F70[gActors[actor_1].unk_0DB](actor_0, actor_1);
    }
}

void func_80054474(u16 actor_0, u16 unused_arg1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].flags &= 0xFDFFFFFF;
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_0D6;
        gActors[actor_0].unk_140_u8[1] = 0x1E;
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].unk_170 = 0x36;
        }
        else {
            gActors[actor_0].unk_170 = 0x39;
        }
        if (gActors[actor_0].unk_140_u8[0] == 0) {
            gActors[actor_0].unk_170 += 1;
        }
        if (gActors[actor_0].unk_140_u8[0] == 8) {
            gActors[actor_0].unk_170 += 2;
        }
        gActors[actor_0].stateUpper += 1;
    }
    gActors[actor_0].flags |= 0x40;
    if (gActors[actor_0].flags & 0x810000) {
        gActors[actor_0].state = 3;
    }
    else {
        gActors[actor_0].state = 0x16;
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/PKzT7
void func_8005457C(u16 actor_0, u16 actor_1) {
    s32 sp34;
    s32 sp30;
    s32 temp_f18;
    s32 sp28;
    s32 sp24;

    gActors[actor_0].graphicFlags |= 8;
    gActors[actor_0].rotateZ = gActors[actor_1].unk_140_f32;
    func_80052C4C(actor_0, actor_1);
    if (gActors[actor_1].unk_0DE == 0x10) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags |= 0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags &= ~0x20;
        }
        sp28 = 0x12;
        sp24 = 4;
    }
    if (gActors[actor_1].unk_0DE == 0x11) {
        sp28 = -1;
        if (D_801373D8 & 2) {
            gActors[actor_0].flags &= ~0x20;
        }
        sp24 = 0x1B;
        if (D_801373D8 & 1) {
            gActors[actor_0].flags |= 0x20;
        }
    }
    if (gActors[actor_0].flags & 0x20) {
        sp28 = -sp28;
    }
    temp_f18 = gActors[actor_0].rotateZ / 0.3515625;
    sp34 = sp28 * COS(temp_f18);
    sp30 = sp24 * COS(temp_f18);
    sp34 -= sp24 * SIN(temp_f18);
    sp30 += sp28 * SIN(temp_f18);
    sp34 <<= 0x10;
    sp30 <<= 0x10;

    temp_f18 = 0x40000;
    if (func_8005C6D0(D_801373E0.unk_00[0].raw - sp34) < temp_f18) {
        D_801373E0.unk_00[0].raw = sp34;
    }
    else if (D_801373E0.unk_00[0].raw < sp34) {
        D_801373E0.unk_00[0].raw += temp_f18;
    }
    else {
        D_801373E0.unk_00[0].raw -= temp_f18;
    }
    if (func_8005C6D0(D_801373E0.unk_00[1].raw - sp30) < temp_f18) {
        D_801373E0.unk_00[1].raw = sp30;
    }
    else if (D_801373E0.unk_00[1].raw < sp30) {
        D_801373E4 = D_801373E0.unk_00[1].raw + temp_f18;
    }
    else {
        D_801373E4 = D_801373E0.unk_00[1].raw - temp_f18;
    }

    gActors[actor_0].posX.raw = (gActors[actor_1].posX.raw + (((gActors[actor_1].hitboxBX0 + gActors[actor_1].hitboxBX1) << 0x10) / 2)) - D_801373E0.unk_00[0].raw;
    gActors[actor_0].posY.raw = (gActors[actor_1].posY.raw + (((gActors[actor_1].hitboxBY0 + gActors[actor_1].hitboxBY1) << 0x10) / 2)) - D_801373E0.unk_00[1].raw;
    gActors[actor_0].unk_0F8.raw = ((gActors[actor_1].posX.raw + gScreenPosCurrentX.raw) - gActors[actor_1].unk_104) - gScreenPosNextX.raw;
    gActors[actor_1].unk_104 = gActors[actor_1].posX.raw;
    gActors[actor_0].unk_0FC.raw = ((gActors[actor_1].posY.raw + gScreenPosCurrentY.raw) - gActors[actor_1].unk_108) - gScreenPosNextY.raw;
    gActors[actor_1].unk_108 = gActors[actor_1].posY.raw;
    gActors[actor_1].unk_10C = gActors[actor_1].posZ.raw;
}
#else
void func_8005457C(u16 actor_0, u16 actor_1);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005457C.s")
#endif

void func_8005498C(u16 actor_0, u16 actor_1) {
    s32 sp34;
    s32 check;
    s32 sp2C;

    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF;
        gActors[actor_0].stateUpper = 1;
    }
    if ((gActors[actor_0].flags & 0x4040) && (func_8005D418(actor_0) != 0)) {
        gActors[actor_0].flags &= ~0x4040;
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        if (gActors[actor_1].unk_0DE == 0x10) {
            gActors[actor_0].unk_140_u8[0] = 4;
            func_8005D370(actor_0, 0x3F);
        }
        if (gActors[actor_1].unk_0DE == 0x11) {
            gActors[actor_0].unk_140_u8[0] = 0;
            func_8005D370(actor_0, 0x43);
        }
    }
    func_80052A6C(actor_0, actor_1);
    func_8005457C(actor_0, actor_1);
    sp34 = func_80053210(actor_0, actor_1);
    if (sp34 != 0) {
        gActors[actor_0].graphicFlags &= 0xFFF7;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        Sound_PlaySfx(0x24);
    }
    if (sp34 == 3) {
        if (gActors[actor_0].unk_0F8.raw > 0) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (gActors[actor_0].unk_0F8.raw < 0) {
            gActors[actor_0].flags |= 0x20;
        }
        gActors[actor_0].velocityX.raw = Math_ClampLimit(gActors[actor_0].unk_0F8.raw, 0x80000);
        gActors[actor_0].velocityY.raw = Math_ClampLimit(gActors[actor_0].unk_0FC.raw, 0x80000);
        gActors[actor_0].state = 0x17;
    }
    else if (sp34 == 2) {
        sp2C = 0;
        check = D_801373D8 & 2;
        if (D_801373D8 & 1) {
            sp2C = 8;
        }
        if (D_801373D8 & 0x20) {
            sp2C = 4;
            if (check) {
                sp2C = 2;
            }
            if (D_801373D8 & 1) {
                sp2C = 6;
            }
        }
        if (D_801373D8 & 0x10) {
            sp2C = 0xC;
            if (check) {
                sp2C = 0xE;
            }
            if (D_801373D8 & 1) {
                sp2C = 0xA;
            }
        }
        sp2C <<= 6;
        gActors[actor_0].velocityX.raw = Math_ClampLimit(gActors[actor_1].unk_0F8.raw, 0x80000);
        gActors[actor_0].velocityY.raw = Math_ClampLimit(gActors[actor_1].unk_0FC.raw, 0x80000);
        gActors[actor_0].velocityX.raw += (196608.0f * COS(sp2C));
        gActors[actor_0].velocityY.raw += (196608.0f * SIN(sp2C));
        if (gActors[actor_0].velocityX.raw > 0) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (gActors[actor_0].velocityX.raw < 0) {
            gActors[actor_0].flags |= 0x20;
        }
        if (D_801373D8 & 2) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags |= 0x20;
        }
        func_8004F514(actor_0, actor_1);
        gActors[actor_0].unk_170_s8[1] = 0x7F;
        gActors[actor_0].state = 0x17;
    }
    else if (sp34 == 4) {
        if (gActors[actor_0].unk_0F8.raw > 0) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (gActors[actor_0].unk_0F8.raw < 0) {
            gActors[actor_0].flags |= 0x20;
        }
        gActors[actor_0].velocityX.raw = Math_ClampLimit(gActors[actor_0].unk_0F8.raw, 0x80000);
        gActors[actor_0].velocityY.raw = Math_ClampLimit(gActors[actor_0].unk_0FC.raw, 0x80000);
        gActors[actor_0].state = 0x17;
    }
}

void func_80054E18(u16 actor_0, u16 actor_1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (!(gActors[actor_1].flags & 0x20)) {
        gActors[actor_0].flags |= 0x20;
    }
    else {
        gActors[actor_0].flags &= ~0x20;
    }
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0] = 4;
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    if (gActors[actor_0].flags & 0x4040) {
        if (func_8005D418(actor_0) != 0) {
            gActors[actor_0].flags &= ~0x4040;
        }
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, 0x3FU);
    }
    func_80052A6C(actor_0, actor_1);
    func_800536CC(actor_0, actor_1);
    if (func_80053210(actor_0, actor_1) == 2) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags |= 0x20;
        }
        gActors[actor_0].unk_140_u16[1] = 4;
    }
}

void func_80054FD0(u16 actor_0, u16 actor_1) {
    gActors[actor_0].unk_12E_u8 |= 0x80;
    if (!(gActors[actor_1].flags & 0x20)) {
        gActors[actor_0].flags &= ~0x20;
    }
    else {
        gActors[actor_0].flags |= 0x20;
    }
    if (gActors[actor_0].stateUpper == 0) {
        gActors[actor_0].unk_140_u16[1] = gActors[actor_0].unk_140_u8[0] = 4;
        gActors[actor_0].flags &= ~0x4040;
        gActors[actor_0].flags &= 0xFF3CFFFF; \
        gActors[actor_0].flags |= 0x20000;
        gActors[actor_0].stateUpper = 1;
    }
    if (gActors[actor_0].flags & 0x4040) {
        if (func_8005D418(actor_0) != 0) {
            gActors[actor_0].flags &= ~0x4040;
        }
    }
    if (!(gActors[actor_0].flags & 0x4040)) {
        func_8005D370(actor_0, 0x3FU);
    }
    func_80052A6C(actor_0, actor_1);
    func_800536CC(actor_0, actor_1);
    if (func_80053210(actor_0, actor_1) == 2) {
        if (D_801373D8 & 2) {
            gActors[actor_0].flags &= ~0x20;
        }
        if (D_801373D8 & 1) {
            gActors[actor_0].flags |= 0x20;
        }
        gActors[actor_0].unk_140_u16[1] = 4;
    }
}

void func_80055188(u16 actor_0) {
    u16 actor_1 = gActors[actor_0].unk_0D6;
    D_800D3EB0[gActors[actor_1].unk_0DE](actor_0, actor_1);
}

void func_800551F8(u16 actor_index) {
    s32 sp24;
    s32 temp_v0;
    s32 temp_v0_2;

    gActors[actor_index].unk_12E_u8 |= 1;
    if (gActors[actor_index].stateUpper == 0) {
        gActors[actor_index].unk_170 = 0x45;
        gActors[actor_index].unk_17C = 0;
        gActors[actor_index].stateUpper = 1;
    }
    else if ((gActors[actor_index].stateUpper == 1) && (func_8005D418(actor_index) != 0)) {
        temp_v0 = func_80048C28(1);
        switch (temp_v0) {
        case 4:
            sp24 = 0x30;
            break;
        case 6:
            sp24 = 0x380;
            break;
        case 8:
            sp24 = 0x380;
            break;
        default:
            sp24 = 0x80;
            break;
        }
        temp_v0_2 = func_80048C94(0xF);
        gActors[actor_index].velocityX.raw = func_8005C6D0(COS(sp24) * temp_v0_2);
        if (gActors[actor_index].flags & 0x20) {
            gActors[actor_index].velocityX.raw = -gActors[actor_index].velocityX.raw;
        }
        temp_v0_2 = func_80048C94(0xF);
        gActors[actor_index].velocityY.raw = SIN(sp24) * temp_v0_2;
        gActors[actor_index].unk_170 = 0x46;
        if (gActors[actor_index].velocityY.raw > 0) {
            gActors[actor_index].unk_17C = 4;
        }
        gActors[actor_index].flags &= 0xFF3CFFFF;
        gActors[actor_index].flags |= 0x20000;
        D_801373F3 = 0;
        Sound_PlaySfx(0x24);
        gActors[actor_index].state = 0x16;
    }
}

void func_800553EC(u16 actor_index) {
    gActors[actor_index].unk_12E_u8 |= 0x81;
    func_80053358(actor_index, 0xFFFF);
}

void func_8005544C(u16 actor_index) {
    gActors[actor_index].unk_12E_u8 |= 0x81;
    func_80055C2C(actor_index, 0xFFFF);
}

void func_800554AC(u16 actor_0, u16 actor_1) {
    s32 idx;

    if (actor_1 != 0xFFFF) {
        idx = gActors[actor_0].unk_140_u8[0];
        gActors[actor_1].unk_0F8.raw = D_800E3630[gActors[actor_1].unk_0CE * 10 + idx];
        gActors[actor_1].unk_0FC.raw = D_800E3630[gActors[actor_1].unk_0CE * 10 + idx + 1];
    }
}

void func_8005552C(s32 arg0, s32 arg1) {
}

void func_80055538(u16 actor_0, u16 actor_1) {
    s32 var_v0;

    switch (gActors[actor_0].stateUpper) {
    case 0:
        if (gActors[actor_0].flags & 0x810000) {
            gActors[actor_0].unk_170 = 0x66;
            gActors[actor_0].var_15C = 0;
        }
        else {
            gActors[actor_0].unk_170 = 0x6A;
            gActors[actor_0].var_15C = 4;
        }
        if (gActors[actor_1].unk_0DE == 0x16) {
            gActors[actor_0].unk_140_u8[0] = 4;
            gActors[actor_0].unk_140_u16[1] = 0;
        }
        var_v0 = 0;
        if (gActors[actor_0].unk_140_u8[0] == 0) {
            var_v0 = 1;
        }
        if (gActors[actor_0].unk_140_u8[0] == 2) {
            var_v0 += 3;
        }
        if (gActors[actor_0].unk_140_u8[0] >= 5) {
            var_v0 += 2;
        }
        gActors[actor_0].velocityY.raw = 0;
        gActors[actor_0].velocityX.raw = 0;
        gActors[actor_0].var_150 = 0;
        gActors[actor_0].var_15C += var_v0;
        gActors[actor_0].unk_170 += var_v0;
        gActors[actor_0].stateUpper = 1;
        /* fallthrough */
    case 1:
        func_8004F7D8(actor_0);
        func_8004FB30(actor_0, gActors[actor_0].var_15C);
        if (func_8004F35C(actor_0, (u32*) &gActors[actor_0].var_150) != 0) {
            func_800554AC(actor_0, actor_1);
            func_8004F614(actor_0, gActors[actor_1].unk_0F8.raw, gActors[actor_1].unk_0FC.raw, 0x1E);
            gActors[actor_0].unk_170 = func_8005D338(actor_0) + 8;
            D_800D57E0 = 0;
            if ((s32) gActors[actor_0].unk_140_u8[0] >= 5) {
                gActors[actor_0].flags &= 0xFF3CFFFF;
                gActors[actor_0].flags |= 0x20000;
                if (!(gActors[actor_0].flags & 0x20)) {
                    gActors[actor_0].velocityX.raw = -0x30000;
                }
                else {
                    gActors[actor_0].velocityX.raw = 0x30000;
                }
                if (gActors[actor_0].unk_140_u8[0] == 8) {
                    gActors[actor_0].velocityX.raw = 0;
                }
                gActors[actor_0].velocityY.raw = 0x30000;
                gActors[actor_0].velocityX.raw = gActors[actor_0].velocityX.raw * gActors->unk_120;
                gActors[actor_0].velocityY.raw = gActors[actor_0].velocityY.raw * gActors->unk_120;
            }
            if (gActors[actor_0].flags & 0x810000) {
                gActors[actor_0].flags |= 0x4000;
                gActors[actor_0].state = 3;
            }
            else {
                gActors[actor_0].state = 0x19;
            }
        }
        break;
    case 2:
        gActors[actor_0].unk_12C_u16[0] |= 4;
        if (gActors[actor_0].unk_140_u8[0] < 4) {
            gActors[actor_0].velocityY.raw = Math_ApproachS32(gActors[actor_0].velocityY.raw, -0x60000, func_80048C94(0x13));
        }
        else {
            gActors[actor_0].velocityY.raw = Math_ApproachS32(gActors[actor_0].velocityY.raw, -0x60000, func_80048C94(0x13) * 0.5);
        }
        if (func_800491B8(actor_0, 0, -14) != 0) {
            gActors[actor_0].state = 5;
        }
        else if (func_8005D418(actor_0) != 0) {
            gActors[actor_0].var_150--;
            if (gActors[actor_0].var_150 <= 0) {
                gActors[actor_0].flags ^= 0x20;
                gActors[actor_0].state = 0x16;
            }
        }
        break;
    }
}

void func_800558F8(u16 actor_0, u16 actor_1) {
    u16 var_v1;

    switch (gActors[actor_0].stateUpper) {
    case 0:
        gActors[actor_0].unk_140_u16[1] = 0;
        var_v1 = func_80048C28(1);
        if (var_v1 == 0xFF) {
            if (!(gActors[actor_0].flags & 0x20)) {
                var_v1 = 4;
            }
            else {
                var_v1 = 12;
            }
        }
        else if ((D_801373D8 & 1) && (var_v1 & 7)) {
            var_v1 = 16 - var_v1;
        }
        if (gActors[actor_0].flags & 0x20) {
            var_v1 = func_8005C6D0(var_v1 - 16);
        }
        gActors[actor_0].var_15C = var_v1;
        var_v1 /= 2;
        gActors[actor_0].unk_170 = var_v1 + 118;
        gActors[actor_0].velocityY.raw = 0;
        gActors[actor_0].velocityX.raw = 0;
        gActors[actor_0].var_150 = 0;
        gActors[actor_0].stateUpper = 1;
        /* fallthrough */
    case 1:
        func_8004F7D8(actor_0);
        if (func_8004F35C(actor_0, (u32* ) &gActors[actor_0].var_150) != 0) {
            func_800554AC(actor_0, actor_1);
            if (gActors[actor_0].var_15C >= 9) {
                gActors[actor_1].unk_0F8.raw = -gActors[actor_1].unk_0F8.raw;
            }
            func_8004F614(actor_0, gActors[actor_1].unk_0F8.raw, gActors[actor_1].unk_0FC.raw, 0x1E);
            gActors[actor_0].unk_170 = func_8005D338(actor_0) + 8;
            Sound_StopSfx(0xB4);
            Sound_StopSfx(0xCA);
            Sound_PlaySfx(0xB9);
            D_800D57E0 = 0;
            if (gActors[actor_0].unk_140_u8[0] >= 5) {
                gActors[actor_0].flags &= 0xFF3CFFFF;
                gActors[actor_0].flags |= 0x20000;
                if (!(gActors[actor_0].flags & 0x20)) {
                    gActors[actor_0].velocityX.raw = -0x20000;
                }
                else {
                    gActors[actor_0].velocityX.raw = 0x20000;
                }
                if (gActors[actor_0].unk_140_u8[0] == 8) {
                    gActors[actor_0].velocityX.raw = 0;
                }
                gActors[actor_0].velocityY.raw = 0x30000;
                gActors[actor_0].velocityX.raw = gActors[actor_0].velocityX.raw * gActors->unk_120;
                gActors[actor_0].velocityY.raw = gActors[actor_0].velocityY.raw * gActors->unk_120;
            }
            if (gActors[actor_0].flags & 0x810000) {
                gActors[actor_0].flags |= 0x4000;
                gActors[actor_0].state = 3;
            }
            else {
                gActors[actor_0].state = 0x16;
            }
        }
        break;
    }
}

void func_80055C2C(u16, u16);
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800562EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005664C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800569AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056F54.s")

void func_8005701C(u16 actor_index) {
    u16 index;
    s32 step;

    index = gActors[actor_index].unk_0D6;
    gActors[actor_index].unk_12E_u8 |= 0x81;
    func_8005C550(actor_index, 1);
    switch (gActors[actor_index].stateUpper) {
    case 0:
        gActors[actor_index].unk_17C = 0;
        gActors[actor_index].unk_17C_s8[1] = 3;
        gActors[actor_index].unk_170 = 0x5F;
        gActors[actor_index].var_15C = 8;
        gActors[actor_index].var_150 = 0;
        gActors[actor_index].stateUpper = 1;
        /* fallthrough */
    case 1:
        if ((gActors[actor_index].unk_170_s8[0] == 0) && (gActors[actor_index].unk_170_s8[1] == 3)) {
            gActors[actor_index].velocityY.raw = func_80048C94(0xF);
            gActors[actor_index].flags &= 0xFF3CFFFF; \
            gActors[actor_index].flags |= 0x20000;
        }
        func_8004F7D8(actor_index);
        func_8004FB30(actor_index, gActors[actor_index].var_15C);
        if (func_8004F35C(actor_index, (u32* ) &gActors[actor_index].var_150) != 0) {
            gActors[actor_index].velocityX.raw = gActors[actor_index].velocityX.raw / 2;
            func_800554AC(actor_index, index);
            func_8004F614(actor_index, gActors[index].unk_0F8.raw, gActors[index].unk_0FC.raw, 0x32);
            gActors[index].unk_0DD = 0x1B;
            gActors[actor_index].unk_170 = 0x60;
            gActors[actor_index].stateUpper = 2;
        case 2:
            if (gActors[actor_index].flags & 0x810000) {
                step = func_80048C94(0);
                gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, step);
            }
            else {
                step = func_80048C94(0);
                gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, 0, step);
            }
            if (func_8005D418(actor_index) != 0) {
                if (gActors[actor_index].flags & 0x810000) {
                    gActors[actor_index].flags |= 0x4000;
                    gActors[actor_index].state = 3;
                }
                else {
                    gActors[actor_index].state = 0x16;
                }
            }
        }
        break;
    }
}

void func_80057268(u16 actor_index) {
    s32 pad;

    gActors[actor_index].unk_12E_u8 |= 0x81;
    gActors[actor_index].velocityX.raw = 0;
    gActors[actor_index].velocityY.raw = 0;
    func_8004F514(actor_index, gActors[actor_index].unk_0D6);
    gActors[actor_index].unk_12F_u8 = 0;
    D_801370CE &= ~gButton_B;
    if (gActors[actor_index].flags & 0x810000) {
        gActors[actor_index].state = 3;
    }
    else {
        gActors[actor_index].state = 0x19;
    }
}

s32 func_80057320(u16 actor_index, s16 health_increment) {
    if (gActors[actor_index].health < 0) {
        return -1;
    }

    gActors[actor_index].health += health_increment;
    if (gActors[actor_index].health > 3000) {
        gActors[actor_index].health = 3000;
        return 2;
    }
    else {
        return 1;
    }
}

s32 func_8005739C(u16 actor_index, s16 health_decrement) {
    s32 var_a0;

    if (actor_index == 0) {
        if (gActors[actor_index].unk_0DC & 2) {
            gActors[actor_index].unk_13C_u16[1] = 0;
        }
        else {
            gActors[actor_index].unk_13C_u16[1] = health_decrement / 2;
        }
    }
    if (health_decrement == 0) {
        return 0;
    }

    if (gActors[actor_index].health > 0) {
        gActors[actor_index].health -= health_decrement;
        var_a0 = 1;
        if (gActors[actor_index].health < 0) {
            gActors[actor_index].health = 0;
            var_a0 = (actor_index != 0) ? 3 : 2;
        }
    }
    else {
        if (actor_index != 0) {
            return 3;
        }
        var_a0 = (gActors[actor_index].health == 0) ? 3 : 4;
        gActors[actor_index].health -= health_decrement;
    }
    return var_a0;
}

s32 func_800574B4(u16 actor_index) {
    if (gActors[actor_index].health < 0) {
        return -1;
    }
    if (!(gActors[actor_index].unk_0DC & 0x40)) {
        return -1;
    }
    if (D_801373E0.unk_0B != 0) {
        D_801373E0.unk_0B -= 1;
        return -2;
    }
    if (!(D_801370CE & (gButton_DUp | gButton_DDown | gButton_DLeft | gButton_DRight | gButton_B | gButton_A))) {
        return 0;
    }
    D_801373E0.unk_0A -= 1;
    if (D_801373E0.unk_0A > 0) {
        return 0;
    }
    gActors[actor_index].state = 0x11;
    return 1;
}

s32 func_800575C0(u16 actor_index) {
    if (gActors[actor_index].unk_0DC & 0x1) {
        return 0;
    }
    gActors[actor_index].unk_0DC |= 0x1;
    if (func_8005C6D0(gActors[actor_index].unk_0F8.raw) < 0x20000) {
        gActors[actor_index].unk_0F8.raw = 2.0 * gActors[actor_index].unk_0F8.raw;
    }
    if (gActors[actor_index].unk_0FC.raw < 0x30000) {
        gActors[actor_index].unk_0FC.raw = 0x30000;
    }
    return 1;
}

void func_800576A0(u16 actor_index) {
    func_8005C550(actor_index, -0x10);
    if (gActors[actor_index].flags_098 & 0x200) {
        gActors[actor_index].flags_098 |= 0x80000;
        gActors[actor_index].unk_12E_u8 |= 0x41;
        gActors[actor_index].posX.raw = gActors[actor_index].unk_104;
        gActors[actor_index].posY.raw = gActors[actor_index].unk_108;
        gActors[actor_index].posZ.raw = gActors[actor_index].unk_10C;
        func_8002877C(actor_index);
        if (gActors[actor_index].flags_098 & 0xC) {
            gActors[gActors[actor_index].unk_0D6].posX.raw = (gActors[gActors[actor_index].unk_0D6].posX.raw + gActors[actor_index].posX.raw) - gActors[actor_index].unk_104;
        }
        if (D_801370CE != 0) {
            gActors[actor_index].unk_170_s8[0] += 1;
        }
    }
    else {
        if (gActors[actor_index].flags_098 & 0x400) {
            if (gActors[actor_index].unk_0DD == 0x1C) {
                gActors[actor_index].state = 0x32;
            }
            else {
                gActors[actor_index].state = 0x31;
            }
            if (gActors[actor_index].flags_098 & 0x10000) {
                gActors[actor_index].unk_12E_u8 |= 2;
            }
            gActors[actor_index].velocityX.raw = gActors[actor_index].unk_0F8.raw;
            gActors[actor_index].velocityY.raw = gActors[actor_index].unk_0FC.raw;
        }
        else {
            gActors[actor_index].state = 0x16;
        }
        gActors[actor_index].flags &= 0xFF3CFFFF; \
        gActors[actor_index].flags |= 0x20000;
    }
}

void func_80057848(u16 actor_index) {
    gActors[actor_index].unk_12E_u8 |= 0x41;
    func_8005C550(actor_index, -0x8000);
    switch (gActors[actor_index].stateUpper) {
    case 0:
        if (!(gActors[actor_index].flags & 0x20)) {
            if (gActors[actor_index].unk_0F8.raw < 0) {
                gActors[actor_index].unk_170 = 0x90;
            }
            else {
                gActors[actor_index].unk_170 = 0x92;
            }
        }
        else if (gActors[actor_index].unk_0F8.raw > 0) {
            gActors[actor_index].unk_170 = 0x90;
        }
        else {
            gActors[actor_index].unk_170 = 0x92;
        }
        if (func_8005D338(actor_index) == 0x90) {
            gActors[actor_index].var_15C = 0;
        }
        if (func_8005D338(actor_index) == 0x92) {
            gActors[actor_index].var_15C = 1;
        }
        if (((gActors[gActors[actor_index].unk_0D6].hitboxAY1 + gActors[gActors[actor_index].unk_0D6].hitboxAY0) / 2) + gActors[gActors[actor_index].unk_0D6].posY.whole <= gActors[actor_index].posY.whole) {
            if (func_8005D338(actor_index) == 0x90) {
                gActors[actor_index].unk_170 = 0x92;
                gActors[actor_index].var_15C = 2;
            }
            else {
                gActors[actor_index].unk_170 = 0x90;
                gActors[actor_index].var_15C = 3;
            }
        }
        gActors[actor_index].unk_170_u16[1] |= 0x4000;
        gActors[actor_index].velocityY.raw = 0;
        gActors[actor_index].velocityX.raw = 0;
        gActors[actor_index].var_150 = 0;
        gActors[actor_index].stateUpper = 1;
        /* fallthrough */
    case 1:
        gActors[actor_index].velocityX.raw = gActors[actor_index].unk_0F8.raw;
        if (!(gActors[actor_index].flags & 0x810000)) {
            gActors[actor_index].velocityY.raw = gActors[actor_index].unk_0FC.raw;
        }
        gActors[actor_index].velocityX.raw = gActors[actor_index].velocityX.raw / gActors->unk_120;
        gActors[actor_index].velocityY.raw = gActors[actor_index].velocityY.raw / gActors->unk_120;
        func_8005D3D8(actor_index);
        if ((gActors[actor_index].stateLower == 0x33) || (gActors[actor_index].stateLower == 0x34)) {
            Sound_PlaySfx(0xB2);
        }
        else if (!(gActors[actor_index].flags_098 & 0x10000)) {
            Sound_PlaySfx(0xB5);
        }
        gActors[actor_index].stateUpper = 2;
        /* fallthrough */
    case 2:
        if (gActors[actor_index].flags & 0x810000) {
            gActors[actor_index].unk_180_u8[3] = 5;
            gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0) / 2);
            if (func_8005C6D0(gActors[actor_index].velocityX.raw) > 0x10000) {
                return;
            }
        }
        else if (func_800491B8(actor_index, 0, -0xE) != 0) {
            gActors[actor_index].state = 5;
            return;
        }
        else {
            gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, -0x60000, func_80048C94(0x13) / 2);
            if (gActors[actor_index].velocityY.raw > 0x10000) {
                return;
            }
        }
        if (func_8005D418(actor_index) != 0) {
            if (gActors[actor_index].flags & 0x810000) {
                if (gActors[actor_index].var_15C == 0) {
                    gActors[actor_index].unk_170 = 0x91;
                }
                else if (gActors[actor_index].var_15C == 1) {
                    gActors[actor_index].unk_170 = 0x93;
                }
                else if (gActors[actor_index].var_15C == 2) {
                    gActors[actor_index].unk_170 = 0x93;
                }
                else if (gActors[actor_index].var_15C == 3) {
                    gActors[actor_index].unk_170 = 0x91;
                }
                gActors[actor_index].flags |= 0x4000;
                gActors[actor_index].state = 3;
            }
            else {
                if (!(gActors[actor_index].var_15C & 1)) {
                    gActors[actor_index].unk_170 = 0x8E;
                }
                else {
                    gActors[actor_index].unk_170 = 0x8F;
                }
                D_800D57E0 = 0;
                gActors[actor_index].state = 0x19;
            }
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057C98.s")

void func_800584D4(u16 actor_index) {
    s16 var_v0;
    gActors[actor_index].unk_12E_u8 |= 0x41;
    func_8005C550(actor_index, -8);
    switch (gActors[actor_index].stateUpper) {
    case 0:
        if (!(gActors[actor_index].flags & 0x20)) {
            if (gActors[actor_index].unk_0F8.raw < 0) {
                gActors[actor_index].unk_170 = 0x90;
            }
            else {
                gActors[actor_index].unk_170 = 0x92;
            }
        }
        else if (gActors[actor_index].unk_0F8.raw > 0) {
            gActors[actor_index].unk_170 = 0x90;
        }
        else {
            gActors[actor_index].unk_170 = 0x92;
        }

        if (func_8005D338(actor_index) == 0x90) {
            gActors[actor_index].var_15C = 0;
        }
        if (func_8005D338(actor_index) == 0x92) {
            gActors[actor_index].var_15C = 1;
        }
        gActors[actor_index].var_150 = func_8005C774(0x28) + 0x50;
        func_8005739C(actor_index, gActors[actor_index].pendingDamage / 5);
        gActors[actor_index].var_15C = ((gActors[actor_index].pendingDamage - gActors[actor_index].pendingDamage / 5) / 180) + 1;
        gActors[actor_index].pendingDamage = 0;
        Sound_PlaySfxAtActorTimed(0x65, actor_index, gActors[actor_index].var_150);
        gActors[actor_index].stateUpper = 1;
        /* fallthrough */
    case 1:
        if (gActors[actor_index].unk_170_s8[0] == 0) {
            var_v0 = func_8005C708(3);
            gActors[actor_index].unk_170_s8[1] = func_8005C6D0(var_v0);
        }
        D_800BE5E0 = func_8005C708(2);
        D_800BE5E4 = func_8005C708(2);
        func_8005739C(actor_index, gActors[actor_index].var_15C);
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, func_80048C94(0));
        gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, 0, func_80048C94(0));
        gActors[actor_index].unk_180_u8[3] = 7;
        if (D_801370CE != 0) {
            gActors[actor_index].var_150 -= 10;
        }
        gActors[actor_index].var_150--;
        if ((gActors[actor_index].var_150 <= 0) || (gActors[actor_index].health < 0)) {
            func_8005C550(actor_index, 0x3C);
            Sound_StopSfx(0x65);
            if (gActors[actor_index].health < 0) {
                func_800575C0(actor_index);
                Sound_PlaySfx(0x3C);
            }
            if (!(gActors[actor_index].unk_0DC & 1)) {
                gActors[actor_index].state = 0x30;
            }
            else {
                gActors[actor_index].state = 0x31;
            }
        }
        break;
    }
}

void func_8005878C(u16 actor_index) {
    if (1) { } // fakematch
    gActors[actor_index].unk_12E_u8 |= 0x41;
    if (D_801370CE != 0) {
        gActors[actor_index].unk_170_s8[0] = 0x7F;
        gActors[actor_index].var_150 -= 10;
    }
    if (gActors[actor_index].stateUpper == 0) {
        func_8005C550(actor_index, -8);
        if (func_8005D418(actor_index) != 0) {
            gActors[actor_index].var_150--;
            if (gActors[actor_index].var_150 <= 0) {
                if (func_8005D338(actor_index) == 0x9A) {
                    gActors[actor_index].unk_170 = 0x9C;
                }
                if (func_8005D338(actor_index) == 0x9B) {
                    gActors[actor_index].unk_170 = 0x9D;
                }
                gActors[actor_index].unk_17C = 0;
                gActors[actor_index].unk_17C_s8[1] = 2;
                func_8005C550(actor_index, 0x1E);
                gActors[actor_index].stateUpper = 1;
            }
        }
    }
    else if ((gActors[actor_index].stateUpper == 1) && (func_8005D418(actor_index))) {
        if (gActors[actor_index].health >= 0) {
            gActors[actor_index].state = 3;
        }
        else if (gGameState == 6) {
            gGameState = 7;
            gGameStateSubState = 0;
            gActors[actor_index].var_150 = gActors[actor_index].flags & ~0x1B80;
            gActors[actor_index].unk_170 = 0xA4;
            Sound_PlaySfx(0xB2);
            gActors[actor_index].stateUpper = 6;
            gActors[actor_index].stateLower = 1;
        }
    }
}

void func_80058924(u16 actor_index) {
    gActors[actor_index].flags &= 0xFDFFB53F;
}

void func_8005896C(s32 arg0, s32 arg1) {
}

void func_80058978(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    if (!(gActors[actor_0].flags & 0x20)) {
        gActors[actor_0].unk_0F8.raw = -0x18000;
    }
    else {
        gActors[actor_0].unk_0F8.raw = 0x18000;
    }
    gActors[actor_0].unk_0FC.raw = 0x30000;
    gActors[actor_0].iFrames = 0x78;
    gActors[actor_0].state = 0x31;
}

void func_80058A38(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    if (!(gActors[actor_0].unk_0DC & 1)) {
        gActors[actor_0].state = 0x30;
    }
    else {
        gActors[actor_0].state = 0x31;
    }
}

void func_80058AE0(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    gActors[actor_0].state = 0x31;
}

void func_80058B68(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    if (!(gActors[actor_0].unk_0DC & 1)) {
        gActors[actor_0].state = 0x33;
    }
    else {
        gActors[actor_0].state = 0x34;
    }
    func_8005C098(actor_0, 3);
    gActors[actor_0].unk_144 = D_800EBEBC;
}

void func_80058C24(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        actor_0 = actor_0;
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    gActors[actor_0].state = 0x35;
}

void func_80058CAC(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    gActors[actor_0].state = 0x32;
    gActors[actor_0].var_158 = 0x2000;
}

void func_80058D3C(u16 actor_0, u16 actor_1) {
    gActors[actor_0].flags &= ~0x4AC0;
    if (!(gActors[actor_0].flags & 0x20)) {
        gActors[actor_0].velocityX.raw += gActors[actor_0].unk_0F8.raw;
    }
    else {
        gActors[actor_0].velocityX.raw -= gActors[actor_0].unk_0F8.raw;
    }
    if (gActors[actor_0].flags & 0x810000) {
        if (gActors[actor_0].unk_140_u8[0] == 0) {
            gActors[actor_0].unk_170 = 0x2C;
        }
        else {
            gActors[actor_0].unk_170 = 0x2B;
        }
    }
    else {
        gActors[actor_0].velocityY.raw += gActors[actor_1].unk_0FC.raw;
    }
    gActors[actor_0].velocityX.raw = Math_ClampLimit(gActors[actor_0].velocityX.raw, 0x60000);
    gActors[actor_0].velocityY.raw = Math_ClampLimit(gActors[actor_0].velocityY.raw, 0x80000);
}

void func_80058E44(u16 arg0, u16 arg1) {
    func_80058924(arg0);
    gActors[arg0].unk_0F8.raw = -gActors[arg0].unk_0F8.raw;
    gActors[arg0].unk_0FC.raw = gActors[arg0].unk_0FC.raw;
    gActors[arg0].state = 0x2B;
}

void func_80058EB0(u16 actor_0, u16 unused_arg1) {
    if (gActors[actor_0].flags & 0x02000000) {
        func_8004F514(actor_0, gActors[actor_0].unk_0D6);
    }
    func_80058924(actor_0);
    gActors[actor_0].flags &= ~0x1501;
    gActors[actor_0].var_150 = gActors[actor_0].flags;
    gActors[actor_0].stateUpper = 4;
    gActors[actor_0].stateLower = 1;
}

void func_80058F54(u16 actor_0, u16 unused_arg1) {
    gActors[actor_0].unk_0F8.raw = gActors[actor_0].velocityX.raw;
    gActors[actor_0].state = 0x2A;
}

s32 func_80058F9C(u16 actor_index) {
    u16 sp26;
    s32 sp20;

    sp26 = gActors[actor_index].unk_0D6;
    if (gActors[actor_index].unk_12E_u8 & 2) {
        gActors[actor_index].flags_098 |= 0x10000;
    }
    if (gActors[actor_index].flags_098 & 0x200) {
        if (gActors[actor_index].stateLower != 0x2F) {
            if (gActors[actor_index].flags & 0x02000000) {
                func_8004F514(actor_index, gActors[actor_index].unk_0D6);
            }
            func_80058924(actor_index);
            gActors[actor_index].flags &= 0xFF3CFFFF;
            gActors[actor_index].flags &= 0xFF3CFFFF; \
            gActors[actor_index].flags |= 0x20000;
            gActors[actor_index].velocityZ.raw = 0;
            gActors[actor_index].velocityY.raw = 0;
            gActors[actor_index].velocityX.raw = 0;
            gActors[actor_index].unk_170 = 0x9E;
            gActors[actor_index].unk_17C = 6;
            Sound_PlaySfx(0x2F);
            gActors[actor_index].state = 0x2F;
        }
        return 1;
    }
    if (gActors[actor_index].iFrames != 0) {
        gActors[actor_index].unk_180_u8[3] = 6;
        gActors[actor_index].iFrames--;
    }
    else if (D_801373E0.unk_08 != 0) {
        D_801373E0.unk_08 -= 1;
    }
    if (!(gActors[actor_index].flags_098 & 2)) {
        return 0;
    }
    if (gActors[actor_index].unk_0DD == 0x13) {
        func_80058EB0(actor_index, sp26);
        return 1;
    }
    if (gActors[actor_index].health < 0) {
        return 1;
    }
    if (gActors[actor_index].flags & 0x8000) {
        return 0;
    }
    gActors[actor_index].unk_12C_u16[0] = 0;
    gActors[actor_index].unk_12E_u8 = 0xFF;
    gActors[actor_index].unk_17C = 0;
    D_801373E0.unk_13 = 0;
    if (gActors[actor_index].unk_0DC & 8) {
        D_801373E0.unk_08 += 0x200;
        if (D_801373E0.unk_08 >= 0x801) {
            D_801373E0.unk_08 = 0;
            gActors[actor_index].iFrames = 0;
            func_8005C550(actor_index, 0x12C);
            func_800575C0(actor_index);
            Sound_PlaySfx(0x63);
        }
    }
    if ((gActors[actor_index].unk_0DD < 12) || (gActors[actor_index].unk_0DD > 14)) {
        sp20 = func_8005739C(actor_index, gActors[actor_index].pendingDamage);
        gActors[actor_index].pendingDamage = 0;
        gActors[actor_index].unk_0DC &= 0xFF7F;
        if (sp20 >= 3) {
            func_800575C0(actor_index);
            if (sp20 == 3) {
                Sound_PlaySfx(0x3C);
            }
        }
    }
    if ((gActors[actor_index].stateLower == 0x31) || (gActors[actor_index].stateLower == 0x32)) {
        func_800575C0(actor_index);
    }
    D_800D3F70[gActors[actor_index].unk_0DD](actor_index, sp26);
    if (gActors[actor_index].unk_0DD == 0x11) {
        return 0;
    }
    else {
        return 1;
    }
}

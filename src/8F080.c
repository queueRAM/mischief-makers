#include "common.h"
#include "actor.h"

extern s16 D_800E5E48[];
extern u8 D_800E8BEC[];
extern u8 D_800E9654[];
extern u8 D_800E9634[];
extern u8 D_800E9700[];
extern u8 D_800E9720[];
extern u8 D_800E9414[];
extern u8 D_800E93C4[];
extern u8 D_800E95E8[];
extern u8 D_800E961C[];
extern u8 D_800E8C08[];
extern u16 D_800E8D8C[];
extern f32 D_800E90E8[];

// TODO: func_8001FCA0 only matches if arg1/arg2 are `s16`, but only matches below as `s32`
u8 func_8001FCA0(u16 arg0, s32 arg1, s32 arg2); // arg1/arg2: s16 -> s32

extern void func_8008105C(u16 actor_index, void* arg1, void* arg2);

extern void func_8008FB20(u16 actor_index);
extern void func_8008FD08(u16 actor_index);
extern void func_80090064(u16 actor_index);
extern void func_800902B0(u16 actor_index);
extern void func_80090558(u16 actor_index);
extern s32 func_80092FD4(u16);

s32 func_8008E480(u16 actor_index) {
    f32 temp_f4;
    s32 y;
    s32 x;
    u8 temp_s3;
    u8 temp_t4;
    u16 index;

    x = (30.0f * gActors[actor_index + 1].unk_130) + gActors[actor_index].posX.whole;
    y = gActors[actor_index].hitboxBY1 + gActors[actor_index].posY.whole + 1;
    for (index = 0; index != 3; index++) {
        if (func_8001FCA0(actor_index, x, y) & 0x80) {
            break;
        }
        y += 0xF;
    }
    
    if (index != 3) {
        y = gActors[actor_index].hitboxBY0 + 8;
        for (index = 6; index > 0; index--) {
            if ((func_8001FCA0(actor_index, gActors[actor_index].posX.whole, gActors[actor_index].posY.whole + y) & 0x80)) {
                break;
            }
            temp_s3 = func_8001FCA0(actor_index, gActors[actor_index].posX.whole + (gActors[actor_index + 1].unk_130 * 31.0f), gActors[actor_index].posY.whole + y) & 0x80;
            temp_t4 = func_8001FCA0(actor_index, gActors[actor_index].posX.whole + (gActors[actor_index + 1].unk_130 * 16.0f), gActors[actor_index].posY.whole + y) & 0x80;
            if ((temp_s3 == 0) && (temp_t4 == 0)) {
                gActors[actor_index].state = 0x170;
                y += 8;
                temp_f4 = 32.0f;
                temp_f4 *= y * 0x10;
                temp_f4 = ((sqrtf((temp_f4) + 16.0f) - 4.0f) / 8);
                gActors[actor_index + 2].unk_180 = (gActors[actor_index + 1].unk_130 * 98304.0f);
                gActors[actor_index + 3].unk_180 = (temp_f4 * 17408.0f);
                return FALSE;
            }
            y += 0x10;
        }
    }
    return TRUE;
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/RkfHg
u16 func_8008E790(u16 arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    u16 var_a2;
    u16 temp_v0;
    s32 pad;

    temp_v0 = func_80029FB8(arg0, arg3, arg4, arg5, arg6);
    var_a2 = arg1;
    if (temp_v0 & 0x8000) {
        if ((((gActors[arg0].flags & 0x20) == 0) && (temp_v0 & 1)) || 
            (((gActors[arg0].flags & 0x20) != 0) && !(temp_v0 & 1))) {
            var_a2 = arg2;
        }
        if ((gActors[arg0].state == 0x111) || (gActors[arg0].state == 0x131) || (gActors[arg0].state == 0x141)) {
            if (arg2 != var_a2) {
                if ((func_8008E480(arg0)) && (gActors[arg0].state != (var_a2 + 1))) {
                    gActors[arg0].state = var_a2;
                }
            }
            else if (gActors[arg0].state != (var_a2 + 1)) {
                gActors[arg0].state = var_a2;
            }
        }
    }
    else {
        if ((gActors[arg0].state == 0x131) || (gActors[arg0].state == 0x141)) {
            gActors[arg0].state = 0x110;
        }
    }
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008E790.s")
#endif

void func_8008E918(u16 actor_index) {
    func_80081790(actor_index, D_800E8BEC);
}

s32 func_8008E948(u16 actor_index) {
    u16 actor_1;

    actor_1 = (u16)gActors[actor_index + 2].var_110;
    if ((actor_1 != PLAYER_INDEX) && (gActors[actor_1].flags_098 & ACTOR_FLAG3_UNK0)) {
        return TRUE;
    }
    return FALSE;
}

void func_8008EA4C(u16 actor_index) {
    u16 actor_1;

    actor_1 = (u16)gActors[actor_index + 2].var_110;
    if (actor_1 != 0) {
        gActors[actor_1].flags &= ~(ACTOR_FLAG_UNK11 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK7);
    }
    gActors[actor_index + 2].var_110 = 0;
}

void func_8008EB44(u16 actor_index) {
    func_8008EA4C(actor_index);
    gActors[actor_index].unk_170 = 0;
    gActors[actor_index].iFrames = 7;
    gActors[actor_index].flags &= ~(ACTOR_FLAG_UNK15 | ACTOR_FLAG_UNK11 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK8 | ACTOR_FLAG_UNK7);
    gActors[actor_index].velocityX.raw = 0;
    gActors[actor_index].velocityY.raw = 0;
    if (gActors[actor_index].unk_0F8.raw != 0) {
        if (((gActors[actor_index].flags & ACTOR_FLAG_FLIPPED) == 0 && (gActors[actor_index].unk_0F8.raw > 0)) ||
            ((gActors[actor_index].flags & ACTOR_FLAG_FLIPPED) != 0 && (gActors[actor_index].unk_0F8.raw < 0))) {
            gActors[actor_index].flags ^= ACTOR_FLAG_FLIPPED;
        }
    }
}

void func_8008EBF0(u16 actor_index) {
    func_8008EB44(actor_index);
    Actor_Clamp_0F8(actor_index, FIXED_UNIT(2.0));
    if (gActors[actor_index].flags & ACTOR_FLAG_UNK17) {
        gActors[actor_index].state = 0x1F0;
        gActors[actor_index].unk_0FC.raw = FIXED_UNIT(1.5);
        gActors[actor_index + 5].unk_180 = (s32)D_800E8D8C;
    }
    else {
        gActors[actor_index].state = 0x1E0;
        gActors[actor_index].unk_0FC.raw = 0;
        gActors[actor_index + 5].unk_180 = (s32)D_800E8D8C;
    }
}

void func_8008ECDC(u16 actor_index) {
    func_8008EB44(actor_index);
    gActors[actor_index].state = 0x200;
    gActors[actor_index + 5].unk_180 = (s32)D_800E8D8C;
    Actor_Clamp_0F8(actor_index, 0x40000);
    gActors[actor_index].unk_0FC.raw = 0x28000;
    gActors[actor_index].flags |= ACTOR_FLAG_UNK17;
    gActors[actor_index].flags &= ~ACTOR_FLAG_UNK16; \
    gActors[actor_index].flags_098 &= ~ACTOR_FLAG3_UNK5;
}

s32 func_8008EDB0(u16 actor_index) {
    s32 pad;
    if ((gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK1) && !(gActors[actor_index].flags & ACTOR_FLAG_UNK15)) {
        switch (gActors[actor_index].unk_0DD) {
        case 20:
        case 21:
        case 22:
        case 23:
            return FALSE;
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            func_8008EBF0(actor_index);
            Sound_PlaySfxAtActor2(0x9D, actor_index);
            break;
        case 6:
        case 7:
        case 8:
            func_8008ECDC(actor_index);
            Sound_PlaySfxAtActor2(0x9D, actor_index);
            break;
        case 9:
        case 10:
        case 11:
            func_8008ECDC(actor_index);
            Sound_PlaySfxAtActor2(0x9D, actor_index);
            break;
        case 12:
        case 13:
        case 14:
            func_8008ECDC(actor_index);
            Sound_PlaySfxAtActor2(0x9D, actor_index);
            break;
        case 19:
            Sound_PlaySfxAtActor2(0x9D, actor_index);
            gActors[actor_index].flags = 0;
            gActors[actor_index].health = 0;
            break;
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
}

s32 func_8008EEF8(u16 actor_index) {
    if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK9) {
        Sound_PlaySfxAtActor2(0x2F, actor_index);
        func_8008EA4C(actor_index);
        gActors[actor_index].state = 0x1B0;
        gActors[actor_index].flags &= ~(ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK7);
        gActors[actor_index].flags |= ACTOR_FLAG_UNK17;
        gActors[actor_index].velocityX.raw = 0;
        gActors[actor_index].velocityY.raw = 0;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

s32 func_8008EFA8(u16 actor_index) {
    if (((u16)gActors[actor_index].var_110 & 0x80) == 0) {
        if (gActors[actor_index].health == 0) {
            gActors[actor_index].state = 0x250;
            gActors[actor_index].iFrames = 0x2710;
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_8008F094(u16 actor_index, u16 arg1) {
    gActors[actor_index].health -= arg1;
    if (gActors[actor_index].health & 0x8000) {
        gActors[actor_index].health = 0;
    }

    return func_8008EFA8(actor_index);
}

void func_8008F108(u16 actor_index) {
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, FIXED_UNIT(1.0));
}

s32 func_8008F168(u16 actor_index) {
    if (func_8008EFA8(actor_index)) {
        return 4;
    }
    if (func_8008EEF8(actor_index)) {
        return 1;
    }
    if (func_8008EDB0(actor_index)) {
        return 2;
    }
    if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK6) {
        gActors[actor_index].state = 0x150;
        return 3;
    }
    return 0;
}

s32 func_8008F220(u16 actor_index) {
    if (func_8008EFA8(actor_index)) {
        return 4;
    }
    if (func_8008EEF8(actor_index)) {
        return 1;
    }
    if (func_8008EDB0(actor_index)) {
        return 2;
    }
    return 0;
}

void func_8008F294(u16 actor_index) {
    if (gActors[actor_index].unk_11C < 0.0f) {
        gActors[actor_index].state = 0x110;
    }
}

u16 func_8008F2E8(u16 actor_0, u16 actor_1) {
    u16 index;
    s32 temp;
    s32 temp_t5;
    s32 x;
    s32 y;

    temp_t5 = (gActors[actor_1].flags & ACTOR_FLAG_FLIPPED) ? (0x200 - gActors[actor_1].var_150) : gActors[actor_1].var_150;
    temp_t5 = (temp_t5 + 0x40) & 0x380;
    index = 0;
    x = (COS(temp_t5) * 524288.0f * gActors[actor_1].scaleX) + gActors[actor_1].posX.raw;
    y = (SIN(temp_t5) * 524288.0f * gActors[actor_1].scaleX) + gActors[actor_1].posY.raw;
    temp = temp_t5 << 0x10;
    if (gActors[actor_0 + 2].unk_180 == 0) {
        index = Actor_RangeFindInactive(0x70, 0x7A);
        if (index != 0) {
            func_8002DB0C(index, 0, temp, x, y, gActors[actor_1].posZ.raw);
        }
    }
    return index;
}

void func_8008F498(u16 actor_index, u16 list_index) {
    gActors[actor_index + 0x1].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x1].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x3].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x3].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x4].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x4].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x5].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x5].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x7].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x7].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0xD].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0xD].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0xF].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0xF].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x11].scaleX *= D_800E90E8[list_index++];
    gActors[actor_index + 0x11].scaleY *= D_800E90E8[list_index++];
    gActors[actor_index + 0x8].scaleX = gActors[actor_index + 0x4].scaleX;
    gActors[actor_index + 0x9].scaleX = gActors[actor_index + 0x5].scaleX;
    gActors[actor_index + 0xB].scaleX = gActors[actor_index + 0x7].scaleX;
    gActors[actor_index + 0x8].scaleY = gActors[actor_index + 0x4].scaleY;
    gActors[actor_index + 0x9].scaleY = gActors[actor_index + 0x5].scaleY;
    gActors[actor_index + 0xB].scaleY = gActors[actor_index + 0x7].scaleY;
    gActors[actor_index + 0x13].scaleX = gActors[actor_index + 0xD].scaleX;
    gActors[actor_index + 0x15].scaleX = gActors[actor_index + 0xF].scaleX;
    gActors[actor_index + 0x17].scaleX = gActors[actor_index + 0x11].scaleX;
    gActors[actor_index + 0x13].scaleY = gActors[actor_index + 0xD].scaleY;
    gActors[actor_index + 0x15].scaleY = gActors[actor_index + 0xF].scaleY;
    gActors[actor_index + 0x17].scaleY = gActors[actor_index + 0x11].scaleY;
}

void func_8008F734(u16 actor_index) {
    if (gActors[actor_index].unk_16C & 0x100) {
        gActors[actor_index + 0xA].unk_13C_f32 = 12.0f;
    }
    else if (gActors[actor_index].unk_16C & 0x200) {
        gActors[actor_index + 0xA].unk_13C_f32 = 5.0f;
    }
}

void func_8008F7E0(u16 actor_index) {
    u16 temp_v0;
    if (gActors[actor_index].state >= 0x101) {
        gActors[actor_index].posZ.raw = 0xEFFF;
        gActors[actor_index + 1].unk_180 &= ~0x800300; // 1.0x180
        if (!((u16)gActors[actor_index].var_110 & 0x1000)) {
            temp_v0 = func_8002877C(actor_index);
            if (temp_v0 != 0) {
                if (temp_v0 & 1) {
                    gActors[actor_index + 1].unk_180 |= 0x100;
                }
                else {
                    gActors[actor_index + 1].unk_180 |= 0x200;
                }
            }
        }
        D_800E3580 = 0;
        func_8002AA20(actor_index, 0);
        if (gActors[actor_index].iFrames > 0) {
            gActors[actor_index].iFrames--;
        }
        func_800819A8(actor_index, D_800E5E48);
        gActors[actor_index + 1].unk_12C = gActors[actor_index].unk_168 / 10000.0f;
        gActors[actor_index + 1].unk_12C *= gActors[actor_index].unk_120;
    }
    else if (gActors[actor_index].state != 0) {
        func_800819A8(actor_index, D_800E5E48);
        gActors[actor_index + 1].unk_12C = gActors[actor_index].unk_168 / 10000.0f;
        gActors[actor_index + 1].unk_12C *= gActors[actor_index].unk_120;
    }
}

void func_8008FA50(s32 arg0_unused, u16 actor_index, u16* graphic_indices) {
    s32 var_a0;
    u16 index;

    gActors[actor_index].unk_138 = -gActors[actor_index].var_154 / FIXED_UNIT(1.0);
    var_a0 = 0;
    for (index = 0; graphic_indices[index] != 0; index++) {
        if (gActors[actor_index].var_154 < var_a0) {
            gActors[actor_index].graphicIndex = graphic_indices[index];
            return;
        }
        var_a0 += FIXED_UNIT(4.0);
    }
    gActors[actor_index].graphicIndex = graphic_indices[index - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008FB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8008FD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800902B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800907E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80090F48.s")

void func_80091158(u16 actor_index) {
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, 0x800);
    if (gActors[actor_index].velocityY.raw > FIXED_UNIT(-6.5)) {
        gActors[actor_index].velocityY.raw -= FIXED_UNIT(0.265625);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800911D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800913C0.s")

void func_80091524(u16 actor_index) {
    if (!func_8008F168(actor_index)) {
        if (gActors[actor_index].unk_11C < 0.0f) {
            gActors[actor_index].state = 0x110;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009159C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800918D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800919C8.s")

void func_80091BDC(u16 actor_index);
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800922D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800923C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800924F8.s")

void func_800925D8(u16 actor_index) {
    if (!func_8008F168(actor_index)) {
        if (gActors[actor_index].state == 0x220) {
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800929B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80092FD4.s")

void func_800930AC(u16 arg0) {
    if (func_80092FD4(arg0)) {
        func_8005DFC8(0);
    }
}

void func_800930E4(u32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800930EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800931CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009333C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009349C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009351C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800935B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094E10.s")

void func_80094EB8(u16 actor_index) {
    if (func_80029B00(0x50, 0x40, -0x40)) {
        gActors[actor_index].flags_098 |= ACTOR_FLAG3_UNK18;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800955F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80095928.s")

void func_80095A10(u16 actor_index) {
    gActors[actor_index].unk_118 += gActors[actor_index].unk_114;
    if (gActors[actor_index].unk_118 > 360.0f) {
        gActors[actor_index].unk_118 -= 360.0f;
        Sound_PlaySfx2(0x116);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80095A8C.s")

void func_80095FC8(u16 actor_index) {
    gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
    func_8008105C(actor_index, D_800E9414, D_800E93C4);
    gActors[actor_index].unk_178 = (intptr_t)D_800E961C;
    func_80081790(actor_index, D_800E95E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800962C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009672C.s")

void func_8009685C(u16 actor_index) {
    gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
    func_8008105C(actor_index, D_800E9654, D_800E9634);
    gActors[actor_index].unk_178 = (intptr_t)D_800E9720;
    func_80081790(actor_index, D_800E9700);
}

void func_800968EC(u16 actor_index) {
    func_800819A8(actor_index, D_800E9654);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_8009691C.s")

void func_800969CC(u16 actor_index) {
    func_80090558(actor_index);
}

void func_800969F4(u16 arg0) {
}

void func_800969FC(u16 arg0) {
}

void func_80096A04(u16 arg0) {
}

void func_80096A0C(u16 arg0) {
}

void func_80096A14(u16 arg0) {
}

void func_80096A1C(u16 actor_index) {
    gActors[actor_index + 1].var_0D8 = 1;
    func_8008FB20(actor_index);
}

void func_80096A70(u16 actor_index) {
    gActors[actor_index + 1].var_0D8 = 2;
    func_8008FD08(actor_index);
}

void func_80096AC4(u16 actor_index) {
    gActors[actor_index + 1].var_0D8 = 3;
    func_80090064(actor_index);
}

void func_80096B18(u16 actor_index) {
    gActors[actor_index + 1].var_0D8 = 5;
    func_800902B0(actor_index);
}

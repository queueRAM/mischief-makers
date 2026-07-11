#include "common.h"
#include "actor.h"
#include "cosine.h"

extern u16 D_800D1C04[];
extern u16 D_800D9284[];
extern u16 D_800D98F4[];
extern u16 D_800D99A4[];
extern u16 D_800DB67C[];
extern u16 D_800DB87C[];

extern s16 D_800E2364[];
extern u16 D_800E5B00[];
extern u16 D_800E5B8C[];
extern u16 D_800E5C18[];
extern u16 D_800E5CA4[];
extern u16 D_800E5D30[];
extern u16 D_800E5DBC[];
extern u16 D_800E5E48[];
extern u16 D_800E5E48[];
extern u16 D_800E8820[];
extern u16 D_800E89D4[];
extern u16 D_800E8A08[];
extern u16 D_800E8A48[];
extern u16 D_800E8AA8[];
extern u16 D_800E8B98[];
extern u16 D_800E8BD0[];
extern u16 D_800E8BEC[];
extern u16 D_800E8C08[];
extern u16 D_800E8C18[];
extern u16 D_800E8C2C[];
extern u16 D_800E8C40[];
extern u16 D_800E8C7C[];
extern u16 D_800E8CE4[];
extern u16 D_800E8CF8[];
extern u16 D_800E8D1C[];
extern u16 D_800E8D3C[];
extern u16 D_800E8D4C[];
extern u16 D_800E8D60[];
extern u16 D_800E8D60[];
extern u16 D_800E8D8C[];
extern u16 D_800E8DB8[];
extern u16 D_800E8DCC[];
extern u16 D_800E8E38[];
extern u16 D_800E8EAC[];
extern u16 D_800E8EAC[];
extern u16 D_800E8EC8[];
extern u16 D_800E8F4C[];
extern u16 D_800E8F60[];
extern u16 D_800E8F60[];
extern u16 D_800E8FA4[];
extern u16 D_800E8FC0[];
extern u16 D_800E8FF8[];
extern u16 D_800E9034[];
extern u16* D_800E905C[];
extern f32 D_800E90E8[];
extern u16 D_800E91E8[];
extern u16 D_800E91F0[];
extern u16 D_800E91F8[];
extern u16 D_800E9204[];
extern u16 D_800E9210[];
extern u16 D_800E921C[];
extern u16 D_800E9224[];
extern u16 D_800E922C[];
extern u16 D_800E9248[];
extern u16 D_800E9260[];
extern u16 D_800E927C[];
extern u16 D_800E928C[];
extern u16 D_800E92AC[];
extern u16 D_800E92C4[];
extern u16 D_800E92E0[];
extern u16 D_800E92E4[];
extern u16 D_800E9300[];
extern ActorFunc D_800E9320[];
extern u16 D_800E93BC;
extern u16 D_800E93C0;
extern u8 D_800E9414[];
extern u8 D_800E9654[];
extern u8 D_800E9634[];
extern u8 D_800E9700[];
extern u8 D_800E9720[];
extern u8 D_800E93C4[];
extern u8 D_800E95E8[];
extern u8 D_800E961C[];

extern s16 D_801826B0;
extern u16 D_801826B2;
extern u16 D_801826B4;
extern f32 D_801826B8;

extern u16 D_80335ED4;

// TODO: func_8001FCA0 only matches if arg1/arg2 are `s16`, but only matches below as `s32`
u8 func_8001FCA0(u16 arg0, s32 arg1, s32 arg2); // arg1/arg2: s16 -> s32

extern void func_8008105C(u16 actor_index, void* arg1, void* arg2);

extern void func_8008FB20(u16 actor_index);
extern void func_8008FD08(u16 actor_index);
extern void func_80090064(u16 actor_index);
extern void func_800902B0(u16 actor_index);
extern void func_80090558(u16 actor_index);
extern s32 func_80092FD4(u16);
void func_80094F24(u16 arg0, s32 arg1);

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

u16 func_8008E790(u16 actor_index, u16 state_1, u16 state_2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    u16 temp_v0;

    temp_v0 = func_80029FB8(actor_index, arg3, arg4, arg5, arg6);
    if (temp_v0 & 0x8000) {
        if (((gActors[actor_index].flags & 0x20) == 0 && (temp_v0 & 1) != 0) || 
            ((gActors[actor_index].flags & 0x20) != 0 && (temp_v0 & 1) == 0)) {
            state_1 = state_2;
        }
        switch (gActors[actor_index].state) {
        case 0x111:
        case 0x131:
        case 0x141:
            if (state_1 != state_2) {
                if ((func_8008E480(actor_index)) && (gActors[actor_index].state != (state_1 + 1))) {
                    gActors[actor_index].state = state_1;
                }
            }
            else if (gActors[actor_index].state != (state_1 + 1)) {
                gActors[actor_index].state = state_1;
            }
            break;
        }
    }
    else {
        switch (gActors[actor_index].state) {
        case 0x131:
        case 0x141:
            gActors[actor_index].state = 0x110;
            break;
        }
    }
    return temp_v0;
}

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

// needs return to match some callers
s32 func_8008F108(u16 actor_index) {
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

void func_8008FA50(u16 arg0_unused, u16 actor_index, u16* graphic_indices) {
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

void func_8008FB20(u16 actor_index) {
    f32 temp_f0;
    f32 scale;

    temp_f0 = gActors[actor_index].unk_168 / 10000.0f;
    scale = temp_f0 * 0.7;
    func_80032E60(actor_index + 8, 0x182A, 0x300, 3.0f * temp_f0, -1, scale, scale);
    gActors[actor_index].colorR = 0x18;
    gActors[actor_index].colorG = 0x18;
    gActors[actor_index].colorB = 0x18;
    Actor_SetColorRgb(actor_index + 8, 0);
    Actor_SetColorRgb(actor_index + 0xB, 0);
    Actor_SetColorRgb(actor_index + 0x13, 0);
    Actor_SetColorRgb(actor_index + 0x15, 0);
    Actor_SetColorRgb(actor_index + 0x17, 0);
    func_8008FA50(actor_index, actor_index + 3, D_800E9210);
    func_8008FA50(actor_index, actor_index + 7, D_800E921C);
    func_8008FA50(actor_index, actor_index + 0xB, D_800E9224);
    *((u16*)0x80335ED4) = func_8004571C();
    gActors[actor_index + 3].unk_138 = -gActors[actor_index + 3].var_154 / FIXED_UNIT(1.0);
}

void func_8008FD08(u16 actor_index) {
    f32 scale;

    scale = gActors[actor_index].unk_168 / 10000.0f;
    func_80032E60(actor_index + 3, 0x1044, 0x120, 9.0f * scale, 1, scale, scale);
    func_80032E60(actor_index + 3, 0x1042, 0x180, 8.0f * scale, 0, scale, scale);
    func_80032E60(actor_index + 3, 0x1048, 0x190, 13.0f * scale, 2, scale, scale);
    func_80032E60(actor_index + 3, 0x104A, 0x1B8, 21.0f * scale, 2, scale, scale);
    gActors[actor_index + 0x1].scaleX *= 1.2;
    gActors[actor_index + 0x5].scaleX *= 0.7;
    gActors[actor_index + 0x9].scaleX *= 0.7;
    gActors[actor_index + 0x4].scaleX *= 0.6;
    gActors[actor_index + 0x4].scaleY = gActors[actor_index + 0x4].scaleX;
    gActors[actor_index + 0x8].scaleX *= 0.6;
    gActors[actor_index + 0x8].scaleY = gActors[actor_index + 0x8].scaleX;
    gActors[actor_index + 0xD].scaleX *= 0.8;
    gActors[actor_index + 0x13].scaleX *= 0.8;
    gActors[actor_index + 0xF].scaleY *= 1.3;
    gActors[actor_index + 0x15].scaleY *= 1.3;
    gActors[actor_index + 0x8].graphicFlags |= 0x10;
    gActors[actor_index + 0xB].graphicFlags |= 0x10;
    gActors[actor_index + 0x13].graphicFlags |= 0x10;
    gActors[actor_index + 0x15].graphicFlags |= 0x10;
    Actor_SetColorRgb(actor_index + 8, 0x20);
    Actor_SetColorRgb(actor_index + 0xB, 0x20);
    Actor_SetColorRgb(actor_index + 0x13, 0x20);
    Actor_SetColorRgb(actor_index + 0x15, 0x20);
    func_8008FA50(actor_index, actor_index + 7, D_800E91E8);
    func_8008FA50(actor_index, actor_index + 0xB, D_800E91F0);
    gActors[actor_index + 0x3].unk_138 = -gActors[actor_index + 0x3].var_154 / FIXED_UNIT(1.0);
    gActors[actor_index + 0x6].unk_138 = -1.0f;
    gActors[actor_index + 0xA].unk_138 = -1.0f;
    gActors[actor_index + 0x2].unk_138 = -1.0f;
}

void func_80090064(u16 actor_index) {
    gActors[actor_index + 0x4].scaleX *= 0.8;
    gActors[actor_index + 0x4].scaleY = gActors[actor_index + 0x4].scaleX;
    gActors[actor_index + 0x8].scaleX *= 0.8;
    gActors[actor_index + 0x8].scaleY = gActors[actor_index + 0x8].scaleX;
    gActors[actor_index + 0x5].scaleX *= 0.7;
    gActors[actor_index + 0x9].scaleX *= 0.7;
    gActors[actor_index + 0x7].scaleX *= 0.75;
    gActors[actor_index + 0x7].scaleY *= 0.7;
    gActors[actor_index + 0xB].scaleX *= 0.75;
    gActors[actor_index + 0xB].scaleY *= 0.7;
    gActors[actor_index + 0xF].scaleY *= 1.3;
    gActors[actor_index + 0x15].scaleY *= 1.3;
    func_8008FA50(actor_index, actor_index + 0x7, D_800E91F8);
    func_8008FA50(actor_index, actor_index + 0xB, D_800E9204);
    if (gActors[actor_index].palette_18C == NULL) {
        gActors[actor_index + 0x4].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x7].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x8].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0xB].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x4].palette_18C = D_800DB87C;
        gActors[actor_index + 0x7].palette_18C = D_800DB87C;
        gActors[actor_index + 0x8].palette_18C = D_800DB87C;
        gActors[actor_index + 0xB].palette_18C = D_800DB87C;
    }
    gActors[actor_index + 0x3].unk_138 = -gActors[actor_index + 0x3].var_154 / FIXED_UNIT(1.0);
    gActors[actor_index + 0x2].unk_138 = -2.0f;
    gActors[actor_index + 0x6].unk_138 = -2.0f;
    gActors[actor_index + 0xA].unk_138 = -2.0f;
}

void func_800902B0(u16 actor_index) {
    f32 scale;

    scale = gActors[actor_index].unk_168 / 10000.0f;
    func_80032E60(actor_index + 3, 0x254, 0x118, 10.0f * scale, 1, scale, scale);
    gActors[actor_index + 0x4].scaleX *= 0.8;
    gActors[actor_index + 0x4].scaleY = gActors[actor_index + 0x4].scaleX;
    gActors[actor_index + 0x8].scaleX *= 0.8;
    gActors[actor_index + 0x8].scaleY = gActors[actor_index + 0x8].scaleX;
    gActors[actor_index + 0x5].scaleX *= 0.7;
    gActors[actor_index + 0x9].scaleX *= 0.7;
    gActors[actor_index + 0x7].scaleX *= 0.75;
    gActors[actor_index + 0x7].scaleY *= 0.8;
    gActors[actor_index + 0xB].scaleX *= 0.75;
    gActors[actor_index + 0xB].scaleY *= 0.8;
    gActors[actor_index + 0xF].scaleY *= 1.3;
    gActors[actor_index + 0x15].scaleY *= 1.3;
    func_8008FA50(actor_index, actor_index + 0x7, D_800E91F8);
    func_8008FA50(actor_index, actor_index + 0xB, D_800E9204);
    if (gActors[actor_index].unk_18C == 0) {
        gActors[actor_index + 0x4].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x7].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x8].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0xB].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index + 0x4].palette_18C = D_800DB67C;
        gActors[actor_index + 0x7].palette_18C = D_800DB67C;
        gActors[actor_index + 0x8].palette_18C = D_800DB67C;
        gActors[actor_index + 0xB].palette_18C = D_800DB67C;
    }
    gActors[actor_index + 0x3].unk_138 = -gActors[actor_index + 0x3].var_154 / FIXED_UNIT(1.0);
    gActors[actor_index + 0x6].unk_138 = -2.0f;
    gActors[actor_index + 0xA].unk_138 = -2.0f;
}

void func_80090558(u16 actor_index) {
    s32 pad;
    switch (gActors[actor_index + 1].var_0D8) {
    case 0:
        func_8008F734(actor_index);
        func_8008FA50(actor_index, actor_index + 0x7, D_800E91F8);
        func_8008FA50(actor_index, actor_index + 0xB, D_800E9204);
        gActors[actor_index + 3].unk_138 = -gActors[actor_index + 3].var_154 / FIXED_UNIT(1.0);
        break;
    case 1:
        func_8008FB20(actor_index);
        break;
    case 2:
        func_8008FD08(actor_index);
        break;
    case 3:
        func_80090064(actor_index);
        break;
    case 5:
        func_800902B0(actor_index);
        break;
    default:
        break;
    }
    if (gActors[actor_index].flags & ACTOR_FLAG_FLIPPED) {
        gActors[actor_index + 1].unk_130 = -1.0f;
        gActors[actor_index].unk_138 = 1.0f;
    }
    else {
        gActors[actor_index + 1].unk_130 = 1.0f;
        gActors[actor_index].unk_138 = 0.0f;
    }
    gActors[actor_index].hitboxBY0 = gActors[actor_index + 1].unk_12C * 18.0f;
    gActors[actor_index].hitboxBY1 = gActors[actor_index + 1].unk_12C * -16.0f;
    gActors[actor_index].hitboxBX0 = gActors[actor_index + 1].unk_12C * -8.0f;
    gActors[actor_index].hitboxBX1 = gActors[actor_index + 1].unk_12C * 8.0f;
    gActors[actor_index].flags_098 &= ~(ACTOR_FLAG3_UNK21 | ACTOR_FLAG3_UNK10 | ACTOR_FLAG3_UNK9);
}


void func_800907E4(u16 actor_index) {
    u16 index;

    gActors[actor_index].posZ.whole = 1;
    gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
    gActors[actor_index].flags = ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK12 | ACTOR_FLAG_UNK10 | ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
    gActors[actor_index].unk_0CE = 0xA;
    switch (gActors[actor_index + 1].var_0D8) {
    case 0:
        gActors[actor_index].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor_index].palette_18C = (u16*)0x80202C90;
        func_8008105C(actor_index, D_800E5E48, D_800E5B00);
        break;
    case 1:
        gActors[actor_index].palette_18C = NULL;
        func_8008105C(actor_index, D_800E5E48, D_800E5B8C);
        break;
    case 2:
        gActors[actor_index].palette_18C = NULL;
        func_8008105C(actor_index, D_800E5E48, D_800E5C18);
        break;
    case 3:
        gActors[actor_index].palette_18C = NULL;
        func_8008105C(actor_index, D_800E5E48, D_800E5D30);
        break;
    case 4:
        gActors[actor_index].palette_18C = NULL;
        func_8008105C(actor_index, D_800E5E48, D_800E5DBC);
        break;
    case 5:
        gActors[actor_index].palette_18C = NULL;
        func_8008105C(actor_index, D_800E5E48, D_800E5CA4);
        break;
    }
    if (gActors && gActors) {} // fakematch
    gActors[actor_index].unk_178 = (s32) D_800E8820;
    func_80081478(actor_index, D_800E5E48, 1);
    func_80081790(actor_index, D_800E89D4);
    func_800819A8(actor_index, D_800E5E48);
    gActors[actor_index].colorA = 0xFE;
    gActors[actor_index + 0xA].unk_180 = gActors[actor_index].posX.whole + (0, gScreenPosCurrentX.whole);
    gActors[actor_index + 0xB].unk_180 = gActors[actor_index].posY.whole + (0, gScreenPosCurrentY.whole);
    if (gActors[actor_index].graphicFlags & ACTOR_GFLAG_PALETTE) {
        index = ((gActors[actor_index].var_0D8 & 0x1F0) / 16) * 5;
        gActors[actor_index + 0x1].palette_18C = D_800E905C[index + 0];
        gActors[actor_index + 0x3].palette_18C = D_800E905C[index + 0];
        gActors[actor_index + 0x4].palette_18C = D_800E905C[index + 1];
        gActors[actor_index + 0x8].palette_18C = D_800E905C[index + 1];
        gActors[actor_index + 0x7].palette_18C = D_800E905C[index + 2];
        gActors[actor_index + 0xB].palette_18C = D_800E905C[index + 2];
        gActors[actor_index + 0xF].palette_18C = D_800E905C[index + 3];
        gActors[actor_index + 0x15].palette_18C = D_800E905C[index + 3];
        gActors[actor_index + 0x11].palette_18C = D_800E905C[index + 4];
        gActors[actor_index + 0x17].palette_18C = D_800E905C[index + 4];
    }
}

void func_80090A88(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x110:
            gActors[actor_index].state++;
            gActors[actor_index].flags |= ACTOR_FLAG_UNK12;
            switch (gActors[actor_index + 1].var_0D8) {
                case 3:
                case 5:
                    func_80081790(actor_index, D_800E8EAC);
                break;
                case 2:
                    func_80081790(actor_index, D_800E8F4C);
                break;
                default:
                    func_80081790(actor_index, D_800E89D4);
                break;
            }
            gActors[actor_index + 2].unk_180 = 0;
            // fallthrough
        case 0x111:
            if (gActors[actor_index + 2].unk_180 < 0x7FFF) {
                gActors[actor_index + 2].unk_180++;
            }
            func_8008F108(actor_index);
            break;
        }
    }
}

void func_80090BFC(u16 actor_index) {
    if (func_8008F168(actor_index) != 0) {
        return;
    }

    switch (gActors[actor_index].state) {
    case 0x120:
        gActors[actor_index].state++;
        func_80081790(actor_index, D_800E8A08);
        /* fallthrough */
    case 0x121:
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index].flags ^= ACTOR_FLAG_FLIPPED;
        }
        if (gActors[actor_index].unk_11C < 0.0f) {
            gActors[actor_index].state = 0x110;
        }
        break;
    }
}

void func_80090CDC(u16 actor_index) {
    if (func_8008F168(actor_index) != 0) {
        return;
    }

    switch (gActors[actor_index].state) {
    case 0x130:
        gActors[actor_index].state++;
        gActors[actor_index + 2].unk_180 = (65536.0f * gActors[actor_index + 1].unk_12C) * gActors[actor_index + 1].unk_130;
        gActors[actor_index].velocityX.raw = 0;
        if ((gActors[actor_index + 1].var_0D8 == 2) || (gActors[actor_index + 1].var_0D8 == 3) || (gActors[actor_index + 1].var_0D8 == 5)) {
            func_80081790(actor_index, D_800E8FA4);
        }
        else {
            func_80081790(actor_index, D_800E8A48);
        }
        /* fallthrough */
    case 0x131:
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index + 2].unk_180, 0, gActors[actor_index + 1].unk_12C * FIXED_UNIT(0.125));
        gActors[actor_index + 2].unk_180 = Math_ApproachS32(gActors[actor_index + 2].unk_180, 0, gActors[actor_index + 1].unk_12C * FIXED_UNIT(0.015625));
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index + 2].unk_180 = (77824.0f * gActors[actor_index + 1].unk_12C) * gActors[actor_index + 1].unk_130;
        }
        break;
    }
}


void func_80090F48(u16 actor_index) {
    if (func_8008F168(actor_index) != 0) {
        return;
    }

    switch (gActors[actor_index].state) {
    case 0x140:
        gActors[actor_index].state++;
        gActors[actor_index].velocityX.raw = 0;
        if ((gActors[actor_index + 1].var_0D8 == 2) || (gActors[actor_index + 1].var_0D8 == 3) || (gActors[actor_index + 1].var_0D8 == 5)) {
            func_80081790(actor_index, D_800E8F60);
        }
        else {
            func_80081790(actor_index, D_800E8AA8);
        }
        /* fallthrough */
    case 0x141:
        gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, gActors[actor_index + 1].unk_12C * FIXED_UNIT(0.0078125));
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index].velocityX.raw = FIXED_UNIT(2.0);
        }
        if (gActors[actor_index].unk_16C & 2) {
            gActors[actor_index].velocityX.raw = FIXED_UNIT(2.5);
        }
        if (gActors[actor_index].unk_16C & 3) {
            gActors[actor_index].velocityX.raw = (gActors[actor_index + 1].unk_12C * gActors[actor_index + 1].unk_130) * gActors[actor_index].velocityX.raw;
        }
        break;
    }
}

void func_80091158(u16 actor_index) {
    gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, FIXED_UNIT(0.03125));
    if (gActors[actor_index].velocityY.raw > FIXED_UNIT(-6.5)) {
        gActors[actor_index].velocityY.raw -= FIXED_UNIT(0.265625);
    }
}

s32 func_800911D8(u16 actor_index) {
    func_80091158(actor_index);
    if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK5) {
        if (gActors[actor_index].velocityY.raw < 0) {
            if (gActors[actor_index].velocityY.raw < FIXED_UNIT(-3.75)) {
                gActors[actor_index].state = 0x160;
                func_80081790(actor_index, D_800E8BEC);
            }
            else {
                gActors[actor_index].state = 0x110;
            }
            gActors[actor_index].flags &= ~ACTOR_FLAG_UNK17;
            gActors[actor_index].flags |= ACTOR_FLAG_UNK16;
            gActors[actor_index].velocityX.raw = (f32) gActors[actor_index].velocityX.raw * 0.3;
            gActors[actor_index].velocityY.raw = 0;
            gActors[actor_index].unk_170 = 0;
            return 2;
        }
    }
    return 0;
}

void func_80091300(u16 actor_index) {
    if (func_8008F220(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x150:
            gActors[actor_index].state++;
            gActors[actor_index].flags &= ~ACTOR_FLAG_UNK16; \
            gActors[actor_index].flags |= ACTOR_FLAG_UNK17;
            func_80081790(actor_index, D_800E8BD0);
            /* fallthrough */
        case 0x151:
            func_800911D8(actor_index);
            break;
        }
    }
}

void func_800913C0(u16 actor_index) {
    if (func_8008F220(actor_index) != 0) {
        return;
    }

    switch (gActors[actor_index].state) {
    case 0x170:
        gActors[actor_index].state++;
        gActors[actor_index].velocityX.raw = 0;
        func_80081790(actor_index, D_800E8B98);
        /* fallthrough */
    case 0x171:
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index].state++;
            gActors[actor_index].flags &= ~ACTOR_FLAG_UNK16;
            gActors[actor_index].flags |= ACTOR_FLAG_UNK17;
            gActors[actor_index].velocityX.raw = gActors[actor_index + 2].unk_180;
            gActors[actor_index].velocityY.raw = gActors[actor_index + 3].unk_180;
        }
        break;
    case 0x172:
        if (gActors[actor_index].velocityY.raw < 0) {
            gActors[actor_index].state++;
            func_80081790(actor_index, D_800E8BD0);
        }
        func_800911D8(actor_index);
        break;
    case 0x173:
        func_800911D8(actor_index);
        break;
    }
}

void func_80091524(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        if (gActors[actor_index].unk_11C < 0.0f) {
            gActors[actor_index].state = 0x110;
        }
    }
}

s32 func_8009159C(u16 actor_index) {
    u16 actor_7;
    u16 parent;

    actor_7 = actor_index + 7;
    if (func_80028C08(actor_7) != 0) {
        parent = gActors[actor_7].parentIndex;
        gActors[parent].unk_104 = gActors[actor_7].posX.raw;
        gActors[parent].unk_108 = gActors[actor_7].posY.raw;
        gActors[parent].unk_10C = gActors[actor_7].posZ.raw - 1;
        gActors[parent].flags_098 |= ACTOR_FLAG3_UNK9;
        gActors[parent].parentIndex = actor_index + 7;
        return TRUE;
    }
    else {
        gActors[actor_index].state = 0x110;
        return FALSE;
    }
}

void func_80091664(u16 actor_index) {
    u16 actor_7;

    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x180:
            gActors[actor_index].state++;
            gActors[actor_index].velocityX.raw = 0;
            func_80081790(actor_index, D_800E8D1C);
            /* fallthrough */
        case 0x181:
            actor_7 = actor_index + 7;
            if (gActors[actor_index].unk_16C & 2) {
                gActors[actor_index + 2].var_110 = actor_7;
                gActors[actor_7].flags |= ACTOR_FLAG_UNK11;
                Actor_SetHitboxA(actor_7, gActors[actor_index + 1].unk_12C * 7.0f);
            }
            if ((gActors[actor_7].flags_098 & ACTOR_FLAG3_UNK8) && (actor_index != gActors[actor_7].parentIndex) && !(gActors[gActors[actor_7].parentIndex].unk_0DF & 0x40)) {
                gActors[actor_index].state = 0x190;
                gActors[actor_7].flags &= ~ACTOR_FLAG_UNK11;
                func_8009159C(actor_index);
            }
            else if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state++;
                func_80081790(actor_index, D_800E8D3C);
                gActors[actor_7].flags &= ~ACTOR_FLAG_UNK11;
            }
            break;
        case 0x182:
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
            break;
        }
    }
    else {
        func_8008EA4C(actor_index);
    }
}

void func_800918D4(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x190:
            gActors[actor_index].velocityX.raw = 0;
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state++;
                func_80081790(actor_index, D_800E8D4C);
            }
            func_8009159C(actor_index);
            break;
        case 0x191:
            func_8008F108(actor_index);
            if ((func_8009159C(actor_index) != 0) && (gActors[actor_index].unk_11C < 0.0f)) {
                gActors[actor_index].state = 0x1A0;
            }
            break;
        }
    }
}

void func_800919C8(u16 actor_index) {
    u16 parent;
    s32 index;

    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x1A0:
            gActors[actor_index].state++;
            func_80081790(actor_index, D_800E8D60);
            /* fallthrough */
        case 0x1A1:
            if (func_8009159C(actor_index) != 0) {
                parent = gActors[actor_index + 7].parentIndex;
                if (gActors[actor_index].unk_16C & 2) {
                    gActors[actor_index].state++;
                    gActors[parent].flags_098 &= ~ACTOR_FLAG3_UNK9;
                    gActors[parent].flags_098 |= ACTOR_FLAG3_UNK10;
                    if (parent == 0) {
                        gActors[parent].unk_0F8.raw = gActors[actor_index + 2].unk_180 * gActors[actor_index + 1].unk_130;
                        gActors[parent].unk_0FC.raw = gActors[actor_index + 3].unk_180;
                    }
                    else {
                        index = gActors[parent].unk_0CE * 10;
                        gActors[parent].unk_0F8.raw = D_800E3630[index + 4] * gActors[actor_index + 1].unk_130;
                        gActors[parent].unk_0FC.raw = D_800E3630[index + 5];
                    }
                }
            }
            break;
        case 0x1A2:
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
            break;
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/3UMF9
void func_80091BDC(u16 arg0) {
    s32 temp_v0;

    func_80040858(arg0);
    temp_v0 = func_800291AC(arg0, 0x1C0, 0x214A3, 0x150, 0x21423);
    switch (temp_v0) {
    case 0:
        gActors[arg0].posZ.raw = gActors[arg0].unk_10C - 0x10000;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
#else
void func_80091BDC(u16 actor_index);
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80091BDC.s")
#endif

void func_80091C90(u16 actor_index) {
    switch (gActors[actor_index].state) {
    case 0x1B0:
        gActors[actor_index].state++;
        func_80081790(actor_index, D_800E8C08);
        /* fallthrough */
    case 0x1B1:
        func_80091BDC(actor_index);
        break;
    }
}

void func_80091D28(u16 actor_index) {
    if (func_8008F220(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x1C0:
            gActors[actor_index].state++;
            gActors[actor_index + 1].var_110 = 10.0f;
            // fallthrough
        case 0x1C1:
            gActors[actor_index].unk_170 -= FIXED_UNIT(48.0);
            if ((gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK0) || 
                ((gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK2) && (gActors[actor_index].velocityX.raw < 0)) || 
                ((gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK3) && (gActors[actor_index].velocityX.raw > 0))) {
                gActors[actor_index].velocityX.raw = -(f32) gActors[actor_index].velocityX.raw * 0.75;
                gActors[actor_index].velocityY.raw = (f32) gActors[actor_index].velocityY.raw * 0.75;
                Sound_PlaySfxAtActor2(0x2D, actor_index);
                func_8008F094(actor_index, 0x32);
            }
            if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK4) {
                if (gActors[actor_index].velocityY.raw > 0) {
                    gActors[actor_index].velocityX.raw = -(f32) gActors[actor_index].velocityX.raw * 0.75;
                    gActors[actor_index].velocityY.raw = -gActors[actor_index].velocityY.raw;
                    Sound_PlaySfxAtActor2(0x2D, actor_index);
                    func_8008F094(actor_index, 0x32);
                }
            }
            if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK5) {
                if (gActors[actor_index].velocityY.raw < 0) {
                    gActors[actor_index].unk_0F8.raw = gActors[actor_index].velocityX.raw / 2;
                    gActors[actor_index].unk_0FC.raw = FIXED_UNIT(2.0);
                    func_8008ECDC(actor_index);
                    Sound_PlaySfxAtActor2(0x2D, actor_index);
                    func_8008F094(actor_index, 0x32);
                }
            }
            if (gActors[actor_index + 1].var_110 != 0.0f) {
                gActors[actor_index + 1].var_110 -= 1.0f;
            }
            else {
                func_80091158(actor_index);
            }
            break;
        }
    }
}

void func_80092028(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x1D0:
            gActors[actor_index].state++;
            func_80081790(actor_index, D_800E8C18);
            /* fallthrough */
        case 0x1D1:
            if (!(gActiveFrames & 0xF)) {
                gActors[actor_index].state += 2;
                func_80081790(actor_index, D_800E8C2C);
            }
            break;
        case 0x1D3:
            func_8008F294(actor_index);
            break;
        }
    }
}

void func_80092114(u16 actor_index) {
    func_80040858(actor_index);
    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x1E0:
            if (gActors[actor_index].iFrames < 4) {
                gActors[actor_index].state++;
                func_80081790(actor_index, (u16*)gActors[actor_index + 5].unk_180); // TODO: unk_180 used as pointer
                gActors[actor_index].velocityX.raw = gActors[actor_index].unk_0F8.raw;
                gActors[actor_index].velocityY.raw = gActors[actor_index].unk_0FC.raw;
            }
            gActors[actor_index + 1].var_110 = 0.0f;
            break;
        case 0x1E1:
            if (gActors[actor_index].unk_16C & 1) {
                gActors[actor_index + 1].var_110 = 1.0f;
            }
            if (gActors[actor_index + 1].var_110 != 0.0f) {
                gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, FIXED_UNIT(0.1875));
            }
            else {
                gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, FIXED_UNIT(0.015625));
            }
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
            break;
        }
    }
}

void func_800922D8(u16 actor_index) {
    func_80040858(actor_index);
    if (func_8008F220(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x1F0:
            if (gActors[actor_index].iFrames < 4) {
                gActors[actor_index].state++;
                func_80081790(actor_index, (u16*)gActors[actor_index + 5].unk_180);
                gActors[actor_index].velocityX.raw = gActors[actor_index].unk_0F8.raw;
                gActors[actor_index].velocityY.raw = gActors[actor_index].unk_0FC.raw;
            }
            break;
        case 0x1F1:
            func_800911D8(actor_index);
            break;
        }
    }
}

void func_800923C8(u16 actor_index) {
    func_80040858(actor_index);
    if (func_8008F220(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x200:
            if (gActors[actor_index].iFrames < 4) {
                gActors[actor_index].state++;
                func_80081790(actor_index, D_800E8DB8);
                gActors[actor_index].velocityX.raw = gActors[actor_index].unk_0F8.raw;
                gActors[actor_index].velocityY.raw = gActors[actor_index].unk_0FC.raw;
            }
            break;
        case 0x201:
            if (func_800911D8(actor_index) == 2) {
                gActors[actor_index].state = 0x210;
                Sound_PlaySfxAtActor2(0x94, actor_index);
                func_80081790(actor_index, D_800E8DCC);
                gActors[actor_index + 1].var_110 = 40.0f;
            }
            break;
        }
    }
}

void func_800924F8(u16 actor_index) {
    func_80040858(actor_index);
    if (func_8008F168(actor_index) == 0) {
        if (gActors[actor_index].state == 0x210) {
            func_8008F108(actor_index);
            gActors[actor_index + 1].var_110 -= 1.0f;
            if (gActors[actor_index + 1].var_110 < 0.0f) {
                gActors[actor_index].state = 0x220;
                func_80081790(actor_index, D_800E8E38);
            }
        }
    }
}

void func_800925D8(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        if (gActors[actor_index].state == 0x220) {
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
        }
    }
}

void func_80092660(u16 actor_index) {
    switch (gActors[actor_index].state) {
    case 0x250:
        func_80040858(actor_index);
        gActors[actor_index].state++;
        gActors[actor_index].flags &= ~ACTOR_FLAG_UNK16;
        gActors[actor_index].flags |= ACTOR_FLAG_UNK17;
        gActors[actor_index + 2].unk_180 = 0xDC;
        func_80081790(actor_index, D_800E9034);
        SpawnParticle_RingWaveRed(1.5f, gActors[actor_index].posX.whole, gActors[actor_index].posY.whole, gActors[actor_index].posZ.whole + 10);
        func_8003EEC0(2.0f, gActors[actor_index].posX.whole, gActors[actor_index].posY.whole, gActors[actor_index].posZ.whole + 10);
        // fallthrough

    case 0x251:
        gActors[actor_index + 2].unk_180--;
        if (gActors[actor_index + 2].unk_180 < 0) {
            gActors[actor_index].state++;
            gActors[actor_index].flags = 0;
            gActors[actor_index].actorType = 0;
            func_80081720(actor_index, D_800E5E48, 3);
            return;
        }
    
        if (((gActors[actor_index].velocityX.raw > 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK3)) || 
            ((gActors[actor_index].velocityX.raw < 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK2))) {
            gActors[actor_index].velocityX.raw = -gActors[actor_index].velocityX.raw;
        }
        if ((gActors[actor_index].velocityY.raw > 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK4)) {
            gActors[actor_index].velocityY.raw = -gActors[actor_index].velocityY.raw;
        }
        if ((gActors[actor_index].velocityY.raw < 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK5)) {
            func_80081790(actor_index, D_800E9034);
            gActors[actor_index].velocityY.raw = FIXED_UNIT(8.0) - ((Rand() & 3) << 0x10);
            if (func_80029B74(0x60) != 0) {
                gActors[actor_index].velocityX.raw = ((Rand() & 3) * FIXED_UNIT(0.75)) + FIXED_UNIT(0.5);
                if (Rand() & 1) {
                    gActors[actor_index].velocityX.raw = -gActors[actor_index].velocityX.raw;
                }
            }
            else {
                gActors[actor_index].velocityX.raw = ((Rand() & 3) * FIXED_UNIT(0.75)) + FIXED_UNIT(0.5);
                if (gActors->posX.whole < gActors[actor_index].posX.whole) {
                    gActors[actor_index].velocityX.raw = -gActors[actor_index].velocityX.raw;
                }
            }
            if (gActors[actor_index].velocityX.raw > 0) {
                gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
            }
            else {
                gActors[actor_index].flags |= ACTOR_FLAG_FLIPPED;
            }
        }
        else {
            gActors[actor_index].unk_170 += FIXED_UNIT(64.0);
            func_80091158(actor_index);
        }
        BossDeathExplode(0, actor_index, 1.5f, 1.5f);
        break;
    }
    gActors[actor_index].flags &= ~(ACTOR_FLAG_UNK12 | ACTOR_FLAG_UNK10);
}

void func_800929B8(u16 actor_index) {
    u16 actor_1;

    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x230:
            gActors[actor_index].state++;
            func_80081790(actor_index, D_800E8C7C);
            gActors[actor_index + 1].var_110 = Rand() & 3;
            gActors[actor_index + 1].unk_114 = 0.0f;
            // fallthrough
        case 0x231:
            gActors[actor_index].velocityX.raw = Math_ApproachS32(gActors[actor_index].velocityX.raw, 0, gActors[actor_index + 1].unk_12C * FIXED_UNIT(0.1875));
            if (gActors[actor_index].unk_16C & 3) {
                if (gActors[actor_index].unk_16C & 1) {
                    gActors[actor_index].velocityX.raw = FIXED_UNIT(2.25);
                    actor_1 = actor_index + 0xB;
                }
                else {
                    gActors[actor_index].velocityX.raw = FIXED_UNIT(2.625);
                    actor_1 = actor_index + 7;
                }
                gActors[actor_index].velocityX.raw *= gActors[actor_index + 1].unk_12C * gActors[actor_index + 1].unk_130;
                gActors[actor_index + 1].unk_114 = 10.0f;
                gActors[actor_index + 2].var_110 = actor_1;
                gActors[actor_1].flags |= ACTOR_FLAG_UNK9;
                gActors[actor_1].unk_0DA = 4; \
                gActors[actor_1].unk_0DB = 3; \
                gActors[actor_1].damage = 0x1E;
                gActors[actor_1].unk_0F8.raw = FIXED_UNIT(2.125); \
                gActors[actor_1].unk_0FC.raw = FIXED_UNIT(3.125);
                Actor_SetHitboxA(actor_1, gActors[actor_index + 1].unk_12C * 6.0f);
            }
            if (gActors[actor_index].unk_16C & 4) {
                gActors[actor_index + 1].var_110 -= 1.0f;
                if (gActors[actor_index + 1].var_110 < 0.0f) {
                    func_80081790(actor_index, D_800E8CE4);
                }
            }
            if (gActors[actor_index + 1].unk_114 != 0.0f) {
                gActors[actor_index + 1].unk_114 -= 1.0f;
                if (gActors[actor_index + 1].unk_114 == 0.0f) {
                    func_8008EA4C(actor_index);
                }
            }
            if (func_8008E948(actor_index) != 0) {
                Sound_PlaySfxAtActor2(0x2C, actor_index);
                func_800340CC((u16)gActors[actor_index + 2].var_110, 0xE, 1);
                gActors[actor_index].velocityX.raw = gActors[actor_index + 1].unk_12C * gActors[actor_index + 1].unk_130 * -114688.0f;
                func_8008EA4C(actor_index);
            }
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
        }
    }
    else {
        func_8008EA4C(actor_index);
    }
}

void func_80092E30(u16 actor_index) {
    if (func_8008F168(actor_index) == 0) {
        switch (gActors[actor_index].state) {
        case 0x240:
            gActors[actor_index].state++;
            func_80081790(actor_index, D_800E8CF8);
            // fallthrough
        case 0x241:
            func_8008F108(actor_index);
            if (gActors[actor_index].unk_16C & 1) {
                func_8008F2E8(actor_index, actor_index + 0xB);
            }
            if (gActors[actor_index].unk_11C < 0.0f) {
                gActors[actor_index].state = 0x110;
            }
            break;
        }
    }
}

void func_80092F2C(u16 actor_src, u16 actor_dst) {
    u16 index;
    u16* vals;

    vals = (u16*)gActors[actor_src + 2].unk_180;
    for (index = 0; (vals[index] & 0x8000) == 0; index++) {
        (&gActors[actor_dst].var_150)[index] = vals[index];
    }
}

s32 func_80092FD4(u16 actor_index) {
    u16 index;
    u16* vals;

    vals = (u16*)gActors[actor_index + 2].unk_180;
    for (index = 0; (vals[index] & 0x8000) == 0; index++) {
        if ((func_8005DEFC() & 0x7FFF) == vals[index]) {
            if ((vals[index + 1] & 0x8000)) {
                return 2;
            }
            else {
                return 1;
            }
        }
    }
    return 0;
}

void func_800930AC(u16 arg0) {
    if (func_80092FD4(arg0)) {
        func_8005DFC8(0);
    }
}

void func_800930E4(u32 arg0) {
}

void func_800930EC(u16 actor_index, void* arg1) {
    if (D_801826B0 < 0) {
        D_801826B0 = 0;
    }
    if (D_801826B0 > 0xFF) {
        D_801826B0 = 0xFF;
    }
    if (D_801826B0 != 0) {
        func_8007EA14(arg1, 0x2910, 0, 0xFFB00000, 0x01800000, 0, 0, 0x10, 0x10, D_801826B0, 0, 1.0f);
        func_8007EF58(arg1, 0x2901, 0, 0xFFB00000, 0x017FFFFF, D_801826B0, 1.1f, 1.1f);
    }
}

void func_800931CC(u16 actor_index) {
    switch (gActors[actor_index].state) {
    case 0xE3:
    case 0xE4:
        func_800930EC(actor_index, D_800E922C);
        break;
    case 0xE7:
    case 0xE8:
        func_800930EC(actor_index, D_800E9248);
        break;
    case 0xEB:
    case 0xED:
        func_800930EC(actor_index, D_800E9260);
        break;
    }
}

void func_80093274(u16 actor_index, u16 arg1) {
    switch (arg1) {
    case 0:
        func_800930EC(actor_index, D_800E9300);
        break;
    case 1:
        switch (gActors[actor_index].var_0D8) {
        case 5:
            func_800930EC(actor_index, D_800E92E0);
            break;
        case 2:
            func_800930EC(actor_index, D_800E92E4);
            break;
        }
        break;
    case 2:
        func_800930EC(actor_index, D_800E92C4);
        break;
    }
}

void func_8009333C(u16 actor_index) {
    s32 pad;
    func_8003D68C(0x2800, 0, -gActors[actor_index + 6].unk_180, -0x98, 0x98, 0, 0x680000, 0x01200000, 0, 0, 0);
    func_8003D68C(0x2800, gActors[actor_index + 6].unk_180_s16[1], 0, -0x98, 0x98, 0, 0xFF980000, 0x01200000, 0, 0, 0);
}

s32 func_80093410(u16 actor_index) {
    gActors[actor_index + 6].unk_180 = Math_ApproachS32(gActors[actor_index + 6].unk_180, 0xA0, 6);
    func_8009333C(actor_index);
    if (gActors[actor_index + 6].unk_180 == 0xA0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

s32 func_8009349C(u16 actor_index) {
    gActors[actor_index + 6].unk_180 = Math_ApproachS32(gActors[actor_index + 6].unk_180, 0, 6);
    if (gActors[actor_index + 6].unk_180 == 0) {
        return TRUE;
    }
    else {
        func_8009333C(actor_index);
        return FALSE;
    }
}

void func_8009351C(u16 actor_index) {
    gActors[actor_index].posY.raw += D_800BE73C * gActors[actor_index].unk_11C;
    gActors[actor_index].var_150--;
    if (gActors[actor_index].var_150 < 0) {
        gActors[actor_index].flags = 0;
    }
}

void func_800935B8(u16 actor_index, u16 arg1) {
    u16 actor_1;

    actor_1 = actor_index + 0x18;
    gActors[actor_1].actorType = 0x6D;
    Actor_Initialize(actor_1);
    gActors[actor_1].flags = 2;
    gActors[actor_1].var_110 = actor_index;
    gActors[actor_1].var_0D8 = arg1;
}

void func_80093654(u16 actor_index) {
    f32 temp_f0;
    f32 scale;

    temp_f0 = gActors[actor_index].unk_168 / 10000;
    scale = temp_f0 * 0.75;
    func_80032E60(actor_index + 0xB, 0x1098, 0, 4.0f * temp_f0, -1, scale, scale);
}

#ifdef NON_MATCHING
void func_80093704(u16 arg0) {
    u16 temp_s1;
    f32 temp_f2;

    temp_s1 = Actor_RangeFindInactive_90ToC0();
    if (temp_s1 != 0) {
        gActors[temp_s1].actorType = 0x34;
        Actor_Initialize(temp_s1);
        gActors[temp_s1].flags = 0xB;
        gActors[temp_s1].posX.whole = 0;
        gActors[temp_s1].posY.whole = 0;
        if (gActors[arg0].state >= 0xF6) {
            gActors[temp_s1].graphicFlags = 0x311;
            gActors[temp_s1].graphicIndex = 0xDA;
            gActors[temp_s1].palette_18C = D_800D9284;
            gActors[temp_s1].posZ.whole = -0x20;
            gActors[temp_s1].scaleX = 13.0f;
            gActors[temp_s1].scaleY = 13.0f;
        }
        else {
            gActors[temp_s1].graphicFlags = 0x319;
            gActors[temp_s1].graphicIndex = 0xC8;
            gActors[temp_s1].palette_18C = D_800D99A4;
            gActors[temp_s1].rotateZ = 90.0f;
            gActors[temp_s1].scaleX = 11.0f;
            gActors[temp_s1].scaleY = 12.0f;
            if ((gActiveFrames % 12) == 0) {
                SpawnParticle_RingSparkle(arg0, 0, 0.4f, (f32)(0x80 - Rand()) * 0.75, (f32)(0x80 - Rand()) * 0.75, 0x80);
            }
            gActors[temp_s1].posZ.whole = 0x100;
        }
        gActors[temp_s1].colorR = gActors[arg0 + 8].unk_180 / 32;
        gActors[temp_s1].colorB = gActors[temp_s1].colorG = (gActors[arg0 + 8].unk_180 / 16) & 0xFF;
        gActors[temp_s1].colorA = D_801826B2;
        if (gActors[arg0].flags != 0) {
            func_80031D58(arg0, temp_s1);
        }
        else {
            gActors[temp_s1].unk_148 = 120.0f;
        }
    }
    if ((gActors[arg0].state < 0xF5) && ((gActiveFrames % 6) == 0)) {
        temp_s1 = Actor_RangeFindInactive_90ToC0();
        if (temp_s1 != 0) {
            gActors[temp_s1].actorType = 0x6F;
            Actor_Initialize(temp_s1);
            gActors[temp_s1].graphicFlags |= 0x309;
            gActors[temp_s1].flags = 0xB;
            gActors[temp_s1].graphicIndex = 0xC8;
            gActors[temp_s1].palette_18C = D_800D98F4;
            gActors[temp_s1].posX.whole = (f32)(0x80 - Rand()) * 1.25;
            gActors[temp_s1].posY.whole = ((f32)(0x80 - Rand()) * 0.7) - (D_800BE73C / 4096);
            temp_f2 = (f32) (Rand() & 0x3F);
            gActors[temp_s1].posZ.whole = -64.0f - temp_f2;
            gActors[temp_s1].unk_118 = temp_f2 / 16;
            temp_f2 = (64.0f - temp_f2) / 16;
            gActors[temp_s1].unk_11C = temp_f2;
            gActors[temp_s1].scaleX = temp_f2 * 4.0;
            gActors[temp_s1].scaleY = temp_f2 * 0.4;
            gActors[temp_s1].colorA = 0x60;
            gActors[temp_s1].colorR = 0x7F;
            gActors[temp_s1].var_150 = 0x10;
            gActors[temp_s1].unk_114 = temp_f2 * 0.2;
            gActors[temp_s1].rotateZ = 90.0f;
        }
    }
}
#else
void func_80093704(u16 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80093704.s")
#endif

void func_80093C10(u16 actor_index) {
    u16 actor;

    actor = Actor_RangeFindInactive_90ToC0();
    if (actor != 0) {
        gActors[actor].actorType = 0x34;
        Actor_Initialize(actor);
        gActors[actor].graphicFlags = ACTOR_GFLAG_PALETTE | ACTOR_GFLAG_UNK8 | ACTOR_GFLAG_ROTZ | ACTOR_GFLAG_SCALE;
        gActors[actor].flags = ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[actor].graphicIndex = 0xC8;
        gActors[actor].scaleX = 10.0f;
        gActors[actor].scaleY = D_801826B8;
        gActors[actor].posX.whole = 0;
        gActors[actor].posY.whole = 0;
        gActors[actor].posZ.whole = gActors[actor_index].posZ.whole + 4;
        gActors[actor].colorA = D_801826B4;
        gActors[actor].rotateZ = 90.0f;
        if (gActiveFrames & 1) {
            gActors[actor].palette_18C = D_800D99A4;
        }
        else {
            gActors[actor].palette_18C = D_800D98F4;
        }
        func_80031D58(actor_index, actor);
    }
}

void func_80093D38(u16 actor_index) {
    u16 index;
    
    gActors[actor_index + 9].unk_180++;
    gCannotPause = 1;
    switch (gActors[actor_index].state) {
    case 0xE0:
        gActors[actor_index].state++;
        func_80081720(actor_index, D_800E5E48, 3);
        gActors[actor_index + 6].unk_180 = 0x68;
        gActors[actor_index].colorA = 0;
        D_800BE73C = FIXED_UNIT(4.0);
        D_801826B2 = 0xA0;
        Sound_PlaySfx(0x13C);
        break;
    case 0xE1:
        func_8009349C(actor_index);
        gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0x500, 8);
        if (gActors[actor_index + 9].unk_180 >= 0x5B) {
            gActors[actor_index].state++;
            gActors[actor_index + 9].unk_180 = 0;
        }
        break;
    case 0xE2:
        gActors[actor_index].state++;
        func_800816AC(actor_index, D_800E5E48, 3);
        func_80081790(actor_index, D_800E8F60);
        gActors[actor_index].posX.whole = -0x38; \
        gActors[actor_index].posY.whole = -0x20;
        gActors[actor_index].posZ.whole = 0x80;
        gActors[actor_index].velocityX.raw = FIXED_UNIT(0.125); \
        gActors[actor_index].velocityY.raw = FIXED_UNIT(0.6875); \
        gActors[actor_index].velocityZ.raw = FIXED_UNIT(-1.0);
        gActors[actor_index].unk_168 = 0x61A8;
        gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
        D_801826B0 = 0;
        gActors[actor_index].unk_120 = 1.9f;
        break;
    case 0xE6:
        gActors[actor_index].state++;
        func_800816AC(actor_index, D_800E5E48, 3);
        func_80081790(actor_index, D_800E8D60);
        gActors[actor_index].posX.whole = 0x38; \
        gActors[actor_index].posY.whole = -0x20; \
        gActors[actor_index].posZ.whole = 0x40;
        gActors[actor_index].velocityX.raw = FIXED_UNIT(-0.125); \
        gActors[actor_index].velocityY.raw = FIXED_UNIT(0.625); \
        gActors[actor_index].velocityZ.raw = FIXED_UNIT(-1.0);
        gActors[actor_index].unk_168 = 0x4E20;
        gActors[actor_index].flags |= ACTOR_FLAG_FLIPPED;
        D_801826B0 = 0;
        gActors[actor_index].unk_120 = 1.7f;
        break;
    case 0xEA:
        gActors[actor_index].state++;
        func_800816AC(actor_index, D_800E5E48, 3);
        func_80081790(actor_index, D_800E8C40);
        gActors[actor_index].posX.whole = 0; \
        gActors[actor_index].posZ.whole = 0x80; \
        gActors[actor_index].posY.whole = -0x48;
        gActors[actor_index].velocityX.raw = 0; \
        gActors[actor_index].velocityY.raw = FIXED_UNIT(1.0); \
        gActors[actor_index].velocityZ.raw = FIXED_UNIT(-2.0);
        gActors[actor_index].unk_168 = 0x61A8;
        gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
        D_801826B0 = 0;
        gActors[actor_index].unk_120 = 3.0f;
        func_800935B8(actor_index, 2);
        break;
    case 0xE3:
    case 0xE7:
    case 0xEB:
        gActors[actor_index].colorA = Math_ApproachS32(gActors[actor_index].colorA, 0xFF, 8);
        gActors[actor_index].unk_168 -= 0x32;
        if (gActors[actor_index].state != 0xEB) {
            func_80093654(actor_index);
        }
        gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0x500, 8);
        D_801826B0 += 8;
        func_800931CC(actor_index);
        if (gActors[actor_index + 9].unk_180 >= 0x2E) {
            gActors[actor_index].state++;
        }
        break;
    case 0xE4:
    case 0xE8:
        gActors[actor_index].colorA = Math_ApproachS32(gActors[actor_index].colorA, 0, 8);
        D_801826B0 -= 8;
        func_800931CC(actor_index);
        if (gActors[actor_index].colorA == 0) {
            gActors[actor_index].state++;
            func_80081720(actor_index, D_800E5E48, 3);
        }
        else {
            gActors[actor_index].unk_168 -= 0x32;
            func_80093654(actor_index);
        }
        break;
    case 0xE5:
    case 0xE9:
        if (gActors[actor_index + 9].unk_180 >= 0x5B) {
            gActors[actor_index].state++;
            gActors[actor_index + 9].unk_180 = 0;
        }
        break;
    case 0xEC:
        gActors[actor_index].state++;
        func_80081790(actor_index, D_800E8EC8);
        gActors[actor_index].unk_120 = 1.0f;
        /* fallthrough */
    case 0xED:
        gActors[actor_index].velocityY.raw -= 0x500;
        D_801826B0 -= 8;
        func_800931CC(actor_index);
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index].state++;
            index = actor_index + 0x18;
            gActors[index].state++;
            gActors[index].velocityY.raw = FIXED_UNIT(8.0);
            gActors[actor_index + 9].unk_180 = 0;
            Sound_PlaySfx(0x2A);
        }
        break;
    case 0xEE:
        gActors[actor_index].velocityY.raw -= FIXED_UNIT(0.125);
        gActors[actor_index].velocityZ.raw += FIXED_UNIT(0.125);
        if ((gActors[actor_index].unk_11C < 0.0f) && (func_80093410(actor_index) != 0)) {
            gActors[actor_index].state++;
            func_800935B8(actor_index, 1);
            gActors[actor_index + 9].unk_180 = 0;
            func_80081720(actor_index, D_800E5E48, 3);
            D_801826B2 = 0;
            Sound_PlaySfx(0x13D);
        }
        break;
    case 0xEF:
        func_8009349C(actor_index);
        gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0x500, 8);
        D_801826B2 = Math_ApproachS32(D_801826B2, 0xA0, 1);
        if (gActors[actor_index + 9].unk_180 >= 0x12D) {
            gActors[actor_index].state++;
            index = actor_index + 0x18;
            gActors[index].state++;
        }
        break;
    case 0xF0:
        D_800BE73C = Math_ApproachS32(D_800BE73C, FIXED_UNIT(-4.0), FIXED_UNIT(0.125));
        gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0x500, 8);
        if (gActors[actor_index + 9].unk_180 >= 0x169) {
            index = actor_index + 0x18;
            gActors[index].flags = 0;
            gActors[actor_index + 9].unk_180 = 0;
            gActors[actor_index].state++;
            gActors[actor_index].posX.whole = 0; \
            gActors[actor_index].posY.whole = -0x80; \
            gActors[actor_index].posZ.whole = 0x40;
            gActors[actor_index].velocityY.raw = FIXED_UNIT(2.625);
            gActors[actor_index].velocityZ.raw = 0;
            gActors[actor_index].velocityX.raw = 0;
            gActors[actor_index].unk_168 = 0x4650;
            gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
            gActors[actor_index].colorA = 0xFF;
            gActors[actor_index].unk_120 = 1.0f;
            Sound_PlaySfx(0x4F);
        }
        break;
    case 0xF1:
        gActors[actor_index].state++;
        func_800816AC(actor_index, D_800E5E48, 3);
        /* fallthrough */
    case 0xF2:
        D_800BE73C = Math_ApproachS32(D_800BE73C, FIXED_UNIT(-4.0), FIXED_UNIT(0.0625));
        func_80094F24(actor_index, 0);
        gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, 0, 0x800);
        if ((gActors[actor_index + 9].unk_180 >= 0x3C) && (gActors[actor_index + 9].unk_180 < 0x78)) {
            if (gActors[actor_index + 9].unk_180 >= 0x5B) {
                D_801826B0 -= 0x10;
            }
            else {
                D_801826B0 += 0x20;
            }
            func_800930EC(actor_index, D_800E927C);
            Sound_PlaySfx(0x13E);
        }
        if ((gActors[actor_index + 9].unk_180 >= 0x78) && (gActors[actor_index + 9].unk_180 < 0xB4)) {
            if (gActors[actor_index + 9].unk_180 >= 0x97) {
                D_801826B0 -= 0x10;
            }
            else {
                D_801826B0 += 0x20;
            }
            func_800930EC(actor_index, D_800E928C);
        }
        if (gActors[actor_index + 9].unk_180 >= 0xB4) {
            D_801826B0 += 0x20;
            func_800930EC(actor_index, D_800E92AC);
        }
        if (gActors[actor_index + 9].unk_180 == 0xF0) {
            gActors[actor_index].state++;
            gActors[actor_index].palette_18C = D_800D1C04;
            func_80081584(actor_index, D_800E5E48);
            Sound_PlaySfx(0x13F);
            gActors[actor_index].colorA = 0xFE;
            func_80081790(actor_index, D_800E8FC0);
            D_801826B4 = 0xA0;
            gActors[actor_index].unk_120 = 4.0f;
            D_801826B8 = 5.0f;
            func_80093C10(actor_index);
            D_801826B2 = 0xFF;
            gActors[actor_index + 9].unk_180 = 0;
        }
        break;
    case 0xF4:
        D_801826B2 = Math_ApproachS32(D_801826B2, 0xFF, 0x10);
        if (D_801826B2 == 0xFF) {
            gActors[actor_index].state++;
            gActors[actor_index + 9].unk_180 = 0;
            func_80081720(actor_index, D_800E5E48, 3);
            func_80093C10(actor_index);
            gActors[actor_index].colorA = 0;
            func_80081644(actor_index, D_800E5E48);
            break;
        }
        else {
            gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0, 0x20);
        }
        // fallthrough
    case 0xF3:
        D_801826B0 -= 0x10;
        func_800930EC(actor_index, D_800E92AC);
        if (gActors[actor_index].state == 0xF3) {
            D_801826B2 = Math_ApproachS32(D_801826B2, 0xA0, 4);
        }
        D_801826B8 = D_801826B8 + 0.02;
        if (gActors[actor_index].unk_16C & 1) {
            gActors[actor_index].flags ^= ACTOR_FLAG_FLIPPED;
        }
        gActors[actor_index].unk_120 = Math_ApproachF32(gActors[actor_index].unk_120, 1.0f, 0.015f);
        func_80093C10(actor_index);
        gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, FIXED_UNIT(0.125), FIXED_UNIT(0.001953125));
        gActors[actor_index].unk_168 -= 0xA;
        if ((gActors[actor_index + 9].unk_180 >= 0xD3) && (D_801826B4 < 0xFF)) {
            if (D_800D1C04 && D_800D1C04 && D_800D1C04) {} // fakematch
            D_801826B4++;
        }
        func_80094F24(actor_index, 0);
        if (gActors[actor_index + 9].unk_180 == 0x168) {
            Sound_PlaySfx(0xA6);
        }
        if (gActors[actor_index + 9].unk_180 == 0x168) {
            if (D_800D1C04 && D_800D1C04 && D_800D1C04) {} // fakematch
            gActors[actor_index].state++;
        }
        break;
    case 0xF5:
        if (gActors[actor_index + 9].unk_180 == 0x3C) {
            func_800816AC(actor_index, D_800E5E48, 3);
            gActors[actor_index + 1].var_0D8 = gActors[actor_index].var_0D8;
            func_800907E4(actor_index);
            gActors[actor_index].state = 0xF6;
            func_80081478(actor_index, D_800E5E48, 0x5C);
            func_80081790(actor_index, D_800E8EAC);
            gActors[actor_index].unk_120 = 1.0f;
            gActors[actor_index].colorA = 0;
            gActors[actor_index + 9].unk_180 = 0x3C;
            gActors[actor_index].graphicFlags &= ~ACTOR_GFLAG_UNK4;
            Actor_SetColorRgb(actor_index, 0x7F);
            gActors[actor_index].unk_168 = 0xEA60;
            gActors[actor_index].palette_18C = NULL;
            D_801826B2 = 0;
            Sound_PlaySfx(0x5B);
            Sound_PlaySfx(0x12E);
        }
        break;
    case 0xF6:
        if (gActors[actor_index + 9].unk_180 >= 0x21D) {
            gActors[actor_index].flags = 0;
            func_80081720(actor_index, D_800E5E48, 3);
        }
        else {
            gActors[actor_index].unk_168 = Math_ApproachS32(gActors[actor_index].unk_168, 0x4E20, 0x7D0);
            gActors[actor_index].posX.whole = 0;
            gActors[actor_index].posY.whole = 0;
            gActors[actor_index].posZ.whole = 0;
            gActors[actor_index].colorR = Math_ApproachS32(gActors[actor_index].colorR, 0x20, 1);
            Actor_SetColorRgb(actor_index, gActors[actor_index].colorR);
            gActors[actor_index].colorA = Math_ApproachS32(gActors[actor_index].colorA, 0xFC, 0x10);
            D_801826B2 = Math_ApproachS32(D_801826B2, 0xA0, 8);
            gActors[actor_index + 8].unk_180 = Math_ApproachS32(gActors[actor_index + 8].unk_180, 0x200, 0x10);
            if ((gActors[actor_index + 9].unk_180 >= 0x3D) && !(gActiveFrames & 0xF)) {
                SpawnParticle_HeartBubble(2.0f, (f32) (0x80 - Rand()) * 0.8, (f32) (0x80 - Rand()) * 0.8, -0x40);
            }
            if (gActors[actor_index + 9].unk_180 == 0x172) {
                func_80081790(actor_index, D_800E8FF8);
            }
            if (gActors[actor_index].unk_11C < 0.0f) {
                func_80081790(actor_index, D_800E8EAC);
            }
            if ((gActors[actor_index + 9].unk_180 >= 0x78) && (gActors[actor_index + 9].unk_180 < 0xF0)) {
                if (gActors[actor_index + 9].unk_180 >= 0xB5) {
                    D_801826B0 -= 0x20;
                }
                else {
                    D_801826B0 += 0x20;
                }
                func_80093274(actor_index, 0);
            }
            if ((gActors[actor_index + 9].unk_180 >= 0xF0) && (gActors[actor_index + 9].unk_180 < 0x168)) {
                if (gActors[actor_index + 9].unk_180 >= 0x12D) {
                    D_801826B0 -= 0x20;
                }
                else {
                    D_801826B0 += 0x20;
                }
                func_80093274(actor_index, 1);
            }
            if (gActors[actor_index + 9].unk_180 >= 0x168) {
                D_801826B0 += 0x20;
                func_80093274(actor_index, 2);
            }
        }
        break;
    }
    gActors[actor_index].flags &= ~(ACTOR_FLAG_UNK17 | ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK12 | ACTOR_FLAG_UNK10 | ACTOR_FLAG_UNK8);
    func_80093704(actor_index);
}

void func_80094C5C(u16 actor_index) {
    func_8008F7E0(actor_index);
    if (gActors[actor_index].state < 0x4000) {
        D_800E9320[gActors[actor_index].state / 16](actor_index);
    }
    func_80090558(actor_index);
}

void func_80094CF8(u16 actor_index, u16 arg1) {
    func_8008E790(actor_index, 0x130, 0x120,
                  gActors[actor_index + 10].unk_180 - arg1, gActors[actor_index + 10].unk_180 + arg1,
                  gActors[actor_index + 11].unk_180 + 40, gActors[actor_index + 11].unk_180 - 40);
}

void func_80094D84(u16 actor_index, u16 arg1) {
    func_8008E790(actor_index, 0x140, 0x120,
                  gActors[actor_index + 10].unk_180 - arg1, gActors[actor_index + 10].unk_180 + arg1, 
                  gActors[actor_index + 11].unk_180 + 0x28, gActors[actor_index + 11].unk_180 - 0x28);
}

void func_80094E10(u16* arg0, u16 arg1) {
    if (func_80029B00(0x50, 0x40, -0x40)) {
        func_800406A4(arg0, arg1, gActors[arg1 + 1].unk_130 * 26.0f, 0x10, 0xA);
    }
}

void func_80094EB8(u16 actor_index) {
    if (func_80029B00(0x50, 0x40, -0x40)) {
        gActors[actor_index].flags_098 |= ACTOR_FLAG3_UNK18;
    }
}

void func_80094F24(u16 arg0, s32 arg1_unused) {
    u16 actor_index;

    if ((gActiveFrames % 7) == 0) {
        actor_index = Actor_RangeFindInactive(0x50, 0xC0);
        if (actor_index != 0) {
            gActors[actor_index].actorType = 0x6C;
            Actor_Initialize(actor_index);
            gActors[actor_index].var_150 = arg0;
            if ((gActiveFrames % 14) == 0) {
                gActors[actor_index].var_110 = 1.0f;
            }
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/PpDbA
void func_80094FE4(u16 arg0) {
    f32 temp_f2;
    u16 temp_a1;
    s32 var_v0;

    if (gActors[gActors[arg0].var_150].state == 0xF5) {
        gActors[arg0].flags = 0;
        return;
    }

    switch (gActors[arg0].state) {
    case 0:
        gActors[arg0].state++;
        gActors[arg0].graphicFlags = 0x307;
        gActors[arg0].flags = 0xB;
        gActors[arg0].graphicIndex = 0x1A8;
        gActors[arg0].var_154 = 0x02000000;
        gActors[arg0].var_158 = 0xC00000;
        gActors[arg0].unk_170 = -0x400000;
        gActors[arg0].unk_174 = -0x500000;
        gActors[arg0].unk_17C = 0x8000;
        gActors[arg0].colorA = 0;
        gActors[arg0].rotateX = 90.0f;
        gActors[arg0].scaleX = 2.0f;
        /* fallthrough */
    case 1:
        gActors[arg0].var_158 = Math_ApproachS32(gActors[arg0].var_158, 0x400000, 0x12492);
        gActors[arg0].unk_170 = Math_ApproachS32(gActors[arg0].unk_170, 0, 0x9249);
        gActors[arg0].unk_174 = Math_ApproachS32(gActors[arg0].unk_174, 0, 0xB6DB);
        gActors[arg0].colorA = Math_ApproachS32(gActors[arg0].colorA, 0xFF, 8);
        gActors[arg0].unk_178 = Math_ApproachS32(gActors[arg0].unk_178, -0x49249, gActors[arg0].unk_17C);
        if (gActors[arg0].unk_170 == 0) {
            gActors[arg0].state++;
        }
        goto default_case;
    case 3:
        gActors[arg0].colorA = Math_ApproachS32(gActors[arg0].colorA, 0, 8);
        if (gActors[arg0].colorA == 0) {
            gActors[arg0].flags = 0;
            return;
        }
        // fallthrough
    case 2:
        gActors[arg0].var_158 -= 0x8000;
        gActors[arg0].unk_17C += 0x100;
        gActors[arg0].unk_178 = Math_ApproachS32(gActors[arg0].unk_178, -0x200000, gActors[arg0].unk_17C);
        gActors[arg0].unk_174 += 0x20000;
        if (gActors[arg0].unk_178 <= -0x180000) {
            gActors[arg0].state = 3;
        }
        // fallthrough
    default:
default_case:
        var_v0 = (gActors[arg0].posZ.whole - gActors[gActors[arg0].var_150].posZ.whole) / 2;
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 >= 0x80) {
            var_v0 = 0x7F;
        }
        gActors[arg0].colorR = (u8) var_v0;
        if (gActors[arg0].posZ.whole >= gActors[gActors[arg0].var_150].posZ.whole) {
            gActors[arg0].graphicFlags &= 0xFFEF;
        }
        else {
            gActors[arg0].graphicFlags |= 0x10;
        }
        gActors[arg0].colorG = (u8) var_v0;
        gActors[arg0].colorB = (u8) var_v0;
        if ((u16)gActors[arg0].var_110) {
            if (gActiveFrames & 2) {
                gActors[arg0].palette_18C = (u16*)0x8022D528;
            }
            else {
                gActors[arg0].palette_18C = (u16*)0x8022D4E8;
            }
        }
        else if (gActiveFrames & 2) {
            gActors[arg0].palette_18C = (u16*)0x8022D548;
        }
        else {
            gActors[arg0].palette_18C = (u16*)0x8022D568;
        }
        gActors[arg0].rotateX = Math_ApproachF32(gActors[arg0].rotateX, 0.0f, 0.5f);
        gActors[arg0].var_154 += gActors[arg0].unk_178;
        var_v0 = gActors[arg0].var_154 / 0x10000;
        temp_a1 = var_v0; // fakematch going through var_v0?
        temp_f2 = (f32) gActors[arg0].var_158;
        gActors[arg0].posX.raw = (gActors[gActors[arg0].var_150].posX.raw + gActors[arg0].unk_170) + (COS(temp_a1) * temp_f2);
        gActors[arg0].rotateY = ((temp_a1 + 0x100) & 0x3FF) * 0.3515625;
        if ((u16)gActors[arg0].var_110) {
            gActors[arg0].posX.raw = -gActors[arg0].posX.raw;
            gActors[arg0].rotateY = 0.0f - gActors[arg0].rotateY;
        }
        gActors[arg0].posY.raw = gActors[gActors[arg0].var_150].posY.raw + gActors[arg0].unk_174;
        gActors[arg0].posZ.raw = gActors[gActors[arg0].var_150].posZ.raw + (SIN(temp_a1) * temp_f2);
        gActors[arg0].scaleX = Math_ApproachF32(gActors[arg0].scaleX, 1.0f, 0.01f);
        gActors[arg0].scaleY = gActors[arg0].scaleX;
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80094FE4.s")
#endif

void func_800955F4(u16 actor_index) {
    s32 pad;
    if (gButtonPress & gButton_CUp) {
        D_800E93BC++;
        if (D_800E93BC >= 5) {
            D_800E93BC = 0;
        }
        gActors[actor_index].state = 0;
    }
    if (gButtonPress & gButton_CLeft) {
        D_800E93C0++;
        if (D_800E93C0 >= 4) {
            D_800E93C0 = 0;
        }
    }
    gActors[actor_index + 1].var_0D8 = D_800E93BC;
    func_80094C5C(actor_index);
    func_8008F498(actor_index, D_800E93C0 * 0x10);
    switch (gActors[actor_index].state) {
    case 0x0:
        gActors[actor_index].state = 0x110;
        break;
    case 0x111:
        if (gButtonPress & gButton_B) {
            gActors[actor_index].state = 0x180;
            gActors[actor_index + 2].unk_180 = FIXED_UNIT(4.0);
            gActors[actor_index + 3].unk_180 = FIXED_UNIT(8.0);
        }
        if (gButtonPress & gButton_A) {
            gActors[actor_index].state = 0x170;
            gActors[actor_index + 2].unk_180 = 0;
            gActors[actor_index + 3].unk_180 = FIXED_UNIT(6.5);
        }
        if ((gButtonHold & gButton_DLeft) || (gButtonHold & gButton_DRight)) {
            if (((gActors[actor_index].flags & ACTOR_FLAG_FLIPPED) && (gButtonHold & gButton_DRight)) || 
                (((gActors[actor_index].flags & ACTOR_FLAG_FLIPPED) == 0) && ( gButtonHold & gButton_DLeft))) {
                gActors[actor_index].state = 0x120;
            }
            else {
                gActors[actor_index].state = 0x140;
                gActors[actor_index + 3].unk_180 = 0;
            }
        }
        break;
    case 0x131:
        if (gButtonHold & gButton_DLeft) {
            gActors[actor_index].flags |= ACTOR_FLAG_FLIPPED;
            gActors[actor_index + 1].unk_130 = -1.0f;
        }
        else if (gButtonHold & gButton_DRight) {
            gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
            gActors[actor_index + 1].unk_130 = 1.0f;
        }
        else {
            gActors[actor_index].state = 0x110;
        }
        break;
    case 0x141:
        if (gButtonHold & gButton_DLeft) {
            gActors[actor_index].flags |= ACTOR_FLAG_FLIPPED;
        }
        else if (gButtonHold & gButton_DRight) {
            gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
        }
        else {
            gActors[actor_index].state = 0x110;
        }
        break;
    }
}

void func_80095928(u16 actor_index) {
    s32 pad;
    if (gActors[actor_index].state >= 0xF6) {
        gActors[actor_index + 1].var_0D8 = gActors[actor_index].var_0D8;
    }
    else {
        gActors[actor_index + 1].var_0D8 = 3;
    }
    func_80094C5C(actor_index);
    if (gActors[actor_index].state == 0) {
        gActors[actor_index].state = 0xE0;
        gActors[actor_index].flags &=
            ~(ACTOR_FLAG_UNK17 | ACTOR_FLAG_UNK16 | ACTOR_FLAG_UNK12 | ACTOR_FLAG_UNK11 |
              ACTOR_FLAG_UNK10 | ACTOR_FLAG_UNK9 | ACTOR_FLAG_UNK8 | ACTOR_FLAG_UNK7);
        gActors[actor_index + 2].var_0D8 = 0;
    }
}

void func_80095A10(u16 actor_index) {
    gActors[actor_index].unk_118 += gActors[actor_index].unk_114;
    if (gActors[actor_index].unk_118 > 360.0f) {
        gActors[actor_index].unk_118 -= 360.0f;
        Sound_PlaySfx2(0x116);
    }
}

void func_80095A8C(u16 actor_index) {
    u16 actor_1;
    u32 angle;

    gActors[actor_index].unk_14C += 1.0f;
    switch (gActors[actor_index].state) {
    case 0x0:
        gActors[actor_index].state++;
        gActors[actor_index].graphicFlags = ACTOR_GFLAG_UNK8 | ACTOR_GFLAG_ROTZ | ACTOR_GFLAG_SCALE;
        gActors[actor_index].flags = ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[actor_index].graphicIndex = 0x1098;
        switch (gActors[actor_index].var_0D8) {
        case 0:
            gActors[actor_index].scaleX = 0.8f;
            gActors[actor_index].posX.whole = 0;
            break;
        case 1:
            gActors[actor_index].state = 0x100;
            gActors[actor_index].posZ.whole = 0xC0;
            gActors[actor_index].posY.whole = -0x30;
            gActors[actor_index].velocityY.raw = FIXED_UNIT(2.0);
            gActors[actor_index].scaleX = 4.0f;
            break;
        case 2:
            gActors[actor_index].state = 0x110;
            gActors[actor_index].flags &= ~ACTOR_FLAG_DRAW;
            break;
        }
        break;
    case 1:
        break;
    case 0x100:
        gActors[actor_index].posX.whole = 0;
        gActors[actor_index].scaleX = Math_ApproachF32(gActors[actor_index].scaleX, 1.5f, 0.03f);
        if (gActors[actor_index].scaleX <= 1.6) {
            gActors[actor_index].rotateZ += gActors[actor_index].unk_114;
            gActors[actor_index].unk_114 = Math_ApproachF32(gActors[actor_index].unk_114, 30.0f, 0.1f);
            func_80095A10(actor_index);
            gActors[actor_index].velocityY.raw = Math_ApproachS32(gActors[actor_index].velocityY.raw, 0, FIXED_UNIT(0.25));
            gActors[actor_index].colorR = Math_ApproachS32(gActors[actor_index].colorR, 0x7F, 1);
        }
        else {
            gActors[actor_index].posZ.whole--;
            gActors[actor_index].velocityY.raw -= FIXED_UNIT(0.03125);
        }
        if ((gActiveFrames & 7) == 0) {
            angle = (f32) (gActors[actor_index].rotateZ / RadStep) + COSPiOver2;
            // fakematch: & 0xFFFF
            SpawnParticle_RingSparkle(actor_index & 0xFFFF, 0, gActors[actor_index].scaleX * 0.5, 
                gActors[actor_index].posX.whole + ((COS(angle) * gActors[actor_index].scaleX * 983040.0f) / 65536.0f), 
                gActors[actor_index].posY.whole + ((SIN(angle) * gActors[actor_index].scaleX * 983040.0f) / 65536.0f), 
                gActors[actor_index].posZ.whole + 0x10);
        }
        break;
    case 0x101:
        gActors[actor_index].rotateZ += gActors[actor_index].unk_114;
        gActors[actor_index].velocityY.raw += FIXED_UNIT(0.125);
        func_80095A10(actor_index);
        break;
    case 0x110:
        gActors[actor_index].flags |= ACTOR_FLAG_DRAW;
        actor_1 = (u16)gActors[actor_index].var_110 + 0xB;
        gActors[actor_index].scaleX = gActors[(u16)gActors[actor_index].var_110].unk_168 / 10000;
        gActors[actor_index].scaleX *= 0.75;
        func_800330A4(actor_index, actor_1, 0, gActors[actor_index].scaleX * 4.0f);
        gActors[actor_index].posZ.whole = gActors[actor_1].posZ.whole - 1;
        break;
    case 0x111:
        gActors[actor_index].rotateZ = 0.0f;
        break;
    }
    gActors[actor_index].colorG = gActors[actor_index].colorR;
    gActors[actor_index].colorB = gActors[actor_index].colorR;
    gActors[actor_index].scaleY = gActors[actor_index].scaleX;
}

void func_80095FC8(u16 actor_index) {
    gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
    func_8008105C(actor_index, D_800E9414, D_800E93C4);
    gActors[actor_index].unk_178 = (intptr_t)D_800E961C;
    func_80081790(actor_index, D_800E95E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096104.s")

void func_800962C4(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_800962C4.s")

void func_80096478(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/8F080/func_80096478.s")

void func_8009672C(u16 actor_index) {
    s32 x;
    s32 y;

    x = gActors[actor_index].posX.whole + gScreenPosCurrentX.whole;
    gActors[actor_index].unk_180 = x;
    y = gActors[actor_index].posY.whole + gScreenPosCurrentY.whole;
    gActors[actor_index].unk_184 = y;
    gActors[actor_index].scaleY = gActors[actor_index].scaleX;
    switch (gActors[actor_index].state) {
    case 0:
        gActors[actor_index].state++;
        gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
        gActors[actor_index].flags = ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[actor_index].graphicList = D_800E2364;
        gActors[actor_index].graphicTimer = 1;
        gActors[actor_index].unk_164 = x;
        gActors[actor_index].unk_168 = y;
        gActors[actor_index].scaleX = 0.6f;
        gActors[actor_index].scaleY = 0.6f;
        /* fallthrough */
    case 1:
        if (gActiveFrames & 8) {
            gActors[actor_index].flags |= ACTOR_FLAG_FLIPPED;
        }
        else {
            gActors[actor_index].flags &= ~ACTOR_FLAG_FLIPPED;
        }
        func_80096478(actor_index);
        func_800962C4(actor_index);
        break;
    }
}

void func_8009685C(u16 actor_index) {
    gActors[actor_index].graphicFlags = ACTOR_GFLAG_SCALE;
    func_8008105C(actor_index, D_800E9654, D_800E9634);
    gActors[actor_index].unk_178 = (intptr_t)D_800E9720;
    func_80081790(actor_index, D_800E9700);
}

void func_800968EC(u16 actor_index) {
    func_800819A8(actor_index, D_800E9654);
}

void func_8009691C(u16 actor_index) {
    s32 pad;
    switch (gActors[actor_index].state) {
    case 0:
        func_8009685C(actor_index);
        gActors[actor_index].state = 1;
        gActors[actor_index].unk_168 = gActors[actor_index].var_110;
        /* fallthrough */
    case 1:
        func_800968EC(actor_index);
        break;
    }
}

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

#include "common.h"
#include "actor.h"
#include "Alphabet.h"
#include "music.h"

typedef struct {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
} Unk800D1788;

extern u16 D_800BE4E0;
extern s16 D_800BE558;
extern s16 D_800BE55C;
extern f32 D_800BE5B4;
extern s16 D_800BE5D8;
extern s16 D_800BE5DC;
extern u16 D_800CA230;
extern u32 D_800D28FC;
extern s16 D_800D291C;
extern s16 D_800D2920;
extern s16 D_800D2924;
extern s32 D_800E3578;
extern s32 D_800E357C;
extern u16 D_800E3580; // nearest actor index, updated in func_800289E4
extern s32 D_800E3584;
extern u16 D_80137450;
extern u32 D_80137458;
extern u16 D_80178136;

extern Unk800D1788 D_800D1788[];
extern u8 D_800D17FC[];
extern s8 D_800D2204[];
extern s8 D_800D2228[];
extern s8 D_800D222C[];
extern u16 D_800D36DC[];
extern u16 D_800D36FC[];

// forward declarations
void func_8002A200(u16 actor_index, s32 max_val);
void func_8002A258(u16 actor_index, s32 max_val);
void func_8002AC30(u16 actor_index, s16 val);

void func_80027370(u16 actor_index, u16 x, u16 y, u16 z) {
    gActors[actor_index].actorType = 0;
    func_8001E2D0(actor_index);
    gActors[actor_index].unk_094 |= 0x800;
    gActors[actor_index].unk_188 = 0;
    gActors[actor_index].posX.whole = x;
    gActors[actor_index].posY.whole = y;
    gActors[actor_index].posZ.whole = z;
}

void func_800273FC(u16 actor_index, u16 arg1, u16 x, u16 y, u16 z) {
    func_80027370(actor_index, x, y, z);
    gActors[actor_index].unk_084 = arg1;
}

void func_80027468(u16 actor_index, u16 arg1, u16 x, u16 y, u16 z, u8 red, u8 green, u8 blue) {
    func_80027370(actor_index, x, y, z);
    gActors[actor_index].unk_0E6 = 0;
    gActors[actor_index].unk_084 = arg1;
    if (red | green | blue) {
        gActors[actor_index].unk_094 |= 0x10;
        gActors[actor_index].colorR = red;
        gActors[actor_index].colorG = green;
        gActors[actor_index].colorB = blue;
    }
}

void func_80027510(u16 actor_index, void* arg1, u16 x, u16 y, u16 z) {
    func_80027370(actor_index, x, y, z);
    gActors[actor_index].unk_0E8 = arg1;
    gActors[actor_index].unk_0E6 = 1;
}

void* func_80027588(u16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    Unk800D1788* temp_v1;

    temp_v1 = &D_800D1788[arg0];
    temp_v1->unk2 = (((arg1 / 2) << 11) + ((arg2 / 2) << 6) + ((arg3 / 2) * 2) + 1);
    temp_v1->unk4 = ((arg1 << 11) + (arg2 << 6) + (arg3 * 2) + 1);
    return temp_v1;
}

void func_80027644(u16 actor_index, u16 arg1, u16 x, u16 y, u16 z, s32 arg5) {
    func_800273FC(actor_index, arg1, x, y, z);
    gActors[actor_index].unk_094 |= 0x200;
    gActors[actor_index].flags |= 8;
    gActors[actor_index].unk_18C = arg5;
}

extern u16 D_800D16C4[];

u16 func_800276DC(u16 actor_index, u8* arg1, u16 x, u16 y, u16 z, s32 arg5) {
    while (*arg1 != 0) {
        if (*arg1 == 0x23) {
            gActors[actor_index].flags = 0;
            actor_index++;
        } else if (*arg1 != 0x20) {
            /////////////////////////////////////////////
            // #######   ###   #     # #     # #######
            // #          #     #   #  ##   ## #
            // #          #      # #   # # # # #
            // #####      #       #    #  #  # #####
            // #          #      # #   #     # #
            // #          #     #   #  #     # #
            // #         ###   #     # #     # #######
            /////////////////////////////////////////////
            // D_800D16C4 is from 26A00 and is likely the wrong symbol
            // likely data in 27F70 which has an appropriate lookup table
            /////////////////////////////////////////////
            func_80027644(actor_index, D_800D16C4[(*arg1) - 0x1A] * 2 + 0x2D2, x, y, z, arg5);
            /////////////////////////////////////////////
            actor_index++;
        }
        arg1++;
        x += 9;
    }
    return actor_index;
}

u16 func_80027800(u16 actor_index, u16 num, u16 x, u16 y, u16 z, s32 arg5) {
    u16 tens;

    tens = 0;
    while (num >= 10) {
        num -= 10;
        tens++;
    }
    func_80027644(actor_index + 0, (tens * 2) + 0x2D2, x, y, z, arg5);
    func_80027644(actor_index + 1, (num * 2) + 0x2D2, x + 9, y, z, arg5);
    return actor_index + 2;
}

u16 func_800278E8(u16 actor_index, u16 num, u16 x, u16 y, u16 z, s32 arg5) {
    u16 hundos;
    u16 tens;
    s32 index;

    tens = 0;
    hundos = 0;
    while (num >= 100) {
        num -= 100;
        hundos++;
    }
    while (num >= 10) {
        num -= 10;
        tens++;
    }
    index = actor_index;
    func_80027644(index, (hundos * 2) + 0x2D2, x, y, z, arg5);
    func_80027644(index + 1, (tens * 2) + 0x2D2, x + 9, y, z, arg5);
    func_80027644(index + 2, (num * 2) + 0x2D2, x + 18, y, z, arg5);
    return index + 3;
}

extern u8 D_800D17B8[];

u16 func_80027A44(u16* str) {
    if (*str < ALPHA_LOWER_A) {
        return 6;
    }
    else if (*str == ALPHA_BOLD_SPACE) {
        return 7;
    }
    else {
        /////////////////////////////////////////////
        // #######   ###   #     # #     # #######
        // #          #     #   #  ##   ## #
        // #          #      # #   # # # # #
        // #####      #       #    #  #  # #####
        // #          #      # #   #     # #
        // #          #     #   #  #     # #
        // #         ###   #     # #     # #######
        /////////////////////////////////////////////
        // FIXME: D_800D17B8 may be the wrong symbol as this could have a positive or negative offset
        // disasm was: return D_800D0E84[*arg0 + 0x826];
        /////////////////////////////////////////////
        return D_800D17B8[*str - 0x10E];
        /////////////////////////////////////////////
    }
}

u16 func_80027A88(u16* str) {
    u16 len0;
    u16 len1;
    len0 = func_80027A44(str++);
    len1 = func_80027A44(str);
    return len1 + len0;
}

u16 func_80027AC8(u16 actor_index, u16* str) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            gActors[actor_index].flags = 0;
            actor_index++;
        }
        str++;
    }
    return actor_index;
}

u16 func_80027B28(u16 actor_index, u16* str, u16 x, u16 y, u16 z) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            func_80027370(actor_index, x, y, z);
            gActors[actor_index].flags |= 0x8;
            gActors[actor_index].unk_084 = (*str * 2) + 0x2D2;
            actor_index++;
            x += func_80027A88(str);
        }
        else {
            x += 14;
        }
        str++;
    }
    return actor_index;
}

u16 func_80027C40(u16 actor_index, u16* str, u16 x, u16 y, u16 z, u8 red, u8 green, u8 blue) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            func_80027370(actor_index, x, y, z);
            gActors[actor_index].flags |= 8;
            gActors[actor_index].unk_084 = (*str * 2) + 0x2D2;
            if (red | green | blue) {
                gActors[actor_index].unk_094 |= 0x10;
                gActors[actor_index].colorR = red;
                gActors[actor_index].colorG = green;
                gActors[actor_index].colorB = blue;
            }
            actor_index++;
            x += func_80027A88(str);
        }
        else {
            x += 14;
        }
        str++;
    }
    return actor_index;
}

u16 func_80027D94(u16 actor_index, u16* str, u16 x, u16 y, u16 z, u8 red, u8 green, u8 blue, f32 scale_x, f32 scale_y) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            func_80027370(actor_index, x, y, z);
            gActors[actor_index].flags |= 8;
            if ((scale_x != 1.0) || (scale_y != 1.0)) {
                gActors[actor_index].unk_094 |= 1;
            }
            gActors[actor_index].scaleX = scale_x;
            gActors[actor_index].scaleY = scale_y;
            gActors[actor_index].unk_084 = (*str * 2) + 0x2D2;
            if (red | green | blue) {
                gActors[actor_index].unk_094 |= 0x10;
                gActors[actor_index].colorR = red;
                gActors[actor_index].colorG = green;
                gActors[actor_index].colorB = blue;
            }
            actor_index++;
        }
        str++;
        x += 16 * scale_x;
    }
    return actor_index;
}

u16 func_8002801C(u16 actor_index, u16* str, u16 x, u16 y, u16 z) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            func_80027370(actor_index, x, y, z);
            gActors[actor_index].unk_094 |= 0x200;
            gActors[actor_index].unk_18C = (s32)D_800D17FC;
            gActors[actor_index].flags |= 0x8;
            gActors[actor_index].unk_084 = (*str * 2) + 0x2D2;
            actor_index++;
            x += func_80027A88(str);
        }
        else {
            x += 14;
        }
        str++;
    }
    return actor_index;
}

u16 func_80028150(u16 actor_index, u16* str, u16 x, u16 y, u16 z) {
    while (*str != ALPHA_NULL) {
        if (*str != 0) {
            func_80027370(actor_index, x, y, z);
            gActors[actor_index].flags |= 8;
            gActors[actor_index].unk_084 = (*str * 2) + 0x2D2;
        }
        else {
            gActors[actor_index].flags = 0;
        }
        actor_index++;
        str++;
        x += 16;
    }
    return actor_index;
}

void func_80028260(u16 arg0, u16 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u16* sp4;
    if ((arg0 == 0) || (arg0 == 1) || (arg0 == 2)) {
        sp4 = (u16*)0x80380400;
    }
    sp4[arg1] = ((arg2 << 8) & 0xF800) | ((arg3 << 3) & 0x7C0) | ((arg4 >> 2) & 0x3E) | 1;
}

void func_800282F0(s16 x, s16 y) {
    func_80012288();
    D_801373E0.unk_20 = 0;
    D_801373E0.unk_24 = 0;
    gActors->posX.whole = x;
    gActors->posY.whole = y;
    D_800BE5D8 = D_800BE558 + x;
    D_800BE5DC = D_800BE55C + y;
    D_800CA230 = 0;
    if (gActors->health < 0) {
        gActors->health = 0;
    }
}

void func_80028380(void) {
    gActors[0].flags = 0;
    D_800CA230 = 1;
    D_80137458 = 0;
    if (gActors[0].health < 0) {
        gActors[0].health = 0;
    }
}

void func_800283BC(u32 arg0, u16 arg1) {
    s16 var_v0;

    var_v0 = (gActors[arg1 & 0xFFF].posX.whole - D_800BE5B4) / 2;
    if (var_v0 >= 0x40) {
        var_v0 = 0x3F;
    }
    else if (var_v0 < -0x40) {
        var_v0 = -0x40;
    }

    if (arg1 & 0x8000) {
        func_80003474(arg0, 0x100, var_v0 + 0x40);
    }
    else {
        func_80003430(arg0, 0x100, var_v0 + 0x40);
    }
}

void func_800284B0(s32 arg0) {
}

// Actor_RangeFindFlag2
u16 func_800284B8(u16 actor_index, u16 end) {
    while (actor_index < end) {
        if (!(gActors[actor_index].flags & 0x2)) {
            return actor_index;
        }
        actor_index++;
    }
    return 0;
}

// Actor_RangeFindFlag2_90ToC0
void func_80028528(void) {
    func_800284B8(0x90, 0xC0);
}

#ifdef NON_MATCHING
// only matches if func_8001E2D0 returns void
// https://decomp.me/scratch/opNVZ
u16 func_8002854C(u16 actor_type, s16 x, s16 y, s16 z) {
    u16 actor_index;

    actor_index = func_800284B8(0x90, 0xC0);
    if (actor_index != 0) {
        gActors[actor_index].actorType = actor_type;
        func_8001E2D0(actor_index);
        gActors[actor_index].posX.whole = x;
        gActors[actor_index].posY.whole = y;
        gActors[actor_index].posZ.whole = z;
    }
    return actor_index;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002854C.s")
#endif

void Actor_ClearRange(u16 actor_index, u16 end) {
    while (actor_index < end) {
        gActors[actor_index].flags = 0;
        actor_index++;
    }
}

void Actor_ClearRange_10To20(void) {
    Actor_ClearRange(0x10, 0x20);
}

void Actor_ClearRange_30To90(void) {
    Actor_ClearRange(0x30, 0x90);
}

void Actor_ClearRange_90ToC0(void) {
    Actor_ClearRange(0x90, 0xC0);
}

void Actor_ClearRange_C0ToC7(void) {
    Actor_ClearRange(0xC0, 0xC7);
}

/////////////////////////////////////////////
// ####### ####### #####   #######
//    #    #     # #    #  #     #
//    #    #     # #     # #     #
//    #    #     # #     # #     #
//    #    #     # #     # #     #
//    #    #     # #    #  #     #
//    #    ####### #####   #######
/////////////////////////////////////////////
// TODO: resolve type of D_80104098
/////////////////////////////////////////////
typedef struct {
    u8 unk0[0x80];
    u16 unk80;
    u8 unk82[0xA0 - 0x82];
} Unk80104098;
extern Unk80104098 D_80104098[0x40];
/////////////////////////////////////////////

void func_800286C8(void) {
    u16 index;
    for (index = 0; index < (u16)ARRAYLENGTH(D_80104098); index++) {
        D_80104098[index].unk80 = 0;
    }
}

void func_80028704(void) {
    Actor_ClearRange_10To20();
    Actor_ClearRange_30To90();
    Actor_ClearRange_90ToC0();
    Actor_ClearRange_C0ToC7();
    func_800286C8();
}

void Actor_ClearSceneActors(void) {
    Actor_ClearRange_10To20();
    Actor_ClearRange_30To90();
    Actor_ClearRange_90ToC0();
    Actor_ClearRange_C0ToC7();
}

u16 func_8002877C(u16 actor_index) {
    s16 temp_v1;

    temp_v1 = D_800BE558 + gActors[actor_index].posX.whole + gActors[actor_index].unk_0AA;
    if (temp_v1 < D_800D2920) {
        gActors[actor_index].posX.whole += D_800D2920 - temp_v1;
        gActors[actor_index].unk_098 |= 4;
        return 1;
    }
    temp_v1 = D_800BE558 + gActors[actor_index].posX.whole + gActors[actor_index].unk_0AC;
    if (temp_v1 > D_800D2924) {
        gActors[actor_index].posX.whole += D_800D2924 - temp_v1;
        gActors[actor_index].unk_098 |= 8;
        return 2;
    }
    return 0;
}

u16 func_8002884C(u16 actor_index) {
    s16 temp_v1;
    temp_v1 = D_800BE558 + gActors[actor_index].posX.whole + gActors[actor_index].unk_0AA;
    if (temp_v1 < D_800D2920) {
        return 0;
    }
    temp_v1 = D_800BE558 + gActors[actor_index].posX.whole + gActors[actor_index].unk_0AC;
    if (temp_v1 > D_800D2924) {
        return 0;
    }
    return 1;
}

// Actor_IsOutsideBox
u16 func_800288EC(u16 actor_index, s16 length) {
    if ((gActors[actor_index].posX.whole > (0x90 + length)) || (gActors[actor_index].posX.whole < (-0x90 - length)) || 
        (gActors[actor_index].posY.whole > (0x60 + length)) || (gActors[actor_index].posY.whole < (-0x60 - length))) {
        return 1;
    }
    else {
        return 0;
    }
}

// Actor_OutsideBoxSound
void func_80028980(u16 arg0, s16 arg1, u32 arg2) {
    if (func_800288EC(arg0, arg1) == 0) {
        func_800036C8(arg2, arg0);
    }
}

// Math_AbsS32()
s32 func_800289CC(s32 arg0) {
    if (arg0 < 0) {
        return -arg0;
    }
    else {
        return arg0;
    }
}

// Actor_NearestFromList
void func_800289E4(u16 actor_index, u16* actor_list, s16 max_dist) {
    s16 dist_x;
    u16 index;

    D_800E3580 = 0;
    while (*actor_list != 0) {
        index = *actor_list;
        dist_x = func_800289CC(gActors[actor_index].posX.whole - gActors[index].posX.whole);
        if (dist_x < max_dist) {
            D_800E3580 = index;
            max_dist = dist_x;
        }
        actor_list++;
    }
}

// Actor_UpdateNearest
void func_80028AE8(u16 actor_index) {
    func_800289E4(actor_index, D_800D36FC, 0x7FFF);
}

void func_80028B1C(u16 actor_index) {
    s16 dist = func_800289CC(gActors[actor_index].posX.whole - gActors[0].posX.whole);
    func_800289E4(actor_index, D_800D36DC, dist);
}

void func_80028B90(u16 actor_index) {
    u16 other_index = gActors[actor_index].unk_0D6;
    if (gActors[actor_index].posX.whole < gActors[other_index].posX.whole) {
        gActors[actor_index].unk_0F8 = -gActors[other_index].unk_0F8;
    }
    else {
        gActors[actor_index].unk_0F8 = gActors[other_index].unk_0F8;
    }
}

void func_80028C00(s32 arg0) {
}

s32 func_80028C08(u16 actor_index) {
    u16 other_index = gActors[actor_index].unk_0D6;
    if ((gActors[other_index].flags & 0x2) && (gActors[other_index].health > 0)) {
        gActors[other_index].unk_0D6 = actor_index;
        gActors[other_index].unk_098 |= 0x200;
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80028C80(u16 actor_inde) {
    if (gActors[actor_inde].unk_098 & 0x200) {
        gActors[actor_inde].posX.raw = gActors[actor_inde].unk_104;
        gActors[actor_inde].posY.raw = gActors[actor_inde].unk_108;
        gActors[actor_inde].posZ.raw = gActors[actor_inde].unk_10C;
        return 0;
    }
    else {
        return 1;
    }
}

void func_80028CE8(u16 actor_index) {
    gActors[actor_index].velocityX = gActors[actor_index].unk_0F8;
    gActors[actor_index].velocityY = gActors[actor_index].unk_0FC;

    gActors[actor_index].flags &= ~0x280;
    if (gActors[gActors[actor_index].unk_0D6].flags & 0x100) {
        gActors[actor_index].flags |= 0x80;
    }
    else {
        gActors[actor_index].flags |= 0x200;
    }

    if (gActors[actor_index].velocityX != 0) {
        if (gActors[actor_index].velocityX < 0) {
            gActors[actor_index].flags |= 0x20;
        }
        else {
            gActors[actor_index].flags &= ~0x20;
        }
    }
}

// TODO: func_8001FCA0 only matches if arg1/arg2 are `s16`, but only matches below as `s32`
// see https://decomp.me/scratch/ZJ7E3
#if 0
u8 func_8001FCA0(u16 arg0, s16 arg1, s16 arg2);
#else
u8 func_8001FCA0(u16 arg0, s32 arg1, s32 arg2);
#endif
s32 func_80028DAC(u16 arg0, s16 arg1) {
    if ((func_8001FCA0(arg0, arg1, gActors[0].posY.whole + 2) & 0x80) &&
        (func_8001FCA0(arg0, arg1, gActors[0].posY.whole + 2) & 0x80)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80028E1C(u16 arg0) {
    s16 actor0_pos;
    if (gActors[arg0].unk_098 & 0x200) {
        if (D_80137450 == arg0) {
            if ((gActors[0].unk_140_u8 == 0) && (gActors[0].posY.whole < gActors[arg0].posY.whole)) {
                actor0_pos = gActors[0].posY.whole;
                while (actor0_pos < gActors[arg0].posY.whole) {
                    if (func_8001FCA0(arg0, gActors[0].posX.whole, actor0_pos) & 0x80) {
                        gActors[0].unk_098 = 0x10000;
                        gActors[0].unk_0F8 = 0;
                        gActors[0].unk_0FC = -0x30000;
                        func_800036C8(100, arg0);
                        return 1;
                    }
                    actor0_pos += 16;
                }
            }
            else if (gActors[0].unk_140_u8 == 4) {
                if (gActors[0].flags & 0x20) {
                    actor0_pos = gActors[0].posX.whole;
                    while (gActors[arg0].posX.whole < actor0_pos) {
                        if (func_80028DAC(arg0, actor0_pos) != 0) {
                            gActors[0].unk_098 = 0x10000;
                            gActors[0].unk_0F8 = 0x30000;
                            gActors[0].unk_0FC = 0;
                            func_800036C8(100, arg0);
                            return 1;
                        }
                        actor0_pos -= 16;
                    }
                }
                else {
                    actor0_pos = gActors[0].posX.whole;
                    while (actor0_pos < gActors[arg0].posX.whole) {
                        if (func_80028DAC(arg0, actor0_pos) != 0) {
                            gActors[0].unk_098 = 0x10000;
                            gActors[0].unk_0F8 = -0x30000;
                            gActors[0].unk_0FC = 0;
                            func_800036C8(100, arg0);
                            return 1;
                        }
                        actor0_pos += 16;
                    }
                }
            }
        }
    }
    return 0;
}

s32 func_80029044(u16 arg0) {
    s32 x;
    s32 y;
    if ((gActors[arg0].unk_098 & 0x200) && (D_80137450 == arg0)) {
        x = ((gActors[arg0].posX.whole - gActors[0].posX.whole) / 2) + gActors[0].posX.whole;
        y = ((gActors[arg0].posY.whole - gActors[0].posY.whole) / 2) + gActors[0].posY.whole;
        if (func_8001FCA0(arg0, x, y) & 0x80) {
            gActors->unk_098 = 0x10000;
            gActors->unk_0F8 = 0;
            gActors->unk_0FC = 0x30000;
            func_800036C8(100, arg0);
            return 1;
        }
    }
    return 0;
}

void func_80029134(u16 actor_index) {
    gActors[actor_index].flags &= 0xFFFEEFFF; \
    gActors[actor_index].flags |= 0x20000;
    gActors[actor_index].velocityX = 0;
    gActors[actor_index].velocityY = 0;
    gActors[actor_index].unk_0F4 = 0;
    gActors[actor_index].posX.raw = gActors[actor_index].unk_104;
    gActors[actor_index].posY.raw = gActors[actor_index].unk_108;
    gActors[actor_index].posZ.raw = gActors[actor_index].unk_10C;
}

s32 func_800291AC(u16 actor_index, u16 state1, s32 flags1, u16 state2, s32 flags2) {
    if (gActors[actor_index].unk_098 & 0x200) {
        func_8002AC30(actor_index, 8);
        gActors[actor_index].unk_098 |= 0x80000;
        gActors[actor_index].velocityX = 0;
        gActors[actor_index].velocityY = 0;
        gActors[actor_index].unk_0F4 = 0;
        gActors[actor_index].posX.raw = gActors[actor_index].unk_104;
        gActors[actor_index].posY.raw = gActors[actor_index].unk_108;
        gActors[actor_index].posZ.raw = gActors[actor_index].unk_10C;
        if (gActors->stateLower == 0x26) {
            if (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) & 0x80) {
                gActors[actor_index].posX.raw = gActors->posX.raw;
            }
        }
        if (func_80028E1C(actor_index) != 0) {
            gActors[actor_index].state = state2;
            gActors[actor_index].flags = (gActors[actor_index].flags & 0x20) + (flags2 & 0x6B503);
            return 3;
        }
        else {
            if (flags1 & 0x20) {
                gActors[actor_index].flags &= ~0x20;
                gActors[actor_index].flags |= (gActors[gActors[actor_index].unk_0D6].flags & 0x20);
            }
            if ((gActors[actor_index].unk_098 & 2) && (D_80137450 == actor_index)) {
                if (gActors[actor_index].unk_0DD != 0x15) {
                    gActors->unk_0DC = 0;
                    gActors->unk_098 |= 2;
                    gActors->unk_0DD = 0x11;
                    gActors->unk_0F8 = gActors[actor_index].unk_0F8;
                    gActors->unk_0FC = gActors[actor_index].unk_0FC;
                    func_8002A200(0, 0x40000);
                    func_8002A258(0, 0x20000);
                    gActors->unk_0E2 = 0;
                }
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    else if (gActors[actor_index].unk_098 & 0x400) {
        gActors[actor_index].state = state1;
        gActors[actor_index].flags = (gActors[actor_index].flags & 0x20) + (flags1 & 0x6B503);
        gActors[actor_index].velocityX = gActors[actor_index].unk_0F8;
        gActors[actor_index].velocityY = gActors[actor_index].unk_0FC;
        if (flags1 & 0x280) {
            if (gActors[gActors[actor_index].unk_0D6].flags & 0x100) {
                gActors[actor_index].flags |= 0x80;
            }
            else {
                gActors[actor_index].flags |= 0x200;
            }
        }
        if (flags1 & 0x20) {
            if (gActors[actor_index].velocityX != 0) {
                if (gActors[actor_index].velocityX < 0) {
                    gActors[actor_index].flags |= 0x20;
                }
                else {
                    gActors[actor_index].flags &= ~0x20;
                }
            }
        }
        return 2;
    }
    gActors[actor_index].state = state2;
    gActors[actor_index].flags = (gActors[actor_index].flags & 0x20) + (flags2 & 0x6B503);
    return 3;
}

// Math_Atan2?
s32 func_800294E0(s32 arg0, s32 arg1) {
    s32 tmp;
    s32 var_v1;
    s32 var_a0;
    s8* var_v0;
    u8 ret;

    var_v0 = D_800D2228;
    if (arg0 == 0) {
        return (arg1 > 0) ? 0x100 : 0x300;
    }
    if (arg1 == 0) {
        return (arg0 > 0) ? 0 : 0x200;
    }
    if (arg0 < 0) {
        arg0 = -arg0;
        var_v0 = D_800D222C;
    }
    if (arg1 < 0) {
        arg1 = -arg1;
        var_v0 += 2;
    }
    if (arg0 < arg1) {
        tmp = arg0;
        arg0 = arg1;
        arg1 = tmp;
        var_v0 += 1;
    }
    var_v1 = (arg0 * 4) / arg1;
    if (var_v1 > 35) {
        var_v1 = 35;
    }
    var_v1 = D_800D2204[var_v1];
    var_a0 = *var_v0;
    if (var_a0 < 0) {
        var_v1 = -var_v1;
    }
    var_v1 += (var_a0 * 2);
    return (var_v1 & 0xFF) * 4;
}

s32 func_800295D8(s32 arg0, s32 arg1) {
    return (func_800294E0(arg0, arg1) + 0x100) & 0x200;
}

s32 func_80029600(s32 arg0, s32 arg1) {
    return (func_800294E0(arg0, arg1) + 0x80) & 0x300;
}

s32 func_80029628(s32 arg0, s32 arg1) {
    return (func_800294E0(arg0, arg1) + 0x40) & 0x380;
}

s32 func_80029650(s32 arg0, s32 arg1) {
    return (func_800294E0(arg0, arg1) + 0x20) & 0x3C0;
}

s32 func_80029678(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    s16 temp_t2;
    s32 var_v1;
    u16 low_bits;

    var_v1 = 0;
    temp_t2 = arg0;
    temp_t2 -= (arg2 * arg1);

    if ((temp_t2 >= 0) && (arg3 < temp_t2)) {
        var_v1 = 0x20000000;
        temp_t2 = 0;
        arg0 = 0;
    }

    if (temp_t2 <= 0) {
        if ((arg0 % arg2) == 0) {
            var_v1 |= 0x80000000;
        }
        var_v1 |= ((arg0 / arg2) << 16);
    }
    else {
        var_v1 = 0x40000000;
    }

    low_bits = arg0 + 0;
    return var_v1 | low_bits;
}

u16 func_80029798(u16 actor_index) {
    Actor* actor;
    s32 prev_flags;

    if (D_800D28FC & 0x400) {
        actor = &gActors[actor_index];
        if ((D_800BE55C + actor->posY.whole) < (D_800D291C - 0x10)) {
            prev_flags = actor->flags;
            actor->flags = 0;
            return prev_flags;
        }
    }
    return 0;
}

s32 Math_ApproachS32(s32 current, s32 target, s32 step) {
    if ((current - target) > 0) {
        if (step >= (current - target)) {
            current = target;
        }
        else {
            current -= step;
        }
    }
    else if ((current - target) >= -step) {
        current = target;
    }
    else {
        current += step;
    }
    return current;
}

f32 Math_ApproachF32(f32 current, f32 target, f32 step) {
    if ((current - target) > 0) {
        if (step >= (current - target)) {
            current = target;
        }
        else {
            current -= step;
        }
    }
    else if ((current - target) >= -step) {
        current = target;
    }
    else {
        current += step;
    }
    return current;
}

s32 func_800298D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_t7;

    arg1 &= 0x03FFFFFF;
    temp_v0 = arg0 - arg1;
    temp_v1 = temp_v0 & 0x03FFFFFF;
    temp_t7 = 0x04000000 - arg2;
    if ((arg2 >= temp_v1) || (temp_v1 >= temp_t7)) {
        return arg0;
    }

    if (arg0 >= arg1) {
        if (temp_v0 < 0x02000000) {
            arg1 += arg2;
        }
        else {
            arg1 -= arg2;
        }
    }
    else if (temp_v0 >= -0x01FFFFFF) {
        arg1 -= arg2;
    }
    else {
        arg1 += arg2;
    }
    return arg1 & 0x03FFFFFF;
}

s32 func_8002995C(s32 arg0, s32 arg1) {
    if (arg0 >= arg1) {
        if ((arg0 - arg1) < 0x02000000) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        if ((arg0 - arg1) >= -0x01FFFFFF) {
            return -1;
        }
        else {
            return 1;
        }
    }
}

void func_800299B0(u16 actor_index) {
    if ((gActors[actor_index].velocityX > 0) && (gActors[actor_index].unk_098 & 0x8)) {
        gActors[actor_index].velocityX = 0;
    }
    if ((gActors[actor_index].velocityX < 0) && (gActors[actor_index].unk_098 & 0x4)) {
        gActors[actor_index].velocityX = 0;
    }
    if ((gActors[actor_index].velocityY > 0) && (gActors[actor_index].unk_098 & 0x10)) {
        gActors[actor_index].velocityY = 0;
    }
    if ((gActors[actor_index].velocityY < 0) && (gActors[actor_index].unk_098 & 0x20)) {
        gActors[actor_index].velocityY = 0;
    }
}

s32 func_80029A7C(s16 arg0, s16 arg1, s16 arg2) {
    if ((D_800E3584 & 0x10000) &&
        (arg0 > D_800E3578) && (-arg0 < D_800E3578) &&
        (arg1 > D_800E357C) && (arg2 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029B00(s16 arg0, s16 arg1, s16 arg2) {
    if ((D_800E3578 < arg0) && (-arg0 < D_800E3578) && (D_800E357C < arg1) && (arg2 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029B74(s16 arg0) {
    if ((D_800E3578 < arg0) && (-arg0 < D_800E3578)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029BB4(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if ((D_800E3584 & 0x10000) &&
        (arg1 > D_800E3578) && (arg0 < D_800E3578) &&
        (arg2 > D_800E357C) && (arg3 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029C44(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if ((arg0 < D_800E3578) && (arg1 > D_800E3578) &&
        (arg2 > D_800E357C) && (arg3 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029CC0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if ((((arg0 < D_800E3578) && (arg1 > D_800E3578)) ||
        ((-arg0 > D_800E3578) && (-arg1 < D_800E3578))) &&
         (arg2 > D_800E357C) && (arg3 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029D58(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if ((D_800E3584 & 0x30000) &&
        (arg1 > D_800E3578) && (arg0 < D_800E3578) &&
        (arg2 > D_800E357C) && (arg3 < D_800E357C)) {
        return 1;
    }
    else {
        return 0;
    }
}

s32 func_80029DEC(u16 arg0, u16 arg1) {
    if (!(D_800BE4E0 & arg0) && !(func_8000178C() & arg1)) {
        return 1;
    }
    else {
        return 0;
    }
}

u16 func_80029E48(u16 actor_index, s16 arg1, s16 arg2) {
    Actor* actor;
    s16 temp_v0;
    s16 temp_t0;
    u16 var_v1;

    actor = &gActors[actor_index];
    temp_v0 = D_800BE558 + actor->posX.whole;
    if ((arg1 >= temp_v0) || (arg2 < temp_v0)) {
        var_v1 = 0x8000;
    }
    else {
        var_v1 = 0;
    }
    temp_t0 = (arg1 + ((arg2 - arg1) / 2));
    if (temp_t0 < temp_v0) {
        var_v1 |= 0x1;
    }
    return var_v1;
}

u16 func_80029F00(u16 actor_index, s16 arg1, s16 arg2) {
    Actor* actor;
    s16 temp_v0;
    s16 temp_t0;
    u16 var_v1;

    actor = &gActors[actor_index];
    temp_v0 = D_800BE55C + actor->posY.whole;
    if ((arg2 >= temp_v0) || (arg1 < temp_v0)) {
        var_v1 = 0x8000;
    }
    else {
        var_v1 = 0;
    }
    temp_t0 = arg2 + ((s32) (arg1 - arg2) / 2);
    if (temp_t0 < temp_v0) {
        var_v1 |= 0x2;
    }
    return var_v1;
}

u16 func_80029FB8(u16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_80029E48(arg0, arg1, arg2) | func_80029F00(arg0, arg3, arg4);
}

s16* func_8002A018(s16* arg0, s16 arg1) {
    s16 var_a1;
    s16 var_v0;
    s16* var_v1;

    var_v1 = arg0;
    var_v0 = 0x7FFF;
    while (*arg0 != 0x765) {
        var_a1 = *arg0 - arg1;
        if (var_a1 < 0) {
            var_a1 = -var_a1;
        }
        if (var_a1 < var_v0) {
            var_v1 = arg0;
            var_v0 = var_a1;
        }
        arg0++;
    }
    return var_v1;
}

s32 func_8002A090(s32 arg0, s32 arg1) {
    if (arg1 < 0) {
        arg1 = -arg1;
    }
    if (arg1 < arg0) {
        arg0 = arg1;
    }
    if (arg0 < -arg1) {
        arg0 = -arg1;
    }
    return arg0;
}

void func_8002A0C4(u16 actor_index, s32 velocity_x) {
    if (gActors[actor_index].flags & 0x20) {
        gActors[actor_index].velocityX = -velocity_x;
    }
    else {
        gActors[actor_index].velocityX = velocity_x;
    }
}

// Actor_CapVelocityX
void func_8002A118(u16 actor_index, s32 max_val) {
    gActors[actor_index].velocityX = func_8002A090(gActors[actor_index].velocityX, max_val);
}

// Actor_CapVelocityY
void func_8002A170(u16 actor_index, s32 max_val) {
    gActors[actor_index].velocityY = func_8002A090(gActors[actor_index].velocityY, max_val);
}

// Actor_CapVelocity
void func_8002A1C8(u16 actor_index, s32 max_val) {
    func_8002A118(actor_index, max_val);
    func_8002A170(actor_index, max_val);
}

// Actor_Cap_0F8 (related to VelX)
void func_8002A200(u16 actor_index, s32 max_val) {
    gActors[actor_index].unk_0F8 = func_8002A090(gActors[actor_index].unk_0F8, max_val);
}

// Actor_Cap_0FC (related to VelY)
void func_8002A258(u16 actor_index, s32 max_val) {
    gActors[actor_index].unk_0FC = func_8002A090(gActors[actor_index].unk_0FC, max_val);
}

// Actor_Cap_0F8_0FC (related to VelY)
void func_8002A2B0(u16 actor_index, s32 max_val) {
    gActors[actor_index].unk_0F8 = func_8002A090(gActors[actor_index].unk_0F8, max_val);
    gActors[actor_index].unk_0FC = func_8002A090(gActors[actor_index].unk_0FC, max_val);
}

void func_8002A320(u16 actor_index, s32 dist) {
    s16 angle;
    angle = func_800294E0(gActors[actor_index].velocityX, gActors[actor_index].velocityY);
    gActors[actor_index].unk_0F8 = COS(angle) * dist;
    gActors[actor_index].unk_0FC = SIN(angle) * dist;
}

// Actor_UpdateVelocityX
void func_8002A404(u16 actor_index, s32 dvx) {
    gActors[actor_index].velocityX = Math_ApproachS32(gActors[actor_index].velocityX, 0, dvx);
}

// Actor_UpdateVelocityY
void func_8002A464(u16 actor_index, s32 dvy) {
    gActors[actor_index].velocityY = Math_ApproachS32(gActors[actor_index].velocityY, 0, dvy);
}

// Actor_UpdateVelocity
void func_8002A4C4(u16 actor_index, s32 dvx, s32 dvy) {
    func_8002A404(actor_index, dvx);
    func_8002A464(actor_index, dvy);
}

s32 func_8002A4FC(u16 arg0) {
    if (gActors[arg0].velocityX > 0) {
        if (gActors[arg0].unk_098 & 0x8) {
            gActors[arg0].velocityX = 0;
            return 1;
        }
    }
    else {
        if (gActors[arg0].unk_098 & 0x4) {
            gActors[arg0].velocityX = 0;
            return 2;
        }
    }
    // TODO: missing return
}

void func_8002A57C(u16 actor_index, s32 arg1, s32 arg2, s32 max_vx) {
    gActors[actor_index].velocityX = (arg2 - gActors[actor_index].posX.raw) / ((gActors[actor_index].velocityY / arg1) * 2 + 1);
    if (gActors[actor_index].velocityX > 0) {
        if (gActors[actor_index].velocityX > max_vx) {
            gActors[actor_index].velocityX = max_vx;
        }
    }
    else {
        if (gActors[actor_index].velocityX < -max_vx) {
            gActors[actor_index].velocityX = -max_vx;
        }
    }
}

#ifdef NON_MATCHING
// matches: https://decomp.me/scratch/r3ke1
// TODO: need to map .rodata
s32 func_8002A658(u16 arg0) {
    u8 var_v0;
    u8 var_v1;

    if (gActors[0].unk_140_u8 & 0x80) {
        var_v0 = ((gActors[arg0].unk_0C4 / 0.3515625) / 64) + 4.0;
        var_v0 &= 0xF;
        switch (gActors[0].unk_140_u8 & 0xF) {
            case 0:
                if (!(gActors[0].flags & 0x20)) {
                    var_v1 = ((var_v0 == 0) || (var_v0 >= 8)) ? 2 : 14;
                }
                else {
                    var_v1 = (var_v0 >= 9) ? 2 : 14;
                }
                break;
            case 4:
                var_v1 = ((var_v0 >= 4) && (var_v0 < 0xD)) ? 2 : 6;
                break;
            case 12:
                var_v1 = ((var_v0 >= 4) && (var_v0 < 0xD)) ? 14 : 10;
                break;
            case 8:
                if (!(gActors[0].flags & 0x20)) {
                    var_v1 = ((var_v0 == 0) || (var_v0 >= 8)) ? 6 : 10;
                }
                else {
                    var_v1 = (var_v0 >= 9) ? 6 : 10;
                }
                break;
        }
        return (-var_v1 << 22) + 0x01000000;
    }
    else {
        return (-gActors[0].unk_140_u8 << 22) + 0x01000000;
    }
}
#else
s32 func_8002A658(u16 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002A658.s")
#endif

s32 func_8002A898(u16 actor_index) {
    gActors[actor_index].flags &= ~0x600;
    gActors[actor_index].flags |= 0x80;
    return func_8002A658(actor_index);
}

s32 func_8002A900(u16 andex0, u16 andex1) {
    return (gActors[andex0].unk_0AC + gActors[andex0].unk_0AA) / 2 + gActors[andex1].posX.whole + 
           (gActors[andex1].unk_0AA + gActors[andex1].unk_0AC) / 2 - gActors[andex0].posX.whole;
}

s32 func_8002A990(u16 andex0, u16 andex1) {
    return ((gActors[andex0].unk_0AE + gActors[andex0].unk_0B0) / 2) + gActors[andex1].posY.whole + 
           ((gActors[andex1].unk_0B0 + gActors[andex1].unk_0AE) / 2) - gActors[andex0].posY.whole;
}

void func_8002AA20(u16 actor_index, s32 arg1) {
    s32 var_v0;
    s32 var_v1;

    D_800E3584 = 0;
    if (D_800E3580 != actor_index) {
        D_800E3578 = func_8002A900(actor_index, D_800E3580);
        D_800E357C = func_8002A990(actor_index, D_800E3580);
        if (D_800E3578 < 0) {
            var_v1 = (gActors[actor_index].flags & 0x20) ? 1 : 0;
            var_v0 = (gActors[D_800E3580].flags & 0x20) ? 1 : 0;
        }
        else {
            var_v1 = (gActors[actor_index].flags & 0x20) ? 0 : 1;
            var_v0 = (gActors[D_800E3580].flags & 0x20) ? 0 : 1;
        }

        if (var_v1) {
            if (var_v0) {
                D_800E3584 |= 0x20000;
            }
            else {
                D_800E3584 |= 0x10000;
            }
        }
        else {
            if (var_v0) {
                D_800E3584 |= 0x80000;
            }
            else {
                D_800E3584 |= 0x40000;
            }
        }
    }
}

void func_8002ABE4(u16 actor_index, s16 val) {
    gActors[actor_index].unk_0A6 = val;
    gActors[actor_index].unk_0A8 = -val;
    gActors[actor_index].unk_0A2 = -val;
    gActors[actor_index].unk_0A4 = val;
}

void func_8002AC30(u16 actor_index, s16 val) {
    gActors[actor_index].unk_0AE = val;
    gActors[actor_index].unk_0B0 = -val;
    gActors[actor_index].unk_0AA = -val;
    gActors[actor_index].unk_0AC = val;
}

void func_8002AC7C(u16 actor_index, s16 arg1, s16 arg2) {
    if (gActors[actor_index].flags & 0x20) {
        gActors[actor_index].unk_0A4 = -arg1;
        gActors[actor_index].unk_0A2 = -arg2;
    }
    else {
        gActors[actor_index].unk_0A2 = arg1;
        gActors[actor_index].unk_0A4 = arg2;
    }
}

void func_8002ACFC(u16 actor_index, s16 arg1, s16 arg2) {
    if (gActors[actor_index].flags & 0x20) {
        gActors[actor_index].unk_0AC = -arg1;
        gActors[actor_index].unk_0AA = -arg2;
    }
    else {
        gActors[actor_index].unk_0AA = arg1;
        gActors[actor_index].unk_0AC = arg2;
    }
}

s32 func_8002AD7C(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_t0;
    s32 temp_t4;
    s32 temp_v0;

    gActors[arg0].unk_18C &= ~1;
    arg2 &= 0x3FF;
    temp_v0 = arg1 - arg2;
    temp_t0 = temp_v0 & 0x3FF;
    temp_t4 = 0x400 - arg3;
    if ((arg3 >= temp_t0) || (temp_t0 >= temp_t4)) {
        gActors[arg0].unk_18C |= 1;
        return arg1;
    }

    if (arg1 >= arg2) {
        if (temp_v0 < 0x200) {
            arg2 += arg3;
        }
        else {
            arg2 -= arg3;
        }
    }
    else {
        if (temp_v0 >= -0x1FF) {
            arg2 -= arg3;
        }
        else {
            arg2 += arg3;
        }
    }
    return arg2 & 0x3FF;
}

// clamps colors to +/-arg1
u16 func_8002AE44(s16 arg0, s16 arg1) {
    if (arg1 < 0) {
        if (-arg1 >= arg0) {
            return 0;
        }
        else {
            return (arg0 + arg1);
        }
    }
    else {
        arg0 += arg1;
        if (arg0 >= 0x100) {
            return 0xFF;
        }
        else {
            return arg0;
        }
    }
}

void Actor_SetColorRgb(u16 actor_index, u16 color) {
    gActors[actor_index].colorR = color;
    gActors[actor_index].colorG = color;
    gActors[actor_index].colorB = color;
}

// clamp actor's RGB to arg1
void func_8002AEF8(u16 actor_index, s16 arg1) {
    gActors[actor_index].colorR = func_8002AE44(gActors[actor_index].colorR, arg1);
    gActors[actor_index].colorG = func_8002AE44(gActors[actor_index].colorG, arg1);
    gActors[actor_index].colorB = func_8002AE44(gActors[actor_index].colorB, arg1);
}

void func_8002AF7C(u16 actor_index, u16 arg1, s16 arg2) {
    if (!(D_800BE4E0 & arg1)) {
        gActors[actor_index].colorR = 0x7F;
        gActors[actor_index].colorG = 0x7F;
        gActors[actor_index].colorB = 0x7F;
    }
    else {
        func_8002AEF8(actor_index, arg2);
    }
}

u8 func_8002B010(u16 actor_index, s16 arg1, s16 arg2) {
    if (arg2 > 0) {
        if (gActors[actor_index].unk_094 & 0x10) {
            arg1 = arg1 - arg2;
            if (arg1 < 0) {
                gActors[actor_index].unk_094 &= 0xFFEF;
                arg1 = -arg1;
            }
        }
        else {
            arg1 = arg1 + arg2;
        }
    } else {
        if (gActors[actor_index].unk_094 & 0x10) {
            arg1 = arg1 - arg2;
        }
        else {
            arg1 = arg1 + arg2;
            if (arg1 < 0) {
                gActors[actor_index].unk_094 |= 0x10;
                arg1 = -arg1;
            }
        }
    }

    if (arg1 >= 0x80) {
        return 0x7F;
    }
    else {
        return arg1;
    }
}

void func_8002B140(u16 actor_index, s16 arg1) {
    gActors[actor_index].colorR = func_8002B010(actor_index, gActors[actor_index].colorR, arg1);
    gActors[actor_index].colorG = func_8002B010(actor_index, gActors[actor_index].colorG, arg1);
    gActors[actor_index].colorB = func_8002B010(actor_index, gActors[actor_index].colorB, arg1);
}

void func_8002B1D0(u16 actor_index, s16 arg1) {
    gActors[actor_index].colorR = Math_ApproachS32(gActors[actor_index].colorR, 0, arg1);
    gActors[actor_index].colorG = Math_ApproachS32(gActors[actor_index].colorG, 0, arg1);
    gActors[actor_index].colorB = Math_ApproachS32(gActors[actor_index].colorB, 0, arg1);
}

void func_8002B25C(u16 actor_index, s16 arg1) {
    gActors[actor_index].colorR = func_8002B010(actor_index, gActors[actor_index].colorR, arg1);
    gActors[actor_index].colorG = gActors[actor_index].colorR;
    gActors[actor_index].colorB = gActors[actor_index].colorR;
}

void func_8002B2D0(u16 actor_index) {
    gActors[actor_index].unk_094 &= 0xFFEF;
    gActors[actor_index].colorR = (-D_800BE4E0 & 0xF) << 3;
    gActors[actor_index].colorG = gActors[actor_index].colorR;
    gActors[actor_index].colorB = gActors[actor_index].colorR;
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B4D0.s")

u16 Palette_AdjustRgb5551(u16 color, s16 blue_offset, s16 green_offset, s16 red_offset) {
    s16 clamped_blue;
    s16 clamped_green;
    s16 clamped_red;

    clamped_blue = ((color / 2) & 0x1F) + blue_offset;
    clamped_green = ((color / 0x40) & 0x1F) + green_offset;
    clamped_red = ((color / 0x800) & 0x1F) + red_offset;

    if (clamped_blue < 0) {
        clamped_blue = 0;
    }
    else if (clamped_blue >= 0x20) {
        clamped_blue = 0x1F;
    }

    if (clamped_green < 0) {
        clamped_green = 0;
    }
    else if (clamped_green >= 0x20) {
        clamped_green = 0x1F;
    }

    if (clamped_red < 0) {
        clamped_red = 0;
    }
    else if (clamped_red >= 0x20) {
        clamped_red = 0x1F;
    }

    return (clamped_red << 11) | (clamped_green << 6) | (clamped_blue << 1) | (color & 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B7B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B7F4.s")

void Palette_AdjustRgb5551Array(u16* src, u16* dst, s16 count, s16 blue_offset, s16 green_offset, s16 red_offset) {
    u16 result;
    while (count > 0) {
        result = Palette_AdjustRgb5551(*src, blue_offset, green_offset, red_offset);
        count--;
        src++;
        dst++;
        dst[-1] = result; // wtf??
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002B9D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002BACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002BB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002BC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002BC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C140.s")

void func_8002C1D8(s32 arg0) {
}

void func_8002C1E0(u16* src, u16* dst, u16 count) {
    while (count > 0) {
        *dst = *src;
        count--;
        src++;
        dst++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C5C4.s")

void func_8002C6DC(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002C6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002CCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002D904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002DB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002DC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002DFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002E288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002E500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002E89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002EBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002ECAC.s")

void func_8002ED34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002ED48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002EDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002EFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F420.s")

void func_8002F6AC(void) {
    if (D_80178136 >= 0x270F) {
        D_80178136 = 0x270F;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002F93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002FC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002FD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8002FEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800303A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800309C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030A24.s")

void func_80030A74(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030A74.s")

void func_80030B0C(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030B0C.s")

void func_80030B84(u16 arg0) {
    func_80030A74(arg0);
    func_80030B0C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80030F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800310A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800311EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003123C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800312CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003137C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800313CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003141C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80031E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800320F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800327B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80032900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80032E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800330A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800333A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003358C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800335E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800336B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800337F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800338F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033948.s")

void func_800339AC(s32 arg0, s32 arg1, s32 arg2) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800339BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80033E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800340CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80034644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003480C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800348E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800349C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80034A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80034D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80034D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80034E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003510C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800351C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003526C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800352C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035878.s")

s32 func_800358CC(s32 arg0, s32 arg1) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800358DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80035E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003667C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800366E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800367D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800369A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80036A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80036B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80036C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80036CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80036DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003707C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800370AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800374D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003766C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80037B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80037B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800384FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80038FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800390BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003929C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800398F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80039E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003A120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003A958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003A9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003AA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003AB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003AC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003B630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003B8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003BE3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003C328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003D518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003D5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003D628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003D68C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003D794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003DBD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003DF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003E230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003E52C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003E640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003E6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003E854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003EAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003EC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003ED48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003EDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003EEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003EF98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F8B0.s")

void func_8003F9CC(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003F9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003FB20.s")

void func_8003FD0C(s32, s16, s16, s16, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003FD0C.s")

void func_8003FE4C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8003FD0C(arg0, arg1, arg2, arg3, 0);
}

void func_8003FE90(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8003FD0C(arg0, arg1, arg2, arg3, 1);
}

void func_8003FED8(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8003FD0C(arg0, arg1, arg2, arg3, 2);
}

void func_8003FF20(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8003FD0C(arg0, arg1, arg2, arg3, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8003FF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004023C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800404AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800405C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800406A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800407D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004089C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800409E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80040E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80041018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004151C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004168C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004172C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004178C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_8004185C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800418A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042290.s")

void func_80042308(s32 arg0) {
}

void func_80042310(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_80042324(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_80042338(s32 arg0) {
}

void func_80042340(s32 arg0) {
}

void func_80042348(s32 arg0) {
}

void func_80042350(s32 arg0) {
}

void func_80042358(s32 arg0) {
}

void Actor_AdvanceState(u16 actor_index) {
    gActors[actor_index].state++;
}

void func_800423A0(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800423A0.s")

void func_800427E0(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800427E0.s")

void func_80042864(u16);
#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_800429A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042A0C.s")

void func_80042AEC(u16 arg0) {
    func_80042864(arg0);
    func_800423A0(arg0);
    func_800427E0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042B2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/27F70/func_80042C10.s")

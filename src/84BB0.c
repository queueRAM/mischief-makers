#include "common.h"
#include "28EF0.h"

extern u16 D_800E3D20[]; // array of graphic indices, used in func_80084974
extern u8 D_800E3D2C[];

void func_80083FB0(s16 x, s16 y) {
    u16 actor_index;

    actor_index = func_8003EEC0(1.0 - ((f32) (Rand() & 3) * 0.1), (0x10 - (Rand() & 0x1F)) + x, (0x10 - (Rand() & 0x1F)) + y, 1);
    if (actor_index != 0) {
        Actor_SetColorRgb(actor_index, 0x6F);
        gActors[actor_index].velocityZ.raw = 0x38000;
    }
}

void func_800840A4(u16 actor_index) {
    if (gActors[actor_index].unk_178 != 0) {
        gActors[actor_index].unk_17C++;
        if (gActors[actor_index].unk_17C >= 0x2D0) {
            gActors[actor_index].flags = 0;
        }
        if (gActors[actor_index].unk_17C >= 0x21C) {
            if (gActors[actor_index].unk_17C & 4) {
                gActors[actor_index].colorA = 0;
            }
            else {
                gActors[actor_index].colorA = 0xFF;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008412C.s")

s32 func_800842AC(s32* arg0, f32* arg1, f32* arg2, f32* arg3) {
    s32 result;

    result = FALSE;
    if (*arg0 != 0) {
        if (*arg1 >= 270.0f) {
            *arg2 -= *arg3;
        }
        else {
            *arg2 += *arg3;
            if (*arg2 >= 0.0f) {
                *arg2 = 0.0f;
                result = TRUE;
                *arg0 ^= 1;
            }
        }
    }
    else if (*arg1 <= 270.0f) {
        *arg2 += *arg3;
    }
    else {
        *arg2 -= *arg3;
        if (*arg2 <= 0.0f) {
            *arg2 = 0.0f;
            result = TRUE;
            *arg0 ^= 1;
        }
    }
    *arg1 += *arg2;
    return result;
}

void func_800843E0(u16 actor_index) {
    s32 pad0;
    s32 pad1;

    gActors[actor_index].var_15C = gActors[actor_index].velocityX.raw;
    gActors[actor_index].var_160 = gActors[actor_index].velocityY.raw;
    if (gActors[actor_index].velocityX.raw < 0) {
        gActors[actor_index].var_154 = 0;
    }
    else if (gActors[actor_index].velocityX.raw > 0) {
        gActors[actor_index].var_154 = 1;
    }
    else {
        gActors[actor_index].var_154 = Rand() & 1;
    }
    if (gActors[actor_index].var_154 != 0) {
        gActors[actor_index].unk_114 = 295.0f;
    }
    else {
        gActors[actor_index].unk_114 = 255.0f;
    }
    gActors[actor_index].unk_11C = 0.08f;
    if (gActors[actor_index].var_154 != 0) {
        gActors[actor_index].unk_16C = 0;
    }
    else {
        gActors[actor_index].unk_16C = 1;
    }
}

void func_800844B8(u16 actor_index) {
    s16 angle;

    gActors[actor_index].var_15C = Math_ApproachS32(gActors[actor_index].var_15C, 0, 0x400);
    gActors[actor_index].var_160 = Math_ApproachS32(gActors[actor_index].var_160, -0x4000, 0x4000);
    if (func_800842AC(&gActors[actor_index].var_154, &gActors[actor_index].unk_114, &gActors[actor_index].unk_118, &gActors[actor_index].unk_11C)) {
        gActors[actor_index].unk_11C = (Rand() * 0.0001) + 0.04;
    }
    angle = gActors[actor_index].unk_114 * 2.84;
    gActors[actor_index].velocityX.raw = gActors[actor_index].var_15C + (COS(angle) * 131072.0f);
    gActors[actor_index].velocityY.raw = gActors[actor_index].var_160 + (SIN(angle) * 8192.0f);
    gActors[actor_index].rotateZ = INDEX_TO_DEG((Math_Atan2(gActors[actor_index].velocityX.raw, gActors[actor_index].velocityY.raw) + 0x100) & 0x3FF);
}

s32 func_800846A8(u16 actor_index) {
    if (gActors[actor_index].velocityY.raw <= 0) {
        if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK5) {
            gActors[actor_index].state = 1;
            gActors[actor_index].flags &= ~ACTOR_FLAG_UNK17;
            gActors[actor_index].flags |= ACTOR_FLAG_UNK16;
            gActors[actor_index].velocityX.raw = 0;
            gActors[actor_index].velocityY.raw = 0;
            return TRUE;
        }
    }
    return FALSE;
}

void func_80084734(u16 actor_index) {
    if ((gActors[actor_index].velocityY.raw > 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK4)) {
        gActors[actor_index].state = 5;
        gActors[actor_index].velocityX.raw = 0;
        gActors[actor_index].velocityY.raw = -gActors[actor_index].velocityY.raw / 2;
    }
    if (((gActors[actor_index].velocityX.raw < 0) && (gActors[actor_index].flags_098 & (ACTOR_FLAG3_UNK3 | ACTOR_FLAG3_UNK2))) || 
        ((gActors[actor_index].velocityX.raw > 0) && (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK3))) {
        gActors[actor_index].var_154 ^= 1;
        if (gActors[actor_index].var_154 != 0) {
            gActors[actor_index].unk_114 = 295.0f;
        }
        else {
            gActors[actor_index].unk_114 = 255.0f;
        }
        gActors[actor_index].velocityX.raw = -gActors[actor_index].velocityX.raw / 2;
        gActors[actor_index].velocityY.raw = gActors[actor_index].velocityY.raw / 2;
        gActors[actor_index].unk_0F8.raw = -gActors[actor_index].unk_0F8.raw / 2;
        gActors[actor_index].var_15C = 0;
    }
}

void func_8008486C(u16 actor_index) {
    func_800846A8(actor_index);
    func_80084734(actor_index);
}

s32 func_800848A0(u16 actor_index) {
    if (gActors[actor_index].flags_098 & ACTOR_FLAG3_UNK9) {
        gActors[actor_index].state = 2;
        gActors[actor_index].flags = ACTOR_FLAG_UNK17 | ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[actor_index].velocityX.raw = 0;
        gActors[actor_index].velocityY.raw = 0;
        Sound_PlaySfxAtActor2(0x2F, actor_index);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void func_80084924(u16 actor_index) {
    gActors[actor_index].hitboxBY0 = 12; \
    gActors[actor_index].hitboxBY1 = -4; \
    gActors[actor_index].hitboxBX0 = -4; \
    gActors[actor_index].hitboxBX1 = 4;
}

void func_80084974(u16 actor_index) {
    u16 index;
    u16 temp_v0;
    s32 flags;

    flags = ACTOR_FLAG_UNK17 | ACTOR_FLAG_UNK12 | ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
    if (Clanpot_AddItemCheck3(actor_index, 0, 0, 0, gActors[actor_index].graphicIndex) >= 0) {
        gActors[actor_index].state = 0xA;
        gActors[actor_index].flags = ACTOR_FLAG_ACTIVE;
    }
    gActors[actor_index].posZ.raw = FIXED_UNIT(-4.0);
    switch (gActors[actor_index].state) {
    case 0: 
        gActors[actor_index].state++;
        gActors[actor_index].graphicFlags = ACTOR_GFLAG_ROTZ;
        gActors[actor_index].flags = flags;
        // comparison on gActors[arg0].var_110?
        index = gActors[actor_index].var_110;
        if (gActors[actor_index].var_110 >= 0.0f) {
            gActors[actor_index].graphicIndex = D_800E3D20[index & 0xF];
        }
        gActors[actor_index].unk_178 = gActors[actor_index].var_0D8 & 1;
        gActors[actor_index].unk_0DF = 0x40;
        func_80084924(actor_index);
        /* fallthrough */
    case 1: 
        gActors[actor_index].rotateZ = 0.0f;
        if (!func_800846A8(actor_index)) {
            gActors[actor_index].state = 4;
        }
        if (func_800848A0(actor_index)) {
            gActors[actor_index].state = 2;
        }
        break;
    case 2:
        temp_v0 = func_800291AC(actor_index, 3, flags, 4, flags);
        switch (temp_v0) {
        case 0:
        case 1:
            break;
        case 2:
            gActors[actor_index].var_150 = 0x14;
            gActors[actor_index].unk_0F8.raw = (s32) gActors[actor_index].unk_0F8.raw / 24;
            gActors[actor_index].unk_0FC.raw /= 24;
            gActors[actor_index].unk_0FC.raw -= 0x800;
            func_80084924(actor_index);
            break;
        case 3:
            func_80084924(actor_index);
            gActors[actor_index].var_150 = 0xA;
            break;
        }
        break;
    case 3: 
        gActors[actor_index].velocityX.raw -= gActors[actor_index].unk_0F8.raw;
        gActors[actor_index].velocityY.raw -= gActors[actor_index].unk_0FC.raw;
        gActors[actor_index].var_150--;
        if (gActors[actor_index].var_150 < 0) {
            gActors[actor_index].var_150 = 0xA;
            gActors[actor_index].state = 4;
        }
        gActors[actor_index].rotateZ = INDEX_TO_DEG((Math_Atan2(gActors[actor_index].velocityX.raw, gActors[actor_index].velocityY.raw) + 0x100) & 0x3FF);
        func_800848A0(actor_index);
        func_8008486C(actor_index);
        break;
    case 4: 
        func_800843E0(actor_index);
        gActors[actor_index].state++;
        /* fallthrough */
    case 5: 
        func_800844B8(actor_index);
        func_800848A0(actor_index);
        func_8008486C(actor_index);
        break;
    case 10:
        func_800848A0(actor_index);
        break;
    }
    gActors[actor_index].flags_098 &= ~(ACTOR_FLAG3_UNK21 | ACTOR_FLAG3_UNK10 | ACTOR_FLAG3_UNK9);
    func_800840A4(actor_index);
}

void func_80084D18(u16 actor_index) {
    u8 base_index;

    base_index = gActors[actor_index].var_110 * 4;
    gActors[actor_index].unk_138_arr[0] = D_800E3D2C[base_index + 0];
    gActors[actor_index].unk_138_arr[1] = D_800E3D2C[base_index + 1];
    gActors[actor_index].unk_138_arr[2] = D_800E3D2C[base_index + 2];
    gActors[actor_index].unk_138_arr[3] = D_800E3D2C[base_index + 3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80084F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800852CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800853C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800859C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085F08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80085F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008603C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800860FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800862CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800865BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80086B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Clanbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Spikeball_OrbitXY.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80087EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Spikeball_77.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800882E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Spikeball_78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800886E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800887B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800887F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Spikeball_OrbitYZ.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80088E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_Spikeball_80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800891EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_800896AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/DiggingSpot_SpawnActor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/DiggingSpot_SpawnActorCheck.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_80089EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008A50C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/ActorUpdate_DiggingSpot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AA28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AD3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008AFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008B9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008BFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84BB0/func_8008C304.s")

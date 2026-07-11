#include "common.h"

extern s16 D_800E10D0[];
extern s16 D_800E11C0[];
extern s16* D_800E1298[];

#ifdef NON_MATCHING
u16 func_8007F9E0(u16 arg0) {
    u16 temp_a0;
    s16* var_v0;
    s16* temp_a3;
    Actor* temp_a2;

    temp_a2 = &gActors[arg0];
    var_v0 = (s16*)temp_a2->var_150;
    if (var_v0[2] != 0) {
        if (temp_a2->var_154 < var_v0[1]) {
            temp_a2->var_154++;
        }
        else {
            var_v0 += 2;
            if (var_v0[2] < 0) {
                var_v0 += var_v0[2];
            }
            temp_a2->var_150 = (s32)var_v0;
            temp_a2->var_154 = 1;
        }
    }
    else {
        temp_a2->var_154 = 0;
    }
    temp_a3 = &D_800E10D0[var_v0[0]];
    temp_a2->graphicIndex = temp_a3[0];
    if (temp_a3[1] != 0) {
        if (arg0 >= 0x90) {
            arg0++;
        }
        else {
            arg0 = 0x90;
        }
        temp_a0 = Actor_RangeFindInactive(arg0, 0xC0);
        if (temp_a0 != 0) {
            gActors[temp_a0].actorType = 0x34;
            Actor_Initialize(temp_a0);
            gActors[temp_a0].graphicFlags = temp_a2->graphicFlags & 0x8101;
            gActors[temp_a0].flags = (temp_a2->flags & 0x20) + 3;
            gActors[temp_a0].graphicIndex = temp_a3[1];
            if (temp_a2->flags & 0x20) {
                gActors[temp_a0].posX.raw = (-temp_a3[2] * temp_a2->scaleX * 65536.0f) + (0, temp_a2->posX.raw);
            }
            else {
                gActors[temp_a0].posX.raw = (temp_a3[2] * temp_a2->scaleX * 65536.0f) + (0, temp_a2->posX.raw);
            }
            gActors[temp_a0].posY.raw = (temp_a3[3] * temp_a2->scaleY * 65536.0f) + (0, temp_a2->posY.raw);
            gActors[temp_a0].posZ.raw = temp_a2->posZ.raw + 1;
            gActors[temp_a0].unk_148 = 1.0f;
            return temp_a0;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/805E0/func_8007F9E0.s")
#endif

void func_8007FCA0(s32 value, s32 x_pos, s32 y_pos) {
    s16 actor_index;
    s16 non_zero_index;
    s16 start;
    s16 index;
    s16 x_pos_2;
    char sp4C[10];

    sprintf(sp4C, "%08d", value);
    non_zero_index = 7;
    for (index = 0; index < 8; index++) {
        if (sp4C[index] != 0x30) {
            non_zero_index = index;
            break;
        }
    }
    start = (non_zero_index < 5) ? non_zero_index : 5;
    x_pos_2 = ((x_pos - (start * 4)) - 0x20);
    for (index = start; index < 8; index++) {
        if (index < non_zero_index) {
            actor_index = SpawnParticle_List_90C0_16(D_800E11C0, (index * 8) + x_pos_2, y_pos, 0);
            if (actor_index != 0) {
                gActors[actor_index].graphicFlags |= ACTOR_GFLAG_UNK11 | ACTOR_GFLAG_UNK4 | ACTOR_GFLAG_ROTZ;
                gActors[actor_index].flags |= ACTOR_FLAG_FREEZE_POS;
                gActors[actor_index].posY.raw = y_pos << 0x10;
                gActors[actor_index].posZ.raw = FIXED_UNIT(128.0);
                gActors[actor_index].unk_188 = 8;
                gActors[actor_index].colorR = 0x80;
                gActors[actor_index].colorG = 0x80;
                gActors[actor_index].colorB = 0x80;
                gActors[actor_index].colorA = 0xB9;
                gActors[actor_index].var_15C = 0xE00;
                gActors[actor_index].unk_16C = -0x6E;
                gActors[actor_index].unk_17C = (s32) func_80030B0C;
                gActors[actor_index].unk_104 = 0x20;
                gActors[actor_index].unk_108 = -8;
            }
        }
        else {
            actor_index = SpawnParticle_List_90C0_16(D_800E1298[sp4C[index]], (index * 8) + x_pos_2, y_pos, 0);
            if (actor_index != 0) {
                gActors[actor_index].graphicFlags |= ACTOR_GFLAG_UNK11 | ACTOR_GFLAG_ROTZ;
                gActors[actor_index].flags |= ACTOR_FLAG_FREEZE_POS;
                gActors[actor_index].posY.raw = y_pos << 0x10;
                gActors[actor_index].posZ.raw = FIXED_UNIT(128.0);
                gActors[actor_index].unk_188 = 8;
                gActors[actor_index].var_15C = 0xE00;
                gActors[actor_index].unk_16C = -0x6E;
                gActors[actor_index].unk_17C = (s32) func_80030B84;
                gActors[actor_index].unk_104 = 0x20;
                gActors[actor_index].unk_108 = -8;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/805E0/func_8007FF28.s")

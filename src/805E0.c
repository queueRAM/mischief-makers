#include "common.h"

extern s16 D_800E10D0[];

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

#pragma GLOBAL_ASM("asm/nonmatchings/805E0/func_8007FCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/805E0/func_8007FF28.s")

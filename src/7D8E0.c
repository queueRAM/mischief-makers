#include "common.h"

extern s8 D_800E0F00[];

void func_8007CCE0(u32 val) {
    u16 count;
    u32 tens_place;

    if (val > 99999999) {
        val = 99999999;
    }
    tens_place = 10000000;
    for (count = 0; count < 8; ) {
        D_800E0F00[count++] = val / tens_place;
        val %= tens_place;
        tens_place /= 10;
    }
}

void func_8007CD68(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, s32 arg6) {
    gActors[actor_index].actorType = 0x29;
    Actor_Initialize(actor_index);
    gActors[actor_index].flags = ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE;
    gActors[actor_index].posX.whole = pos_x;
    gActors[actor_index].posY.whole = pos_y;
    gActors[actor_index].var_150 = arg4;
    gActors[actor_index].var_154 = arg1;
    gActors[actor_index].var_15C = arg6;
    gActors[actor_index].unk_14C = arg5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007CE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007CEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007CFE0.s")

// spawns a text box over an actor for a few moments.
// ...in the japanese version.
// @param index index of "speaking" actor
// @param text "string" to display
// @param off_x x-position offset of text.
// @param off_y y-position offset of text.
// @param arg4 unused(?)
// @returns index of actor, 0 if failed or English version.
u16 SpawnTextBubble(u16 index, u16* text, s16 off_x, s16 off_y, s32 arg4) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D3EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007DF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EE14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EF58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F560.s")

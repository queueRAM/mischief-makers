#include "common.h"

u16 func_800592A0(u16 actor_index, s32* arg1) {
    u16 free_actor;

    if (actor_index < 0x10) {
        free_actor = Actor_RangeFindInactive(0x10, 0x2D);
    }
    else {
        free_actor = Actor_RangeFindInactive(0x90, 0xC0);
    }
    if (free_actor == 0) {
        return free_actor;
    }
    gActors[free_actor].actorType = 9;
    func_8001E2D0(free_actor);
    gActors[free_actor].graphicFlags |= gActors[actor_index].graphicFlags & 0x160;
    gActors[free_actor].flags |= (gActors[actor_index].flags & 0x28) | 0x80000;
    gActors[free_actor].colorA = 0xFE;
    gActors[free_actor].posX.raw = arg1[0] << 0x10;
    gActors[free_actor].posY.raw = arg1[1] << 0x10;
    gActors[free_actor].posZ.raw = arg1[2] << 0x10;
    gActors[free_actor].unk_130 = -1.0f;
    return free_actor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_800593DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_80059F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A7D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005A930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005ACA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005ACB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005B82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005BFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005C098.s")

// unused variant of after-image. uses arrays to store history.
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005C0CC.s")

// spawns after-image of Marina while dashing
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005C250.s")

// "tick" of actor for Marina's after-image
#pragma GLOBAL_ASM("asm/nonmatchings/59EA0/func_8005C3C8.s")

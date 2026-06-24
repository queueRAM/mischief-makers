#include "common.h"

void func_8005C520(s8 arg0, s8 arg1) {
    gActors[0].unk_0DC |= 0x40;
    D_801373E0.unk_0A = arg0;
    D_801373E0.unk_0B = arg1;
}

s32 func_8005C550(u16 actor_index, s16 arg1) {
    if (gActors[actor_index].unk_13C_s16[0] == 0) {
        gActors[actor_index].unk_13C_s16[0] = arg1;
        return 1;
    }
    if (arg1 > 0) {
        if (gActors[actor_index].unk_13C_s16[0] < arg1) {
            gActors[actor_index].unk_13C_s16[0] = arg1;
            return 2;
        }
    }
    else if ((gActors[actor_index].unk_13C_s16[0] < 0) && (arg1 < gActors[actor_index].unk_13C_s16[0])) {
        gActors[actor_index].unk_13C_s16[0] = arg1;
        return 3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005C8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005CA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005CA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005CAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5D120/func_8005D450.s")

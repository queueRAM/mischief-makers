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

s32 func_8005C5E0(u16 actor_index) {
    gActors[actor_index].flags |= 0x1000;
    gActors[actor_index].flags &= 0xFFFF7FFF;
    if (gActors[actor_index].unk_13C_s16[0] == 0) {
        return 0;
    }
    gActors[actor_index].flags &= ~0x1000;
    if (gActors[actor_index].unk_13C_s16[0] > 0) {
        gActors[actor_index].flags |= 0x8000;
    }
    if ((gActors[actor_index].unk_13C_s16[0] == 0x7FFF) || (gActors[actor_index].unk_13C_s16[0] == -0x8000)) {
        if (func_8005D418(actor_index) != 0) {
            gActors[actor_index].unk_13C_s16[0] = 0;
        }
        return 2;
    }
    if (gActors[actor_index].unk_13C_s16[0] < 0) {
        gActors[actor_index].unk_13C_s16[0]++;
    }
    if (gActors[actor_index].unk_13C_s16[0] > 0) {
        gActors[actor_index].unk_13C_s16[0]--;
    }
    return 1;
}

// abs_s32
s32 func_8005C6D0(s32 x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

// abs_f32
f32 func_8005C6E4(f32 x) {
    if (x < 0.0f) {
        x = -x;
    }
    return x;
}

// rand8_mod
s32 func_8005C708(s32 arg0) {
    s8 val;
    s32 var_v1;

    val = Rand();
    var_v1 = val;
    if (arg0 != 0) {
        var_v1 %= arg0;
    }
    return var_v1;
}

u16 func_8005C774(s32 arg0) {
    f32 temp;
    if (arg0 == 0) {
        return D_800BE668;
    }
    if (arg0 >= 100) {
        return D_800BE668 + 1;
    }
    temp = (D_800BE668 + 1);
    temp /= (100.0f / arg0);
    return temp;
}

u8 func_8005C870(u8 arg0) {
    if ((arg0 & 0x30) == 0x30) {
        return arg0 & 0xC0;
    }
    return arg0;
}

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

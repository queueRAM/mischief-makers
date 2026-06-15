#include "common.h"
#include "boot.h"

extern u16 D_801373D8;

s32 func_8004F2B0(u16 actor_index) {
    s32 pad;

    if (!(D_801370CE & gButton_B)) {
        return 0;
    }
    gActors[actor_index].flags &= ~0x4040;
    gActors[actor_index].unk_140_u8[0] = func_80048C28(0, actor_index);
    if (!(D_801373D8 & ~0x80)) {
        return 1;
    }
    return 2;
}

s32 func_8004F35C(u16 actor_index, u32* arg1) {
    if (func_8005D418(actor_index) != 0) {
        gActors[actor_index].unk_12F_u8 = 0;
        Sound_PlaySfx(0xAD);
        return 1;
    }
    *arg1 += 1;
    if (!(*arg1 & 0x40000000)) {
        if ((*arg1 & 0x3FFFFFFF) >= 0x10) {
            if (func_8005D338(actor_index) == 0x6B) {
                Sound_PlaySfx(0xB4);
            }
            else {
                Sound_PlaySfx(0xCA);
            }
            *arg1 |= 0x40000000;
        }
    }
    if ((gActors[actor_index].unk_170_s8[0] == 0) && (gActors[actor_index].unk_170_s8[1] == 0)) {
        return 0;
    }
    if (!(*arg1 & 0x80000000)) {
        if (!(D_801370CE & gButton_B)) {
            return 0;
        }
        *arg1 |= 0x80000000;
    }
    if (!(D_801370CC & gButton_B)) {
        return 0;
    }
    gActors[actor_index].unk_170_s8[0] = 0x7F;
    *arg1 += 4;
    return 0;
}

void func_8004F514(u16 actor0, u16 actor1) {
    gActors[actor0].flags &= 0xFDFFFFFF;
    if (actor1 != 0xFFFF) {
        if (gActors[actor1].flags & 2) {
            gActors[actor1].flags_098 &= ~0x200;
        }
        if (actor0 == 0) {
            gActors[actor0].unk_140_u16[1] = gActors[actor0].unk_0D6;
            gActors[actor0].unk_140_u8[1] = 0x1E;
        }
    }
}

void func_8004F5B0(u16 actor_index) {
    switch (gActors[actor_index].unk_140_u16[1]) {
    case 0:
        gActors[actor_index].unk_140_u16[1] = 1;
        break;
    case 8:
        gActors[actor_index].unk_140_u16[1] = 2;
        break;
    default:
        gActors[actor_index].unk_140_u16[1] = 0;
        break;
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/YqmQz
void func_80059D88(u16, s32*, s32, s32);
void func_8005C520(s8, s32);
s32 func_8005C774(s32);
extern FixedCoord D_800D413C[];
u16 func_8004F614(u16 arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 var_v0;
    s32 sp34[4];
    u16 temp_s0;
    s32 temp_v0;

    var_v0 = gActors[arg0].unk_140_u16[1];
    temp_s0 = gActors[arg0].unk_0D6;
    if (var_v0 >= 3) {
        var_v0 = 0;
    }
    sp34[0] = 0x12;
    sp34[2] = 1;
    sp34[3] = 0x8022D4E8;
    sp34[1] = D_800D413C[var_v0].whole;
    func_80059D88(arg0, sp34, 0, 0x40400000);
    gActors[arg0].flags &= 0xFDFFFFFF;
    if (temp_s0 == 0xFFFF) {
        return temp_s0;
    }
    if (!(gActors[temp_s0].flags & 2)) {
        return 0xFFFF;
    }
    func_8004F514(arg0, temp_s0);
    gActors[temp_s0].flags_098 |= 0x400;
    gActors[temp_s0].unk_0DC = 0xC0;
    gActors[temp_s0].unk_0DD = 0x19;
    gActors[temp_s0].pendingDamage = arg3;
    if (!(gActors[arg0].flags & 0x20)) {
        gActors[temp_s0].unk_0F8.raw = arg1;
    } else {
        gActors[temp_s0].unk_0F8.raw = -arg1;
    }
    gActors[temp_s0].unk_0FC.raw = arg2;
    if (temp_s0 == 0) {
        gActors[temp_s0].unk_13C_u16[1] = arg3;
        temp_v0 = func_8005C774(2);
        func_8005C520(temp_v0 + 1, 6);
    }
    return temp_s0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004F614.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004F7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FC68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8004FDF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800500B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005060C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005074C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800508F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800509C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80050F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80051C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005278C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800528F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80052CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800536CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005396C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80053F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800541B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005457C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005498C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80054FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800551F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800553EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005544C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800554AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005552C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800558F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80055F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800562EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005664C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800569AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80056F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005701C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005739C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800574B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800575C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800576A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80057C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_800584D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005878C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_8005896C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB0/func_80058F9C.s")

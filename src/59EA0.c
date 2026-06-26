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

void func_800593DC(u16 actor_index) {
    s16 index;
    u16 actor_1;
    s32 pad;
    s32 sp4C[5];

    sp4C[0] = -0x10;
    sp4C[1] = -0x40;
    sp4C[2] = 0xA;
    actor_1 = func_800592A0(actor_index, sp4C);
    if (actor_1 == 0) {
        return;
    }

    gActors[actor_1].flags &= ~0x20;
    gActors[actor_1].flags |= 0x8;
    gActors[actor_1].graphicIndex = 0x128;
    gActors[actor_1].unk_148 = 0.0f;
    if (!(D_801373E0.unk_7C & 0x2)) {
        gActors[actor_1].graphicFlags |= 0x8;
        gActors[actor_1].var_160 = 0x01000000;
    }
    sp4C[0] += 0x10;
    actor_1 = func_800592A0(actor_index, sp4C);
    if (actor_1 == 0) {
        return;
    }

    gActors[actor_1].flags &= ~0x20;
    gActors[actor_1].flags |= 0x8;
    gActors[actor_1].graphicIndex = 0x110;
    gActors[actor_1].unk_148 = 0.0f;
    sp4C[0] += 0x10;
    actor_1 = func_800592A0(actor_index, sp4C);
    if (actor_1 == 0) {
        return;
    }

    gActors[actor_1].flags &= ~0x20;
    gActors[actor_1].flags |= 0x8;
    gActors[actor_1].graphicIndex = 0x10E;
    gActors[actor_1].unk_148 = 0.0f;
    sp4C[0] = 0;
    sp4C[1] = -0x28;
    for (index = D_801373E0.unk_0A; index > 0; index--) {
        actor_1 = func_800592A0(actor_index, sp4C);
        if (actor_1 == 0) {
            return;
        }
        gActors[actor_1].graphicFlags |= 0x9;
        gActors[actor_1].flags &= ~0x20;
        gActors[actor_1].flags |= 0x8;
        gActors[actor_1].graphicIndex = 0x12E;
        gActors[actor_1].unk_148 = 0.0f;
        gActors[actor_1].scaleX = 0.75f;
        gActors[actor_1].scaleY = 0.75f;
        gActors[actor_1].var_160 = 0x03000000;
        sp4C[1] += 8;
        sp4C[2] -= 1;
    }
}

u16 func_80059624(u16 actor_index, f32 scale, s32 arg2) {
    s32 sp9C[5];
    s32 pad;
    s32 index;
    u16 actor_1;
    u16 actor_2;

    sp9C[0] = gActors[actor_index].posX.whole + ((gActors[actor_index].hitboxAX0 + gActors[actor_index].hitboxAX1) / 2);
    sp9C[1] = gActors[actor_index].posY.whole + ((gActors[actor_index].hitboxAY0 + gActors[actor_index].hitboxAY1) / 2);
    sp9C[2] = gActors[actor_index].posZ.whole + 1;
    actor_1 = gActors[actor_index].unk_0D6;
    if (actor_1 != 0xFFFF) {
        if (func_8005C6D0(gActors[actor_1].hitboxBX1 - gActors[actor_1].hitboxBX0) < 0x30) {
            sp9C[0] = (gActors[actor_1].posX.whole + sp9C[0] + ((gActors[actor_1].hitboxBX0 + gActors[actor_1].hitboxBX1) / 2)) / 2;
        }
        if (func_8005C6D0(gActors[actor_1].hitboxBY0 - gActors[actor_1].hitboxBY1) < 0x30) {
            sp9C[1] = (gActors[actor_1].posY.whole + sp9C[1] + ((gActors[actor_1].hitboxBY0 + gActors[actor_1].hitboxBY1) / 2)) / 2;
        }
        if (gActors[actor_index].posZ.whole > gActors[actor_1].posZ.whole) {
            sp9C[2] = gActors[actor_index].posZ.whole + 1;
        }
        else {
            sp9C[2] = gActors[actor_1].posZ.whole + 1;
        }
    }
    actor_2 = func_800592A0(actor_index, sp9C);
    if (actor_2 == 0) {
        return actor_2;
    }

    gActors[actor_2].graphicFlags |= 0x201;
    gActors[actor_2].graphicIndex = 0x168;
    gActors[actor_2].scaleX = 0.5 * scale;
    gActors[actor_2].scaleY = 0.5 * scale;
    gActors[actor_2].timer_110 = -gActors[actor_2].scaleX / 30.0;
    gActors[actor_2].unk_114 = -gActors[actor_2].scaleY / 30.0;
    gActors[actor_2].colorA = 0xC0;
    gActors[actor_2].var_154 = -0xA;
    gActors[actor_2].unk_148 = 20.0f;
    gActors[actor_2].unk_18C = arg2;

    for (index = 0; index < 5; index++) {
        actor_1 = func_800592A0(actor_index, sp9C);
        if (actor_1 == 0) {
            break;
        }
        gActors[actor_1].graphicFlags |= 0x209;
        gActors[actor_1].posZ.raw -= 1;
        if (!(Rand() & 1)) {
            gActors[actor_1].graphicIndex = 0x1D6;
        }
        else {
            gActors[actor_1].graphicIndex = 0x160;
        }
        gActors[actor_1].unk_148 = 20.0f;
        gActors[actor_1].scaleX = 2.0 * scale;
        gActors[actor_1].scaleY = 0.1 * scale;
        gActors[actor_1].timer_110 = -gActors[actor_1].scaleX / 30.0;
        gActors[actor_1].unk_114 = -gActors[actor_1].scaleY / 30.0;
        gActors[actor_1].var_154 = -0xF;
        gActors[actor_1].var_160 = Rand() << 0x12;
        if (!(gActors[actor_index].flags & 0x20)) {
            gActors[actor_1].var_150 = -0x100000;
        }
        else {
            gActors[actor_1].var_150 = 0x100000;
        }
        gActors[actor_1].flags |= 0x8000;
        gActors[actor_1].unk_184 = gActors[actor_1].posX.raw;
        gActors[actor_1].unk_188 = gActors[actor_1].posY.raw;
        gActors[actor_1].unk_140_f32 = func_8005C708(0xA);
        gActors[actor_1].unk_144 = 0.0f;
        gActors[actor_1].unk_18C = arg2;
    }
    return actor_2;
}

u16 func_80059ABC(u16 actor_index, f32 scale) {
    s32 sp34[5];
    s32 pad;
    u16 actor_1;

    actor_1 = gActors[actor_index].unk_0D6;
    sp34[0] = gActors[actor_index].posX.whole + ((gActors[actor_index].hitboxAX0 + gActors[actor_index].hitboxAX1) / 2);
    sp34[1] = gActors[actor_index].posY.whole + ((gActors[actor_index].hitboxAY0 + gActors[actor_index].hitboxAY1) / 2);
    sp34[2] = gActors[actor_index].posZ.whole + 1;
    if (actor_1 != 0xFFFF) {
        if (func_8005C6D0(gActors[actor_1].hitboxBX1 - gActors[actor_1].hitboxBX0) < 0x30) {
            sp34[0] = (gActors[actor_1].posX.whole + sp34[0] + ((gActors[actor_1].hitboxBX0 + gActors[actor_1].hitboxBX1) / 2)) / 2;
        }
        if (func_8005C6D0(gActors[actor_1].hitboxBY0 - gActors[actor_1].hitboxBY1) < 0x30) {
            sp34[1] = (gActors[actor_1].posY.whole + sp34[1] + ((gActors[actor_1].hitboxBY0 + gActors[actor_1].hitboxBY1) / 2)) / 2;
        }
        if (gActors[actor_1].posZ.whole < gActors[actor_index].posZ.whole) {
            sp34[2] = gActors[actor_index].posZ.whole + 1;
        }
        else {
            sp34[2] = gActors[actor_1].posZ.whole + 1;
        }
    }
    actor_1 = func_800592A0(actor_index, sp34);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].graphicIndex = 0x19A;
    gActors[actor_1].colorA = 0xE0;
    gActors[actor_1].var_154 = -5;
    gActors[actor_1].unk_148 = 60.0f;
    gActors[actor_1].scaleX = scale;
    gActors[actor_1].scaleY = scale;
    gActors[actor_1].unk_114 = -gActors[actor_1].scaleY / 30.0f;
    gActors[actor_1].timer_110 = -gActors[actor_1].scaleX / 30.0f;
    if (!(gActors[actor_index].flags & 0x20)) {
        gActors[actor_1].var_150 = 0x220000;
    }
    else {
        gActors[actor_1].var_150 = -0x220000;
    }
    gActors[actor_1].unk_18C = 0x8022D568;
    return actor_1;
}

u16 func_80059D88(u16 actor_index, s32* arg1, s32 unused_arg2, f32 scale) {
    s32 pad;
    u16 actor_1;

    if (gActors[actor_index].flags & 0x20) {
        arg1[0] = -arg1[0];
    }
    arg1[0] += gActors[actor_index].posX.whole;
    arg1[1] += gActors[actor_index].posY.whole;
    arg1[2] += gActors[actor_index].posZ.whole;
    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].graphicIndex = 0x194;
    gActors[actor_1].colorA = 0xE0;
    gActors[actor_1].var_154 = -7;
    gActors[actor_1].unk_148 = 60.0f;
    gActors[actor_1].scaleX = scale / 2;
    gActors[actor_1].scaleY = scale / 2;
    gActors[actor_1].unk_114 = (scale / 30.0f) / 2;
    gActors[actor_1].timer_110 = (scale / 30.0f) / 2;
    if (!(gActors[actor_index].flags & 0x20)) {
        gActors[actor_1].var_150 = 0x220000;
    }
    else {
        gActors[actor_1].var_150 = -0x220000;
    }
    if (arg1[4] == 0) {
        gActors[actor_1].graphicFlags &= 0xFDFF;
    }
    else {
        gActors[actor_1].unk_18C = arg1[4];
    }
    return actor_1;
}

u16 func_80059F30(u16 actor_index, s32* arg1, f32 scale, s32 arg3) {
    u16 actor_1;

    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x201;
    gActors[actor_1].graphicIndex = arg1[3];
    if (arg1[4] == 0) {
        gActors[actor_1].graphicFlags &= ~0x200;
    }
    else {
        gActors[actor_1].unk_18C = arg1[4];
    }
    gActors[actor_1].scaleX = scale;
    gActors[actor_1].scaleY = scale;
    gActors[actor_1].unk_148 = arg3;
    if (arg3 == 0) {
        return actor_1;
    }
    gActors[actor_1].var_154 = -(200 / arg3);
    gActors[actor_1].timer_110 = scale / arg3;
    gActors[actor_1].unk_114 = scale / arg3;
    gActors[actor_1].unk_118 = -gActors[actor_1].timer_110 / arg3;
    gActors[actor_1].unk_11C = -gActors[actor_1].unk_114 / arg3;
    return actor_1;
}

u16 func_8005A068(u16 actor_index, s32* arg1, s32 angle, f32 scale, s32 arg4) {
    u16 actor_1;

    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].graphicIndex = arg1[3];
    if (arg1[4] == 0) {
        gActors[actor_1].graphicFlags &= ~0x200;
    }
    else {
        gActors[actor_1].unk_18C = arg1[4];
    }
    gActors[actor_1].scaleX = scale;
    gActors[actor_1].scaleY = scale;
    gActors[actor_1].var_160 = angle;
    gActors[actor_1].unk_148 = arg4;
    if (arg4 == 0) {
        return actor_1;
    }
    gActors[actor_1].var_154 = -(200 / arg4);
    gActors[actor_1].timer_110 = scale / arg4;
    gActors[actor_1].unk_114 = scale / arg4;
    gActors[actor_1].unk_118 = -gActors[actor_1].timer_110 / arg4;
    gActors[actor_1].unk_11C = -gActors[actor_1].unk_114 / arg4;
    return actor_1;
}

u16 func_8005A1A4(u16 actor_index, s32* arg1, f32 scale) {
    u16 actor_1;

    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].graphicIndex = 0x16A;
    gActors[actor_1].unk_148 = 20.0f;
    gActors[actor_1].var_154 = -0xA;
    gActors[actor_1].scaleY = scale * 0.8;
    gActors[actor_1].scaleX = scale * 0.8;
    gActors[actor_1].timer_110 = -0.05f;
    gActors[actor_1].unk_114 = -0.05f;
    gActors[actor_1].unk_18C = 0x8022D568;

    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].graphicIndex = 0x1D6;
    gActors[actor_1].unk_148 = 20.0f;
    gActors[actor_1].var_154 = -0xA;
    gActors[actor_1].var_150 = 0x100000;
    gActors[actor_1].scaleY = scale * 1.0;
    gActors[actor_1].scaleX = scale * 1.0;
    gActors[actor_1].unk_114 = -0.05f;
    gActors[actor_1].timer_110 = -0.05f;
    gActors[actor_1].unk_18C = 0x8022D4E8;
    return actor_1;
}

u16 func_8005A320(u16 actor_index, s32* arg1, s32 angle, f32 scale) {
    u16 actor_1;

    arg1[2]--;
    if (arg1[3] == 0) {
        arg1[3] = 0x18E;
    }
    if (angle == 0) {
        actor_1 = func_80059F30(actor_index, arg1, scale, 0x14);
    }
    else {
        actor_1 = func_8005A068(actor_index, arg1, angle, scale, 0x14);
    }
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].velocityX.raw = SIN(angle / 0x10000) * (0 * scale);
    gActors[actor_1].velocityY.raw = COS(angle / 0x10000) * -(0 * scale);
    gActors[actor_1].scaleX = scale / 2;
    gActors[actor_1].scaleY = scale / 4;
    gActors[actor_1].unk_11C *= 2;
    return actor_1;
}

u16 func_8005A4B0(u16 actor_index, f32 scale) {
    s32 sp2C[5];
    u16 actor_1;

    sp2C[0] = gActors[actor_index].posX.whole;
    sp2C[1] = gActors[actor_index].posY.whole + gActors[actor_index].hitboxBY1;
    sp2C[2] = gActors[actor_index].posZ.whole + 1;
    sp2C[3] = 0x1AC;
    sp2C[4] = 0;
    actor_1 = func_80059F30(actor_index, sp2C, (f64)scale, 0x14);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].flags &= ~0x20;
    gActors[actor_1].velocityX.raw = 65536.0f * scale;
    gActors[actor_1].var_158 = -gActors[actor_1].velocityX.raw / 20;
    gActors[actor_1].var_15C = 1024.0f * scale;
    actor_1 = func_80059F30(actor_index, sp2C, (f64)scale, 0x14);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].flags |= 0x20;
    gActors[actor_1].velocityX.raw = -65536.0f * scale;
    gActors[actor_1].var_15C = 1024.0f * scale;
    gActors[actor_1].var_158 = -gActors[actor_1].velocityX.raw / 20;
    return actor_1;
}

u16 func_8005A6D0(u16 actor_index, s32* arg1, s32 arg2) {
    u16 actor_1;

    actor_1 = func_800592A0(actor_index, arg1);
    if (actor_1 == 0) {
        return actor_1;
    }
    gActors[actor_1].graphicFlags |= 0x209;
    gActors[actor_1].flags &= ~0x20;
    gActors[actor_1].graphicIndex = 0x166;
    gActors[actor_1].colorA = 0xA0;
    gActors[actor_1].flags |= 0x8000;
    gActors[actor_1].unk_184 = gActors[actor_1].posX.raw;
    gActors[actor_1].unk_188 = gActors[actor_1].posY.raw;
    gActors[actor_1].unk_148 = 1.0f;
    gActors[actor_1].unk_140_f32 = -20.0f;
    gActors[actor_1].unk_144 = 0.0f;
    gActors[actor_1].var_160 = arg2;
    if (arg1[4] == 0) {
        gActors[actor_1].graphicFlags &= 0xFDFF;
    }
    else {
        gActors[actor_1].unk_18C = arg1[4];
    }
    return actor_1;
}

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

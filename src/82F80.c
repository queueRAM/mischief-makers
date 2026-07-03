#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_8008310C.s")

void func_80083140(s16 arg0, s16 arg1) {
    u16 index;
    s32* var_v0;

    var_v0 = (s32*)(((arg0 % 8) * 8) + ((arg0 / 8) << 0xA) + (arg1 << 0xB) + 0x8027EEE8);
    for (index = 0; index < 0x10; index++) {
        var_v0[0] = 0;
        var_v0[1] = 0;
        var_v0 += 0x10;
    }
}

void func_800831D0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u16 index;
    s32* var_a0;
    s32* var_v1;
    s32 temp;

    temp = arg3 * 0x44444444;
    if (arg2 < 0x51) {
        var_v1 = (s32*)((arg2 << 6) + 0x802524A8);
        var_a0 = (s32*)(((arg0 % 16) * 4) + ((arg0 / 16) << 0xA) + (arg1 << 0xB) + 0x8027EEE8);
        for (index = 0; index < 0x10; index++) {
            *var_a0 = *var_v1 + temp;
            var_v1 += 1;
            var_a0 += 0x10;
        }
    }
    else {
        var_v1 = (s32*)((arg2 << 7) + 0x80252468);
        var_a0 = (s32*)(((arg0 % 8) * 8) + ((arg0 / 8) << 0xA) + (arg1 << 0xB) + 0x8027EEE8);
        for (index = 0; index < 0x10; index++) {
            var_a0[0] = var_v1[0] + temp;
            var_a0[1] = var_v1[1] + temp;
            var_v1 += 2;
            var_a0 += 0x10;
        }
    }
}

void func_80083358(s16 arg0, s16 arg1, u16* arg2, s16 arg3) {
    if (*arg2 < 0xA1) {
        arg0 *= 2;
    }
    while (*arg2 != 0x8FFF) {
        if (*arg2 == 0) {
            arg2++;
            arg0++;
        }
        else {
            func_800831D0(arg0++, arg1, *arg2++ - 0x50, arg3);
        }
    }
}

void func_80083454(void) {
    u16 index;
    s32* var_v0;

    var_v0 = (s32*)0x8027CEE8;
    for (index = 0; index < 0x400; index++) {
        var_v0[0] = 0;
        var_v0[1] = 0;
        var_v0 += 2;
    }
}

void func_80083488(s16 arg0, s16 arg1) {
    u16 index;
    s32* var_v0;

    var_v0 = (s32*)(((arg0 % 8) * 8) + ((arg0 / 8) << 0xA) + (arg1 << 0xB) + 0x8027CEE8);
    for (index = 0; index < 0x10; index++) {
        var_v0[0] = 0;
        var_v0[1] = 0;
        var_v0 += 0x10;
    }
}

void func_80083518(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u16 index;
    s32* var_a0;
    s32* var_v1;
    s32 temp;

    temp = arg3 * 0x44444444;
    if (arg2 < 0x51) {
        var_v1 = (s32*)((arg2 << 6) + 0x802524A8);
        var_a0 = (s32*)(((arg0 % 16) * 4) + ((arg0 / 16) << 0xA) + (arg1 << 0xB) + 0x8027CEE8);
        for (index = 0; index < 0x10; index++) {
            *var_a0 = *var_v1 + temp;
            var_v1 += 1;
            var_a0 += 0x10;
        }
    }
    else {
        var_v1 = (s32*)((arg2 << 7) + 0x80252468);
        var_a0 = (s32*)(((arg0 % 8) * 8) + ((arg0 / 8) << 0xA) + (arg1 << 0xB) + 0x8027CEE8);
        for (index = 0; index < 0x10; index++) {
            var_a0[0] = var_v1[0] + temp;
            var_a0[1] = var_v1[1] + temp;
            var_v1 += 2;
            var_a0 += 0x10;
        }
    }
}

void func_800836A0(s16 arg0, s16 arg1, u16* arg2, s16 arg3) {
    if (*arg2 < 0xA1) {
        arg0 = arg0 * 2;
    }
    while (*arg2 != 0x8FFF) {
        if (*arg2 == 0) {
            arg2++;
            arg0++;
        }
        else {
            func_80083518(arg0++, arg1, *arg2++ - 0x50, arg3);
        }
    }
}

void func_8008379C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (arg1 < 3) {
        func_800831D0(arg0, arg1, arg2, arg3);
    }
    else {
        func_80083518(arg0, arg1 - 3, arg2, arg3);
    }
}

void func_80083810(s16 arg0, s16 arg1, u16* arg2, s16 arg3) {
    if (arg1 < 3) {
        func_80083358(arg0, arg1, arg2, arg3);
    }
    else {
        func_800836A0(arg0, arg1 - 3, arg2, arg3);
    }
}

void func_80083878(s16 arg0, s16 arg1) {
    if (arg1 < 3) {
        func_80083140(arg0, arg1);
    }
    else {
        func_80083488(arg0, arg1 - 3);
    }
}

#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_8008310C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_800831D0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083488.s")

extern void func_80083518(s16, s16, s16, s16);
#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083518.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_8008379C.s")

void func_80083810(s16 arg0, s16 arg1, u16* arg2, s16 arg3) {
    if (arg1 < 3) {
        func_80083358(arg0, arg1, arg2, arg3);
    }
    else {
        func_800836A0(arg0, arg1 - 3, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80083878.s")

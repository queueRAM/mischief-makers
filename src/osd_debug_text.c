#include "common.h"

typedef struct {
    s16 unk0;
    u8 unk2[0x50];
    s32 unk54;
    s32 unk58;
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    f32 unk60;
    f32 unk64;
} Unk_80180FD8; // size = 0x68

extern s32 D_80180FD0;
extern Unk_80180FD8 D_80180FD8[0x28];

void func_800838E0(void) {
    s16 index;

    for (index = 0; index < 0x28; index++) {
        D_80180FD8[index].unk0 = 0;
    }
}

void func_8008391C(u8* arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7, f32 arg8) {
    u16 index;

    if (D_80180FD0 < 0x29) {
        D_80180FD8[D_80180FD0].unk0 = 1;
        D_80180FD8[D_80180FD0].unk54 = arg1;
        D_80180FD8[D_80180FD0].unk58 = arg2;
        D_80180FD8[D_80180FD0].unk5C = arg3;
        D_80180FD8[D_80180FD0].unk5D = arg4;
        D_80180FD8[D_80180FD0].unk5E = arg5;
        D_80180FD8[D_80180FD0].unk5F = arg6;
        D_80180FD8[D_80180FD0].unk60 = arg7;
        D_80180FD8[D_80180FD0].unk64 = arg8;
        
        for (index = 0; index < 0x50; index++) {
            D_80180FD8[D_80180FD0].unk2[index] = *arg0;
            if (*arg0 == 0) {
                break;
            }
            arg0++;
        }
        D_80180FD0++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083E74.s")

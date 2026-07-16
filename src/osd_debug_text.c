#include "common.h"

typedef struct {
    s16 unk0;
    char unk2[0x50];
    s32 positionX;
    s32 positionY;
    u8 colorR;
    u8 colorG;
    u8 colorB;
    u8 colorA;
    f32 scaleX;
    f32 scaleY;
} Unk_80180FD8; // size = 0x68

extern s32 D_80180FD0;
extern Unk_80180FD8 D_80180FD8[0x28];

void func_800838E0(void) {
    s16 index;

    for (index = 0; index < 0x28; index++) {
        D_80180FD8[index].unk0 = 0;
    }
}

void func_8008391C(char* str, s32 x, s32 y, u8 red, u8 green, u8 blue, u8 alpha, f32 scale_x, f32 scale_y) {
    u16 index;

    if (D_80180FD0 < 0x29) {
        D_80180FD8[D_80180FD0].unk0 = 1;
        D_80180FD8[D_80180FD0].positionX = x;
        D_80180FD8[D_80180FD0].positionY = y;
        D_80180FD8[D_80180FD0].colorR = red;
        D_80180FD8[D_80180FD0].colorG = green;
        D_80180FD8[D_80180FD0].colorB = blue;
        D_80180FD8[D_80180FD0].colorA = alpha;
        D_80180FD8[D_80180FD0].scaleX = scale_x;
        D_80180FD8[D_80180FD0].scaleY = scale_y;
        
        for (index = 0; index < 0x50; index++) {
            D_80180FD8[D_80180FD0].unk2[index] = *str;
            if (*str == 0) {
                break;
            }
            str++;
        }
        D_80180FD0++;
    }
}

void func_80083A04(s32 value, s32 x, s32 y) {
    char str[0x50];

    sprintf(str, "%08X", value);
    func_8008391C(str, x, y, gDebugOSDTint, gDebugOSDTint, gDebugOSDTint, 0xFF, 1.0f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_80083E74.s")

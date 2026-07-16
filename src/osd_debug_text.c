#include "common.h"
#include "boot.h"
#include "font.h"
#include "compiler/ido/string.h" // for strlen

typedef struct {
    u16 isSet;
    char text[0x50];
    s32 posX;
    s32 posY;
    u8 colorR;
    u8 colorG;
    u8 colorB;
    u8 colorA;
    f32 scaleX;
    f32 scaleY;
} Unk_80180FD8; // size = 0x68

extern s32 D_80180FD0;
extern Unk_80180FD8 D_80180FD8[40];
extern u32 D_80182018;

void func_800838E0(void) {
    s16 index;

    for (index = 0; index < 0x28; index++) {
        D_80180FD8[index].isSet = 0;
    }
}

void func_8008391C(char* str, s32 x, s32 y, u8 red, u8 green, u8 blue, u8 alpha, f32 scale_x, f32 scale_y) {
    u16 index;

    if (D_80180FD0 < 0x29) {
        D_80180FD8[D_80180FD0].isSet = 1;
        D_80180FD8[D_80180FD0].posX = x;
        D_80180FD8[D_80180FD0].posY = y;
        D_80180FD8[D_80180FD0].colorR = red;
        D_80180FD8[D_80180FD0].colorG = green;
        D_80180FD8[D_80180FD0].colorB = blue;
        D_80180FD8[D_80180FD0].colorA = alpha;
        D_80180FD8[D_80180FD0].scaleX = scale_x;
        D_80180FD8[D_80180FD0].scaleY = scale_y;
        
        for (index = 0; index < 0x50; index++) {
            D_80180FD8[D_80180FD0].text[index] = *str;
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

void func_80083CF0(s32 arg0, s32 arg1) {
    s32 delta_t;
    s32 time_val;
    char str[0x50];

    delta_t = (osGetTime() - D_80182018);
    time_val = ((delta_t * 1.32) / 1000.0);
    sprintf(str, "%03d", time_val);
    func_8008391C(str, arg0, arg1, gDebugOSDTint, gDebugOSDTint, gDebugOSDTint, 0xFF, 1.0f, 1.0f);
}

void func_80083DB8(u16 arg0) {
    s32 delta_t;
    s32 time_val;

    delta_t = osGetTime() - D_80182018;
    if (!arg0) {
        rmonPrintf("\n");
    }
    time_val = ((delta_t * 1.32) / 10000.0);
    rmonPrintf("%02d : %03d%\n", arg0, time_val);
    D_80182018 = osGetTime();
}

void func_80083E74(void) {
    Gfx* display_list;
    s32 i;
    char pad[0x50]; // unused, likely allocated for local string

    display_list = gDisplayListHead;
    Font_Init(&display_list);
    Font_SetTransparent(0);
    Font_SetColor(gDebugOSDTint, gDebugOSDTint, gDebugOSDTint, 0xFF);
    Font_SetScale(1.0, 1.0);
    Font_SetTransparent(1);
    
    for (i = 0; i < ARRAYLENGTH(D_80180FD8); i++) {
        if (D_80180FD8[i].isSet) {
            Font_SetWindow(strlen(D_80180FD8[i].text) + 1, 1);
            Font_SetPos(D_80180FD8[i].posX + SCREEN_WIDTH / 2, -D_80180FD8[i].posY + SCREEN_HEIGHT / 2);
            Font_SetColor(D_80180FD8[i].colorR, D_80180FD8[i].colorG, D_80180FD8[i].colorB, D_80180FD8[i].colorA);
            Font_SetScale(D_80180FD8[i].scaleX, D_80180FD8[i].scaleY);
            Font_ShowString(&display_list, D_80180FD8[i].text);
        }
    }
    D_80180FD0 = 0;
    Font_Finish(&display_list);
    gDisplayListHead = display_list;
}

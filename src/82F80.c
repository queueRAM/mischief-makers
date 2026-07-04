#include "common.h"
#include "boot.h"

extern Gfx D_800E3590[];
extern Gfx D_800E35E0[];
extern u8 D_801376A8[];
extern u8 D_801376AC[];
extern u8 D_801376B0[];
extern u8 D_801376B4[];
extern u8 D_801376B8[];
extern u8 D_801376BC[];

#ifdef NON_MATCHING
// https://decomp.me/scratch/SJ5vt
void func_80082380(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3[][10], u8* arg4, u8 arg5) {
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 var_s2;
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 var_t5;
    Gfx* var_v0;

    if (D_801376BC[arg5] != 0) {
        gSPDisplayList(gDisplayListHead++, D_800E3590);
        spAC = spA8 = 1;
        spA4 = 4;
    }
    else {
        gSPDisplayList(gDisplayListHead++, D_800E35E0);
        if (D_801376B8[arg5] != 0) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
        }
        else {
            gDPSetPrimColor(gDisplayListHead++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        gDPSetEnvColor(gDisplayListHead++, D_801376A8[arg5], D_801376AC[arg5], D_801376B0[arg5], D_801376B4[arg5]);
        spAC = spA8 = 0;
        spA4 = 1;
    }

    var_v0 = arg0;
    for (var_s2 = 0; var_s2 < 7; var_s2++) {
        for (var_t5 = 0; var_t5 < 10; var_t5++) {
            temp_t1 = arg3[var_s2][var_t5];
            if (arg3[var_s2][var_t5] != 0) {
                temp_a3 = (var_t5 * 32) + arg1;
                temp_t0 = (var_s2 * 32) + arg2;
                if (((temp_a3 + 32) >= 0) && ((temp_t0 + 32) >= 0)) {
                    gDPLoadTextureBlock(var_v0++, temp_t1, G_IM_FMT_CI, G_IM_SIZ_8b,
                                        32, 32, 0, 
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 
                                        5, 5, G_TX_NOLOD, G_TX_NOLOD);
                    gSPTextureRectangle(var_v0++, 
                                        MAX(0, temp_a3) << 2, // ((temp_a3 < 0) ? 0 : temp_a3) * 4,
                                        MAX(0, temp_t0) << 2, // ((temp_t0 < 0) ? 0 : temp_t0) * 4, 
                                        ((temp_a3 - spAC) + 32) << 2, 
                                        ((temp_t0 - spA8) + 32) << 2, 
                                        G_TX_RENDERTILE,
                                        ((temp_a3 < 0) ? -temp_a3 : 0) * 32, // permuter keeps finding things with:
                                        ((temp_t0 < 0) ? -temp_t0 : 0) * 32, // temp_a3 or temp_t0 here
                                        spA4 << 10,
                                        1 << 10);
                }
            }
            temp_t1 = arg3[var_s2][var_t5]; // fakematch
        }
    }
    gDPLoadTLUT_pal256(gDisplayListHead++, arg4);
    gSPEndDisplayList(var_v0); // this is a weird place to put this
    gSPDisplayList(gDisplayListHead++, arg0);
    gDPPipeSync(gDisplayListHead++);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082380.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/j3YGA
void func_80082820(Gfx* arg0, s32 arg1[][10], u8* arg2, u8 arg3) {
    s32 temp_v1;
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 var_s1;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 var_t4;
    Gfx* var_v0;

    if (D_801376BC[arg3] != 0) {
        gSPDisplayList(gDisplayListHead++, D_800E3590);
        spB0 = spAC = 1;
        spA8 = 4;
    }
    else {
        gSPDisplayList(gDisplayListHead++, D_800E35E0);
        if (D_801376B8[arg3] != 0) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
        }
        else {
            gDPSetPrimColor(gDisplayListHead++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        gDPSetEnvColor(gDisplayListHead++, D_801376A8[arg3], D_801376AC[arg3], D_801376B0[arg3], D_801376B4[arg3]);
        spB0 = spAC = 0;
        spA8 = 1;
    }

    var_v0 = arg0;
    for (var_s1 = 0; var_s1 < 7; var_s1++) {
        if (D_8011D3B0[var_s1][0] != 0xFFFF) {
            temp_v1 = 14 - ((D_8011D3B0[var_s1][0] - 2) & 0x1F);
            for (var_t4 = 0; var_t4 < 10; var_t4++) {
                temp_t1 = arg1[var_s1][var_t4];
                if (temp_t1 != 0) {
                    temp_t0 = (var_s1 * 32) + D_800BE6E0;
                    temp_a3 = (var_t4 * 32) + temp_v1;
                    if (((temp_a3 + 32) >= 0) && ((temp_t0 + 32) >= 0)) {
                        gDPLoadTextureBlock(var_v0++, temp_t1, G_IM_FMT_CI, G_IM_SIZ_8b,
                                            32, 32, 0, 
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 
                                            5, 5, G_TX_NOLOD, G_TX_NOLOD);
                        gSPTextureRectangle(var_v0++, 
                                            MAX(0, temp_a3) << 2, // ((temp_a3 < 0) ? 0 : temp_a3) * 4,
                                            MAX(0, temp_t0) << 2, // ((temp_t0 < 0) ? 0 : temp_t0) * 4, 
                                            ((temp_a3 - spB0) + 32) << 2, 
                                            ((temp_t0 - spAC) + 32) << 2, 
                                            G_TX_RENDERTILE,
                                            ((temp_a3 < 0) ? -temp_a3 : 0) * 32,
                                            ((temp_t0 < 0) ? -temp_t0 : 0) * 32,
                                            spA8 << 10,
                                            1 << 10);
                    }
                }
            }
            temp_t1 = arg1[var_s1][var_t4]; // fakematch
        }
    }
    gDPLoadTLUT_pal256(gDisplayListHead++, arg2);
    gSPEndDisplayList(var_v0); // this is a weird place to put this
    gSPDisplayList(gDisplayListHead++, arg0);
    gDPPipeSync(gDisplayListHead++);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082820.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/82F80/func_80082F10.s")

void func_8008310C(void) {
    u16 index;
    s32* var_v0;

    var_v0 = (s32*)0x8027EEE8;
    for (index = 0; index < 0x300; index++) {
        var_v0[0] = 0;
        var_v0[1] = 0;
        var_v0 += 2;
    }
}

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

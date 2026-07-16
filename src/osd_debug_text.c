#include "common.h"

typedef struct {
    s16 unk0;
    u8 pad2[0x68 - 2];
} Unk_80180FD8; // size = 0x68

extern Unk_80180FD8 D_80180FD8[0x28];

void func_800838E0(void) {
    s16 index;

    for (index = 0; index < 0x28; index++) {
        D_80180FD8[index].unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/osd_debug_text/func_8008391C.s")

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

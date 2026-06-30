#include "common.h"

extern s32 D_800D74A0[];

void func_80060F80(s32 arg0) {
}

void func_80060F88(u16 arg0) {
    switch (gActors[arg0].state) {
    case 0:
        gActors[arg0].graphicFlags |= 0x300F;
        gActors[arg0].graphicIndex = 0;
        gActors[arg0].scaleX = 1.0f;
        gActors[arg0].scaleY = 1.0f;
        gActors[arg0].unk_12C = 1.0f;
        gActors[arg0].posZ.whole = gActors[arg0].timer_110;
        gActors[arg0].unk_17C = D_800D74A0[gActors[arg0].unk_0D8];
        gActors[arg0].state++;
        if (gActors[arg0].var_154 != 0) {
            gActors[arg0].state = gActors[arg0].var_154;
            gActors[arg0].scaleX = 0.35f;
            gActors[arg0].scaleY = 0.35f;
            gActors[arg0].unk_12C = 0.35f;
        }
        break;
    case 1:
        if (gGameState == 6) {
            if (gButtonPress & gButton_CDown) {
                if (gActors[arg0].unk_0D8 > 0) {
                    gActors[arg0].unk_0D8--;
                    gActors[arg0].unk_17C = D_800D74A0[gActors[arg0].unk_0D8];
                }
            }
            if (gButtonPress & gButton_CUp) {
                if (gActors[arg0].unk_0D8 < 0x19) {
                    gActors[arg0].unk_0D8++;
                    gActors[arg0].unk_17C = D_800D74A0[gActors[arg0].unk_0D8];
                }
            }
        }
        if (gButtonHold & gButton_DLeft) {
            gActors[arg0].rotateY += 4.0;
        }
        if (gButtonHold & gButton_DRight) {
            gActors[arg0].rotateY -= 4.0;
        }
        if (gButtonHold & gButton_DDown) {
            gActors[arg0].rotateX += 4.0;
        }
        if (gButtonHold & gButton_DUp) {
            gActors[arg0].rotateX -= 4.0;
        }
        if (gButtonHold & gButton_LTrig) {
            gActors[arg0].rotateZ += 4.0;
        }
        if (gButtonHold & gButton_RTrig) {
            gActors[arg0].rotateZ -= 4.0;
        }
        break;
    case 2:
        gActors[arg0].rotateX += 4.0;
        gActors[arg0].rotateY -= 4.0;
        gActors[arg0].rotateZ -= 4.0;
        return;
    case 3:
        gActors[arg0].rotateX += 4.0;
        gActors[arg0].rotateY -= 4.0;
        gActors[arg0].rotateZ += 4.0;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800612D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800614D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800615BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80061E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800623C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006242C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006291C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800629A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80062F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800630E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800631A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006330C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800633C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006346C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80063FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800640A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800641CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800643CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800645F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006475C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_800648C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80064F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_80065270.s")

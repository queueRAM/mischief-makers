#include "common.h"

extern s32 D_800D74A0[];

void func_80060F80(u16 arg0) {
}

void func_80060F88(u16 actor_index) {
    switch (gActors[actor_index].state) {
    case 0:
        gActors[actor_index].graphicFlags |= 0x300F;
        gActors[actor_index].graphicIndex = 0;
        gActors[actor_index].scaleX = 1.0f;
        gActors[actor_index].scaleY = 1.0f;
        gActors[actor_index].unk_12C = 1.0f;
        gActors[actor_index].posZ.whole = gActors[actor_index].timer_110;
        gActors[actor_index].unk_17C = D_800D74A0[gActors[actor_index].unk_0D8];
        gActors[actor_index].state++;
        if (gActors[actor_index].var_154 != 0) {
            gActors[actor_index].state = gActors[actor_index].var_154;
            gActors[actor_index].scaleX = 0.35f;
            gActors[actor_index].scaleY = 0.35f;
            gActors[actor_index].unk_12C = 0.35f;
        }
        break;
    case 1:
        if (gGameState == 6) {
            if (gButtonPress & gButton_CDown) {
                if (gActors[actor_index].unk_0D8 > 0) {
                    gActors[actor_index].unk_0D8--;
                    gActors[actor_index].unk_17C = D_800D74A0[gActors[actor_index].unk_0D8];
                }
            }
            if (gButtonPress & gButton_CUp) {
                if (gActors[actor_index].unk_0D8 < 0x19) {
                    gActors[actor_index].unk_0D8++;
                    gActors[actor_index].unk_17C = D_800D74A0[gActors[actor_index].unk_0D8];
                }
            }
        }
        if (gButtonHold & gButton_DLeft) {
            gActors[actor_index].rotateY += 4.0;
        }
        if (gButtonHold & gButton_DRight) {
            gActors[actor_index].rotateY -= 4.0;
        }
        if (gButtonHold & gButton_DDown) {
            gActors[actor_index].rotateX += 4.0;
        }
        if (gButtonHold & gButton_DUp) {
            gActors[actor_index].rotateX -= 4.0;
        }
        if (gButtonHold & gButton_LTrig) {
            gActors[actor_index].rotateZ += 4.0;
        }
        if (gButtonHold & gButton_RTrig) {
            gActors[actor_index].rotateZ -= 4.0;
        }
        break;
    case 2:
        gActors[actor_index].rotateX += 4.0;
        gActors[actor_index].rotateY -= 4.0;
        gActors[actor_index].rotateZ -= 4.0;
        return;
    case 3:
        gActors[actor_index].rotateX += 4.0;
        gActors[actor_index].rotateY -= 4.0;
        gActors[actor_index].rotateZ += 4.0;
        break;
    }
}

void func_800612D8(u16 actor_index) {
    gActors[actor_index].posX.raw -= D_800BE73C;
    if (gActors[actor_index].posX.whole < -0x600) {
        gActors[actor_index].posX.whole += 0xC00;
    }
    else if (gActors[actor_index].posX.whole > 0x600) {
        gActors[actor_index].posX.whole -= 0xC00;
    }
}

void func_80061350(u16 actor_index) {
    if (actor_index != 0x90) {
        gActors[actor_index].colorR = gActors[0x90].colorR;
        gActors[actor_index].colorG = gActors[0x90].colorG;
        gActors[actor_index].colorB = gActors[0x90].colorB;
        gActors[actor_index].colorA = gActors[0x90].colorA;
    }
    else
    {
        gActors[actor_index].colorR = Math_ApproachS32(gActors[actor_index].colorR, 0, 4);
        gActors[actor_index].colorG = Math_ApproachS32(gActors[actor_index].colorG, 0, 4);
        gActors[actor_index].colorB = Math_ApproachS32(gActors[actor_index].colorB, 0, 4);
        gActors[actor_index].colorA = Math_ApproachS32(gActors[actor_index].colorA, 0x60, 4);
    }
}

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

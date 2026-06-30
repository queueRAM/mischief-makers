#include "common.h"

typedef struct {
    u8 unk0[0x20];
} Unk_Struct_u8_20;

#define D_803402D0 ((Unk_Struct_u8_20*)0x803402D0)
#define D_803406D0 ((Unk_Struct_u8_20*)0x803406D0)
#define D_80340DE0 ((Unk_Struct_u8_20*)0x80340DE0)
#define D_803409E0 ((Unk_Struct_u8_20*)0x803409E0)

extern s32 D_800D74A0[];
extern u16 D_800D7508[];

extern u16 D_80178450;
extern u16 D_80178452;
extern u16 D_80178454;

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

void func_80061450(u16 actor_index) {
    gActors[actor_index].graphicFlags = 0x900;
    gActors[actor_index].flags |= 0x18;
    gActors[actor_index].unk_188 = 0;
    gActors[actor_index].graphicIndex = D_800D7508[gActors[actor_index].unk_0D8];
    gActors[actor_index].colorA = 0x80;
    if (actor_index >= 0x92) {
        gActors[actor_index].flags &= ~1;
    }
}

void func_800614D4(u16 actor_index) {
    if (gActors[0x90].var_15C != 0) {
        if (!(gActors[actor_index].flags & 1)) {
            gActors[actor_index].flags |= 1;
            gActors[actor_index].colorA = 0;
            gActors[actor_index].state += 1;
        }
        else {
            gActors[actor_index].state += 2;
        }
    }
}

void func_80061554(u16 actor_index) {
    gActors[actor_index].colorA++;
    if (gActors[actor_index].colorA== 0x80) {
        gActors[0x90].var_15C = 0;
        gActors[actor_index].state--;
    }
}

void func_800615BC(u16 actor_index) {
    gActors[actor_index].colorA--;
    if (gActors[actor_index].colorA == 0) {
        gActors[actor_index].flags &= ~1;
        gActors[actor_index].state -= 2;
    }
}

void func_80061624(u16 actor_index) {
    s32 temp_f6;
    s16 temp_v0;
    s16 index;
    s16 jndex;
    s32 pad0;
    s32 pad1;
    s32 pad2;
    s32 pad3;

    switch (gActors[actor_index].state) {
        case 0x0:
            gActors[actor_index].graphicTimer = 0;
            temp_f6 = (s32) gActors[actor_index].timer_110;
            gActors[actor_index].var_150 = temp_f6 & 0xFF00;
            gActors[actor_index].var_154 = temp_f6 & 0xFF;
            switch (gActors[actor_index].var_154) {
                case 0:
                default:
                    goto sw_1_case_0;
                case 1:
                    goto sw_1_case_1;
                case 3:
                    goto sw_1_case_3;
                case 4:
                    goto sw_1_case_4;
                case 5:
                    goto sw_1_case_5;
                case 6:
                    goto sw_1_case_6;
                case 7:
                    goto sw_1_case_7;
                case 8:
                    goto sw_1_case_8;
            }
            break;

        sw_1_case_8:
            gActors[actor_index].graphicIndex = ((s32) ((s32) gActors[actor_index].var_150 / 128) % 8) + 0x2000;
            goto dummy_case_5;
        sw_1_case_0:
            gActors[actor_index].graphicFlags = 0x900;
            gActors[actor_index].flags |= 0x18;
            gActors[actor_index].unk_188 = 0;
            gActors[actor_index].posZ.whole = -0x200;
            gActors[actor_index].graphicIndex = 0x2002;
            gActors[actor_index].state = 0x10;
            gActors[actor_index].posX.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentX.whole) & 0x3FF) - 0x1E0;
        case 0x10:
            gActors[actor_index].posX.raw -= D_800BE73C;
            gActors[actor_index].posX.whole = ((gActors[actor_index].posX.whole + 0x1E0) & 0x3FF) - 0x1E0;
            gActors[actor_index].posY.whole = 0x253 - gScreenPosCurrentY.whole;
            break;
        sw_1_case_1:
            gActors[actor_index].graphicFlags = 0x900;
            gActors[actor_index].flags |= 8;
            gActors[actor_index].unk_188 = 0;
            gActors[actor_index].posZ.whole = -0x100;
            gActors[actor_index].graphicIndex = 0x2000;
            gActors[actor_index].state = 0x20;
            gActors[actor_index].var_158 = 0;
            gActors[actor_index].colorA = 0x80;
            D_80178450 = 2;
            D_80178452 = 0xA5;
            D_80178454 = 0xD;
        case 0x20:
            gActors[actor_index].posY.whole = 0x116 - ((gScreenPosCurrentY.whole * 7) / 8);
            gActors[actor_index].posX.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentX.whole) & 0x3FF) - 0x200;
            if (actor_index != 0x90) {
                gActors[actor_index].var_158 += D_80178450;
                for (index = 0; index < 0x20; index++) {
                    temp_v0 = (SIN(gActors[actor_index].var_158 + (index * D_80178452)) * D_80178454) + index;
                    if (index && index) {
                    }
                    temp_v0 &= 0x1F;
                    for (jndex = 0; jndex < 0x20; jndex++) {
                        D_803402D0[index].unk0[jndex] = D_803406D0[temp_v0].unk0[jndex];
                    }
                }
            }
            break;
        sw_1_case_3:
            func_80061450(actor_index);
            gActors[actor_index].posX.whole = gActors[actor_index].var_150;
            gActors[actor_index].posZ.whole = -0x100;
            gActors[actor_index].state = 0x30;
        case 0x30:
            func_800612D8(actor_index);
            func_800614D4(actor_index);
            break;
        
        case 0x31:
            func_800612D8(actor_index);
            func_80061554(actor_index);
            break;
        
        case 0x32:
            func_800612D8(actor_index);
            func_800615BC(actor_index);
            break;
        sw_1_case_4:
            func_80061450(actor_index);
            gActors[actor_index].posZ.whole = -0xC0;
            gActors[actor_index].state = 0x40;
        
        case 0x40:
            gActors[actor_index].posY.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentY.whole) & 0x7FF) - 0x400;
            func_800614D4(actor_index);
            break;
        
        case 0x41:
            gActors[actor_index].posY.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentY.whole) & 0x7FF) - 0x400;
            func_80061554(actor_index);
            break;
        
        case 0x42:
            gActors[actor_index].posY.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentY.whole) & 0x7FF) - 0x400;
            func_800615BC(actor_index);
            break;
        sw_1_case_5:
            gActors[actor_index].graphicIndex = (gActors[actor_index].var_150 / 128) + 0x200A;
        dummy_case_5:
            gActors[actor_index].graphicFlags = 0x900;
            gActors[actor_index].unk_188 = 0;
            gActors[actor_index].posZ.whole = -0x1F0;
            gActors[actor_index].var_150 = gActors[actor_index].var_150 / 2;
            gActors[actor_index].state = 0x50;
        case 0x50:
            gActors[actor_index].posY.whole = 0x120 - gScreenPosCurrentY.whole;
            if (gCurrentScene == 6) {
                gActors[actor_index].posX.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentX.whole) & 0x3FF) - 0x200;
                if (gLookatEyeZ == 448.0f) {
                    if ((gActors[actor_index].posX.whole < -0x100) || (gActors[actor_index].posX.whole >= 0x101)) {
                        gActors[actor_index].flags &= ~1;
                        break;
                    }
                    gActors[actor_index].flags |= 1;
                    break;
                }
                gActors[actor_index].flags |= 1;
                break;
            }
                
            gActors[actor_index].posX.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentX.whole) & 0x1FF) - 0x100;
            break;
        sw_1_case_6:
            gActors[actor_index].graphicFlags = 0x910;
            gActors[actor_index].flags |= 8;
            gActors[actor_index].unk_188 = 0;
            gActors[actor_index].posZ.whole = -0x120;
            gActors[actor_index].graphicIndex = 0x2002;
            gActors[actor_index].var_158 = 0;
            gActors[actor_index].colorA = 0xC0;
            gActors[actor_index].colorR = 0x80;
            gActors[actor_index].colorG = 0x80;
            D_80178450 = 2;
            D_80178452 = 0xA5;
            D_80178454 = 0xD;
            gActors[actor_index].state = 0x60;
        case 0x60:
            gActors[actor_index].posY.whole = 0x116 - ((s32) (gScreenPosCurrentY.whole * 7) / 8);
            gActors[actor_index].posX.whole = ((gActors[actor_index].var_150 - gScreenPosCurrentX.whole) & 0x3FF) - 0x200;
            if (actor_index != 0x92) {
                gActors[actor_index].var_158 += D_80178450;
                for (index = 0; index < 0x20; index++) {
                    temp_v0 = (SIN(gActors[actor_index].var_158 + (index * D_80178452)) * D_80178454) + index;
                    if (index && index) { // fakematch
                    }
                    temp_v0 &= 0x1F;
                    for (jndex = 0; jndex < 0x20; jndex++) {
                        D_80340DE0[index].unk0[jndex] = D_803409E0[temp_v0].unk0[jndex];
                    }
                }
            }
            break;
        sw_1_case_7:
            gActors[actor_index].unk_164 = 1;
            func_80061450(actor_index);
            gActors[actor_index].posX.whole = gActors[actor_index].var_150;
            gActors[actor_index].posZ.whole = -0x100;
            gActors[actor_index].state = 0x70;
        case 0x70:
            func_800612D8(actor_index);
            func_80061350(actor_index);
            break;
        
        case 0x71:
            func_800612D8(actor_index);
            if (gActors[actor_index].var_15C != 0) {
                func_80061350(actor_index);
            }
            func_80061554(actor_index);
            break;
        
        case 0x72:
            func_800612D8(actor_index);
            if (gActors[actor_index].var_15C != 0) {
                func_80061350(actor_index);
            }
            func_800615BC(actor_index);
            break;
        default:
            break;
    }
}

void func_80061E98(u16 actor_index) {
    u16 index;
    s16 temp_limit;
    switch (gActors[actor_index].state) {
    case 0:
        gActors[actor_index].graphicFlags |= 0x801;
        gActors[actor_index].flags |= 0x2000;
        gActors[actor_index].posZ.whole = -8;
        gActors[actor_index].unk_188 = 0;
        gActors[actor_index].scaleX = gActors[actor_index].timer_110 / 64;
        gActors[actor_index].hitboxBX0 = gActors[actor_index].scaleX * -32.0f;
        gActors[actor_index].hitboxBX1 = gActors[actor_index].scaleX * 32.0f;
        gActors[actor_index].hitboxBY0 = 8;
        gActors[actor_index].hitboxBY1 = 0;
        gActors[actor_index].state++;
        switch (gActors[actor_index].unk_0D8 & 0x30) {
        case 0: 
            gActors[actor_index].graphicIndex = 0x380C;
            break;
        case 16:
            gActors[actor_index].graphicIndex = 0x380E;
            break;
        case 32:
            gActors[actor_index].graphicIndex = 0x3810;
            break;
        }
        switch (gActors[actor_index].unk_0D8 & 0xF) {
        case 1:
        case 5:
            gActors[actor_index].colorB = 0x7F; \
            gActors[actor_index].colorR = 0; \
            gActors[actor_index].colorG = 0; \
            break;
        case 2:
        case 6:
            gActors[actor_index].colorR = 0x7F; \
            gActors[actor_index].colorG = 0; \
            gActors[actor_index].colorB = 0; \
            break;
        case 3:
        case 7:
            gActors[actor_index].colorR = 0x7F; \
            gActors[actor_index].colorB = 0x7F; \
            gActors[actor_index].colorG = 0; \
            break; \
        case 4:
        case 8:
            gActors[actor_index].colorG = 0x7F; \
            gActors[actor_index].colorR = 0; \
            gActors[actor_index].colorB = 0; \
            break;
        }
        if ((gActors[actor_index].unk_0D8 & 0xF) >= 5) {
            gActors[actor_index].graphicFlags |= 0x10;
        }
        break;
    case 1:
        if (gActors[actor_index].flags_098 & 0x80) {
            gActors[actor_index].var_158 = 1;
        }
        // fakematch: temp = 0x148
        if ((D_800D28E4 >= 0xA) && (D_800D28E4 < 0x14) && ((gScreenPosCurrentY.whole + gActors[actor_index].posY.whole) < (temp_limit = 0x148))) {
            gActors[actor_index + 1].flags = 0;
            gActors[actor_index + 0].flags = 0;
            index = func_8003FF68(actor_index, 1.0f);
            gActors[index].unk_188 = gActors[actor_index].posY.raw + FIXED_UNIT(-8.0);
        }
        break;
    }
}

void func_80062174(u16 actor_index) {
    switch (gActors[actor_index].state) {
    case 0:
        gActors[actor_index].graphicFlags |= 0x180F;
        gActors[actor_index].flags |= 9;
        gActors[actor_index].graphicIndex = 0x262;
        gActors[actor_index].graphicTimer = 0;
        gActors[actor_index].posX.whole = 0;
        gActors[actor_index].posY.whole = 0x30;
        gActors[actor_index].posZ.whole = -0x212;
        gActors[actor_index].unk_188 = -0x22;
        gActors[actor_index].scaleX = 9.0f;
        gActors[actor_index].unk_12C = 9.0f;
        gActors[actor_index].rotateX = -8.0f;
        Sound_PlaySfx(0xBF);
        gActors[actor_index].flags |= 1;
        gActors[actor_index].colorA = 3;
        gActors[actor_index].state += 1;
        /* fallthrough */
    case 1:
        gActors[actor_index].rotateY += 2.0f;
        if (gActiveFrames & 1) {
            gActors[actor_index].colorA += 4;
            if (gActors[actor_index].colorA == 0xFF) {
                gDrawBackground = 0;
                gActors[0x8C].unk_18C = 1;
                gActors[actor_index].state++;
            }
        }
        break;
    case 2:
        gActors[actor_index].rotateY += 2.0f;
        break;
    }
    gActors[actor_index].posY.whole = 0x230 - D_800BE580;
}

void func_80062300(u16 actor_index) {
    gActors[actor_index].posX.raw = (((gActors[actor_index].posX.raw + gScreenPosCurrentX.raw) & 0xFFF00000) - gScreenPosCurrentX.raw) + 0x80000;
    gActors[actor_index].velocityX.raw = 0;
}

void func_80062360(u16 actor_index) {
    gActors[actor_index].posY.raw = (((gActors[actor_index].posY.raw + gScreenPosCurrentY.raw) & 0xFFF00000) - gScreenPosCurrentY.raw) + 0x80000;
    gActors[actor_index].velocityY.raw = 0;
}

void func_800623C0(u16 actor_index) {
    if (gActors[actor_index].state <= 0x64) {
        func_80062360(actor_index);
    }
    else {
        func_80062300(actor_index);
    }
}

void func_8006242C(u16 actor_index) {
    gActors[actor_index].unk_17C += gActors[actor_index].unk_178;
    gActors[actor_index].velocityX.raw = SIN(gActors[actor_index].unk_17C) * gActors[actor_index].var_15C;
    gActors[actor_index].velocityY.raw = COS(gActors[actor_index].unk_17C) * gActors[actor_index].var_15C;
    if (gActors[actor_index].unk_17C == gActors[actor_index].unk_174) {
        gActors[actor_index].state = gActors[actor_index].unk_16C;
        func_800623C0(actor_index);
    }
}

void func_80062524(u16 actor_index) {
    gActors[actor_index].unk_17C -= gActors[actor_index].unk_178;
    gActors[actor_index].velocityX.raw = -SIN(gActors[actor_index].unk_17C) * gActors[actor_index].var_15C;
    gActors[actor_index].velocityY.raw = -COS(gActors[actor_index].unk_17C) * gActors[actor_index].var_15C;
    if (gActors[actor_index].unk_17C == gActors[actor_index].unk_170) {
        gActors[actor_index].state = gActors[actor_index].unk_168;
        func_800623C0(actor_index);
    }
}

void func_80062624(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (gActors[actor_index].flags_098 & 0x200) &&
        (gActors[actor_index].flags_098 & 0x20000) && (gActors[actor_index].state >= 0x68)) {
        if (((gActors[actor_index].velocityX.raw < 0) && (func_800486F4() == 4)) || 
            ((gActors[actor_index].velocityX.raw > 0) && (func_800486F4() == 12)) ||
            ((gActors[actor_index].velocityY.raw < 0) && (func_800486F4() == 0)) || 
            ((gActors[actor_index].velocityY.raw > 0) && (func_800486F4() == 8))) {
            gActors[actor_index].state = 0x23;
            gActors[actor_index].unk_180 = gActors[actor_index].velocityX.raw;
            gActors[actor_index].unk_184 = gActors[actor_index].velocityY.raw;
        }
    }
}

void func_8006275C(u16 actor_index) {
    gActors[actor_index].velocityX.raw = 0;
    gActors[actor_index].velocityY.raw = 0;
    if ((gActors[actor_index].flags_098 & 0x200) && (gActors[actor_index].flags_098 & 0x20000)) {
        switch (func_800486F4()) {
        case 4:
            if (gActors[actor_index].unk_180 > 0) {
                gActors[actor_index].state = 0x68;
            }
            else {
                gActors[actor_index].state = 0x69;
            }
            break;
        case 12:
            if (gActors[actor_index].unk_180 > 0) {
                gActors[actor_index].state = 0x69;
            }
            else {
                gActors[actor_index].state = 0x68;
            }
            break;
        case 0:
            if (gActors[actor_index].unk_184 > 0) {
                gActors[actor_index].state = 0x68;
            }
            else {
                gActors[actor_index].state = 0x69;
            }
            break;
        case 8:
            if (gActors[actor_index].unk_184 > 0) {
                gActors[actor_index].state = 0x69;
            }
            else {
                gActors[actor_index].state = 0x68;
            }
            break;
        }
    }
}

void func_80062874(u16 actor_index, u16 arg1, u16 arg2, s32 arg3, s32 arg4) {
    gActors[actor_index].state = 0x68;
    gActors[actor_index].unk_168 = arg1;
    gActors[actor_index].unk_16C = arg2;
    gActors[actor_index].unk_170 = arg3;
    gActors[actor_index].unk_174 = arg4;
    if (arg3 < arg4) {
        gActors[actor_index].unk_178 = gActors[actor_index].var_160;
    }
    else {
        gActors[actor_index].unk_178 = -gActors[actor_index].var_160;
    }
    gActors[actor_index].unk_17C = arg3;
    func_8006242C(actor_index);
}

u8 func_8006291C(u16 actor_index) {
    return ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) &&
            (func_80012AB4(gActors[actor_index].posX.whole + 8, gActors[actor_index].posY.whole) != 0x36));
}

u8 func_800629A8(u16 actor_index) {
    return ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) &&
            (func_80012AB4(gActors[actor_index].posX.whole - 8, gActors[actor_index].posY.whole) != 0x36));
}

u8 func_80062A34(u16 actor_index) {
    return ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) &&
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole + 8) != 0x36));
}

u8 func_80062AC0(u16 actor_index) {
    return ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) &&
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole - 8) != 0x36));
}

void func_80062B4C(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (gActors[actor_index].flags_098 & 0x200) && (gActors[actor_index].flags_098 & 0x20000) && (func_800486F4() == 0xC)) {
        gActors[actor_index].state = 0x20;
    }
    else {
        if ((func_80012AB4(gActors[actor_index].posX.whole + 0x10, gActors[actor_index].posY.whole) == 0) && 
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) != 0x36)) {
            if (func_80012AB4(gActors[actor_index].posX.whole + 0x10, gActors[actor_index].posY.whole + 0x10) == 0x32) {
                func_80062874(actor_index, 0x63, 0x65, 0x100, 4);
            }
            else if (func_80012AB4(gActors[actor_index].posX.whole + 0x10, gActors[actor_index].posY.whole - 0x10) == 0x32) {
                func_80062874(actor_index, 0x63, 0x67, 0x100, 0x1FC);
            }
        }
    }
}

void func_80062CB4(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (gActors[actor_index].flags_098 & 0x200) && (gActors[actor_index].flags_098 & 0x20000) && (func_800486F4() == 4)) {
        gActors[actor_index].state = 0x20;
    }
    else {
        if ((func_80012AB4(gActors[actor_index].posX.whole - 0x10, gActors[actor_index].posY.whole) == 0) && 
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) != 0x36)) {
            if (func_80012AB4(gActors[actor_index].posX.whole - 0x10, gActors[actor_index].posY.whole + 0x10) == 0x32) {
                func_80062874(actor_index, 0x61, 0x65, 0x300, 0x3FC);
            }
            else if (func_80012AB4(gActors[actor_index].posX.whole - 0x10, gActors[actor_index].posY.whole - 0x10) == 0x32) {
                func_80062874(actor_index, 0x61, 0x67, 0x300, 0x204);
            }
        }
    }
}

void func_80062E1C(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (gActors[actor_index].flags_098 & 0x200) && (gActors[actor_index].flags_098 & 0x20000) && (func_800486F4() == 8)) {
        gActors[actor_index].state = 0x21;
    }
    else {
        if ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole + 0x10) == 0) && 
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) != 0x36)) {
            if (func_80012AB4(gActors[actor_index].posX.whole + 0x10, gActors[actor_index].posY.whole + 0x10) == 0x32) {
                func_80062874(actor_index, 0x67, 0x61, 4, 0x100);
            }
            else if (func_80012AB4(gActors[actor_index].posX.whole - 0x10, gActors[actor_index].posY.whole + 0x10) == 0x32) {
                func_80062874(actor_index, 0x67, 0x63, 0x3FC, 0x300);
            }
        }
    }
}

void func_80062F84(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (((gActors[actor_index].flags_098 & 0x200) != 0)) && (gActors[actor_index].flags_098 & 0x20000) && (func_800486F4() == 0)) {
        gActors[actor_index].state = 0x21;
    }
    else {
        if ((func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole - 0x10) == 0) &&
            (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) != 0x36)) {
            if (func_80012AB4(gActors[actor_index].posX.whole + 0x10, gActors[actor_index].posY.whole - 0x10) == 0x32) {
                func_80062874(actor_index, 0x65, 0x61, 0x1FC, 0x100);
            }
            else if (func_80012AB4(gActors[actor_index].posX.whole - 0x10, gActors[actor_index].posY.whole - 0x10) == 0x32) {
                func_80062874(actor_index, 0x65, 0x63, 0x204, 0x300);
            }
        }
    }
}

void func_800630E8(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (func_800486F4() == 4) && (func_80012AB4(gActors[actor_index].posX.whole + 9, gActors[actor_index].posY.whole) != 0)) {
        if (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) {
            gActors[actor_index].state = 0x60;
        }
        else {
            gActors[actor_index].state = 0x61;
        }
    }
}

void func_800631A0(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (func_800486F4() == 0xC) && (func_80012AB4(gActors[actor_index].posX.whole - 9, gActors[actor_index].posY.whole) != 0)) {
        if (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) {
            gActors[actor_index].state = 0x62;
        }
        else {
            gActors[actor_index].state = 0x63;
        }
    }
}

void func_80063258(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (func_800486F4() == 0) && (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole + 9) != 0)) {
        if (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) {
            gActors[actor_index].state = 0x64;
        }
        else {
            gActors[actor_index].state = 0x65;
        }
    }
}

void func_8006330C(u16 actor_index) {
    if ((gActors[actor_index].unk_0D8 < 0x30) && (func_800486F4() == 8) && (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole - 9) != 0)) {
        if (func_80012AB4(gActors[actor_index].posX.whole, gActors[actor_index].posY.whole) == 0x36) {
            gActors[actor_index].state = 0x66;
        }
        else {
            gActors[actor_index].state = 0x67;
        }
    }
}

void func_800633C4(u16 actor_index) {
    if ((gActors[actor_index].posY.whole + 0xC0) < gActors[0].posY.whole) {
        gActors[actor_index].state = 0x7C;
    }
}

void func_80063418(u16 actor_index) {
    if ((gActors[actor_index].posY.whole - 0xC0) > gActors[0].posY.whole) {
        gActors[actor_index].state = 0x7E;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/61B80/func_8006346C.s")

void func_80063FF4(u16 actor_index) {
    gActors[actor_index].unk_180 = gActors[actor_index].posX.whole + gScreenPosCurrentX.whole;
    gActors[actor_index].unk_184 = gActors[actor_index].posY.whole + gScreenPosCurrentY.whole;
    if (gActors[actor_index].state != 0) {
        if (func_8003526C(actor_index, 0x8400, 0, 0, 0x67) >= 0) {
            gActors[actor_index].state = 2;
            gActors[actor_index].flags = 2;
        }
    }
}

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

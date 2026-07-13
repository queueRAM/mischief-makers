#define FUNC_8007CFE0_EXT_ARGS , u16 arg6
#define Actor_Initialize_RET void
#include "common.h"
#include "7D8E0.h"

extern u16 D_800D9A54[];

extern u8 D_800E0F00[];
extern s16 D_800E0F08[]; // x,y pairs used in func_8007D384
extern u16* D_800E0F88[];

void func_8007CCE0(u32 val) {
    u16 count;
    u32 tens_place;

    if (val > 99999999) {
        val = 99999999;
    }
    tens_place = 10000000;
    for (count = 0; count < 8; ) {
        D_800E0F00[count++] = val / tens_place;
        val %= tens_place;
        tens_place /= 10;
    }
}

void func_8007CD68(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, s32 arg6) {
    gActors[actor_index].actorType = 0x29;
    Actor_Initialize(actor_index);
    gActors[actor_index].flags = ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE;
    gActors[actor_index].posX.whole = pos_x;
    gActors[actor_index].posY.whole = pos_y;
    gActors[actor_index].var_150 = arg4;
    gActors[actor_index].var_154 = arg1;
    gActors[actor_index].var_15C = arg6;
    gActors[actor_index].unk_14C = arg5;
}

// TODO: fix return with callers
s32 func_8007CE24(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4) {
    gActors[actor_index].actorType = 0x28;
    Actor_Initialize(actor_index);
    gActors[actor_index].flags |= ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE;
    gActors[actor_index].posX.whole = pos_x;
    gActors[actor_index].posY.whole = pos_y;
    gActors[actor_index].var_150 = arg4;
    gActors[actor_index].var_154 = arg1;
}

void func_8007CEB8(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8) {
    gActors[actor_index].actorType = 0x27;
    Actor_Initialize(actor_index);
    gActors[actor_index].flags |= ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE;
    gActors[actor_index].posX.whole = pos_x;
    gActors[actor_index].posY.whole = pos_y;
    gActors[actor_index].var_154 = arg1;
    gActors[actor_index].unk_11C = arg7;
    gActors[actor_index].unk_120 = arg6;
    gActors[actor_index].unk_124 = arg4;
    gActors[actor_index].unk_128 = arg5;
    gActors[actor_index].unk_16C = arg8 & 1;
}

void func_8007CFE0(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, u16 arg6) {
    gActors[actor_index].actorType = 0x26;
    Actor_Initialize(actor_index);
    gActors[actor_index].flags |= ACTOR_FLAG_FREEZE_POS | ACTOR_FLAG_ACTIVE;
    gActors[actor_index].posX.whole = pos_x;
    gActors[actor_index].posY.whole = pos_y;
    gActors[actor_index].var_110 = arg1;
    gActors[actor_index].unk_114 = arg5;
    gActors[actor_index].unk_118 = arg4;
    gActors[actor_index].unk_16C = arg6 & 1;
}

// spawns a text box over an actor for a few moments.
// ...in the japanese version.
// @param index index of "speaking" actor
// @param text "string" to display
// @param off_x x-position offset of text.
// @param off_y y-position offset of text.
// @param arg4 unused(?)
// @returns index of actor, 0 if failed or English version.
u16 SpawnTextBubble(u16 index, u16* text, s16 off_x, s16 off_y, s32 arg4) {
    return 0;
}

u16 func_8007D0F4(u16 actor_index, u16* text, s16 pos_x, s16 pos_y, u16 arg4) {
    u16 free_actor;

    free_actor = Actor_RangeFindInactive(0x8C, 0x90);
    if (free_actor != 0) {
        gActors[free_actor].actorType = 0x35;
        Actor_Initialize(free_actor);
        gActors[free_actor].graphicFlags = 0x901;
        gActors[free_actor].flags = 2;
        gActors[free_actor].colorA = 0;
        gActors[free_actor].var_150 = (s32)text;
        gActors[free_actor].var_154 = actor_index;
        gActors[free_actor].unk_114 = (f32) (arg4 & 0x7FFF);
        gActors[free_actor].unk_118 = (f32) (arg4 & 0x8000);
        gActors[free_actor].var_158 = pos_x;
        gActors[free_actor].var_15C = pos_y;
        gActors[free_actor].posX.whole = pos_x;
        gActors[free_actor].posY.whole = pos_y;
        gActors[free_actor].posZ.raw = 0x800000;
        gActors[free_actor].scaleX = 0.0f;
        gActors[free_actor].scaleY = 0.0f;
    }
    return free_actor;
}

u16 func_8007D1E8(u16 actor_index, u16* text, s16 off_x, s16 off_y, u16 arg4, u16* palette) {
    u16 actor;

    actor = SpawnTextBubble(actor_index, text, off_x, off_y, (s32) arg4);
    if (actor != 0) {
        gActors[actor].graphicFlags |= ACTOR_GFLAG_PALETTE;
        gActors[actor].graphicFlags &= ~ACTOR_GFLAG_UNK8;
        if (palette != 0) {
            gActors[actor].palette_18C = palette;
        }
        else {
            gActors[actor].palette_18C = D_800D9AE4;
        }
    }
    return actor;
}

u16 func_8007D290(u16 actor_index) {
    u16 free_actor;

    free_actor = Actor_RangeFindInactive_90ToC0();
    if (free_actor != 0) {
        gActors[free_actor].actorType = 0x34;
        Actor_Initialize(free_actor);
        if (gActors[actor_index].unk_18C != 0) {
            gActors[free_actor].graphicFlags = ACTOR_GFLAG_UNK11 | ACTOR_GFLAG_PALETTE;
        }
        else {
            gActors[free_actor].graphicFlags = ACTOR_GFLAG_UNK11;
        }
        gActors[free_actor].flags = ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[free_actor].posZ.raw = gActors[actor_index].posZ.raw + 1;
        gActors[free_actor].unk_18C = gActors[actor_index].unk_18C;
        if (free_actor < actor_index) {
            gActors[free_actor].unk_148 = 0.0f;
        }
        else {
            gActors[free_actor].unk_148 = 1.0f;
        }
    }
    return free_actor;
}

void func_8007D384(u16 arg0, u16 xy_index) {
    u16 free_actor;
    u16 index;

    free_actor = Actor_RangeFindInactive_90ToC0();
    if (free_actor != 0) {
        index = xy_index & 0x7FFF;
        func_8007CFE0(free_actor, arg0, D_800E0F08[index + 4], D_800E0F08[index + 5], 0, 0xF0, 1);
    }
}

void func_8007D3EC(u16 actor_index) {
    if (gActors[actor_index].colorA > 0x80) {
        gActors[actor_index].colorA = 0x90;
    }
}

void func_8007D438(u16 actor_index, u16 alpha) {
    gActors[actor_index].colorA = gActors[actor_index].scaleY * alpha;
}

void func_8007D520(u16 actor_index) {
    gActors[actor_index].flags = 0;
}

void func_8007D554(u16 actor_index) {
    u16* vals;
    u16 free_actor;
    u16 x;
    s16 y;
    u16 graphic_flags;
    u16 var_s5;
    u16 command;

    if (gActors[actor_index].state == 0) {
        gActors[actor_index].state++;
        gActors[actor_index].colorA = 0;
        gActors[actor_index].scaleY = 0.0f;
    }
    graphic_flags = 0;
    vals = D_800E0F88[(u16)gActors[actor_index].var_110];
    y = 0;
    x = 0;
    while (vals[0] != 0x8FFF) {
        for (; vals[0] >= 0x8001; vals++) {
            command = vals[0];
            switch (command & 0x7F00) {
            case 0x100:
                var_s5 = command & 0xFF;
                graphic_flags = ACTOR_GFLAG_PALETTE;
                break;
            case 0x200:
                gActors[actor_index].var_158 = command & 0xFF;
                break;
            case 0x4000:
                x += command & 0xFF;
                break;
            case 0x400:
                x = 0;
                y -= 0x13;
                break;
            }
        }
        
        free_actor = func_8007D290(actor_index);
        if (free_actor != 0) {
            gActors[free_actor].graphicFlags |= graphic_flags;
            gActors[free_actor].palette_18C = &D_800D9A54[var_s5];
            gActors[free_actor].graphicIndex = (vals[0] * 2) + 0x2D2;
            gActors[free_actor].posX.whole = gActors[actor_index].posX.whole + (gActors[actor_index].scaleX * x);
            gActors[free_actor].posY.whole = gActors[actor_index].posY.whole + (gActors[actor_index].scaleY * y);
            x += gActors[actor_index].var_158;
            vals++;
        }
        else {
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007D880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007DB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007DF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007EE14.s")

u16 func_8007EE70(u32 graphic_flags, s32 pos_x, s32 pos_y, s32 pos_z, f32 scale_x, f32 scale_y) {
    u16 actor_index;

    actor_index = Actor_RangeFindInactive_90ToC0();
    if (actor_index != 0) {
        gActors[actor_index].actorType = 0x34;
        Actor_Initialize(actor_index);
        gActors[actor_index].graphicFlags = graphic_flags & 0xDFFF;
        gActors[actor_index].flags = ACTOR_FLAG_ACTIVE | ACTOR_FLAG_DRAW;
        gActors[actor_index].graphicIndex = 0x2D0;
        gActors[actor_index].posX.raw = pos_x;
        gActors[actor_index].posY.raw = pos_y;
        gActors[actor_index].posZ.raw = pos_z;
        gActors[actor_index].scaleX = scale_x;
        gActors[actor_index].scaleY = scale_y;
        gActors[actor_index].colorA = 0xC0;
        if (graphic_flags & ACTOR_GFLAG_3DOBJ) {
            gActors[actor_index].unk_148 = 1.0f;
        }
        else {
            gActors[actor_index].unk_148 = 0.0f;
        }
    }
    return actor_index;
}

void func_8007EF58(u16* vals, u32 graphic_flags, s32 pos_x, s32 pos_y, s32 pos_z, u16 alpha, f32 scale_x, f32 scale_y) {
    f32 scale_numerator;
    f32 scale_denominator;
    u16 actor_index;

    if (graphic_flags & ACTOR_GFLAG_UNK8) {
        scale_denominator = 16.0f;
    }
    else {
        scale_denominator = 8.0f;
    }

    scale_numerator = 0.0f;
    for (; vals[0] != 0x8FFF; vals++) {
        if (vals[0] & 0x8000) {
            scale_numerator += scale_denominator / 2.5;
        }
        else {
            scale_numerator += scale_denominator;
        }
    }
    scale_x = (scale_numerator / (scale_denominator * 0.9)) * scale_x;
    actor_index = func_8007EE70(graphic_flags, pos_x, pos_y, pos_z, scale_x, scale_y);
    if (actor_index != 0) {
        gActors[actor_index].colorA = alpha;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7D8E0/func_8007F560.s")

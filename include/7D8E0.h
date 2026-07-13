#ifndef FILE_7D8E0_H
#define FILE_7D8E0_H

#include <PR/ultratypes.h>

// decomposes each decimal digit of u32 into u8 array
void func_8007CCE0(u32 val);

void func_8007CD68(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, s32 arg6);
s32 func_8007CE24(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4);
void func_8007CEB8(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8);

// warning: has 7th arg - is used in func, but isn't loaded in many calls.
#ifndef FUNC_8007CFE0_EXT_ARGS
#define FUNC_8007CFE0_EXT_ARGS
#endif
void func_8007CFE0(u16 actor_index, u16 arg1, s16 pos_x, s16 pos_y, u16 arg4, u16 arg5 FUNC_8007CFE0_EXT_ARGS);

#endif

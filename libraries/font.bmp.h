#ifndef __FONT_BMP_H
#define __FONT_BMP_H

#include "basic.h"
#include "drivers.h"

void DrawChar(u8, u8*, u32, u32, u32);
void DrawStrn(u8, u8*, u32, u32, u32);

static u8 __fontbmp_A[] = {
    0b00011000,
    0b00111100,
    0b01100110,
    0b11000011,
    0b11111111,
    0b11000011,
    0b11000011,
    0b11000011,
};

u8 *FontBmps[] = {
    ['A'] = __fontbmp_A,
};

void DrawChar(u8 color, u8* _char, u32 x, u32 y, u32 size) {
    for (u32 i = 0; i < 8; i++) {
        for (u32 j = 0;j < 8;j++) {
            if (_char[i] >> (7 - j) & 1) {
                DrawRect(color, x + j * size, y + i * size, size, size);
            }
        }
    }
}

void DrawStrn(u8 color, u8 * strn, u32 x, u32 y, u32 font_size) {
    u64 charptr = 0;

    while (strn[charptr] != '\0') {
        DrawChar(color, FontBmps[strn[charptr++]], x + charptr * 8 * font_size, y, font_size);
    }
}

#endif
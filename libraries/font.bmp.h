#ifndef __FONT_BMP_H
#define __FONT_BMP_H

#include "basic.h"
#include "drivers.h"

void DrawChar(u8, u8, u32, u32, u32);
void DrawStrn(u8, u8*, u32, u32, u32, f64);

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

static u8 __fontbmp_B[] = {
    0b11111000,
    0b11001100,
    0b11001000,
    0b11111000,
    0b11001110,
    0b11000110,
    0b11000110,
    0b11111100,
};

static u8 __fontbmp_C[] = {
    0b00111110,
    0b01110000,
    0b11100000,
    0b11000000,
    0b11000000,
    0b11100000,
    0b01110000,
    0b00111110,
};

static u8 __fontbmp_D[] = {
    0b11111000,
    0b11111100,
    0b11000110,
    0b11000010,
    0b11000010,
    0b11000110,
    0b11111100,
    0b11111000,
};

static u8 __fontbmp_E[] = {
    0b11111110,
    0b11000000,
    0b11000000,
    0b11111110,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11111110,
};

static u8 __fontbmp_F[] = {
    0b11111110,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11111110,
    0b11000000,
    0b11000000,
    0b11000000,
};

static u8 __fontbmp_G[] = {
    0b01111110,
    0b11100111,
    0b11000000,
    0b11000000,
    0b11001111,
    0b11000011,
    0b11100011,
    0b00111110,
};

static u8 __fontbmp_H[] = {
    0b11000010,
    0b11000011,
    0b11000011,
    0b11111111,
    0b11111111,
    0b11000011,
    0b11000011,
    0b10000011,
};

static u8 __fontbmp_I[] = {
    0b11111111,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b11111111,
};

static u8 __fontbmp_J[] = {
    0b11111111,
    0b11000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b11000011,
    0b11000011,
    0b01111110,
};

static u8 __fontbmp_K[] = {
    0b11000011,
    0b11000110,
    0b11001100,
    0b11011000,
    0b11110000,
    0b11011000,
    0b11001100,
    0b11000111,
};

static u8 __fontbmp_L[] = {
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11111111,
};

static u8 __fontbmp_M[] = {
    0b11000011,
    0b11100111,
    0b11011011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
};

static u8 __fontbmp_N[] = {
    0b11000011,
    0b11100011,
    0b11010011,
    0b11001011,
    0b11000111,
    0b11000011,
    0b11000011,
    0b11000011,
};

static u8 __fontbmp_O[] = {
    0b01111110,
    0b11100111,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11100111,
    0b01111110,
};

static u8 __fontbmp_P[] = {
    0b11111100,
    0b11000110,
    0b11000011,
    0b11000011,
    0b11111110,
    0b11000000,
    0b11000000,
    0b11000000,
};

static u8 __fontbmp_Q[] = {
    0b01111110,
    0b11100111,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11001101,
    0b11100110,
    0b01111011,
};

static u8 __fontbmp_R[] = {
    0b11111100,
    0b11000110,
    0b11000011,
    0b11000011,
    0b11111110,
    0b11011000,
    0b11001100,
    0b11000111,
};

static u8 __fontbmp_S[] = {
    0b01111111,
    0b11000000,
    0b11000000,
    0b01111110,
    0b00000011,
    0b00000011,
    0b00000110,
    0b11111100,
};

static u8 __fontbmp_T[] = {
    0b11111111,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
};

static u8 __fontbmp_U[] = {
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b00111100,
};

static u8 __fontbmp_V[] = {
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b01100011,
    0b00110110,
    0b00011100,
};

static u8 __fontbmp_W[] = {
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11011011,
    0b11100111,
    0b11000011,
};

static u8 __fontbmp_X[] = {
    0b10000001,
    0b11000011,
    0b01100110,
    0b00111100,
    0b00011000,
    0b00111100,
    0b01100110,
    0b11000011,
};

static u8 __fontbmp_Y[] = {
    0b11000011,
    0b01100110,
    0b00111100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
};

static u8 __fontbmp_Z[] = {
    0b11111111,
    0b00000011,
    0b00000110,
    0b00001100,
    0b00011000,
    0b00110000,
    0b01100000,
    0b11111111,
};

static u8 __fontbmp_space[] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
};

static u8 __fontbmp_$[] = {
    0b01111111,
    0b11011000,
    0b11011000,
    0b01111110,
    0b00011011,
    0b00011011,
    0b00011110,
    0b11111100,
};

u8 *FontBmps[] = {
    ['$'] = __fontbmp_$,
    [' '] = __fontbmp_space,
    ['A'] = __fontbmp_A,
    ['B'] = __fontbmp_B,
    ['C'] = __fontbmp_C,
    ['D'] = __fontbmp_D,
    ['E'] = __fontbmp_E,
    ['F'] = __fontbmp_F,
    ['G'] = __fontbmp_G,
    ['H'] = __fontbmp_H,
    ['I'] = __fontbmp_I,
    ['J'] = __fontbmp_J,
    ['K'] = __fontbmp_K,
    ['L'] = __fontbmp_L,
    ['M'] = __fontbmp_M,
    ['N'] = __fontbmp_N,
    ['O'] = __fontbmp_O,
    ['P'] = __fontbmp_P,
    ['Q'] = __fontbmp_Q,
    ['R'] = __fontbmp_R,
    ['S'] = __fontbmp_S,
    ['T'] = __fontbmp_T,
    ['U'] = __fontbmp_U,
    ['V'] = __fontbmp_V,
    ['W'] = __fontbmp_W,
    ['X'] = __fontbmp_X,
    ['Y'] = __fontbmp_Y,
    ['Z'] = __fontbmp_Z,
};

void DrawChar(u8 color, u8 _char, u32 x, u32 y, u32 size) {
    u8* bitmap = FontBmps[_char];

    if (bitmap != NULL) {
        for (u32 i = 0; i < 8; i++) {
            for (u32 j = 0;j < 8;j++) {
                if (FontBmps[_char][i] >> (7 - j) & 1) {
                    u32 xpos = x + j * size;
                    if (!(xpos > SCR_WIDTH))
                        DrawRect(color, xpos, y + i * size, size, size);
                }
            }
        }
    }
}

void DrawStrn(u8 color, u8 * strn, u32 x, u32 y, u32 font_size, f64 font_spacing) {
    u64 charptr = 0;

    while (strn[charptr] != '\0') {
        u32 xpos = (u32)(x + charptr * 8 * font_size * font_spacing);
        DrawChar(color, strn[charptr++], xpos, 2 + y, font_size);
    }
}

#endif
#include <font.bmp.h>

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
    ['1'] = __fontbmp_1,
    ['2'] = __fontbmp_2,
    ['3'] = __fontbmp_3,
    ['4'] = __fontbmp_4,
    ['5'] = __fontbmp_5,
    ['6'] = __fontbmp_6,
    ['7'] = __fontbmp_7,
    ['8'] = __fontbmp_8,
    ['9'] = __fontbmp_9,
    ['0'] = __fontbmp_0,
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
    u64 xptr = 0;
    u64 yptr = 0;

    while (strn[charptr] != '\0') {
        u32 xpos = (u32)(x + xptr * 8 * font_size * font_spacing);
        if (strn[charptr] == '\n') {
            ++yptr;
            xptr = -1;
        }

        DrawChar(color, strn[charptr++], xpos, 2 + y + yptr * 8 * font_size * font_spacing, font_size);
        ++xptr;
    }
}
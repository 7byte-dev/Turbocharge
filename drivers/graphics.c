#include "graphics.h"
// #include <basic.h>

extern void DrawPixel(u8 color, u32 x, u32 y) {
    u8 * vga = (u8*)0xA0000;
    vga[x + 320 * y] = color;
}

extern void DrawRect(u8 color, u32 x, u32 y, u32 width, u32 height) {
    for (u32 i = 0;i <= height;++i) {
        for (u32 j = 0;j <= width;++j) {
            DrawPixel(color, x + j, y + i);
        }
    }
}

extern void DrawTexture(u8** texture, u32 x, u32 y, u32 pxw, u32 pxh) {
    u8* row;

    u32 i = 0, j = 0;

    while ((row = texture[i]) != NULL) {
        j = 0;

        while (row[j] != NULL) {
            if (row[j] != 0xFF) {
                DrawRect(row[j], x + j * pxw, y + i * pxh, pxw, pxh);
            }
            ++j;
        }

        ++i;
    }
}
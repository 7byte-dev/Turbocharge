#ifndef __KTEXT_H
#define __KTEXT_H

#include <basic.h>

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

extern void DrawPixel(u8,u32,u32);
extern void DrawRect(u8,u32,u32,u32,u32);
extern void DrawTexture(u8**,u32,u32,u32,u32);

#endif
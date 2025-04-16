#ifndef __KDRIVERS_H
#define __KDRIVERS_H

#include "basic.h"

/* io.c */
extern inline void outb(u16, u8);
extern inline void outw(u16, u16);
extern inline void outl(u16, u32);
extern inline u8 inb(u16);
extern inline u16 inw(u16);
extern inline u32 inl(u16);

/* keyboard.c */
extern u8 ReadKBInput();
extern char TranslateFromScancode(u8);
extern void ClearKBBuffer();

/* graphics.c */
#define SCR_WIDTH 320
#define SCR_HEIGHT 200

extern void DrawPixel(u8,u32,u32);
extern void DrawRect(u8,u32,u32,u32,u32);
extern void DrawTexture(u8**,u32,u32,u32,u32);

#endif
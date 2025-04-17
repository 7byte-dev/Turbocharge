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

#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_ENTER 0x1C
#define KEY_SPACE 0x39

/* graphics.c */
#define SCR_WIDTH 320
#define SCR_HEIGHT 200

extern void DrawPixel(u8,u32,u32);
extern void DrawRect(u8,u32,u32,u32,u32);
extern void DrawTexture(u8**,u32,u32,u32,u32);

#endif
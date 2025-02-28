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

#endif
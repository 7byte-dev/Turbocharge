#ifndef __KTEXT_H
#define __KTEXT_H

#include "basic.h"

#define CGA_WIDTH 80
#define CGA_HEIGHT 25
#define CGA_ADDR (u16*)0xb8000

/* Data */


/* Functions */
void putc(u8, char, u8, u8);
void puts(u8, char*);

void putc(u8 attrs, char _char, u8 x, u8 y) {
    *(u32*)(CGA_ADDR + x + y * CGA_WIDTH) = (attrs << 8) | _char;
}


void puts(u8 attrs, char * str) {
    u64 xpos = 0;
    while (str[xpos]) {
        putc(attrs, str[xpos], xpos, 0);
        xpos++;
    }
}

#endif
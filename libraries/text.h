#ifndef __KTEXT_H
#define __KTEXT_H

#include "basic.h"

#define CGA_WIDTH 80
#define CGA_HEIGHT 25
#define CGA_ADDR (u16*)0xb8000

/* Data */
static u16* cga_buffer = CGA_ADDR;
static u32 cursor = 0;

/* Functions */
void putc(u8, char);
void puts(u8, char*);

void putc(u8 attrs, char _char) {
    if (_char == '\n') {
        cursor += CGA_WIDTH - (cursor % CGA_WIDTH);
    } else {
        cga_buffer[cursor] = (attrs << 8) | _char;
        cursor++;
    }

    /* scrolling (not implemented yet lol) */
    if (cursor <= (CGA_WIDTH * CGA_HEIGHT)) {
        cursor = 0;
    }
}

void puts(u8 attrs, char * str) {
    while (*str) {
        putc(attrs, *str++);
    }
}

#endif
#ifndef __DRIVER_KEYBOARD_H
#define __DRIVER_KEYBOARD_H

#include <basic.h>

typedef struct {
    u8 make;
    char translation;
} KBScancode;

extern u8 ReadKBInput();
extern char TranslateFromScancode(u8);
extern void ClearKBBuffer();

#endif
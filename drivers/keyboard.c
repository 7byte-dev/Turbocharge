// Keyboard Driver
#include <drivers.h>
#include <basic.h>

typedef struct {
    u8 make;
    char translation;
} KBScancode;

static KBScancode CharacterCodes[] = {   // scancode defenitions for english alphabet
    // set 1 make
    {0x1E, 'A'},
    {0x30, 'B'},
    {0x2E, 'C'},
    {0x20, 'D'},
    {0x12, 'E'},
    {0x21, 'F'},
    {0x22, 'G'},
    {0x23, 'H'},
    {0x17, 'I'},
    {0x24, 'J'},
    {0x25, 'K'},
    {0x26, 'L'},
    {0x32, 'M'},
    {0x31, 'N'},
    {0x18, 'O'},
    {0x19, 'P'},
    {0x10, 'Q'},
    {0x13, 'R'},
    {0x1F, 'S'},
    {0x14, 'T'},
    {0x16, 'U'},
    {0x2F, 'V'},
    {0x11, 'W'},
    {0x2D, 'X'},
    {0x15, 'Y'},
    {0x2C, 'Z'},
    {0x02, '1'},
    {0x03, '2'},
    {0x04, '3'},
    {0x05, '4'},
    {0x06, '5'},
    {0x07, '6'},
    {0x08, '7'},
    {0x09, '8'},
    {0x0A, '9'}
};

extern u8 ReadKBInput() {
    if (inb(0x64) & 0x01) {
        return inb(0x60);
    } else {
        return -1;
    }
}

extern char TranslateFromScancode(u8 scancode) {
    for (int i=0;i <= 34;++i) {
        if (CharacterCodes[i].make == scancode) {
            return CharacterCodes[i].translation;
        }
    }

    return scancode;
}

extern void ClearKBBuffer() {
    while (inb(0x64) & 0x01) {
        inb(0x60);
    }
}
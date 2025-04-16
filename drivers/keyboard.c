// Keyboard Driver
#include "keyboard.h"
#include <basic.h>

enum KeyboardKey {
    KEY_A = 0x1E,
    KEY_B = 0x30,
    KEY_C = 0x2E,
    KEY_D = 0x20,
    KEY_E = 0x12,
    KEY_F = 0x21,
    KEY_G = 0x22,
    KEY_H = 0x23,
    KEY_I = 0x17,
    KEY_J = 0x24,
    KEY_K = 0x25,
    KEY_L = 0x26,
    KEY_M = 0x32,
    KEY_N = 0x31,
    KEY_O = 0x18,
    KEY_P = 0x19,
    KEY_Q = 0x10,
    KEY_R = 0x13,
    KEY_S = 0x1F,
    KEY_T = 0x14,
    KEY_U = 0x16,
    KEY_V = 0x2F,
    KEY_W = 0x11,
    KEY_X = 0x2D,
    KEY_Y = 0x15,
    KEY_Z = 0x2C,
    KEY_1 = 0x02,
    KEY_2 = 0x03,
    KEY_3 = 0x04,
    KEY_4 = 0x05,
    KEY_5 = 0x06,
    KEY_6 = 0x07,
    KEY_7 = 0x08,
    KEY_8 = 0x09,
    KEY_9 = 0x0A,
};

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
    {0x0A, '9'},
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
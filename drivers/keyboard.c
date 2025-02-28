// Keyboard Driver
#include <drivers.h>
#include <basic.h>

extern u8 ReadKBInput() {
    while (!inb(0x64) & 1) {;}
    return inb(0x60);
}
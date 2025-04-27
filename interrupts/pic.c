#include "pic.h"
#include <io.h>

void RemapPIC() {
    outb(0x20, 0x11);   // initialize master and slave pic
    outb(0xA0, 0x11);   // for the remap

    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    outb(0x21, 0x04);   // slave is at irq2
    outb(0xA1, 0x02);   // slave id is 2

    outb(0x21, 0x01);
    outb(0xA1, 0x01);   // operate in 8086 mode

    outb(0x21, 0x0);    // clear masks
    outb(0xA1, 0x0);    
}
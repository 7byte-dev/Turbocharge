#include "mouse.h"

void EnableMouse() {
    outb(0x64, 0xA8);   // enable second ps/2 port

    outb(0x64, 0x20);
    u8 status = inb(0x60);
    status |= 0x02;
    outb(0x64, 0x60);
    outb(0x60, status);

    outb(0x64, 0xD4); 
    outb(0x60, 0xF6); 
    inb(0x60);
    outb(0x64, 0xD4);
    outb(0x60, 0xF4);
    inb(0x60); 
}

MouseInput GetMouseInput() {
    MouseInput ret;

    ret.button = inb(0x60);
    ret.xmove = (i8)inb(0x60);
    ret.ymove = (i8)inb(0x60);

    return ret;
}
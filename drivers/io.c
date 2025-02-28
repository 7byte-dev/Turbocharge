// Port input/output

#include <basic.h>
#include "io.h"

extern inline u8 inb(u16 port) {
    u8 value;
    asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

extern inline u16 inw(u16 port) {
    u16 value;
    asm volatile ("inw %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

extern inline u32 inl(u16 port) {
    u32 value;
    asm volatile ("inl %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

extern inline void outb(u16 port, u8 value) {
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

extern inline void outw(u16 port, u16 value) {
    asm volatile ("outw %0, %1" : : "a"(value), "Nd"(port));
}

extern inline void outl(u16 port, u32 value) {
    asm volatile ("outl %0, %1" : : "a"(value), "Nd"(port));
}
#include "idt.h"

void IDTGateSet(u16 n, u32 handler) {
    idt[n] = (IDTEntry){
        .offsetlow = handler & 0xFFFF,
        .offsethigh = (handler >> 16) & 0xFFFF,
        .selector = 0x08,    // kernel code seg
        .z = 0,
        .typeattrs = 0x8E,
    };
}

void LoadIDT() {
    idt_reg.base = (u32)&idt;
    idt_reg.limit = sizeof(idt) - 1;
    idt_flush((u32)&idt_reg);
}
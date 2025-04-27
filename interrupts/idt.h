#ifndef __INTERRUPTS_IDTH
#define __INTERRUPTS_IDTH

#include <basic.h>

typedef struct __interrupts_idth_idtentry {
    u16 offsetlow;
    u16 selector;
    u8 z;
    u8 typeattrs;
    u16 offsethigh;
} __attribute__((packed)) IDTEntry;

typedef struct __interrupts_idth_idtreg {
    u16 limit;
    u32 base;
} __attribute__((packed)) IDTReg;

__attribute__((aligned(0x10)))
IDTEntry idt[256];
IDTReg idt_reg;

void IDTGateSet(u16 n, u32 handler);
void LoadIDT();
void idt_flush(u32);

#endif
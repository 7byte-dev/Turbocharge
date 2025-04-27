#include "isr.h"
#include <drivers.h>
#include <font.bmp.h>
#include <basic.h>

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr44();

void InstallISRs() {
    IDTGateSet(0, (u32)isr0);
    IDTGateSet(1, (u32)isr1);
    IDTGateSet(2, (u32)isr2);
    IDTGateSet(3, (u32)isr3);
    IDTGateSet(4, (u32)isr4);
    IDTGateSet(5, (u32)isr5);
    IDTGateSet(6, (u32)isr6);
    IDTGateSet(7, (u32)isr7);
    IDTGateSet(8, (u32)isr8);
    IDTGateSet(9, (u32)isr9);
    IDTGateSet(10, (u32)isr10);
    IDTGateSet(11, (u32)isr11);
    IDTGateSet(12, (u32)isr12);
    IDTGateSet(13, (u32)isr13);
    IDTGateSet(14, (u32)isr14);
    IDTGateSet(15, (u32)isr15);
    IDTGateSet(16, (u32)isr16);
    IDTGateSet(17, (u32)isr17);
    IDTGateSet(18, (u32)isr18);
    IDTGateSet(19, (u32)isr19);
    IDTGateSet(20, (u32)isr20);
    IDTGateSet(21, (u32)isr21);
    IDTGateSet(22, (u32)isr22);
    IDTGateSet(23, (u32)isr23);
    IDTGateSet(24, (u32)isr24);
    IDTGateSet(25, (u32)isr25);
    IDTGateSet(26, (u32)isr26);
    IDTGateSet(27, (u32)isr27);
    IDTGateSet(28, (u32)isr28);
    IDTGateSet(29, (u32)isr29);
    IDTGateSet(30, (u32)isr30);
    IDTGateSet(31, (u32)isr31);
    IDTGateSet(32, (u32)isr32);
    IDTGateSet(44, (u32)isr44);
}

static u16 mouse_x = 100;
static u16 mouse_y = 100;

void isr_handler(u32 int_num, u32 err_code) {
    //DrawRect(0x1F, 0, 0, 100, 100);
    DrawStrn(0x1F, u32tostr(int_num), 0, 0, 1, 1);
}

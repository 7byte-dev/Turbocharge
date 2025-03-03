#ifndef __KINTERRUPTS_IDT_H
#define __KINTERRUPTS_IDT_H

#include <basic.h>
#include <text.h>

// IDT Entry
typedef struct {
  u16 isr_low;
  u16 kernel_cs;
  u8 reserved;
  u8 attributes;
  u16 isr_high;
} __attribute__((packed)) IDTEntry;

// IDTR
typedef struct {
  u16 limit;
  u32 base;
} __attribute__((packed)) IDTR;

// Interrupt frame to pass to ISRs
typedef struct {
  u32 eip;
  u32 cs;
  u32 eflags;
  u32 sp;
  u32 ss;
} __attribute__((packed)) InterruptFrame;

// Default excp handler w/o error code
__attribute__((interrupt)) void
DefaultExceptionHandler(InterruptFrame *int_frame) {
  asm volatile("mov [0xb8000], 'E'");
}

#endif
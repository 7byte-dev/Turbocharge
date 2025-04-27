#ifndef __INTERRUPTS_ISRH
#define __INTERRUPTS_ISRH

#include <basic.h>

void isr_handler(u32 int_num, u32 err_code);

void InstallISRs();

#endif
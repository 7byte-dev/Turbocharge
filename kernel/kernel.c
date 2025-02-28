#include "drivers.h"
#include <text.h>
#include <basic.h>

extern void main(){
    while (1) {
        u8 kbIn = ReadKBInput();
        putc(0xF, kbIn, 40, 8);
    }

    return;
}

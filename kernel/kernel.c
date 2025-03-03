#include "drivers.h"
#include <text.h>
#include <basic.h>

extern void main(){
    while (1) {
        u8 kbIn = TranslateFromScancode(ReadKBInput());
        putc(0xC, kbIn, 40, 8);
    }

    return;
}

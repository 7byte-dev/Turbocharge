#include "drivers.h"
#include <text.h>
#include <basic.h>
#include <typing.h>

extern void main(){
    ClearKBBuffer();
    while (1) {
        ListenForKeyboard(1, 1);
    }

    return;
}

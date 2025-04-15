#ifndef __KTYPING_H
#define __KTYPING_H

#include <basic.h>
#include <drivers.h>
#include <text.h>

static u64 __ktyping_cursor_pos = 0;

u8 ListenForKeyboard(u8, u8);

u8 ListenForKeyboard(u8 do_output, u8 progress_cursor) {
    u8 _key = -1;

    while (_key == -1 || (_key < 0x10) || (_key > 0x32)) {
        _key = ReadKBInput();
    }

    // puts(0xF, "Key Pressed!");

    if (do_output)
    {
        putc(0xF, TranslateFromScancode(_key), __ktyping_cursor_pos, 0);
    }

    if (progress_cursor) {
        __ktyping_cursor_pos++;
    }
    
    return _key;
}

#endif
#include <drivers.h>
#include <font.bmp.h>

extern void main(){
    u8 key = -1;
    u8 cursorx = 0;
    u8 cursory = 0;
    u8 * textbuff = kmalloc();
    u8 * textbuff_idx = textbuff;
    
    while (key != KEY_ENTER) {
        do {
            key = ReadKBInput();

            if (cursorx > 33) {
                ++cursory;
                cursorx = 0;
            }
            if (key & 0x80) continue;
            if (key == 0x0E) {
                // handle backspace
                DrawRect(0x10, (u32)(--cursorx * 8 * 1.2), 0, 8, 8);
                *textbuff_idx = '\0';
                --textbuff_idx;
                continue;
            }

            *textbuff_idx = TranslateFromScancode(key);
            DrawChar(0x1F, *textbuff_idx++, (u32)(cursorx++ * 8 * 1.2), cursory * 8, 1);
        } while (key == -1);
    }
    *textbuff_idx = '\0';
    
    u8 * command = kmalloc();
    u8 * args = kmalloc();
    u16 texcursor = 0;

    if (command == NULL || args == NULL || textbuff == NULL) {
        DrawStrn(0x0D, "$FAILED TO ALLOCATE MEM$", 0, 0, 1, 1.2);
    }

    while (textbuff[texcursor] != ' ' && textbuff[texcursor]) texcursor++;
    textbuff[texcursor] = '\0';
    strcpy(command, textbuff);
    strcpy(args, textbuff + (texcursor + 1));
    kfreemem(textbuff);

    if (streq(command, "ECHO")) {
        DrawStrn(0x4F, args, 0, 10, 1, 1.2);
    } else if (streq(command, "DIR")) {
        DrawStrn(0x4F, "NOTHING HERE HAHAHAHAHA", 0, 10, 1, 1.2);
    } else if (streq(command, "MEMINF")) {
        DrawStrn(0x4F, u32tostr(kmeminf().mmap), 0, 10, 1, 1.2);
    }

    DrawStrn(0x0F, command, 0, 120, 1, 1.2);

    DrawStrn(0x0D, "$KERNEL EXIT SUCCESS$", 0, 100, 1, 1.2);

    return;
}
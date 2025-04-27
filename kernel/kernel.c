#include <drivers.h>
#include <memory.h>
#include <font.bmp.h>

u8 * memslot1 = NULL;

void RunCommand(char * texbuf) {


    u8 * texbufidx = texbuf;
    u8 * comd = (u8*)kmemallocsz(256);
    u8 * args = (u8*)kmemallocsz(512);

    while (*texbufidx != ' ' && *texbufidx++) continue;
    *texbufidx = '\0';
    strcpy(comd, texbuf);
    strcpy(args, ++texbufidx);

    if (streq(comd, "ECHO")) {
        strcpy(texbuf, args);
    } else if (streq(comd, "MEMALLOC"))
    {
        if (memslot1) {
            strcpy(texbuf, "$MEMORY ALLOCATED ALREADY$");
        } else {
            memslot1 = (u8*)kmemallocsz(256);
            strcpy(texbuf, "$ATTEMPTED MEMALLOC FOR MEMSLOT1$");
        }
    } else if (streq(comd, "MEMPUT1")) {
        if (memslot1) {
            strcpy(memslot1, args);
        } else {
            strcpy(texbuf, "$FAILURE$ UNALLOCATED MEMORY$");
        }
    } else if (streq(comd, "ECHO1")) {
        strcpy(texbuf, memslot1);
    }
    

    kmemfreesz(comd, 256);
    kmemfreesz(args, 512);
}

extern void main(){
    EnableMouse();
    
    RemapPIC();
    InstallISRs();
    LoadIDT();
    
    u8 txbuffer[4096];
    
    i8 kbkey = -1;
    u8 lastkey;
    u16 txbuffidx = 0;
    while (1) {
        kbkey = ReadKBInput();
        
        if (kbkey != -1 && kbkey != lastkey) {
            lastkey = kbkey;
            
            u8 chr = TranslateFromScancode(kbkey);
            if (kbkey & 0x80) continue;
            if (kbkey == 0x1C) {
                chr = '\n';
            }
            
            if (kbkey == 0x0E && txbuffidx > 0) {
                txbuffer[--txbuffidx] = '\0';
            } else {
                txbuffer[txbuffidx++] = chr;
                txbuffer[txbuffidx] = '\0';
            }
            
            if (txbuffer[txbuffidx - 1] == '\n') {
                txbuffidx = 0;
                RunCommand(txbuffer);
            }
            
            DrawRect(0xFB, 0, 0, SCR_WIDTH, SCR_HEIGHT);
            DrawStrn(0x1F, txbuffer, 0, 0, 2, 1.2);
        }
    }

    return;
}
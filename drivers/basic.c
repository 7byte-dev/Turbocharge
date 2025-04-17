#include <basic.h>

u64 ceil(f64 n) {
    return ((u64)n < n) ? ((u64)(n + 1)) : ((u64)(n));
}

void * kmalloc() {
    for (u8 i = 0;i < 64;++i) {
        if (~(memmap >> (63 - i)) & 1) {
            memmap |= 1LL << (63 - i);
            return (void*)(i * PAGE_SIZE + OMNIPAGE_START);
        }
    }

    return NULL;
}

void kfreemem(void * page_addr) {
    u8 page_idx = (u8)((u32)page_addr / PAGE_SIZE);

    if ((u32)page_addr % PAGE_SIZE) {
        return;
    }

    if (page_idx >= 64) {
        return;
    }

    memmap &= ~(1ULL << (63 - page_idx));
}

void strcpy(char * dest, char * src) {
    char * sidx = src;
    char * didx = dest;

    while (*sidx) {
        *didx++ = *sidx++;
    }

    *didx = '\0';
}

u8 streq(const char * a, const char * b) {
    while (*a && *b) {
        if (*a != *b) {
            return 0;
        }
        ++a;
        ++b;
    }

    return *a == *b;
}

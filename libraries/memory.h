#ifndef __KMEMORY_H
#define __KMEMORY_H

#include "basic.h"

/* Memory Maps */
#define MMAP_LOC 0x100000
#define SLABS 8192
#define SLAB_SIZE 64

static u64 * __memory_slab_bmps = (u64*)NULL;
static u64 * __memory_current_slab_bmp = (u64*)NULL;
static u64 __memory_current_slab_bmp_idx;

/* Memory Management */
void * kmemalloc();
void kmemfree(void * addr);
void * kmemallocsz(u64 size);
void kmemfreesz(void *addr, u64 size);

void * kmemalloc() {
    if (!__memory_slab_bmps) {
        // initialize
        __memory_slab_bmps = (u64*)0x100000;
        for (u16 i = 0;i < SLABS;++i) {
            __memory_slab_bmps[i] = 0x0;
        }
        __memory_slab_bmps[0] = 0xFFFFFFFFFFFFFFFF;     // kernel's territory
        for (u16 i = 0xA0000 / 512;i < (0xA0000 + 64000) / 512;++i) {
            __memory_slab_bmps[i] = 0xFFFFFFFFFFFFFFFF; // graphics territory
        }

        __memory_current_slab_bmp_idx = 1;
        __memory_current_slab_bmp = &__memory_slab_bmps[1];
    }

    if (*__memory_current_slab_bmp == 0xFFFFFFFFFFFFFFFF) {
        __memory_current_slab_bmp = &__memory_slab_bmps[++__memory_current_slab_bmp_idx];
    }

    for (u8 i = 0;i < 64;++i) {
        if (!(*__memory_current_slab_bmp & (1ULL << (63 - i)))) {
            *__memory_current_slab_bmp |= 1ULL << (63 - i);
            return (void*)(i * 64);
        }
    }

    return NULL;
}

void kmemfreesz(void *addr, u64 size) {
    u32 start_slab = (u32)((u64)addr / 8);
    u32 slabs_to_free = (size + 7) / 8;

    for (u32 i = 0; i < slabs_to_free; ++i) {
        u32 slab = start_slab + i;
        u32 bidx = slab / 64;
        u32 bpos = 63 - (slab % 64);
        __memory_slab_bmps[bidx] &= ~(1ULL << bpos);
    }
}


void * kmemallocsz(u64 size) {
    if (!__memory_slab_bmps) {
        __memory_slab_bmps = (u64*)0x100000;
        for (u32 i = 0; i < SLABS; ++i)
            __memory_slab_bmps[i] = 0;
        __memory_slab_bmps[0] = 0xFFFFFFFFFFFFFFFF;
        for (u32 i = 0xA0000 / 512; i < (0xA0000 + 64000) / 512; ++i)
            __memory_slab_bmps[i] = 0xFFFFFFFFFFFFFFFF;

        __memory_current_slab_bmp_idx = 1;
        __memory_current_slab_bmp = &__memory_slab_bmps[1];
    }

    u32 slabs_needed = (size + 7) / 8;
    u32 current_count = 0;
    u32 start_slab = 0;

    for (u32 slab = 0; slab < SLABS * 64; ++slab) {
        u32 bmp_idx = slab / 64;
        u32 bit_pos = 63 - (slab % 64);

        if (!(__memory_slab_bmps[bmp_idx] & (1ULL << bit_pos))) {
            if (current_count == 0)
                start_slab = slab;
            current_count++;

            if (current_count >= slabs_needed) {
                for (u32 i = 0; i < slabs_needed; ++i) {
                    u32 si = start_slab + i;
                    u32 bidx = si / 64;
                    u32 bpos = 63 - (si % 64);
                    __memory_slab_bmps[bidx] |= (1ULL << bpos);
                }
                return (void*)(start_slab * 8);
            }
        } else {
            current_count = 0;
        }
    }

    return NULL;
}


#endif
#ifndef __KBASIC_H
#define __KBASIC_H

/* Basic Macros */
#define NULL (void*)0
#define U8_MAX 255
#define U16_MAX 65535
#define U32_MAX 4294967295
#define U64_MAX 18446744073709551615

/* Basic Typedefs */
typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned long u32;
typedef signed long i32;
typedef unsigned long long u64;
typedef signed long long i64;
typedef double f64;

/* Basic Math */
u64 ceil(f64);

/* Basic Memory Management */
#define PAGE_SIZE 4096
#define OMNIPAGE_START 0x100000

static u64 memmap = 0;

void* kmalloc();
void kfreemem(void*);

/* Basic String Manipulation */
void strcpy(char*,char*);
u8 streq(const char*,const char*);
u8* u64tostr(u64 num);

#endif
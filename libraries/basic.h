#ifndef __KBASIC_H
#define __KBASIC_H

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

/* Basic Math 
f64 sqrt(u64 n) {
    u64 left = 0;
    u64 right = n;

    while (left <= right)
    {
        f64 mid = (left + right) / 2;
        f64 midSq = mid * mid;

        if (midSq == n) {
            return mid;
        } else if (midSq < n) {
            left = mid + 1;
        } else {
            left = mid - 1;
        }
    }
    
    return right;
}
*/
#endif
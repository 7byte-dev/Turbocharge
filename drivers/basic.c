#include <basic.h>

u64 ceil(f64 n) {
    return ((u64)n < n) ? ((u64)(n + 1)) : ((u64)(n));
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

u8 * u32tostr(u32 num) {
    static u8 str[21];
    u8 idx = 0;
    u32 tmpnum = num;

    if (tmpnum == 0) {
        return "0";
    }

    while (tmpnum > 0) {
        str[idx] = (tmpnum % 10) + '0';
        tmpnum /= 10;
        ++idx;
    }

    for (u8 i = 0;i < idx / 2;++i) {
        u8 tmp = str[i];
        str[i] = str[idx - i - 1];
        str[idx - i - 1] = tmp;
    }

    str[idx] = '\0';

    return str;
}
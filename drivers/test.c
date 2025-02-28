extern void putc(char _char) {
    *(char*)0xb8000 = _char;

    return;
}
extern void Q32Main() {
    *(volatile unsigned short*)0xb8000 = (0xF << 8) | 'B';

    return;
}
extern void Q32Main() {
    for (unsigned char i=0;i <= 10;++i)
        *(unsigned char*)(0xb8000+i) = 'Q';

    return;
}
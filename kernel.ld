ENTRY(Q32Main);

INPUT (
    bin/Q32.o
    bin/kenter.o
);

STARTUP(bin/kenter.o);

OUTPUT_FORMAT(binary);

SECTIONS {
    . = 0x100000;

    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}
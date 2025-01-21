ENTRY(Q32Main)
OUTPUT_FORMAT(binary)

SECTIONS {
    . = 100000;

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
section .text

    [bits 32]
    [extern Q32Main]

    ; finally load kernel!1!!
    call Q32Main
    jmp $            ; hang in case of error
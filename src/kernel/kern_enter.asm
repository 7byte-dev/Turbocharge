section .text

    mov ah, 0xF
    mov al, 'B'
    mov [0xb8000], ax

    [bits 32]
    [extern Q32Main]

    ; finally load kernel!1!!
    call Q32Main
    jmp $            ; hang in case of error
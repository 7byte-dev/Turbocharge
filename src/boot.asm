[org 0x7c00]

CODESEG equ gdt_codeseg - gdt_start
DATASEG equ gdt_dataseg - gdt_start
KERNLOC equ 0x100000

mov [BootDsk], dl

jmp BootloaderMain
; functions
puts:
    ; prints a string
    ;
    ; Arguments -
    ;   si - string buffer address
    push ax
    push bx
    push si

    ; get the interrupt ready
    mov ah, 0xE
    xor bx, bx

    jmp .puts_loop

.puts_loop:
    lodsb

    or al, al   ; str termination (null character) check
    jz .puts_done

    int 0x10    ; print the character
    jmp .puts_loop

.puts_done:
    pop si
    pop bx
    pop ax
    ret

DskRead:
    ; reads from disk using DAP (extended read)
    ;
    ; Arguments -
    ;   ds:si - pointer to start of DAP
    ;   dl - disk #
    ;
    ; Returns -
    ;   ax - # of sectors read from disk, error code on fail
    ;   cf - set if any error occured, clear if no error
    push si     ; pushed for the error msg, because it uses puts to print the fail msg

    mov ah, 0x42
    int 0x13
    jc .dskread_error
    jmp .dskread_done
    ret

.dskread_error:
    mov si, MSG_DskReadFail
    call puts

    jmp .dskread_done

.dskread_done:
    pop si
    ret

halt:
    jmp halt


BootloaderMain:
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov es, ax

    mov bp, 0x7c00
    mov sp, bp

    ; clear display
    mov ax, 0x3
    int 0x10

    mov si, MSG_TCOSBootloader
    call puts

    ; load kernel
    xor ax, ax
    mov ds, ax
    mov si, KernelDAP
    mov dl, [BootDsk]
    call DskRead
   ; jc halt
    
    ; enter protected mode
    cli
    lgdt [gdt_desc]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODESEG:BootloaderPM

gdt_start:
gdt_null: dq 0

gdt_codeseg:
dw 0xFFFF
dw 0
db 0
db 0b10011010
db 0b11001111
db 0

gdt_dataseg:
dw 0xFFFF
dw 0
db 0
db 0b10010010
db 0b11001111
db 0

gdt_end:
gdt_desc:
dw gdt_end - gdt_start - 1
dd gdt_start

[bits 32]
BootloaderPM:
    mov ax, DATASEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov ebp, 0x90000
    mov esp, ebp

    ; debug print A on screen
    mov ah, 0xF
    mov al, 'A'
    mov [0xb8000], ax

    jmp KERNLOC

    ;jmp $

; data
BootDsk: db 0x0
MSG_TCOSBootloader: db "Turbocharge Bootloader v0", 0x0D, 0x0A, 0
MSG_DskReadFail: db "Failed to read from disk!", 0x0D, 0x0A, 0

KernelDAP:
    db 0x10
    db 0
    dw 20
    dd KERNLOC
    dq 1

times 510-($-$$) db 0
dw 0xaa55

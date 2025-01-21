[org 0x7c00]

Q32Loc equ 0x100000

; real mode code
mov [BootDisk], dl

; set up stack
xor ax, ax
mov es, ax
mov ds, ax
mov bp, 0x7c00
mov sp, bp

; text mode
mov ah, 0
mov al, 0x3
int 0x10

; load kernel
mov ah, 0x42
mov dl, [BootDisk]
mov si, Q32DAP
int 0x13

; x86 protected mode code
CODES equ gdt_code - gdt_start
DATAS equ gdt_data - gdt_start

cli
lgdt [gdt_desc]
mov eax, cr0
or eax, 1
mov cr0, eax
jmp CODES:ProtectedModeBoot

jmp $

; data
BootDisk: db 0

Q32DAP:
    db 0x10
    db 0
    dw 20
    dd Q32Loc
    dq 1

gdt_start:
dq 0

gdt_code:
    dw 0xFFFF
    dw 0
    db 0
    db 0b10011010
    db 0b11001111
    db 0

gdt_data:
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

ProtectedModeBoot:
    ; set up segment and stack registers
    mov ax, DATAS
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    mov al, 'A'
    mov ah, 0xF
   ; mov [0xb8000], ax

    jmp Q32Loc

times 510-($-$$) db 0
dw 0xaa55

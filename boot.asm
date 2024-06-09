[BITS 16]
[ORG 0x7C00]

start:
    ; Set video mode 13h (320x200, 256 colors)
    mov ax, 0x0013
    int 0x10

    ; Load the kernel
    mov ax, 0x1000  ; Load address
    mov es, ax
    mov bx, 0
    mov ah, 0x02
    mov al, 1  ; Number of sectors to read
    mov ch, 0
    mov cl, 2
    mov dh, 0
    int 0x13

    ; Jump to kernel
    jmp 0x1000:0

times 510-($-$$) db 0
dw 0xAA55

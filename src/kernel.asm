bits 32
global halt
global print_ok
extern kernel_main

%include "multiboot.inc"

_main:
    call kernel_main
    call halt

print_ok:
    mov dword [0xb8000], 0x2f4b2f4f
halt:
    jmp halt
bits 32
extern halt
extern kernel_main

%include "multiboot.inc"

section .text
jmp _main
; FUNC
halt:
    jmp halt

; MAIN
_main:
    call kernel_main
    ;jmp halt
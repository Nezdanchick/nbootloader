bits 32
extern halt
extern kernel_main

%include "multiboot.inc"

section .text
; ##### FUNC #####

; ##### MAIN #####
_main:
    mov dword [0xb8000], 0x074b074f
    call kernel_main
bits 32
global _start

%include "multiboot.inc"

_Main:  
    mov dword [0xb8000], 0x2f4b2f4f
    hlt
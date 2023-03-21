bits 32
extern move
extern main

%include "multiboot2.inc"

mov   esp, 0x00200000         ;Setup the stack at 2MiB
push  0                       ;Reset EFLAGS
popfd
push  eax                     ;2nd argument is magic number
push  ebx                     ;1st argument multiboot info pointer
add   esp, 8                  ;Cleanup 8 bytes pushed as arguments

call main
mov dword [0xb8000 + 0], eax ;returned from main
hlt
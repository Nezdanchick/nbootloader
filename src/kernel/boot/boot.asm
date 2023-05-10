bits 32
extern main

%include "boot/longmode.inc"
%include "boot/gdt.inc"

%include "boot/multiboot2.inc" ; entry
call gdt
call cpuid
mov esp, 0x02000000 ;Setup the stack at 2MiB
push 0              ;Reset EFLAGS
popfd
push eax            ;2nd argument is magic number
push ebx            ;1st argument multiboot info pointer

;open A20 gate
in al, 0x92
or al, 2
out 0x92, al


xor eax, eax
mov ebx, eax
mov ecx, eax
mov edx, eax

call main
add esp, 8          ;Cleanup 8 bytes pushed as arguments
hlt


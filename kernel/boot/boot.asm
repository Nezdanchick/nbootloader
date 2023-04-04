bits 32
extern main

%include "boot/multiboot2.inc"

mov esp, 0x02000000 ;Setup the stack at 2MiB
push 0              ;Reset EFLAGS
popfd
push eax            ;2nd argument is magic number
push ebx            ;1st argument multiboot info pointer

;open A20 gate
in al, 0x92
or al, 2
out 0x92, al

lgdt [gdtr]

xor eax, eax
mov ebx, eax
mov ecx, eax
mov edx, eax

call main
add esp, 8          ;Cleanup 8 bytes pushed as arguments
hlt

; GDT
gdt:
  db 0x00, 0x00, 0x00, 0x00, 0x00,      0x00,      0x00, 0x00 
  db 0xFF, 0xFF, 0x00, 0x00, 0x00, 10011010b, 11001111b, 0x00
gdt_size  equ $ - gdt

;GDTR data
gdtr:
  dw gdt_size - 1
  dd gdt

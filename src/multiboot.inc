global _start
section .multiboot
align 4

MAGIC equ 0xe85250d6
FLAGS equ 0
LENGTH equ (multiboot_end - multiboot_start)

multiboot_start:
    dd MAGIC                          ;magic number
    dd FLAGS                          ;protected mode code
    dd LENGTH                         ;header length

    ; checksum
    dd 0x100000000 - MAGIC - FLAGS - LENGTH
multiboot_end:
_start:
        xor   eax, eax                ;Clear eax and ebx in the event
        xor   ebx, ebx                ;we are not loaded by GRUB.
        jmp   multiboot_entry         ;Jump over the multiboot header
        align 4                       ;Multiboot header must be 32
                                      ;bits aligned to avoid error 13
multiboot_entry:
        mov   esp, 0x00200000         ;Setup the stack at 2MiB
        push  0                       ;Reset EFLAGS
        popfd

        push  eax                     ;2nd argument is magic number
        push  ebx                     ;1st argument multiboot info pointer
        call  _main                   ;Entry point
        add   esp, 8                  ;Cleanup 8 bytes pushed as arguments
        hlt
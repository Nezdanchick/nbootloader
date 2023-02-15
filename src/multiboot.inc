global _start
section .multiboot
align 4
mb_start:
    dd 0xe85250d6                ; magic number
    dd 0                         ; protected mode code
    dd mb_end - mb_start ; header length

    ; checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (mb_end - mb_start))
mb_end:
_start:
        xor    eax, eax                ;Clear eax and ebx in the event
        xor    ebx, ebx                ;we are not loaded by GRUB.
        jmp    multiboot_entry         ;Jump over the multiboot header
        align  4                       ;Multiboot header must be 32
                                       ;bits aligned to avoid error 13
multiboot_entry:
        mov    esp, 0x00200000       ;Setup the stack
        push   0                       ;Reset EFLAGS
        popf

        push   eax                     ;2nd argument is magic number
        push   ebx                     ;1st argument multiboot info pointer
        call   _main                   ;Call _Main 
        add    esp, 8                  ;Cleanup 8 bytes pushed as arguments

        cli
endloop:
        hlt
        jmp   endloop


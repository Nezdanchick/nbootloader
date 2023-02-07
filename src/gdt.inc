jmp gdt_end
gdt_start:
gdt        dd 0, 0  ; entry 0 is always unused
flatdesc    db 0xff, 0xff, 0, 0, 0, 10010010b, 11001111b, 0
gdt_end:
mov sp, 0x9c00

cli      ; no interrupt
push ds      ; save real mode
lgdt [gdt_start]   ; load gdt register
mov eax, cr0   ; switch to pmode by
or al,1         ; set pmode bit
mov  cr0, eax
mov  bx, 0x08   ; select descriptor 1
mov  ds, bx   ; 8h = 1000b
and al,0xFE     ; back to realmode
mov  cr0, eax   ; by toggling bit again
pop ds      ; get back old segment
sti
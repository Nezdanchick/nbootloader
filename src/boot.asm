;############### SETUP ###############

use32
format binary
org 0x7C00

include 'gdt.inc'
include 'print16.inc'
include 'sound.inc'


;############### CODE ###############

start:
; clear registres
xor ax, ax
mov es, ax
mov ds, ax
mov ss, ax

; print
print_init

print 'Hi!', 'How are you?'
printb MSG1, nl, MSG2, nl

; sound
beep 15000, 20000, 10000, 7000, 5000, 20000, 15000
print 'I added sound!'
; halt
jmp _halt

;############### FUNC ###############

_halt:
  jmp _halt

;############### DATA ###############

MSG1 db 'i''m nice', 0
MSG2 db '//^w^//', 0

;############### BOOT ###############

times 510-($-$$) db 0 ; compile 512 bytes binary
dw 0xAA55 ; 55 aa bytes

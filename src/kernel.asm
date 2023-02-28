bits 32
extern move
extern kernel_main

%include "multiboot2.inc"


;mov dword [0xb8000], 'L'
;mov dword [0xb8001], 07
call kernel_main
hlt
macro beep [args]
{
  mov ax, args
  call speaker_tone
  hlt
  hlt
  call speaker_off
}

jmp next
speaker_tone:
    pusha
    mov cx, ax                      ; Store note value for now

    mov al, 182
    out 43h, al
    mov ax, cx                      ; Set up frequency
    out 42h, al
    mov al, ah
    out 42h, al
    in al, 61h                      ; Switch PC speaker on
    or al, 03h
    out 61h, al
    popa
    ret
speaker_off:
    pusha
    in al, 61h
    and al, 0FCh
    out 61h, al

    popa
    ret
next:
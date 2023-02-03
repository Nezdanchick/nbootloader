use16

macro printb [line]
{
  mov si, line

  local ch_loop
  local done
  ch_loop:
    lodsb
    or al, al
    jz done
    mov ah, 0x0E
    int 0x10
    jmp ch_loop
  done:
}

macro print [line]
{
  local msg
  msg db  line, 0
  printb msg, nl
}

macro print_init
{
  local clear
  ; set videomode
  mov ax, 0x3
  int 10h
  clear db 0, 'OK', 0
  printb  clear
  ; data
  nl db 10, 13, 0
}

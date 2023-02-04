use16

macro printb [line]
{
  mov si, line
  call _print
}

macro print [line]
{
  local msg
  local prnt
  jmp prnt
  msg db line, 10, 13, 0
  prnt:
  printb msg
}

macro print_init
{
  local end_init
  ; set videomode
  mov ax, 3
  int 10h
  jmp end_init

  ; data
  nl db 10, 13, 0
  ; code
  _print:
  ch_loop:
    lodsb
    or al, al
    jz done
    mov ah, 0x0E
    int 0x10
    jmp ch_loop
  done:
  ret
  end_init:
}

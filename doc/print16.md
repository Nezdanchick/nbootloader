# print16.inc
16 bit BIOS print

# print_init
macro print_init
Description:
inits bios print and nl variable (new line)
Usage:
print_init
Features:
nl - new line bytes (0, 10, 13)

# print
macro print [args]
Description:
you can print string to screen.
Usage:
print 'Hello, ', 'World!'
Features:
adds '\n' to the end of every string

# printb
macro printb [args]
Description:
you can print bytes to screen.
Usage:
printb 0x3, 0x3, 0x3
Features:
_print proc wrapper, using si registry

# _print
_print:
Description:
you can print string to screen using si registry
Usage:
hi db 'Hello!', 0
mov si, hi
call _print
Features:
proc use bios calls
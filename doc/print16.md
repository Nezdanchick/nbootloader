# 16 bit BIOS print

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
adds '\n' no the end of every string

# printb
macro printb [args]
Description:
you can print bytes to screen.
Usage:
printb 0x3, 0x3, 0x3
Features:
args stored in si register


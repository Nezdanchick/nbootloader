#include <lib/asm.h>

inline
extern char inb(u16 port)
{
    u8 ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}
inline
extern void outb(u16 port, char byte)
{
    asm volatile ( "outb %0, %1"
                   :
                   : "a"(byte),
                     "Nd"(port) );
}
inline
extern void io_wait() {
    outb (0x80, 0);
}
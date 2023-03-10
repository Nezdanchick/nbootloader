#ifndef ASM_H
#define ASM_H

#include <stdint.h>
static inline
char inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}
static inline
void outb(uint16_t port, char byte)
{
    asm volatile ( "outb %0, %1"
                   :
                   : "a"(byte),
                     "Nd"(port) );
}
static inline
void io_wait(void) {
    outb (0x80, 0);
}

#endif
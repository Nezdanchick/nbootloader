#pragma once
#include <stdint.h>

extern char inb(u16 port);
extern void outb(u16 port, char byte);
extern void io_wait();
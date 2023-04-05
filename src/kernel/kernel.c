#include <stdio.h>
#include <io/serial.h>
#include <lib/string.h>
#include <video/textmode.h>

extern void init() {
    char* string = "Hello, World!";
    set_pos(40 - strlen(string) / 2, 12);
    set_color(0x02);
    puts(string);
}
extern int loop() {
    return 0xdead;
}
#include <boot/multiboot2.h>
#include <video/textmode.h>
#include <lib/cursor.h>
#include <stdio.h>

extern void init();
extern int  loop();

void main(__attribute__((unused)) struct multiboot_t* multiboot)
{
    cls();

    init();

    int exit_code = 0;
    while (exit_code == 0) {
        exit_code = loop();
    }

    set_color(0x04);
    cursor_disable();
    set_pos(0, 24);
    puts("An error has occurred. Exit code is ");
    putnum(exit_code);
    puts(" or ");
    puthex(exit_code);
}
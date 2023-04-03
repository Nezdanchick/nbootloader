#include <boot/multiboot2.h>
#include <video/textmode.h>
#include <lib/cursor.h>
#include <io/serial.h>
#include <stdio.h>

extern void init();
extern int  loop();

void main(__attribute__((unused)) struct multiboot_t* multiboot)
{
    init_serial(COM1);
    putserial("Serial started\n");
    
    cls();

    putserial("Initialization...\n");
    init();
    putserial("Initialization complete\nStart loop\n");

    int exit_code = 0;
    while (exit_code == 0) {
        exit_code = loop();
    }

    // serial logging
    putserial("An error has occurred. Exit code is ");
    putserialnum(exit_code);
    putserial(" or ");
    putserialhex(exit_code);
    putserial("\n");

    // video warning
    set_color(0x04);
    cursor_disable();
    set_pos(0, 24);
    puts("An error has occurred. Exit code is ");
    putnum(exit_code);
    puts(" or ");
    puthex(exit_code);
}
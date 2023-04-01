#include <boot/multiboot2.h>
#include <video/textmode.h>
#include <lib/cursor.h>

extern void init();
extern int  loop();

int main(__attribute__((unused)) struct multiboot_t* multiboot)
{
    cls();

    init();

    int exit_code = 0;
    while (exit_code == 0) {
        exit_code = loop();
    }

    set_color(0x04);
    cursor_disable();
    set_pos(0, 23);
    putnum(exit_code);
    set_pos(0, 24);
    puthex(exit_code);

	return 0x0428043a; // if falue, show ":)" on top of the screen
}
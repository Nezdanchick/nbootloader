#include <stdlib.h>
#include <boot/multiboot2.h>
#include <video/textmode.h>

int main(__attribute__((unused)) struct multiboot_t* multiboot)
{
    cls();

    set_pos(39, 12);
    set_color(0x04);
    putc(3);

    set_pos(0, 1);
    set_color(0x07);
    putnum(strlen("16 Hello, World!"));

    set_pos(0, 2);
    puthex(0xdeadbeef);

	return 0x0428043a; // :(
}
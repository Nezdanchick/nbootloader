#include <boot/multiboot2.h>
#include <video/textmode.h>

int main(__attribute__((unused)) struct multiboot_t* multiboot)
{
    cursor_enable(0, 16);
    cursor_move(40 + 12 * 80);

    cls();

    set_pos(40, 12);
    set_color(0x02);
    puts(":)");

    //puthex(0x89ABCDEF);

	asm("hlt");
	return 0x0428043a; // :(
}
#include <boot/multiboot2.h>
#include <lib/asm.h>
#include <lib/cursor.h>
#include <lib/string.h>
#include <video/textmode.h>

int main(__attribute__((unused)) struct multiboot_t* multiboot)
{
	const int screen_size = 80 * 25;
    char *video = (char*)0xB8000;
    char buff[screen_size + 1];
    video[screen_size] = '\0';

    memset(buff, ' ', screen_size); //clear screen with ' ' character
    strext(video, buff, 0x07); // cls
    strext(video, "Hello World!", 0x07);
    cursor_enable(15, 16);

    int x = 0;
    int y = 1;
    int pos = x + y * 80;

    cursor_move(pos);
    putc('L');
	asm("hlt");
	return 0x0428043a; // :(
}
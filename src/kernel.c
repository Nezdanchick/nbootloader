#include "video/textmode.h"
struct multiboot;

int main( __attribute__((unused)) struct multiboot *mboot_ptr ) {
	term_init();
	putc('H');
	//putc('\n');
	putc('H');

	puts("hello");
	
	asm("hlt");
	// finish
	return 0x0428043a; // :(
}
#include"print.hpp"

extern "C" void kernel_main(void) {
	term_init();
	term_clear();
	set_color(7,6);
	puts("Hello, Kernel!\n");
	set_color(7,4);
	puts("Hello, World!!!");
}
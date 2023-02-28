#include <stdint.h>

uint16_t volatile *buff;
long term_addr;
long term_color;
int term_height, term_width;

void term_init() {
    term_addr = 0xb8000;
    term_color = 07;
}

void set_color(int fg, int bg) {
    term_color = fg + bg * 16;
}
void set_color(int fg) {
    set_color(fg, 0);
}

void putc(char c) {
    if (c == '\n') {
        term_addr += (160-16) - term_addr % 80;
        return;
    }

    buff = (uint16_t*) term_addr;
	*buff = (uint16_t)c;
	term_addr += 0x00001;
	buff = (uint16_t*) term_addr;
	*buff = (uint16_t) term_color;
	term_addr += 0x00001;
}

void puts(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        putc(s[i]);
    }
}

void term_clear() {
    term_init();
    for (int i = 0; i <= 24*80; i++) {
        putc('\0');
    }
    term_init();
}
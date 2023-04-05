#include <stdio.h>
#include <video/textmode.h>
#include <lib/string.h>

const int SCREEN_SIZE = 80 * 25;
char *VIDEO = (char*)0xb8000;
char BUFFER[2001];
int POS_X = 0, POS_Y = 0;
u8 COLOR = 0x07;

void swap_buffers() {
    strcpy(VIDEO, BUFFER);
}
extern void fill(char c) {
    memset(BUFFER, c, SCREEN_SIZE); //clear buffer with c character
    swap_buffers();
}
extern void cls() {
    fill('\0');
}
extern void set_color(u8 color) {
    COLOR = color;
}
extern int get_pos() {
    return POS_X + POS_Y * 80;
}
extern void set_pos(int x, int y) {
    POS_X = x; POS_Y = y;
    cursor_move(get_pos());
}
extern void putc(char c) {
    strext((VIDEO + get_pos() * 2), &c, COLOR);
    POS_X++;
    cursor_move(get_pos());
}
extern void puts(char *s) {
    strext((VIDEO + get_pos() * 2), s, COLOR);
    int add = strlen(s);
    POS_X += add % 80;
    POS_Y += add / 80;
    cursor_move(get_pos());
}

void _putntext(i64 n, u8 r) {
    if (n < 0) { // value smaller than 0
        putc('-');
        _putntext(n * -1, r);
        return;
    }
    if (n >= r)
        _putntext(n / r, r);
    putc(HEX_NUMBERS[n % r]);
}
extern void putnum(i64 num) {
    _putntext(num, 10);
}
extern void puthex(i64 hex) {
    puts("0x");
    _putntext(hex, 16);
}
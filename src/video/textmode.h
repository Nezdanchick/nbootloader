#ifndef TEXTMODE_H
#define TEXTMODE_H

#include "common/typedef.h"
#include "cursor.h"

volatile uint16_t *screen;
volatile uint32_t term_x_pos;
volatile uint32_t term_y_pos;
uint8_t term_color;

void putc(char c);
void puts(char s[80]);
void puthex(int number);
void set_color(int fg, int bg);
void set_pos(int x, int y);
void scroll();
void term_clear();
void term_init();

void putc(char c) {
    if (c == '\n') {
        term_y_pos++;
        term_x_pos = 0;
    }
    uint32_t index = (term_y_pos * 80 + term_x_pos);
    screen[index] = (term_color << 8| c);
    //cursor_move(index + 1);
    term_x_pos++;
    if(term_x_pos > 80) {
        //scroll();
        putc('\n');
    }
}
void puts(char s[80]) {
    for (int i = 0; s[i] != '\0'; i++) {
        putc(s[i]);
    }
}
void puthex(int number) {
    char index[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F'}; //We use this to convert the number 0-15 into a character.
    puts("0x");
    for (; number >= 16; number /= 16) {
        putc(index[number % 16]);
    }
}
void set_color(int fg, int bg) {
    term_color = fg + bg * 16;
}
void set_pos(int x, int y) {
    term_x_pos = x;
    term_y_pos = y;
}
void scroll()
{
   if(term_y_pos >= 25)
   {
       for (int i = 0; i < 24*80; i++)
       {
           screen[i] = screen[i+80];
       }
       for (int i = 24*80; i < 25*80; i++)
       {
           putc('\0');
       }
       term_y_pos--;
   }
}
void term_clear() {
    for (int i = 0; i < 25*80; i++) {
        putc('\0');
    }
    set_pos(0, 0);
}
void term_init() {
    screen = (uint16_t *)0xb8000;
    set_pos(0, 0);
    set_color(7 , 0);
    cursor_disable();
    term_clear();
    cursor_enable(0, 16);
}

#endif
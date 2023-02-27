#include<stdint.h>

uint8_t terminalColor = 0x07;
uint16_t *terminalBuffer = (uint16_t *)0xb8000;
uint8_t terminalX = 0;
uint8_t terminalY = 0;


void putc(char c) {
    int pos = terminalX + terminalY * 80;
    terminalBuffer[pos * 2] = c;
    terminalBuffer[pos * 2 + 1] = terminalColor;

    terminalX++;
    if (terminalX > 80) {
        terminalX = 0;
        terminalY++;
    }
    if (terminalY > 24) {
        terminalX = 0;
        terminalY = 0;
    }
}

void puts(const char * s) {
    for(int i = 0; s[i] != '\0'; i++) {
        putc(s[i]);
    }
}

void clear() {
    for(int i = 0; i < terminalX + terminalY * 80; i++) {
        putc(' ');
    }
}
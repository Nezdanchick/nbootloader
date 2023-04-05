#include <lib/asm.h>
#include <io/serial.h>
#include <io/com.h>
#include <lib/string.h>

int SERIALPORT;

extern int init_serial(enum Port port) {
    SERIALPORT = port;
    outb(SERIALPORT + 1, 0x00);    // Disable all interrupts
    outb(SERIALPORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(SERIALPORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(SERIALPORT + 1, 0x00);    //                  (hi byte)
    outb(SERIALPORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(SERIALPORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(SERIALPORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    outb(SERIALPORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
    outb(SERIALPORT + 0, 0x60);    // Test serial chip (send byte 0x60 and check if serial returns same byte)

    // Check if serial is faulty (i.e: not same byte as sent)
    if(inb(SERIALPORT) != 0x60) {
        return 1;
    }
 
    // If serial is not faulty set it in normal operation mode
    // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
    outb(SERIALPORT + 4, 0x0F);
    return 0;
}

int serial_received() {
    return inb(SERIALPORT + 5) & 1;
}
 
char read_serial() {
    while (serial_received() == 0);

    return inb(SERIALPORT);
}

int is_transmit_empty() {
    return inb(SERIALPORT + 5) & 0x20;
}
 
void write_serial(char a) {
    while (is_transmit_empty() == 0);

    outb(SERIALPORT, a);
}
extern void putserial(char *s) {
    while (*s != '\0') {
    write_serial(*s++);
    }
}

void _putnserial(i64 n, u8 r) {
    if (n < 0) { // value smaller than 0
        write_serial('-');
        _putnserial(n * -1, r);
        return;
    }
    if (n >= r)
        _putnserial(n / r, r);
    write_serial(HEX_NUMBERS[n % r]);
}
extern void putserialnum(i64 num) {
    _putnserial(num, 10);
}
extern void putserialhex(i64 hex) {
    putserial("0x");
    _putnserial(hex, 16);
}
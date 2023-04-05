#pragma once
#include <stdint.h>
#include <lib/string.h>
#include <lib/cursor.h>

extern void cls();
extern void fill(char c);
extern void set_color(u8 color);
extern int  get_pos();
extern void set_pos(int x, int y);
extern void putnum(i64 num);
extern void puthex(i64 hex);
#pragma once
#include <stdint.h>

extern void cursor_enable(u8 cursor_start, u8 cursor_end);
extern void cursor_disable();
extern void cursor_move(int pos);
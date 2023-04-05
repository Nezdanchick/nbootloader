#pragma once

#include <io/com.h>
#include <stdint.h>

extern int init_serial(enum Port port);
extern void putserial(char *s);
extern void putserialnum(i64 num);
extern void putserialhex(i64 hex);
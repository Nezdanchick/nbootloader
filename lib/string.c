#include <lib/string.h>

extern char* strcpy(char* s1, const char* s2)
{
    while (*s2 != '\0')
        *s1++ = *s2++;
    *s1++ = '\0';
    return s1;
}

extern char* memset(char *buff, const char value, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i) {
        *buff++ = value;
    }
    return buff;
}

extern char* strext(char *buff, const char* str, char attribute)
{
    while (*str != '\0') {
        *buff++ = *str++;
        *buff++ = attribute;
    }
    return buff;
}
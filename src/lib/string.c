#include <lib/string.h>

const char HEX_NUMBERS[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f' };

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
extern int strlen(char* str) {
    int i;
    for (i = 0; *str++ != '\0'; i++);
    return i;
}
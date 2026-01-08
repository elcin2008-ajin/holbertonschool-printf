#include "main.h"

int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int i = 0;

    if (!s)
        s = "(null)";

    while (s[i])
    {
        _putchar(s[i]);
        i++;
    }
    return (i);
}

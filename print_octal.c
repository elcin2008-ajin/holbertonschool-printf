#include "main.h"

int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    char buffer[12];
    int i = 0;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
        count += _putchar(buffer[i]);

    return (count);
}

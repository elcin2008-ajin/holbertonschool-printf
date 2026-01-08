#include "main.h"

int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    char buffer[10];
    int i = 0;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i--)
        count += _putchar(buffer[i]);

    return (count);
}

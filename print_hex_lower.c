#include "main.h"

int print_hex_lower(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0, i = 0;
    char buffer[9];
    char hex_digits[] = "0123456789abcdef";

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = hex_digits[n % 16];
        n /= 16;
    }

    while (i--)
        count += _putchar(buffer[i]);

    return (count);
}

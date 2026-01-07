#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: the number to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1); /* highest bit */

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    /* Skip leading zeros */
    while (!(n & mask))
        mask >>= 1;

    while (mask)
    {
        if (n & mask)
            _putchar('1');
        else
            _putchar('0');
        count++;
        mask >>= 1;
    }

    return count;
}

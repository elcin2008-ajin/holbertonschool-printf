#include "main.h"

int print_number(unsigned long n, char *buffer, int *buff_index,
                 int base, char *digits, int negative, int unused)
{
    (void)unused;

    if (negative)
        buffer[(*buff_index)++] = '-';

    if (n / base)
        print_number(n / base, buffer, buff_index, base, digits, 0, 0);

    buffer[(*buff_index)++] = digits[n % base];

    return (0);
}

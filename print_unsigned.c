#include "main.h"

int print_unsigned(unsigned int n, char *buffer, int *buff_index, int plus_flag)
{
    if (plus_flag)
        buffer[(*buff_index)++] = '+';

    if (n / 10)
        print_unsigned(n / 10, buffer, buff_index, 0);

    buffer[(*buff_index)++] = (n % 10) + '0';
    return (0);
}

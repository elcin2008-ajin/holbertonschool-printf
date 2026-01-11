#include "main.h"

int print_octal(unsigned int n, char *buffer, int *buff_index, int hash_flag)
{
    if (hash_flag && n != 0)
        buffer[(*buff_index)++] = '0';

    if (n / 8)
        print_octal(n / 8, buffer, buff_index, 0);

    buffer[(*buff_index)++] = (n % 8) + '0';
    return (0);
}

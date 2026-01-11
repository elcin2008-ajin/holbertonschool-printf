#include "main.h"

int print_hex_lower(unsigned int n, char *buffer, int *buff_index, int hash_flag)
{
    if (hash_flag && n != 0)
    {
        buffer[(*buff_index)++] = '0';
        buffer[(*buff_index)++] = 'x';
    }

    if (n / 16)
        print_hex_lower(n / 16, buffer, buff_index, 0);

    buffer[(*buff_index)++] = "0123456789abcdef"[n % 16];
    return (0);
}

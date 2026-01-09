#include "main.h"

int print_hex_lower(unsigned int n, char *buffer, int *buff_index, char flag)
{
    int count = 0;

    if (flag == '#' && n != 0)
    {
        buffer[*buff_index] = '0';
        (*buff_index)++;
        buffer[*buff_index] = 'x';
        (*buff_index)++;
        count += 2;
    }

    count += print_number(n, buffer, buff_index, 16, "0123456789abcdef", 0, 0);
    return count;
}

#include "main.h"

int print_octal(unsigned int n, char *buffer, int *buff_index, char flag)
{
    int count = 0;

    if (flag == '#' && n != 0)
    {
        buffer[*buff_index] = '0';
        (*buff_index)++;
        count++;
    }

    count += print_number(n, buffer, buff_index, 8, "01234567", 0, 0);
    return count;
}

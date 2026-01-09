#include "main.h"

int print_number(unsigned int n, char *buffer, int *buff_index,
                 unsigned int base, char *map)
{
    int count = 0;

    if (n >= base)
        count += print_number(n / base, buffer, buff_index, base, map);

    buffer[*buff_index] = map[n % base];
    (*buff_index)++;

    if (*buff_index == BUFFER_SIZE)
    {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }

    return (count + 1);
}

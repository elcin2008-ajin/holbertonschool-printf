#include "main.h"

int print_number(unsigned long n, char *buffer, int *buff_index,
                 unsigned long base, char *map)
{
    int count = 0;

    if (n >= base)
        count += print_number(n / base, buffer, buff_index, base, map);

    buffer[*buff_index] = map[n % base];
    (*buff_index)++;

    if (*buff_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }

    return (count + 1);
}

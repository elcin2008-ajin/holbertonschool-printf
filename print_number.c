#include "main.h"

/**
 * print_number - Prints a number with base and flags
 */
int print_number(unsigned long n, char *buffer, int *buff_index,
                 unsigned long base, char *map,
                 int plus_flag, int space_flag, int is_signed)
{
    int count = 0;
    char sign = 0;

    if (is_signed)
    {
        if ((long)n < 0)
        {
            sign = '-';
            n = -((long)n);
        }
        else if (plus_flag)
            sign = '+';
        else if (space_flag)
            sign = ' ';
    }

    if (sign)
    {
        buffer[*buff_index] = sign;
        (*buff_index)++;
        count++;
    }

    if (n >= base)
        count += print_number(n / base, buffer, buff_index, base, map, 0, 0, 0);

    buffer[*buff_index] = map[n % base];
    (*buff_index)++;

    if (*buff_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }

    return (count + 1);
}

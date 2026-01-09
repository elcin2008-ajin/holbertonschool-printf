#include "main.h"

/**
 * print_string - prints a string
 */
int print_string(char *str, char *buffer, int *buff_index)
{
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        buffer[*buff_index] = *str;
        (*buff_index)++;
        count++;
        if (*buff_index >= BUFFER_SIZE)
        {
            write(1, buffer, *buff_index);
            *buff_index = 0;
        }
        str++;
    }
    return (count);
}

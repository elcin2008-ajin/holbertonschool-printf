#include "main.h"

int print_percent(char *buffer, int *buff_index)
{
    buffer[*buff_index] = '%';
    (*buff_index)++;

    if (*buff_index == BUFFER_SIZE)
    {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }
    return (1);
}

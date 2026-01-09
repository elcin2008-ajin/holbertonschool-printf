#include "main.h"

int print_char(char c, char *buffer, int *buff_index)
{
    buffer[*buff_index] = c;
    (*buff_index)++;

    if (*buff_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }

    return 1;
}

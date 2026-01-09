#include "main.h"

int print_string(char *s, char *buffer, int *buff_index)
{
    int i = 0;

    if (!s)
        s = "(null)";

    while (s[i])
    {
        buffer[*buff_index] = s[i];
        (*buff_index)++;

        if (*buff_index >= BUFFER_SIZE - 1)
        {
            write(1, buffer, *buff_index);
            *buff_index = 0;
        }
        i++;
    }
    return (i);
}

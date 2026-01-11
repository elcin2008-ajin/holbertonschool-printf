#include "main.h"

int print_string(char *str, char *buffer, int *buff_index)
{
    int i = 0;

    if (!str)
        str = "(null)";

    while (str[i])
        buffer[(*buff_index)++] = str[i++];

    return (0);
}

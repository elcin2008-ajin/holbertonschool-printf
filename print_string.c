#include "main.h"

int print_string(char *s, char *buffer, int *buff_index)
{
    int i = 0;
    if (!s)
        s = "(null)";

    while (s[i])
    {
        buffer[(*buff_index)++] = s[i];
        i++;
    }

    return i;
}

#include "main.h"

int print_S(char *s, char *buffer, int *buff_index)
{
    int i = 0;
    int count = 0;
    unsigned char c;
    char hex_map[] = "0123456789ABCDEF";

    if (!s)
        s = "(null)";

    while (s[i])
    {
        c = s[i];

        if (c < 32 || c >= 127)
        {
            buffer[*buff_index] = '\\';
            (*buff_index)++;
            buffer[*buff_index] = 'x';
            (*buff_index)++;

            buffer[*buff_index] = hex_map[c / 16];
            (*buff_index)++;
            buffer[*buff_index] = hex_map[c % 16];
            (*buff_index)++;

            count += 4;
        }
        else
        {
            buffer[*buff_index] = c;
            (*buff_index)++;
            count++;
        }

        if (*buff_index >= BUFFER_SIZE - 4)
        {
            write(1, buffer, *buff_index);
            *buff_index = 0;
        }

        i++;
    }

    return (count);
}

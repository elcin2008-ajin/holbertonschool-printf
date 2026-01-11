#include "main.h"

int print_char(char c, char *buffer, int *buff_index)
{
    buffer[(*buff_index)++] = c;
    return 1;
}

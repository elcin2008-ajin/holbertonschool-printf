#include "main.h"

int print_pointer(void *p, char *buffer, int *buff_index)
{
    unsigned long addr = (unsigned long)p;

    buffer[(*buff_index)++] = '0';
    buffer[(*buff_index)++] = 'x';

    print_number(addr, buffer, buff_index, 16, "0123456789abcdef", 0, 0);
    return (0);
}

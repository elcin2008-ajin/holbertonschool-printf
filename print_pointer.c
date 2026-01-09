#include "main.h"

int print_pointer(void *p, char *buffer, int *buff_index)
{
    int count;
    unsigned long addr;

    if (!p)
        return print_string("(nil)", buffer, buff_index);

    addr = (unsigned long)p;
    count = 0;

    buffer[*buff_index] = '0';
    (*buff_index)++;
    buffer[*buff_index] = 'x';
    (*buff_index)++;
    count += 2;

    count += print_number(addr, buffer, buff_index, 16, "0123456789abcdef", 0, 0);
    return count;
}

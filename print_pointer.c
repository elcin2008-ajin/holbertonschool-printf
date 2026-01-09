#include "main.h"

int print_pointer(void *p, char *buffer, int *buff_index)
{
    unsigned long addr;
    int count = 0;

    if (!p)
        return print_string("0x0", buffer, buff_index);

    addr = (unsigned long)p;

    /* add 0x prefix */
    buffer[*buff_index] = '0';
    (*buff_index)++;
    buffer[*buff_index] = 'x';
    (*buff_index)++;
    count = 2;

    /* print hex address */
    count += print_number(addr, buffer, buff_index, 16, "0123456789abcdef");

    return (count);
}

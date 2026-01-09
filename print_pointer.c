#include "main.h"

int print_pointer(void *p, char *buffer, int *buff_index)
{
    unsigned long addr;
    int count = 0;

    if (p == NULL)
        return print_string("(nil)", buffer, buff_index);

    addr = (unsigned long)p;
    count += print_string("0x", buffer, buff_index);
    count += print_number(addr, buffer, buff_index, 16, "0123456789abcdef", 0, 0);

    return count;
}

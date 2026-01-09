#include "main.h"

int print_pointer(void *p, char *buffer, int *buff_index)
{
    int count;
    unsigned long addr;

    /* NULL pointer */
    if (!p)
        return print_string("(nil)", buffer, buff_index);

    /* bütün dəyişənləri funksiyanın başlanğıcında elan et */
    addr = (unsigned long)p;
    count = 0;

    /* add 0x prefix */
    buffer[*buff_index] = '0';
    (*buff_index)++;
    buffer[*buff_index] = 'x';
    (*buff_index)++;
    count += 2;

    /* print hex address */
    count += print_number(addr, buffer, buff_index, 16, "0123456789abcdef");

    return (count);
}

#include "main.h"

int print_int(int n, char *buffer, int *buff_index)
{
    unsigned int num;
    int count = 0;

    if (n < 0)
    {
        count += print_char('-', buffer, buff_index);
        num = -n;
    }
    else
        num = n;

    count += print_number(num, buffer, buff_index, 10, "0123456789");
    return (count);
}

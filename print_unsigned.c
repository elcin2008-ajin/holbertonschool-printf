#include "main.h"

int print_unsigned(unsigned int n, char *buffer, int *buff_index, char flag)
{
    return print_number(n, buffer, buff_index, 10, "0123456789", flag, 0);
}

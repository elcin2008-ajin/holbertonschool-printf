#include "main.h"

int print_unsigned(unsigned int n, char *buffer, int *buff_index, int plus_flag)
{
    return print_number(n, buffer, buff_index, 10, "0123456789", plus_flag, 0);
}

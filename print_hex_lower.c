#include "main.h"

int print_hex_lower(unsigned int n, char *buffer, int *buff_index)
{
    return (print_number(n, buffer, buff_index, 16, "0123456789abcdef"));
}

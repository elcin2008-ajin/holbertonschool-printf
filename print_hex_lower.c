#include "main.h"

int print_hex_lower(unsigned int n, char *buffer, int *buff_index, int hash_flag)
{
    int count = 0;

    count += print_number(n, buffer, buff_index, 16, "0123456789abcdef", 0, 0);
    return count;
}

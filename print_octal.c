#include "main.h"

int print_octal(unsigned int n, char *buffer, int *buff_index, int hash_flag)
{
    int count = 0;

    count += print_number(n, buffer, buff_index, 8, "01234567", 0, 0);
    return count;
}

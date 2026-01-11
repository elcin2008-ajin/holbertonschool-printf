#include "main.h"

int print_binary(unsigned int n, char *buffer, int *buff_index)
{
    if (n / 2)
        print_binary(n / 2, buffer, buff_index);

    buffer[(*buff_index)++] = (n % 2) + '0';
    return (0);
}

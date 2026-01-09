#include "main.h"

int print_binary(unsigned int n, char *buffer, int *buff_index)
{
    return print_number(n, buffer, buff_index, 2, "01", 0, 0);
}

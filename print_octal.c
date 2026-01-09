#include "main.h"

int print_octal(unsigned int n, char *buffer, int *buff_index)
{
    return (print_number(n, buffer, buff_index, 8, "01234567"));
}

#include "main.h"

/**
 * print_int - Prints signed integer with flags
 */
int print_int(int n, char *buffer, int *buff_index, int plus_flag, int space_flag)
{
    return print_number((unsigned long)n, buffer, buff_index, 10, "0123456789",
                        plus_flag, space_flag, 1);
}

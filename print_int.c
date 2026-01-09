#include "main.h"

/**
 * print_int - Prints a signed integer with flags
 * @n: integer to print
 * @buffer: buffer array
 * @buff_index: current index in buffer
 * @plus_flag: '+' flag
 * @space_flag: ' ' flag
 *
 * Return: number of characters printed
 */
int print_int(int n, char *buffer, int *buff_index, int plus_flag, int space_flag)
{
    return print_number((unsigned long)n, buffer, buff_index, 10, "0123456789",
                        plus_flag, space_flag, 1);
}

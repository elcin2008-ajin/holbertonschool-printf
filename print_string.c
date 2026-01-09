#include "main.h"

/**
 * print_string - Prints a string to buffer
 * @str: The string to print
 * @buffer: Buffer to store chars
 * @buff_index: Pointer to current index in buffer
 *
 * Return: Number of chars printed
 */
int print_string(char *str, char *buffer, int *buff_index)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        buffer[(*buff_index)++] = *str;
        count++;
        str++;
    }

    return count;
}

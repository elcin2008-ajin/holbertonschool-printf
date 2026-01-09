#include "main.h"

/**
 * print_number - Prints a number in any base to buffer
 * @n: The number to print
 * @buffer: Buffer to store chars
 * @buff_index: Pointer to current index in buffer
 * @base: Base to convert to (e.g., 10, 16, 8, 2)
 * @digits: String containing digits for the base (e.g., "0123456789abcdef")
 * @flag1: Flag for plus sign or other features
 * @flag2: Additional flag (for example, hash_flag)
 *
 * Return: Number of chars printed
 */
int print_number(unsigned long n, char *buffer, int *buff_index,
                 int base, char *digits, int flag1, int flag2)
{
    char temp[65]; /* Enough for 64-bit binary number + null */
    int i = 0, count = 0;
    unsigned long num = n;
    int negative = 0;

    /* Handle negative for base 10 */
    if (base == 10 && (long)n < 0)
    {
        negative = 1;
        num = -(long)n;
    }

    /* Convert number to string in reverse */
    if (num == 0)
        temp[i++] = '0';
    else
    {
        while (num > 0)
        {
            temp[i++] = digits[num % base];
            num /= base;
        }
    }

    /* Add sign if needed */
    if (negative)
    {
        buffer[(*buff_index)++] = '-';
        count++;
    }
    else if (flag1 == 1) /* plus_flag */
    {
        buffer[(*buff_index)++] = '+';
        count++;
    }
    else if (flag1 == 2) /* space_flag */
    {
        buffer[(*buff_index)++] = ' ';
        count++;
    }

    /* Add "0x", "0X" or "0" prefix if hash_flag (flag2) set and base 8 or 16 */
    if (flag2)
    {
        if (base == 16)
        {
            buffer[(*buff_index)++] = '0';
            buffer[(*buff_index)++] = (digits[10] == 'a') ? 'x' : 'X';
            count += 2;
        }
        else if (base == 8 && temp[i - 1] != '0') /* octal leading 0 */
        {
            buffer[(*buff_index)++] = '0';
            count++;
        }
    }

    /* Now print digits in correct order */
    while (--i >= 0)
    {
        buffer[(*buff_index)++] = temp[i];
        count++;
    }

    return count;
}

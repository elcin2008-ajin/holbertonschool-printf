#include "main.h"

int handle_length_modifier(va_list args, char length, char specifier,
                           char *buffer, int *buff_index)
{
    unsigned long n;
    int negative = 0;

    if (specifier == 'd' || specifier == 'i')
    {
        if (length == 'l')
        {
            long num = va_arg(args, long);
            if (num < 0)
            {
                negative = 1;
                if (num == LONG_MIN)
                    n = (unsigned long)LONG_MAX + 1;
                else
                    n = (unsigned long)(-num);
            }
            else
                n = (unsigned long)num;
        }
        else if (length == 'h')
        {
            short num = (short)va_arg(args, int);
            if (num < 0)
            {
                negative = 1;
                n = (unsigned short)(-num);
            }
            else
                n = (unsigned short)num;
        }
        else
        {
            int num = va_arg(args, int);
            if (num < 0)
            {
                negative = 1;
                if (num == INT_MIN)
                    n = (unsigned int)INT_MAX + 1;
                else
                    n = (unsigned int)(-num);
            }
            else
                n = (unsigned int)num;
        }
        print_number(n, buffer, buff_index, 10, "0123456789", negative, 0);
    }

    if (specifier == 'u' || specifier == 'o' || specifier == 'x' || specifier == 'X')
    {
        if (length == 'l')
            n = va_arg(args, unsigned long);
        else if (length == 'h')
            n = (unsigned short)va_arg(args, unsigned int);
        else
            n = va_arg(args, unsigned int);

        char *digits;
        int base;

        if (specifier == 'u')
        {
            digits = "0123456789";
            base = 10;
        }
        else if (specifier == 'o')
        {
            digits = "01234567";
            base = 8;
        }
        else if (specifier == 'x')
        {
            digits = "0123456789abcdef";
            base = 16;
        }
        else /* X */
        {
            digits = "0123456789ABCDEF";
            base = 16;
        }

        print_number(n, buffer, buff_index, base, digits, 0, 0);
    }

    return 0;
}

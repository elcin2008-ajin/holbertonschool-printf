#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 */
int _printf(const char *format, ...)
{
    int i = 0, printed = 0, buff_index = 0;
    char buffer[BUFFER_SIZE];
    va_list args;

    va_start(args, format);

    if (!format)
        return (-1);

    while (format[i])
    {
        if (format[i] == '%')
        {
            int plus_flag = 0, space_flag = 0;
            i++;

            while (format[i] == '+' || format[i] == ' ')
            {
                if (format[i] == '+')
                    plus_flag = 1;
                else if (format[i] == ' ')
                    space_flag = 1;
                i++;
            }

            if (format[i] == 'd' || format[i] == 'i')
            {
                int val = va_arg(args, int);
                printed += print_int(val, buffer, &buff_index, plus_flag, space_flag);
            }
            else if (format[i] == 'c')
            {
                char c = (char)va_arg(args, int);
                printed += print_char(c, buffer, &buff_index);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                printed += print_string(str, buffer, &buff_index);
            }
            else if (format[i] == '%')
            {
                printed += print_char('%', buffer, &buff_index);
            }
            else
            {
                printed += print_char('%', buffer, &buff_index);
                printed += print_char(format[i], buffer, &buff_index);
            }
            i++;
        }
        else
        {
            printed += print_char(format[i], buffer, &buff_index);
            i++;
        }
    }

    va_end(args);

    printed += write(1, buffer, buff_index);
    return (printed);
}

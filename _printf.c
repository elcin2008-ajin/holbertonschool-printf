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
            int plus_flag = 0, space_flag = 0, hash_flag = 0;
            i++;

            while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
            {
                if (format[i] == '+')
                    plus_flag = 1;
                else if (format[i] == ' ')
                    space_flag = 1;
                else if (format[i] == '#')
                    hash_flag = 1;
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
                buffer[buff_index++] = '%';
                printed++;
                if (buff_index == BUFFER_SIZE)
                {
                    write(1, buffer, buff_index);
                    buff_index = 0;
                }
            }
            else
            {
                buffer[buff_index++] = '%';
                buffer[buff_index++] = format[i];
                printed += 2;
                if (buff_index >= BUFFER_SIZE)
                {
                    write(1, buffer, buff_index);
                    buff_index = 0;
                }
            }
            i++;
        }
        else
        {
            buffer[buff_index++] = format[i++];
            printed++;
            if (buff_index == BUFFER_SIZE)
            {
                write(1, buffer, buff_index);
                buff_index = 0;
            }
        }
    }

    if (buff_index > 0)
        write(1, buffer, buff_index);

    va_end(args);
    return (printed);
}

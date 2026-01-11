#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buff_index = 0;
    int i = 0;
    int plus = 0, space = 0, hash = 0;

    va_start(args, format);

    if (!format)
        return (-1);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            plus = space = hash = 0;

            while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
            {
                if (format[i] == '+')
                    plus = 1;
                else if (format[i] == ' ')
                    space = 1;
                else if (format[i] == '#')
                    hash = 1;
                i++;
            }

            if (format[i] == 'd' || format[i] == 'i')
            {
                int n = va_arg(args, int);

                if (n >= 0)
                {
                    if (plus)
                        buffer[buff_index++] = '+';
                    else if (space)
                        buffer[buff_index++] = ' ';
                }
                print_number((n < 0) ? -n : n, buffer, &buff_index,
                             10, "0123456789", (n < 0), 0);
            }
            else if (format[i] == 'u')
                print_unsigned(va_arg(args, unsigned int), buffer, &buff_index, plus);
            else if (format[i] == 'b')
                print_binary(va_arg(args, unsigned int), buffer, &buff_index);
            else if (format[i] == 'x')
                print_hex_lower(va_arg(args, unsigned int), buffer, &buff_index, hash);
            else if (format[i] == 'X')
                print_hex_upper(va_arg(args, unsigned int), buffer, &buff_index, hash);
            else if (format[i] == 'o')
                print_octal(va_arg(args, unsigned int), buffer, &buff_index, hash);
            else if (format[i] == 's')
                print_string(va_arg(args, char *), buffer, &buff_index);
            else if (format[i] == 'p')
                print_pointer(va_arg(args, void *), buffer, &buff_index);
            else if (format[i] == '%')
                buffer[buff_index++] = '%';
        }
        else
            buffer[buff_index++] = format[i];
        i++;
    }

    write(1, buffer, buff_index);
    va_end(args);
    return (buff_index);
}

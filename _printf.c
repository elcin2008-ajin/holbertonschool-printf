#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_index = 0;
    int printed = 0;
    int i = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            printed += print_char(format[i], buffer, &buff_index);
        }
        else
        {
            i++;
            if (format[i] == 'c')
                printed += print_char(va_arg(args, int), buffer, &buff_index);
            else if (format[i] == 's')
                printed += print_string(va_arg(args, char *), buffer, &buff_index);
            else if (format[i] == 'S')
                printed += print_S(va_arg(args, char *), buffer, &buff_index);
            else if (format[i] == '%')
                printed += print_percent(buffer, &buff_index);
            else if (format[i] == 'd' || format[i] == 'i')
                printed += print_int(va_arg(args, int), buffer, &buff_index);
            else if (format[i] == 'u')
                printed += print_unsigned(va_arg(args, unsigned int), buffer, &buff_index);
            else if (format[i] == 'b')
                printed += print_binary(va_arg(args, unsigned int), buffer, &buff_index);
            else if (format[i] == 'o')
                printed += print_octal(va_arg(args, unsigned int), buffer, &buff_index);
            else if (format[i] == 'x')
                printed += print_hex_lower(va_arg(args, unsigned int), buffer, &buff_index);
            else if (format[i] == 'X')
                printed += print_hex_upper(va_arg(args, unsigned int), buffer, &buff_index);
        }
        i++;
    }

    if (buff_index > 0)
        write(1, buffer, buff_index);

    va_end(args);
    return (printed);
}

#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_index = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                print_char('%', buffer, &buff_index);
            }
            else
            {
                char length = 0;
                if (format[i] == 'l' || format[i] == 'h')
                {
                    length = format[i];
                    i++;
                }
                /* Handle specifier with length */
                handle_length_modifier(args, length, format[i], buffer, &buff_index);
            }
        }
        else
        {
            print_char(format[i], buffer, &buff_index);
        }
        i++;
    }

    va_end(args);

    /* write buffer to stdout */
    write(1, buffer, buff_index);

    return buff_index;
}

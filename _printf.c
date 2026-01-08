#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j, count = 0;

    format_t specs[] = {
        {'c', print_char},
        {'s', print_string},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex_lower},
        {'X', print_hex_upper},
        {'%', NULL},
        {0, NULL}
    };

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                _putchar('%');
                count++;
                i++;
                continue;
            }
            for (j = 0; specs[j].spec; j++)
            {
                if (format[i] == specs[j].spec)
                {
                    if (specs[j].f)
                        count += specs[j].f(args);
                    break;
                }
            }
            if (!specs[j].spec)
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
            i++;
        }
        else
        {
            _putchar(format[i]);
            count++;
            i++;
        }
    }

    va_end(args);
    return (count);
}

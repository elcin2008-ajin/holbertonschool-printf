#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j, count = 0;

    format_t specs[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'b', print_binary},
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
            for (j = 0; specs[j].spec; j++)
            {
                if (format[i] == specs[j].spec)
                {
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
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

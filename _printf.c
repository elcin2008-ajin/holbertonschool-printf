#include "main.h"

/**
 * _printf - sadə printf funksiyası (c, s, %)
 * @format: format string
 *
 * Return: yazılan simvolların sayı
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *s;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')
            {
                va_end(args);
                return (-1);
            }

            i++;
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    write(1, s++, 1);
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                /* tanınmayan specifier */
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

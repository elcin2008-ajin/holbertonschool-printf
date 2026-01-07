#include "main.h"
#include <unistd.h>

/**
 * print_number - integer-i stdout-a yazır
 * @n: integer
 *
 * Return: yazılan simvolların sayı
 */
int print_number(int n)
{
    int count = 0;
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        if (n == -2147483648)  /* INT_MIN */
        {
            write(1, "2147483648", 10);
            return count + 10;
        }
        n = -n;
    }

    if (n / 10)
        count += print_number(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
    count++;

    return count;
}

/**
 * _printf - simplified printf with c, s, %, d, i
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
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int n = va_arg(args, int);
                count += print_number(n);
            }
            else
            {
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
    return count;
}

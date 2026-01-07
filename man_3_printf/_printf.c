#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'b') /* bizim custom specifier */
                count += print_binary(va_arg(args, unsigned int));
            else if (format[i] == '%')
                count += _putchar('%');
            /* digər format specifiers əlavə edə bilərsən */
            else
                count += _putchar('%'), count += _putchar(format[i]);
        }
        else
            count += _putchar(format[i]);
        i++;
    }

    va_end(args);
    return count;
}

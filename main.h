#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct format - specifier və ona uyğun funksiya
 * @spec: specifier simvolu
 * @f: specifier funksiyasına pointer
 */
typedef struct format
{
    char spec;
    int (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

#endif

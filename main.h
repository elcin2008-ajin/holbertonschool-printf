#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format - format specifier strukturu
 * @spec: format simvolu
 * @f: uyğun funksiya
 */
typedef struct format
{
    char spec;
    int (*f)(va_list);
} format_t;

/* əsas printf */
int _printf(const char *format, ...);

/* util */
int _putchar(char c);

/* printer funksiyalar */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);

#endif

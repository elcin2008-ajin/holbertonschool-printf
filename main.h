#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Buffer size */
#define BUFFER_SIZE 1024

/* Function prototypes */
int _printf(const char *format, ...);

/* Print functions */
int print_char(char c, char *buffer, int *buff_index);
int print_string(char *s, char *buffer, int *buff_index);
int print_percent(char *buffer, int *buff_index);
int print_number(unsigned long n, char *buffer, int *buff_index,
                 int base, char *digits, int negative, int unused);

/* Length modifier handling */
int handle_length_modifier(va_list args, char length, char specifier,
                           char *buffer, int *buff_index);

#endif

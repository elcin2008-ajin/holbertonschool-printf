#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);

int _putchar(char c);

int print_number(unsigned long n, char *buffer, int *buff_index,
                 unsigned long base, char *map,
                 int plus_flag, int space_flag, int is_signed);

int print_int(int n, char *buffer, int *buff_index, int plus_flag, int space_flag);

/* Digər funksiyaların prototipləri */

#endif /* MAIN_H */

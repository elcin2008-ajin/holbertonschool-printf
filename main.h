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
int print_string(char *str, char *buffer, int *buff_index);
int print_char(char c, char *buffer, int *buff_index);
int print_unsigned(unsigned int n, char *buffer, int *buff_index, int plus_flag);
int print_hex_lower(unsigned int n, char *buffer, int *buff_index, int hash_flag);
int print_hex_upper(unsigned int n, char *buffer, int *buff_index, int hash_flag);
int print_octal(unsigned int n, char *buffer, int *buff_index, int hash_flag);
int print_pointer(void *p, char *buffer, int *buff_index);

#endif /* MAIN_H */

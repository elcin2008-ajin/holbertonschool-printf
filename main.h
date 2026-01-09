#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int print_number(unsigned long n, char *buffer, int *buff_index,
                 int base, char *digits, int flag1, int flag2);

int print_binary(unsigned int n, char *buffer, int *buff_index);

int print_unsigned(unsigned int n, char *buffer, int *buff_index, int plus_flag);

int print_hex_lower(unsigned int n, char *buffer, int *buff_index, int hash_flag);

int print_hex_upper(unsigned int n, char *buffer, int *buff_index, int hash_flag);

int print_octal(unsigned int n, char *buffer, int *buff_index, int hash_flag);

int print_pointer(void *p, char *buffer, int *buff_index);

int print_string(char *str, char *buffer, int *buff_index);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);

/* basic */
int print_char(char c, char *buffer, int *buff_index);
int print_string(char *s, char *buffer, int *buff_index);
int print_percent(char *buffer, int *buff_index);
int print_S(char *s, char *buffer, int *buff_index);

/* numbers */
int print_int(int n, char *buffer, int *buff_index);
int print_unsigned(unsigned int n, char *buffer, int *buff_index);
int print_binary(unsigned int n, char *buffer, int *buff_index);
int print_octal(unsigned int n, char *buffer, int *buff_index);
int print_hex_lower(unsigned int n, char *buffer, int *buff_index);
int print_hex_upper(unsigned int n, char *buffer, int *buff_index);
int print_pointer(void *p, char *buffer, int *buff_index);

/* helper */
int print_number(unsigned long n, char *buffer, int *buff_index,
                 unsigned long base, char *map);

#endif

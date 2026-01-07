#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Prototype for our _printf */
int _printf(const char *format, ...);

/* Helper function to print a number in binary */
int print_binary(unsigned int n);

/* Helper functions you may need */
int _putchar(char c);
int _puts(char *str);

#endif /* MAIN_H */

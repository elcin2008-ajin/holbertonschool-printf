#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes character c to stdout
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

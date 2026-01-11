#include "main.h"
#include <limits.h>

int print_int(int n, char *buffer, int *buff_index, int plus_flag, int space_flag)
{
    unsigned long num;
    int negative = 0;

    (void)plus_flag;
    (void)space_flag;

    if (n < 0)
    {
        negative = 1;

        /* INT_MIN üçün overflow-u aradan qaldırır */
        if (n == INT_MIN)
            num = (unsigned long)2147483648UL;
        else
            num = (unsigned long)(-n);
    }
    else
        num = (unsigned long)n;

    return print_number(num, buffer, buff_index, 10,
                        "0123456789", negative, 0);
}

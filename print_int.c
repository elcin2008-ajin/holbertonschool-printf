#include "main.h"

int print_int(int n, char *buffer, int *buff_index, int plus_flag, int space_flag)
{
    int negative = 0;

    (void)plus_flag;
    (void)space_flag;

    if (n < 0)
    {
        negative = 1;
        n = -n;
    }

    return print_number((unsigned long)n, buffer, buff_index, 10,
                        "0123456789", negative, 0);
}

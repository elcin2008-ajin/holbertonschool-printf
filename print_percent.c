#include "main.h"

int print_percent(char *buffer, int *buff_index)
{
    buffer[(*buff_index)++] = '%';
    return 1;
}

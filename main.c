#include <limits.h>
#include "main.h"

int main(void)
{
    int len;

    len = _printf("% +i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    _printf("Length: %d\n", len);

    return (0);
}

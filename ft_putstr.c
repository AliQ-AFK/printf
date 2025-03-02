#include "ft_printf.h"

int ft_putstr(char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";
    while (*str)
        count += ft_putchar(*str++);
    return (count);
}

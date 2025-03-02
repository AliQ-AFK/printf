#include "ft_printf.h"

int ft_put_unsigned(unsigned int n)
{
    int count = 0;

    if (n >= 10)
        count += ft_put_unsigned(n / 10);
    count += ft_putchar((n % 10) + '0');
    return (count);
}

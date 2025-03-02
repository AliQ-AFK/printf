#include "ft_printf.h"

int ft_putnbr(int n)
{
    int count = 0;

    if (n == -2147483648)
    {
        count += ft_putchar('-');
        return (count + ft_putstr("2147483648"));
    }
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        count += ft_putnbr(n / 10);
    count += ft_putchar((n % 10) + '0');
    return (count);
}

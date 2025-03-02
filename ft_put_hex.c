#include "ft_printf.h"

int ft_put_hex(unsigned long n, char format)
{
    int count = 0;
    char *hex;

    if (format == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";

    if (n >= 16)
        count += ft_put_hex(n / 16, format);
    count += ft_putchar(hex[n % 16]);
    return (count);
}

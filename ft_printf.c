
#include "ft_printf.h"

static int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

static int ft_putstr(char *str)
{
    int count;

    count = 0;
    if (!str)
        str = "(null)";
    while (*str)
        count += ft_putchar(*str++);
    return (count);
}

static int ft_putnbr(int n)
{
    int count;

    count = 0;
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
    count += ft_putchar ((n % 10) + '0');
    return (count);
}

static  int ft_put_unsigned(unsigned int n)
{
    int count;

    count = 0;
    if (n >=10)
        count += ft_put_unsigned(n / 10);
    count += ft_putchar((n % 10) + '0');
    return (count);
}

static int ft_put_hex(unsigned long n, char format)
{
    int     count;
    char    *hex;
    
    count = 0;
    if (format == 'x')
        hex = "0123456789abcdef";
    else if (format == 'X')
        hex = "0123456789ABCDEF";
    if (n >=16)
        count += ft_put_hex(n / 16, format);
    count += ft_putchar(hex[n % 16]);
    return (count);
}

static int ft_put_pointer(unsigned long ptr)
{
    int     count;

    count = 0;
    if (ptr == 0)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_put_hex(ptr, 'x');
    return (count);
}

static int ft_handle_specifier(char specifier, va_list args)
{
    if (specifier == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (specifier == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (specifier == 'd' ||specifier == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (specifier == 'u')
        return (ft_put_unsigned(va_arg(args, unsigned int)));
    else if (specifier == 'x' || specifier == 'X')
        return (ft_put_hex(va_arg(args, unsigned int), specifier));
    else if (specifier == 'p')
            return (ft_put_pointer(va_arg(args, unsigned long)));
    ft_putchar('%');
    ft_putchar(specifier);
    return (2);   
}
int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int count;

    i = 0;
    count = 0;
    va_start (args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            i++;
            count += ft_handle_specifier(str[i], args);

        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end (args);
    return (count);
}
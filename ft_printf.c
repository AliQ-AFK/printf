#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, str);
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
    va_end(args);
    return (count);
}
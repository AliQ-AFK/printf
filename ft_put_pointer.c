#include "ft_printf.h"

int ft_put_pointer(unsigned long ptr)
{
    int count = 0;

    if (ptr == 0)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_put_hex(ptr, 'x');
    return (count);
}

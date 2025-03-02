#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_put_unsigned(unsigned int n);
int ft_put_hex(unsigned long n, char format);
int ft_put_pointer(unsigned long ptr);
int ft_handle_specifier(char specifier, va_list args);
int ft_printf(const char *str, ...);

#endif

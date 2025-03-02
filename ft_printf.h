#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>  // For variadic functions (va_list, va_start, etc.)
#include <unistd.h>  // For write()
#include <stdlib.h>  // For malloc() if needed

int ft_printf(const char *format, ...);  // Main function

#endif

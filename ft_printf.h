/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:44:39 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/02 20:48:20 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_put_hex(unsigned long n, char format);
int	ft_put_pointer(unsigned long ptr);
int	ft_handle_specifier(char specifier, va_list args);
int	ft_printf(const char *str, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:50:04 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/02 20:52:53 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
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

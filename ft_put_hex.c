/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:55:21 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/02 20:57:45 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char format)
{
	int		count;
	char	*hex;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_put_hex(n / 16, format);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

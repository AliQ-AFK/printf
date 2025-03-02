/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:54:07 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/02 20:54:53 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_put_hex(ptr, 'x');
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:30:06 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/23 14:45:39 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_convhex(unsigned int c, int t)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	if (t)
		str1 = str2;
	if (c < 16)
		return (ft_putchar(str1[c]));
	i = ft_convhex(c / 16, t);
	ft_convhex(c % 16, t);
	return (i + 1);
}

int	ft_pointer(void *p)
{
	write(1, "0x", 2);
	return (2 + ft_convhex((unsigned int)p, 0));
}

int	ft_match(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_convhex(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_convhex(va_arg(ap, unsigned int), 1));
	else if (c == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	return (0);
}

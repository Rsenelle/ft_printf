/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:30:06 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/26 19:35:33 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_convhex(unsigned int c, char *str)
{
	int		i;

	if (c < 16)
		return (ft_putchar(str[c]));
	i = ft_convhex(c / 16, str);
	ft_convhex(c % 16, str);
	return (i + 1);
}

int	ft_convhex_p(unsigned long int c, char *str)
{
	int		i;

	if (c < 16)
		return (ft_putchar(str[c]));
	i = ft_convhex_p(c / 16, str);
	ft_convhex_p(c % 16, str);
	return (i + 1);
}

int	ft_pointer(void *p)
{
	write(1, "0x", 2);
	return (2 + ft_convhex_p((unsigned long int)p, HEX16_S));
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
		return (ft_convhex(va_arg(ap, unsigned int), HEX16_S));
	else if (c == 'X')
		return (ft_convhex(va_arg(ap, unsigned int), HEX16_B));
	else if (c == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	return (0);
}

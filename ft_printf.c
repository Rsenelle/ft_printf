/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:34:49 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/23 14:43:31 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		res;

	i = -1;
	res = 0;
	va_start (ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			res += ft_match(s[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			res++;
		}
	}
	va_end(ap);
	return (res);
}

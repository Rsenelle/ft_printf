/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:41:27 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/23 13:15:28 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	char	s;
	int		i;

	if (n < 10)
	{
		s = n + '0';
		write(1, &s, 1);
		return (1);
	}
	else
	{
		i = ft_unsigned_putnbr(n / 10);
		ft_unsigned_putnbr(n % 10);
	}
	return (i + 1);
}

int	ft_putnbr(int n)
{
	char	s;
	int		kol;

	kol = ft_lenn(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_putnbr(n);
	}
	else if (n < 10)
	{
		s = n + '0';
		write(1, &s, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (kol);
}

size_t	ft_strlen(const char *s)
{
	size_t	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}

int	ft_lenn(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

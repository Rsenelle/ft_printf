/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:56:50 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/23 14:39:52 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_pointer(void *p);
int		ft_match(char conv, va_list ap);
int		ft_printf(const char *s, ...);
int		ft_convhex(unsigned int c, int t);
int		ft_putchar(char c);
int		ft_lenn(int n);
size_t	ft_strlen(const char *s);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_strdup(const char *s1);

#endif

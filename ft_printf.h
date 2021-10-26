/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:56:50 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/26 19:35:08 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define HEX16_S "0123456789abcdef"
# define HEX16_B "0123456789ABCDEF"

int		ft_pointer(void *p);
int		ft_match(char conv, va_list ap);
int		ft_printf(const char *s, ...);
int		ft_convhex(unsigned int c, char *str);
int		ft_putchar(char c);
int		ft_lenn(int n);
size_t	ft_strlen(const char *s);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_strdup(const char *s1);
int		ft_convhex_p(unsigned long int c, char *str);

#endif

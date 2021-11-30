/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:56:01 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/30 20:38:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char c)
{
	unsigned long	i;
	char			*base;
	int				size;

	i = n;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i >= 16)
		ft_puthexa(i / 16, c);
	ft_putchar(base[i % 16]);
	size = 0;
	if (n == 0)
		size += 1;
	i = n;
	if (n < 0)
		i *= -1;
	size = ft_count(size, i, 16);
	return (size);
}

int	ft_putaddress(unsigned long n)
{
	int	size;

	ft_putstr("0x");
	size = 2;
	size += ft_puthexa(n, 'x');
	return (size);
}

int	ft_count(int size, unsigned long i, int base)
{
	while (i > 0)
	{
		i /= base;
		size++;
	}
	return (size);
}

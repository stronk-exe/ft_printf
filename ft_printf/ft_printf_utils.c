/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:24 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/30 02:16:46 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putprc(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_putstr(char	*s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	i;
	int			size;

	i = n;
	size = 0;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
		size++;
	}
	if (i / 10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar((i % 10) + '0');
	if (n == 0)
		size += 1;
	if (n < 0)
	{
		i = n;
		i *= -1;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	i;
	int				size;

	i = n;
	if (i / 10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar((i % 10) + '0');
	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_puthexaup(unsigned long n, char c)
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
		ft_puthexaup(i / 16, c);
	ft_putchar(base[i % 16]);
	size = 0;
	if (n == 0)
		size += 1;
	if (n < 0)
	{
		i = n;
		i *= -1;
	}
	while (i > 0)
	{
		i /= 16;
		size++;
	}
	return (size);
}

int	ft_putaddress(unsigned long n)
{
	int	size;

	ft_putstr("0x");
	size = 2;
	size += ft_puthexaup(n, 'x');
	return (size);
}

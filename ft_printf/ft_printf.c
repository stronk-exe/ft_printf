/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:26:47 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/30 02:17:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char c, va_list lst)
{
	if (c == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(lst, unsigned int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(lst, int)));
	else if (c == 'X' || c == 'x')
		return (ft_puthexaup(va_arg(lst, unsigned int), c));
	else if (c == 'p')
		return (ft_putaddress(va_arg(lst, unsigned long)));
	else if (c == '%')
		return (ft_putprc());
	else
		return (0);
}

int	ft_printf(const	char	*s, ...)
{
	va_list	lst;
	int		size;
	int		i;

	i = 0;
	size = 0;
	va_start(lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += check_arg(s[i + 1], lst);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			size++;
			i++;
		}
	}
	va_end(lst);
	return (size);
}

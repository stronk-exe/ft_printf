/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:39 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/30 20:36:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const	char	*s, ...);
int	ft_putchar(char c);
int	ft_putprc(void);
int	ft_putstr(char	*s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_putint(int n);
int	ft_puthexa(unsigned long n, char c);
int	ft_putaddress(unsigned long n);
int	ft_count(int size, unsigned long i, int base);

#endif

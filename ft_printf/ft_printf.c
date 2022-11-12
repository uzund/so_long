/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:46:30 by duzun             #+#    #+#             */
/*   Updated: 2022/11/12 13:44:42 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int	ft_bicim(char c, va_list arg)
{
	int	val;

	val = 0;
	if (c == '%')
		val += write(1, "%", 1);
	else if (c == 'c' )
		val += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		val += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		val += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		val += ft_putnbru(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		val += ft_putnbrx(va_arg(arg, int), c);
	else if (c == 'p')
	{
		val += write(1, "0x", 2);
		val += ft_putp(va_arg(arg, unsigned long int));
	}
	return (val);
}

int	ft_printf(const char *str, ...)
{
	int		val;
	int		i;
	va_list	arg;

	va_start(arg, str);
	val = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			val += ft_bicim(str[++i], arg);
			i++;
		}
		else
			val += ft_putchar(str[i++]);
	}
	va_end(arg);
	return (val);
}

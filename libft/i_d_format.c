/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:14:12 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 00:14:34 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(long nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		l = 1;
	else if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static	char	*ft_itoa(int num)
{
	long	nb
	char	*string;
	int		i;

	nb = num;
	i = len(nb);
	string = (char *)malloc (sizeof(char) * (len(nb) + 1));
	if (!string)
		return (NULL);
	string[i--] = '\0';
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		string[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		string[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (string);
}

void	i_d_format(t_printf *tab)
{
	char	*str;
	long	num;

	num = va_arg(tab->args, int);
	str = ft_itoa(num);
	tab->length += write(1, str, ft_strlen(str));
	free (str);
}

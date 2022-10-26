/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:01:10 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 00:01:13 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_len(long nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		l = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static	char	*u_itoa(unsigned int n)
{
	long	nb;
	char	*string;
	int		i;

	nb = n;
	i = u_len(nb);
	string = (char *)malloc (sizeof(char) * (u_len(nb) + 1));
	if (!string)
		return (NULL);
	string[i--] = '\0';
	if (nb == 0)
		string[0] = '0';
	while (nb > 0)
	{
		string[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (string);
}

void	u_format(t_printf *tab)
{
	unsigned int	u;
	char			*str;

	u = va_arg(tab->args, unsigned int);
	str = u_itoa(u);
	tab->length += write(1, str, ft_strlen(str));
	free (str);
}

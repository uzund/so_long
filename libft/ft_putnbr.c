/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:48:21 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:36:32 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	int		len;
	char	*str;
	long	num;

	len = ft_nbrlen(nbr);
	num = nbr;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num = -1 * num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num = num / 10;
	}
	ft_putstr(str);
	free(str);
	return (ft_nbrlen(nbr));
}

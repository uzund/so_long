/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:59:43 by duzun             #+#    #+#             */
/*   Updated: 2022/10/28 12:18:46 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrx(unsigned int nbrx, char c)
{
	int	val;

	val = 0;
	if (nbrx == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (nbrx >= 16)
		val += ft_putnbrx(nbrx / 16, c);
	if (c == 'x')
		val += ft_putchar("0123456789abcdef"[nbrx % 16]);
	else
		val += ft_putchar("0123456789ABCDEF"[nbrx % 16]);
	return (val);
}


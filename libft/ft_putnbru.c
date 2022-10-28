/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:51:39 by duzun             #+#    #+#             */
/*   Updated: 2022/10/28 11:51:53 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbru(unsigned int nbru)
{
	int	val;

	val = 0;
	if (nbru == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (nbru >= 10)
		val += ft_putnbru(nbru / 10);
	val += ft_putchar("0123456789"[nbru % 10]);
	return (val);
}

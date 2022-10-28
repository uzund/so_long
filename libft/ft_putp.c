/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:46:57 by duzun             #+#    #+#             */
/*   Updated: 2022/10/28 12:47:13 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putp(unsigned long int nbrp)
{
	int	val;

	if (nbrp == '\0')
	{
		write(1, "0", 1);
		return (1);
	}
	val = 0;
	if (nbrp >= 16)
		val += ft_putp(nbrp / 16);
	val += ft_putchar("0123456789abcdef"[nbrp % 16]);
	return (val);
}

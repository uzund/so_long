/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:50:22 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:08:48 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Verilen *str stringi tarar space ve özel karakterleri geçer, tek eksi görme
// durumunda sayı negatif olarak takip edip eden sayıyı tespit eder.
// char verilen sayiları int bir değere ddönüştürür.

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\f'
			|| *(str + i) == '\v' || *(str + i) == '\r') || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i = i + 1;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = (*(str + i) - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}

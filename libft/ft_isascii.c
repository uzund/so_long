/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:30:28 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:09:12 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Fonksiyona c değişkeni ile gönderilen değer 0 il1 127 arasında bir değer ise
// 1 değilse 0 döndürür.
// #include <stdio.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	int	x;

	x = 127;
	printf("girilen değer 0 ile 127 arasındaysa 1 değilse 0 yaz:%d\n", \
		ft_isascii(x));
	return (0);
}
*/

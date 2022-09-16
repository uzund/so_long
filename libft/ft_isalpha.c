/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:38:56 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:09:09 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
int	main(void)
{
	int	c;
	int	x;

	c = '0';
	x = ft_isalpha(c);
	if (x == 1)
		printf("c değişkeni alfabatik bir değerdir. dönen değer:%d\n",x);
	else
		printf("alfabetik olmayan bir değer girildi. dönen değer %d\n",x);
	return (0);
}
*/

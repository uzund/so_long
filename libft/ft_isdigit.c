/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:41:37 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:09:23 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Bu fonsiyon c değişkeninin değeri rakamsa 1 değilse 0 döndürür.
// #include <stdio.h> 

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
int	main(void)
{
	int	x;

	x = 55;
	printf("değer rakam ise 1 yazar :%d\n", ft_isdigit(x));
}
*/

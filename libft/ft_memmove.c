/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:50:09 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:12 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// Bu fonksiyon bir gösterici *src ile gösterilen hafıza alanından "n" byte'lık 
//veriyi *dest ile gösterilen hafıza alanına taşır.dest göstericisini döndürür

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}
/*
int	main(void)
{
	char str1[] = "Davut UZUN";
	char str2[] = "42 Okul";

	ft_memmove (str2,str1,5);
	printf("str2 değişkenin değeri '42 Okul' iken değişmiş son hali:%s\n",str2);
	return (0);
}
*/

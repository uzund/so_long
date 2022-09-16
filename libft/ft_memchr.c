/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:12:22 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:00 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// Bu fonksiyon *s ile gösterilen hafıza alanının ilk "n" byte'lık veri 
// araştırması yapar. Aranan veri bulunursa ilk bulduğu yerin adresini,
// bulamazsa NULL değeri döndürür.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str[] = "Davut UZUN";
	char *str2;

	str2 = ft_memchr (str,'U',sizeof(str));
	printf("str değişkenin içinde 'U' arar ve bulunan adresi döndürür :%s\n",str2);
	return (0);
}
*/

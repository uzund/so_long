/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:51:36 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:01 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// "n" uzunluğu kadar *src dizgisinden *dest alanına yazar.
// *src uzunluk değerini döndürür.

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (*(src + i) && i < n - 1)
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char str1[] = "Davut UZUN";
	char str2[] = "42 Okul";
	int rtn;

	rtn = ft_strlcpy (str1,str2,5);
	printf("kopyalama işleminden sonra str2 değişkenin değerinin '42 Okul' \
	uzunluğunu döndürür :%i\n",rtn);
		return (0);
}
*/

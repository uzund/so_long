/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:01:47 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:05 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "stdio.h"

// Bu fonksiyon *s1 ve *s2 göstericilerin ilk "n" byte'lık verinin sayısal
// karşılaştırmasını yapar. Eşitlik durumda "0" sıfır, s1 büyük ise 1 pozitif
// s2 büyük ise -1 negatif sayı döndürür.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str[] = "Davut UZUN";
	char str2[] = "Davut GUZEL";
	int 	rtn;
	char dz1[] = {1, 2, 3, 4,};
	char dz2[] = {1, 2, 3, 4, 5, 6};

	rtn = 0;
	rtn = ft_memcmp(dz1,dz2,6);
	if (rtn < 0)
		 printf("dz1, dz2'den küçük : %d\n",rtn);
	else if (rtn > 0)
		printf("dz1, dz2'den büyük : %d\n",rtn);
	else
		printf("dz1 ile dz2 eşit : %d\n",rtn);
	rtn = 0;
	rtn = ft_memcmp (str, str2,sizeof(str));
	printf("str ve str2 dizgilerinin karşılaştırma sonucu : %d\n",rtn);
	return (0);
}
*/

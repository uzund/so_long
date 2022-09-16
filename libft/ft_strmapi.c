/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:25:18 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:10 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>  // main dosyası için gerekli

// s string dizisinin her sitringi için f alt fonksiyonu uygulanir.
// degistirilmis string geri dondurulur.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;

	if (!s)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = 0;
	return (str);
}

// main başlangıcı
/*

char	test_f(unsigned int i, char str)
{
	printf("İç işlev: index = %d ve %c\n", i, str);
	return (str - 32);
}

int	main(void)
{
	char str[10] = "davut.";
	printf("%s için iç işlemler\n", str);
	char *result = ft_strmapi(str, test_f);
	printf("Sonuç : %s\n", result);
	return (0);
}
*/
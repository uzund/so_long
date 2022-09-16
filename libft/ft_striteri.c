/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:16:08 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:51 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h> // main dosyası için gerekli.

// f işlevini s dizgisinin her karakterine uygular.
// herhangi bir değer döndürülmez.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	if (s && *s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// main başlangıcı
/*
void	test_f(unsigned int i, char *str)
{
	printf("İç fonsiyon index : %d değer: %s\n", i, str);
}

int	main(void)
{
	char str[10] = "Davut.";
	printf("%s için sonuçlar\n", str);
	ft_striteri(str, test_f);
	printf("%s için sonuçlar\n", str);
	return (0);
}
*/
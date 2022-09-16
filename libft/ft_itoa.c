/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:54:23 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:09:30 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>  // main dosyası için gerekli.
//#include <limits.h> // main dosyası için gerekli.
//#include <stdlib.h> // main dosyası için gerekli.

// n ile verilen integer degeri string olarak döndürür.

int	mutlak_deger(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_count(n);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		--len;
		str[len] = mutlak_deger(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

/*
int	main(void)
{
	int	d = INT_MIN;
	printf("%d =? %s\n", d, ft_itoa(d));
	d = -13;
	printf("%d =? %s\n", d, ft_itoa(d));

	d = 0;
	printf("%d =? %s\n", d, ft_itoa(d));

	d = 5;
	printf("%d =? %s\n", d, ft_itoa(d));

	d = INT_MAX;
	printf("%d =? %s\n", d, ft_itoa(d));
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:45:13 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:43 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s1 string uzunlugu kadar hafizada yer acar ve s1 icerigini oraya kopyalar
// herzaman NUL ile sonlandirilir. Yeni hafiza icerigini dondurur.
// Yeterli bellek yoksa NULL dondurulur.

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

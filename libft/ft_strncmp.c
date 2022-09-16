/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:51:04 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:13 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Bu fonsiyon *s1 ve *s2 dizgisini "n" byte kadar karşılaştırır. 
// ilk farklı strigde ascii değerleri birbirinden  çıkarır ve bu değeri
// döndürür. Eğer değer pozitif ise s1 büyük negatif ise s2 büyüktür.
// n = 0 ise karşılaştırma yapılmaz '0' döndürülür.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0'
		&& i < n - 1)
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:54:27 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:27 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s stringi ile verilen dizinin iceriginden, start ile belirtilen konumdan
// len ile belirtilen uzunluk miktarini dondurur.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_strlen(s);
	if (start >= count)
		return (ft_strdup(""));
	if (count < len)
		len = count;
	dst = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dst)
		return (NULL);
	i = start;
	j = 0;
	while (i < count && j < len)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}

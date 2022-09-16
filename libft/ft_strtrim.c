/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:30:05 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:23 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s1 string ile verilen değerden *set ile verilen karakterler baştan ve
// sondan kırpılır. Elde edilen yeni string döndürülür.. 
// Eğer allocation hatasin verirse NULL döndürür.

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

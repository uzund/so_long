/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:13:27 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:58 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//
//

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = ft_strlen(s1);
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n <= s1_len)
		return (s2_len + n);
	while (*(s2 + j) && i < n - 1)
	{
		*(s1 + i) = *(s2 + j);
		i++;
		j++;
	}
	*(s1 + i) = '\0';
	if (n < s1_len)
		return (s2_len + n);
	else
		return (s1_len + s2_len);
}

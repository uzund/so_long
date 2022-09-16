/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:52:54 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:40 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *s göstericisi ile gösterilen dizgi için de c değişkeni arar bulduğu
// konumdan sonrasını döndürür.

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

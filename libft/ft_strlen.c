/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:38:42 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:12:06 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// s ile verilen stringin uzunluğunu bulur.
//#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

/*
int	main(void)
{
	const char	s[11] = "Davut Uzun";
	printf("s değişkeni %ld karakter uzunluğundadır.\n", ft_strlen(s));
	return (0);
}
*/

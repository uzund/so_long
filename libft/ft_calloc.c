/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:27:05 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:08:58 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// count ile belirtilen dizgiler icin size ile belirtilen boyut kadar hafızada
// yer tahsis edilir. Bu hafıza alanı 0 ile doldurulur.
// geriye bu alanın icerigi dondurulur.

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
int	main(void)
{
	char	*c = ft_calloc(2, 1);
	char	x[3] = {'a', 'b', 'c'};

	printf("%s\n", c);
	c = x;
	printf("%s\n", c);
	return (0);
}
*/
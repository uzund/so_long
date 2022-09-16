/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:08:03 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:09 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// bu fonsiyon bir gösterici *src ile gösterilen hafıza alanındaki ilk "n"
// byte'lık veriyi başka bir gösterici *dest ile gösterilen hafıza alanına kopy.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((const char *)src + n);
	return (dest);
}
/*
int	main(void)
{
  char str1[] = "Davut UZUN";
  char str2[] = "42 Okul";

  ft_memcpy (str2,str1,3);
  printf("str2 değişkenin değeri '42 Okul' iken değişmiş son hali:%s\n",str2);
  return (0);
}
*/

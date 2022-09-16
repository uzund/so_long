/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:40:00 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:15 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// Bu fonksiyon ile gösterilen *s hafıza alanının ilk "n" byte'lık kısmına
// istenen verinin yazılması sağlanır.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = (unsigned char)c;
	return (s);
}
/*
int	main(void)
{
	char	str[] = "davut";
	ft_memset(str, 'm', 1); 
	// str dizgisinin ilk elemanına ft_memset fonksiyonu ile 
	 // 'm' karakteri atanmıştır. Dizi "mavut" şekline döner 
	printf("str dizisinin son hali: %s\n",str);
	printf("str dizgisini 'D' ile doldurulduktan sonraki hali : %s\n",
		(char *)ft_memset(str, 'D', sizeof(str)));
	// str dizisinin tüm elemanlarına 'D' karakteri atanmıştır.
	return (0);
}
*/

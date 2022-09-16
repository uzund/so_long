/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:47:20 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:08:53 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "stdio.h"
// Bu fonksiyon ile gösterilen *s hafıza alanının ilk "n" byte'lık kısmına
// NULL '0' (sıfır) yazılması sağlanır.

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = '\0';
}
/*
int	main(void)
{
	char	str[] = "davut uzun";
	ft_bzero(str, 2); // 0 dan farklı bir değer girilirse çıktı alınamaz!!
	// str dizgisinin ilk elemanına ft_memset fonksiyonu ile 
 	// 'm' karakteri atanmıştır. Dizi "mavut" şekline döner 
	printf("str dizisinin son hali: %s\n",str);
	return (0);
}
*/

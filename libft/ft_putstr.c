/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:35:26 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:36:08 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	char	*ptr;

	if (str)
	{
		ptr = (char *) str;
		while (*ptr)
			ptr += 1;
		write(1, str, (ptr - str));
		return (ptr - str);
	}
	else
		write(1, "(null)", 6);
	return (6);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:00:54 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 00:00:59 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_base(unsigned long nb, int base)
{
	int	size;

	size = 0;
	if (nb == 0)
	{
		size += 1;
		return (size);
	}
	while (nb > 0)
	{
		size++;
		nb /= base;
	}
	return (size);
}

static char	*ft_itoa_base(unsigned long nb, unsigned int base)
{
	char	*str;
	char	*characters;
	int		size;

	characters = ft_strdup("0123456789abcdef");
	str = NULL;
	size = ft_numlen_base(nb, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size--] = characters[nb % base];
		nb /= base;
	}
	free(characters);
	return (str);
}

void	p_format(t_printf *tab)
{
	unsigned long	pointer;
	char			*str;

	pointer = (unsigned long) va_arg(tab->args, void *);
	if (pointer == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base(pointer, 16);
	tab->length += write(1, "0x", 2);
	if (pointer == 0)
		tab->length += write(1, "0", 1);
	tab->length += write(1, str, ft_strlen(str));
	free(str);
}

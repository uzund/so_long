/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:05:59 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 00:06:02 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_base(unsigned int nb, int base)
{
	int	size;

	size = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= base;
		size++;
	}
	return (size);
}

static char	*ft_itoa_base_x(unsigned int nb, int base, int index)
{
	char	*str;
	char	*numbers;
	int		size;

	if (!index)
		numbers = ft_strdup("0123456789abcdef");
	else
		numbers = ft_strdup("0123456789ABCDEF");
	str = NULL;
	size = ft_numlen_base(nb, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size--] = numbers[nb % base];
		nb /= base;
	}
	free(numbers);
	return (str);
}

void	x_format(t_printf *tab, int index)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(tab->args, unsigned int);
	if (!index)
		str = ft_itoa_base_x(nb, 16, 0);
	else
		str = ft_itoa_base_x(nb, 16, 1);
	tab->length += write(1, str, ft_strlen(str));
	free(str);
}

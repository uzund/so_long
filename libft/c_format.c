/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:56:13 by duzun             #+#    #+#             */
/*   Updated: 2022/10/26 23:56:14 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

void	c_format(t_printf *tab, int index)
{
	char	c;

	if (index)
		c = '%';
	else
		c = va_arg(tab->args, int);
	tab->length += write(1, &c, 1);
}

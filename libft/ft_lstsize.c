/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 03:48:41 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:57 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* bagli listedeki eleman sayisini bulur.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst != NULL)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

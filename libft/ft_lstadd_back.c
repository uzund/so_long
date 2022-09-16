/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:01:12 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:34 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* bagli listenin sonuna "new" elamanını ekler.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:34:13 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:47 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* 'lst' listesinin uzerinde dolanır ve 'f' fonksiyonunu listenin her elemanina 
* uygular.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

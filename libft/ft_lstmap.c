/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:41:15 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:51 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* 'lst' listesini yineler ve her elemanin icerigine 'f' islevini uygular.
* 'f' fonksiyonunun ardisik uygulamalarinin sonucunda yeni bir liste olusturur.
* 'del' islevi, gerekirse bir elemanin icerigini silmek icin kullanilir.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (lst == NULL)
		return (NULL);
	new_list = 0;
	while (lst != NULL)
	{
		new_element = ft_lstnew(f(lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_element, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

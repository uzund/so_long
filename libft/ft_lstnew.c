/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:23:24 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:54 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* malloc ile yeni bir bagli liste tesis edilir. content ile ilk elemanı 
* content'e yerleştirilir next yani sonraki eleman NULL olarak ayarlandi. 
* Son eleman herzaman NULL dur.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int	main(void)
{
	t_list	*lst;
	int		a = 5667547;

	lst = ft_lstnew("icerik");
	lst->next = ft_lstnew(&a);
	printf("%s\n", lst->content);
	printf("%i\n", *(int *)(lst->next->content));
	return (0);
}
*/

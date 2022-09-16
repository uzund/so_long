/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:10:39 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:10:44 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Bir elemani parametre olarak alir ve parametre olarak verilen 'del' 
* islevini kullanarak elamanin iceriginin bellegini bosaltir ve elemani 
* serbest birakir. 'Sonraki' hafizasi serbest birakilmamalidir.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

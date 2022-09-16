/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:45:28 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:28 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *s ile verilen stringleri fd ile belirtilen yere yazar (ekran, dosya vb.)

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

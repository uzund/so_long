/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:56:56 by duzun             #+#    #+#             */
/*   Updated: 2022/08/31 19:11:21 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s ile verilen strigleri fd ile belirtilen tanımlayıcıya (ekran, dasya vb.)
// yazar ardından yeni satıra geçer.

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:27 by duzun             #+#    #+#             */
/*   Updated: 2022/11/14 00:21:02 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_border(t_game *oyun)
{
	int	i;

	if (oyun->height >= 27)
		exit_error("Geçersiz Harita: Haritanın yüksekliği çok fazla.\n\
Invalid Map: The height of the map is too high", 0);
	if (oyun->width >= 48)
		exit_error("Geçersiz Harita: Haritanın genişliği çok fazla.\n\
Invalid Map: The width of the map is too large.", 0);
	i = -1;
	while (++i < oyun->height)
	{
		if (oyun->map[i][0] != '1' || oyun->map[i][oyun->width -1] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
	i = -1;
	while (oyun->map[0][++i])
	{
		if (oyun->map[0][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
	i = -1;
	while (oyun->map[oyun->height][++i])
	{
		if (oyun->map[oyun->height][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
}

static void	check_char(t_game *oyun)
{
	int	i;
	int	j;

	i = -1;
	while (oyun->map[++i])
	{
		j = -1;
		while (oyun->map[i][++j])
		{
			if (oyun->map[i][j] == 'C')
				oyun->c++;
			if (oyun->map[i][j] == 'E')
				oyun->e++;
			if (oyun->map[i][j] == 'P')
				oyun->p++;
		}
	}
	if (!oyun->c)
		exit_error("Geçersiz harita: Toplanacak öge yok.\n\
Invalid map: No items to collect.", 0);
	if (oyun->e != 1)
		exit_error("Geçersiz harita: Çıkış yok yada birden fazla.\n\
Invalid map: No exit or more than one.", 0);
	if (oyun->p != 1)
		exit_error("Geçersiz harita: Oyuncu yok yada birden fazla.\n\
Invalid map: No or more than one player.", 0);
}

void	check_map(t_game *oyun)
{
	check_border(oyun);
	check_char(oyun);
	init_matrix(oyun);
}

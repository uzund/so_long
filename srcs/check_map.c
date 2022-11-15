/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:27 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:17:12 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_border(t_game *gamyun)
{
	int	i;

	if (gamyun->height >= 27)
		exit_error("Geçersiz Harita: Haritanın yüksekliği çok fazla.\n\
Invalid Map: The height of the map is too high", 0);
	if (gamyun->width >= 48)
		exit_error("Geçersiz Harita: Haritanın genişliği çok fazla.\n\
Invalid Map: The width of the map is too large.", 0);
	i = -1;
	while (++i < gamyun->height)
	{
		if (gamyun->map[i][0] != '1' || gamyun->map[i][gamyun->width -1] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
	i = -1;
	while (gamyun->map[0][++i])
	{
		if (gamyun->map[0][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
	i = -1;
	while (gamyun->map[gamyun->height][++i])
	{
		if (gamyun->map[gamyun->height][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.", 0);
	}
}

static void	check_char(t_game *gamyun)
{
	int	i;
	int	j;

	i = -1;
	while (gamyun->map[++i])
	{
		j = -1;
		while (gamyun->map[i][++j])
		{
			if (gamyun->map[i][j] == 'C')
				gamyun->c++;
			if (gamyun->map[i][j] == 'E')
				gamyun->e++;
			if (gamyun->map[i][j] == 'P')
				gamyun->p++;
		}
	}
	if (!gamyun->c)
		exit_error("Geçersiz harita: Toplanacak öge yok.\n\
Invalid map: No items to collect.", 0);
	if (gamyun->e != 1)
		exit_error("Geçersiz harita: Çıkış yok yada birden fazla.\n\
Invalid map: No exit or more than one.", 0);
	if (gamyun->p != 1)
		exit_error("Geçersiz harita: gamyuncu yok yada birden fazla.\n\
Invalid map: No or more than one player.", 0);
}

void	check_map(t_game *gamyun)
{
	check_border(gamyun);
	check_char(gamyun);
	init_matrix(gamyun);
}

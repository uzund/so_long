/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:56 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 10:25:07 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_game *gamyun)
{
	int	height;
	int	width;

	height = (gamyun->height + 1) * 53;
	width = gamyun->width * 53;
	gamyun->mlx = mlx_init();
	gamyun->mlx_win = mlx_new_window(gamyun->mlx, width, height, "SO_LONG \
	[DAVUT UZUN] [42istanbul]");
	gamyun->mlx_img = mlx_new_image(gamyun->mlx, width, height);
	if (gamyun->mlx == 0 || gamyun->mlx_win == 0 || gamyun->mlx_img == 0)
	{
		free_all(gamyun);
		exit_error(gamyun, "Hata!: Görüntü başlatma başarısız oldu.\n\
		Error!: Image initialization failed.", 0);
	}
}

static void	init_images(t_game *gamyun)
{
	put_image(gamyun, &gamyun->player, "./img/player_on.xpm");
	put_image(gamyun, &gamyun->cikis, "./img/cikis.xpm");
	put_image(gamyun, &gamyun->hediye, "./img/hediye.xpm");
	put_image(gamyun, &gamyun->duvar, "./img/duvar.xpm");
	put_image(gamyun, &gamyun->zemin, "./img/zemin.xpm");
}

static void	init_item(t_game *gamyun, void *item, int i, int j)
{
	if (item == gamyun->player)
	{
		gamyun->player_x = i;
		gamyun->player_y = j;
		mlx_put_image_to_window(gamyun->mlx, gamyun->mlx_win, \
			item, i * 53, j * 53);
	}
	else
		mlx_put_image_to_window(gamyun->mlx, gamyun->mlx_win, \
			item, i * 53, j * 53);
}

int	init_map(t_game *gamyun)
{
	int	i;
	int	j;

	j = -1;
	while (gamyun->map[++j])
	{
		i = -1;
		while (gamyun->map[j][++i])
		{
			if (gamyun->map[j][i] == 'E')
				init_item(gamyun, gamyun->cikis, i, j);
			if (gamyun->map[j][i] == '1')
				init_item(gamyun, gamyun->duvar, i, j);
			if (gamyun->map[j][i] == 'C')
				init_item(gamyun, gamyun->hediye, i, j);
			if (gamyun->map[j][i] == 'P')
				init_item(gamyun, gamyun->player, i, j);
			if (gamyun->map[j][i] == '0')
				init_item(gamyun, gamyun->zemin, i, j);
		}
	}
	return (0);
}

void	so_long(t_game *gamyun)
{
	init_window(gamyun);
	init_images(gamyun);
	init_map(gamyun);
	mlx_hook(gamyun->mlx_win, 2, 1L << 0, keypress, gamyun);
	mlx_hook(gamyun->mlx_win, 17, 1L << 17, free_all_exit, gamyun);
	mlx_hook(gamyun->mlx_win, 9, 1L << 21, init_map, gamyun);
	mlx_loop(gamyun->mlx);
}

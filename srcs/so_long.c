/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:56 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 22:11:21 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_game *oyun)
{
	int	height;
	int	width;

	height = (oyun->height + 1) * 40;
	width = oyun->width * 40;
	oyun->mlx = mlx_init();
	oyun->mlx_win = mlx_new_window(oyun->mlx, width, height, "SO_LONG [DAVUT UZUN] [42istanbul]");
	oyun->mlx_img = mlx_new_image(oyun->mlx, width, height);
	if (oyun->mlx == 0 || oyun->mlx_win == 0 || oyun->mlx_img == 0)
	{
		free_all(oyun);
		exit_error("Hata!: Görüntü başlatma başarısız oldu.", 0);
	}
}

static void	init_images(t_game *oyun)
{
	put_image(oyun, &oyun->player, "./img/player_front.xpm");
	put_image(oyun, &oyun->pikachu, "./img/pikachu.xpm");
	put_image(oyun, &oyun->pokeball, "./img/pokeball.xpm");
	put_image(oyun, &oyun->grass, "./img/grass.xpm");
	put_image(oyun, &oyun->ground, "./img/ground.xpm");
}

static void	init_item(t_game *oyun, void *item, int i, int j)
{
	if (item == oyun->player)
	{
		oyun->player_x = i;
		oyun->player_y = j;
		mlx_put_image_to_window(oyun->mlx, oyun->mlx_win, \
			item, i * 40, j * 40);
	}
	else
		mlx_put_image_to_window(oyun->mlx, oyun->mlx_win, \
			item, i * 40, j * 40);
}

int	init_map(t_game *oyun)
{
	int	i;
	int	j;

	j = -1;
	while (oyun->map[++j])
	{
		i = -1;
		while (oyun->map[j][++i])
		{
			if (oyun->map[j][i] == 'E')
				init_item(oyun, oyun->pikachu, i, j);
			if (oyun->map[j][i] == '1')
				init_item(oyun, oyun->grass, i, j);
			if (oyun->map[j][i] == 'C')
				init_item(oyun, oyun->pokeball, i, j);
			if (oyun->map[j][i] == 'P')
				init_item(oyun, oyun->player, i, j);
			if (oyun->map[j][i] == '0')
				init_item(oyun, oyun->ground, i, j);
		}
	}
	return (0);
}

void	so_long(t_game *oyun)
{
	init_window(oyun);
	init_images(oyun);
	init_map(oyun);
	mlx_hook(oyun->mlx_win, 2, 1L << 0, keypress, oyun);
	mlx_hook(oyun->mlx_win, 17, 1L << 17, free_all_exit, oyun);
	mlx_hook(oyun->mlx_win, 9, 1L << 21, init_map, oyun);
	mlx_loop(oyun->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <ditko73@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:56 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 19:28:20 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_param *param)
{
	int	height;
	int	width;

	height = (param->height + 1) * 40;
	width = param->width * 40;
	param->mlx = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx, width, height, "SO_LONG [DAVUT UZUN] [42istanbul]");
	param->mlx_img = mlx_new_image(param->mlx, width, height);
	if (param->mlx == 0 || param->mlx_win == 0 || param->mlx_img == 0)
	{
		free_all(param);
		exit_error("Hata!: Görüntü başlatma başarısız oldu.", 0);
	}
}

static void	init_images(t_param *param)
{
	put_image(param, &param->player, "./img/player_front.xpm");
	put_image(param, &param->pikachu, "./img/pikachu.xpm");
	put_image(param, &param->pokeball, "./img/pokeball.xpm");
	put_image(param, &param->grass, "./img/grass.xpm");
	put_image(param, &param->ground, "./img/ground.xpm");
}

static void	init_item(t_param *param, void *item, int i, int j)
{
	if (item == param->player)
	{
		param->player_x = i;
		param->player_y = j;
		mlx_put_image_to_window(param->mlx, param->mlx_win, \
			item, i * 40, j * 40);
	}
	else
		mlx_put_image_to_window(param->mlx, param->mlx_win, \
			item, i * 40, j * 40);
}

int	init_map(t_param *param)
{
	int	i;
	int	j;

	j = -1;
	while (param->map[++j])
	{
		i = -1;
		while (param->map[j][++i])
		{
			if (param->map[j][i] == 'E')
				init_item(param, param->pikachu, i, j);
			if (param->map[j][i] == '1')
				init_item(param, param->grass, i, j);
			if (param->map[j][i] == 'C')
				init_item(param, param->pokeball, i, j);
			if (param->map[j][i] == 'P')
				init_item(param, param->player, i, j);
			if (param->map[j][i] == '0')
				init_item(param, param->ground, i, j);
		}
	}
	return (0);
}

void	so_long(t_param *param)
{
	init_window(param);
	init_images(param);
	init_map(param);
	mlx_hook(param->mlx_win, 2, 1L << 0, keypress, param);
	mlx_hook(param->mlx_win, 17, 1L << 17, free_all_exit, param);
	mlx_hook(param->mlx_win, 9, 1L << 21, init_map, param);
	mlx_loop(param->mlx);
}

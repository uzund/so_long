/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:45 by duzun             #+#    #+#             */
/*   Updated: 2022/10/28 02:26:22 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_img(t_game *oyun, char c)
{
	mlx_clear_window(oyun->mlx, oyun->mlx_win);
	mlx_destroy_image(oyun->mlx, oyun->player);
	if (c == 'u')
		put_image(oyun, &oyun->player, "./img/player_arka.xpm");
	if (c == 'r')
		put_image(oyun, &oyun->player, "./img/player_sag.xpm");
	if (c == 'l')
		put_image(oyun, &oyun->player, "./img/player_sol.xpm");
	if (c == 'd')
		put_image(oyun, &oyun->player, "./img/player_on.xpm");
}

int	move_up(t_game *oyun)
{
	int	x;
	int	y;

	oyun->player_y--;
	x = oyun->player_x;
	y = oyun->player_y;
	change_player_img(oyun, 'u');
	if (oyun->map[y][x] == '0' || oyun->map[y][x] == 'C')
	{
		if (oyun->map[y][x] == 'C')
			oyun->c--;
		oyun->map[y][x] = 'P';
		oyun->map[y + 1][x] = '0';
		init_map(oyun);
		return (1);
	}
	if (oyun->map[y][x] == 'E' && oyun->c == 0)
	{
		oyun->map[y + 1][x] = '0';
		oyun->success = 1;
		free_all_exit(oyun);
	}
	oyun->player_y++;
	init_map(oyun);
	return (0);
}

int	move_down(t_game *oyun)
{
	int	x;
	int	y;

	oyun->player_y++;
	x = oyun->player_x;
	y = oyun->player_y;
	change_player_img(oyun, 'd');
	if (oyun->map[y][x] == '0' || oyun->map[y][x] == 'C')
	{
		if (oyun->map[y][x] == 'C')
			oyun->c--;
		oyun->map[y][x] = 'P';
		oyun->map[y - 1][x] = '0';
		init_map(oyun);
		return (1);
	}
	if (oyun->map[y][x] == 'E' && oyun->c == 0)
	{
		oyun->map[y - 1][x] = '0';
		oyun->success = 1;
		free_all_exit(oyun);
	}
	oyun->player_y--;
	init_map(oyun);
	return (0);
}

int	move_left(t_game *oyun)
{
	int	x;
	int	y;

	oyun->player_x--;
	x = oyun->player_x;
	y = oyun->player_y;
	change_player_img(oyun, 'l');
	if (oyun->map[y][x] == '0' || oyun->map[y][x] == 'C')
	{
		if (oyun->map[y][x] == 'C')
			oyun->c--;
		oyun->map[y][x] = 'P';
		oyun->map[y][x + 1] = '0';
		init_map(oyun);
		return (1);
	}
	if (oyun->map[y][x] == 'E' && oyun->c == 0)
	{
		oyun->map[y][x + 1] = '0';
		oyun->success = 1;
		free_all_exit(oyun);
	}
	oyun->player_x++;
	init_map(oyun);
	return (0);
}

int	move_right(t_game *oyun)
{
	int	x;
	int	y;

	oyun->player_x++;
	x = oyun->player_x;
	y = oyun->player_y;
	change_player_img(oyun, 'r');
	if (oyun->map[y][x] == '0' || oyun->map[y][x] == 'C')
	{
		if (oyun->map[y][x] == 'C')
			oyun->c--;
		oyun->map[y][x] = 'P';
		oyun->map[y][x - 1] = '0';
		init_map(oyun);
		return (1);
	}
	if (oyun->map[y][x] == 'E' && oyun->c == 0)
	{
		oyun->map[y][x - 1] = '0';
		oyun->success = 1;
		free_all_exit(oyun);
	}
	oyun->player_x--;
	init_map(oyun);
	return (0);
}

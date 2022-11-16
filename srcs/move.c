/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:45 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 07:06:19 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_img(t_game *gamyun, char c)
{
	mlx_clear_window(gamyun->mlx, gamyun->mlx_win);
	mlx_destroy_image(gamyun->mlx, gamyun->player);
	if (c == 'u')
		put_image(gamyun, &gamyun->player, "./img/player_arka.xpm");
	if (c == 'r')
		put_image(gamyun, &gamyun->player, "./img/player_sag.xpm");
	if (c == 'l')
		put_image(gamyun, &gamyun->player, "./img/player_sol.xpm");
	if (c == 'd')
		put_image(gamyun, &gamyun->player, "./img/player_on.xpm");
}

int	move_up(t_game *gamyun)
{
	int	x;
	int	y;

	gamyun->player_y--;
	x = gamyun->player_x;
	y = gamyun->player_y;
	change_player_img(gamyun, 'u');
	if (gamyun->map[y][x] == '0' || gamyun->map[y][x] == 'C')
	{
		if (gamyun->map[y][x] == 'C')
			gamyun->c--;
		gamyun->map[y][x] = 'P';
		gamyun->map[y + 1][x] = '0';
		init_map(gamyun);
		return (1);
	}
	if (gamyun->map[y][x] == 'E' && gamyun->c == 0)
	{
		gamyun->map[y + 1][x] = '0';
		gamyun->success = 1;
		free_all_exit(gamyun);
	}
	gamyun->player_y++;
	init_map(gamyun);
	return (0);
}

int	move_down(t_game *gamyun)
{
	int	x;
	int	y;

	gamyun->player_y++;
	x = gamyun->player_x;
	y = gamyun->player_y;
	change_player_img(gamyun, 'd');
	if (gamyun->map[y][x] == '0' || gamyun->map[y][x] == 'C')
	{
		if (gamyun->map[y][x] == 'C')
			gamyun->c--;
		gamyun->map[y][x] = 'P';
		gamyun->map[y - 1][x] = '0';
		init_map(gamyun);
		return (1);
	}
	if (gamyun->map[y][x] == 'E' && gamyun->c == 0)
	{
		gamyun->map[y - 1][x] = '0';
		gamyun->success = 1;
		free_all_exit(gamyun);
	}
	gamyun->player_y--;
	init_map(gamyun);
	return (0);
}

int	move_left(t_game *gamyun)
{
	int	x;
	int	y;

	gamyun->player_x--;
	x = gamyun->player_x;
	y = gamyun->player_y;
	change_player_img(gamyun, 'l');
	if (gamyun->map[y][x] == '0' || gamyun->map[y][x] == 'C')
	{
		if (gamyun->map[y][x] == 'C')
			gamyun->c--;
		gamyun->map[y][x] = 'P';
		gamyun->map[y][x + 1] = '0';
		init_map(gamyun);
		return (1);
	}
	if (gamyun->map[y][x] == 'E' && gamyun->c == 0)
	{
		gamyun->map[y][x + 1] = '0';
		gamyun->success = 1;
		free_all_exit(gamyun);
	}
	gamyun->player_x++;
	init_map(gamyun);
	return (0);
}

int	move_right(t_game *gamyun)
{
	int	x;
	int	y;

	gamyun->player_x++;
	x = gamyun->player_x;
	y = gamyun->player_y;
	change_player_img(gamyun, 'r');
	if (gamyun->map[y][x] == '0' || gamyun->map[y][x] == 'C')
	{
		if (gamyun->map[y][x] == 'C')
			gamyun->c--;
		gamyun->map[y][x] = 'P';
		gamyun->map[y][x - 1] = '0';
		init_map(gamyun);
		return (1);
	}
	if (gamyun->map[y][x] == 'E' && gamyun->c == 0)
	{
		gamyun->map[y][x - 1] = '0';
		gamyun->success = 1;
		free_all_exit(gamyun);
	}
	gamyun->player_x--;
	init_map(gamyun);
	return (0);
}

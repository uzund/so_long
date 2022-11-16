/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:03:20 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 09:47:02 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_visited_clear(t_game *gamyun)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= gamyun->mat_y)
	{
		x = -1;
		while (++x <= gamyun->mat_x)
		{
			gamyun->visited[y][x] = '0';
		}
	}
}

int	ft_safe(int y, int j, t_game *gamyun)
{
	if (y >= 0 && y < gamyun->mat_y && j >= 0 && j < gamyun->mat_x)
		return (1);
	return (0);
}

int	ft_path(int y, int x, t_game *gamyun)
{
	if (ft_safe(y, x, gamyun) && gamyun->mat[y][x] != '1' && \
	gamyun->visited[y][x] != '1')
	{
	gamyun->visited[y][x] = '1';
		if (gamyun->mat[y][x] == 'F')
			return (1);
		if (ft_path(y - 1, x, gamyun))
			return (1);
		if (ft_path(y, x - 1, gamyun))
			return (1);
		if (ft_path(y + 1, x, gamyun))
			return (1);
		if (ft_path(y, x + 1, gamyun))
			return (1);
	}
	return (0);
}

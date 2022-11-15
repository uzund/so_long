/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:05:39 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:31:50 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_exit_chack(int i, int j, int matrix[Y][X])
{
	matrix[i][j] = 2;
	ft_path_find(matrix);
}

void	ft_path_find(int matrix[Y][X])
{
	int	visited[Y][X];
	int	result;
	int	y;
	int	x;

	ft_memset(visited, 0, sizeof(visited));
	result = 0;
	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
		{
			if (matrix[y][x] == 1 && !visited[y][x])
			{
				if (ft_path(matrix, y, x, visited))
				{
					result = 1;
					break ;
				}
			}
		}
	}
	ft_paht_put(result);
}

void	init_matrix_tmp_child(int i, int j, int matrix[Y][X])
{
	if (matrix[i][j] == 4)
	{
		matrix[i][j] = 2;
		ft_path_find(matrix);
		matrix[i][j] = 4;
	}
}

void	init_matrix_tmp(int matrix[Y][X], t_game *gamyun)
{
	static int	exit_i;
	static int	exit_j;
	int			i;
	int			j;

	exit_i = 5;
	exit_j = 5;
	i = -1;
	while (++i <= gamyun->mat_y)
	{
		j = -1;
		while (++j <= gamyun->mat_x)
		{
			if (matrix[i][j] == 5)
			{
				exit_i = i;
				exit_j = j;
				matrix[i][j] = 0;
			}
			init_matrix_tmp_child(i, j, matrix);
		}
	}
	map_exit_chack(exit_i, exit_j, matrix);
}

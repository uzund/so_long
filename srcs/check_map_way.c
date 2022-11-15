/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:03:20 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:27:41 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_safe(int y, int j)
{
	if (y >= 0 && y < Y && j >= 0 && j < X)
		return (1);
	return (0);
}

int	ft_path(int matrix[Y][X], int y, int x, int visited[Y][X])
{
	if (ft_safe(y, x) && matrix[y][x] != 0 && !visited[y][x])
	{
	visited[y][x] = 1;
		if (matrix[y][x] == 2)
			return (1);
		if (ft_path(matrix, y - 1, x, visited))
			return (1);
		if (ft_path(matrix, y, x - 1, visited))
			return (1);
		if (ft_path(matrix, y + 1, x, visited))
			return (1);
		if (ft_path(matrix, y, x + 1, visited))
			return (1);
	}
	return (0);
}

void	ft_paht_put(int result)
{
	static int	k;

	if (result)
	{
		k++;
		ft_printf("[%d] ", k);
		write(1, "KONTROL AŞAMALARI / CONTROL STAGES ... BAŞARILI / \
SUCCESSFUL\n", 63);
	}
	else
	{
		exit_error("[X] KONTROL AŞAMASI / CONTROL PHASE : BAŞARISIZ / \
UNSUCCESSFUL\nGeçersiz Harita: Tüm toplanabilir yada çıkışa erişim \
sağlanamıyor\nInvalid Map: All collectible or not accessible to exit", 0);
	}
}

void	init_matrix(t_game *gamyun)
{
	int	i;
	int	j;
	int	matrix[Y][X];

	i = -1;
	while (gamyun->map[++i])
	{
		j = -1;
		while (gamyun->map[i][++j])
		{
			if (gamyun->map[i][j] == 'C')
				matrix[i][j] = 4;
			if (gamyun->map[i][j] == 'E')
				matrix[i][j] = 5;
			if (gamyun->map[i][j] == 'P')
				matrix[i][j] = 1;
			if (gamyun->map[i][j] == '0')
				matrix[i][j] = 3;
			if (gamyun->map[i][j] == '1')
				matrix[i][j] = 0;
		}
	}
	gamyun->mat_y = i;
	gamyun->mat_x = j;
	init_matrix_tmp(matrix, gamyun);
}

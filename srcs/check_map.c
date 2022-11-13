/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:27 by duzun             #+#    #+#             */
/*   Updated: 2022/11/13 21:55:44 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h> // silmeyi unutma
#include <stdio.h> // silmeyi unutma

int matrix[20][35];
#define X 35
#define Y 20

static void	check_border(t_game *oyun)
{
	int	i;

	i = -1;
	while (++i < oyun->height)
	{
		if (oyun->map[i][0] != '1' || oyun->map[i][oyun->width -1] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.\n", 0);
	}
	i = -1;
	while (oyun->map[0][++i])
	{
		if (oyun->map[0][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.\n", 0);
	}
	i = -1;
	while (oyun->map[oyun->height][++i])
	{
		if (oyun->map[oyun->height][i] != '1')
			exit_error("Geçersiz Harita: Sınırlar kapatılmalıdır.\n\
Invalid Map: Borders should be closed.\n", 0);
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
Invalid map: No items to collect.\n", 0);
	if (oyun->e != 1)
		exit_error("Geçersiz harita: Çıkış yok yada birden fazla.\n\
Invalid map: No exit or more than one.\n", 0);
	if (oyun->p != 1)
		exit_error("Geçersiz harita: Oyuncu yok yada birden fazla.\n\
Invalid map: No or more than one player.\n", 0);
}

int	ft_safe(int y, int j, int matrix[Y][X])
{
	(void) matrix[Y][X];
	if (y >= 0 && y < Y && j >= 0 && j < X)
		return (1);
	return (0);
}

int	ft_path(int matrix[Y][X], int y, int x, int visited[Y][X])
{
	if (ft_safe(y, x, matrix) && matrix[y][x] != 0 && !visited[y][x])
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
	if (result)
		write(1, "1 (TRUE)\n", 9);
	else
	{
		write(1, "0 (FALSHE)\n", 11);
		exit_error("Geçersiz Harita: Tüm toplanabilir yada çıkışa erişim \
sağlanamıyor\nInvalid Map: All collectible or not accessible to exit\n", 0);
	}
}

void	ft_path_find(int matrix[Y][X])
{
	int	visited[Y][X];
	int	result;
	int	y;
	int	x;

	memset(visited, 0, sizeof(visited));
	result = 0;
	y = 0;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			if (matrix[y][x] == 1 && !visited[y][x])
			{
				if (ft_path(matrix, y, x, visited))
				{
					result = 1;
					break ;
				}
			}
			x++;
		}
		y++;
	}
	ft_paht_put(result);
}

void	init_matrix_print(void)
{
	int	i;
	int	j;

	i = -1;
	write(1, "\n", 1);
	while (++i <= Y)
	{
		j = -1;
		while (++j <= X)
		{
			ft_printf("%d", matrix[i][j]);
		}
		write(1, "\n", 1);
	}
}

void	map_exit_chack(int i, int j)
{
	matrix[i][j] = 2;
	printf("\n i :%d", i);
	printf("\n j :%d\n", j);
	init_matrix_print();
	ft_path_find(matrix);
	// int	i;
	// int	j;

	// i = -1;
	// while (++i <= Y)
	// {
	// 	j = -1;
	// 	while (++j <= X)
	// 	{
	// 		if (matrix[i][j] == 5)
	// 		{
	// 			ft_path_find(matrix);
	// 		}
	// 	}
	// }
}

void	init_matrix_tmp(void)
{
	static int	exit_i;
	static int	exit_j;
	int			i;
	int			j;

	exit_i = 5;
	exit_j = 5;
	i = -1;
	while (++i <= Y)
	{
		j = -1;
		while (++j <= X)
		{
			if (matrix[i][j] == 5)
			{
				exit_i = i;
				exit_j = j;
				matrix[i][j] = 0;
			}
			if (matrix[i][j] == 4)
			{
				matrix[i][j] = 2;
				init_matrix_print();
				ft_path_find(matrix);
				matrix[i][j] = 4;
			}
			ft_printf("%d", matrix[i][j]);
		}
		write(1, "\n", 1);
	}
	map_exit_chack(exit_i, exit_j);
}

void	init_matrix(t_game *oyun)
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
				matrix[i][j] = 4;
			if (oyun->map[i][j] == 'E')
			{
				// exit_i = 5;
				matrix[i][j] = 5;
			}
			if (oyun->map[i][j] == 'P')
				matrix[i][j] = 1;
			if (oyun->map[i][j] == '0')
				matrix[i][j] = 3;
			if (oyun->map[i][j] == '1')
				matrix[i][j] = 0;
			ft_printf("%d", matrix[i][j]);
		}
		write(1, "\n", 1);
	}
	init_matrix_tmp();
}

void	check_map(t_game *oyun)
{
	check_border(oyun);
	check_char(oyun);
	init_matrix(oyun);
}

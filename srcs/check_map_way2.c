/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_way2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:05:39 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 21:56:57 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_paht_put(t_game *gamyun, int result)
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
		exit_error(gamyun, "[X] KONTROL AŞAMASI / CONTROL PHASE : BAŞARISIZ / \
UNSUCCESSFUL\nGeçersiz Harita: Tüm toplanabilir yada çıkışa erişim \
sağlanamıyor\nInvalid Map: All collectible or not accessible to exit", 0);
	}
}

void	map_exit_chack(int i, int j, t_game *gamyun)
{
	gamyun->mat[i][j] = 'F';
	ft_path_find(gamyun);
}

void	ft_path_find(t_game *gamyun)
{
	int	result;
	int	y;
	int	x;

	ft_visited_clear(gamyun);
	result = 0;
	y = -1;
	while (++y <= gamyun->mat_y)
	{
		x = -1;
		while (++x <= gamyun->mat_x)
		{
			if (gamyun->mat[y][x] == 'P' && gamyun->visited[y][x] != '1')
			{
				if (ft_path(y, x, gamyun))
				{
					result = 1;
					break ;
				}
			}
		}
	}
	ft_paht_put(gamyun, result);
}

void	init_matrix_tmp_child(int i, int j, t_game *gamyun)
{
	if (gamyun->mat[i][j] == 'C')
	{
		gamyun->mat[i][j] = 'F';
		ft_path_find(gamyun);
		gamyun->mat[i][j] = 'C';
	}
}

void	init_matrix(t_game *gamyun)
{
	static int	exit_i;
	static int	exit_j;
	int			i;
	int			j;

	i = -1;
	while (gamyun->mat[++i])
	{
		j = -1;
		while (gamyun->mat[i][++j])
		{
			if (gamyun->mat[i][j] == 'E')
			{
				exit_i = i;
				exit_j = j;
				gamyun->mat[i][j] = '1';
			}
			init_matrix_tmp_child(i, j, gamyun);
		}
	}
	map_exit_chack(exit_i, exit_j, gamyun);
}

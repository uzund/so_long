/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:56:48 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 09:59:29 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_child(t_game *gamyun)
{
	int	i;

	i = -1;
	if (gamyun->mlx && gamyun->map)
	{
		while (gamyun->map[++i])
			free(gamyun->map[i]);
		free(gamyun->map);
		i = -1;
		while (gamyun->mat[++i])
			free(gamyun->mat[i]);
		free(gamyun->mat);
		i = -1;
		while (gamyun->visited[++i])
			free(gamyun->visited[i]);
		free(gamyun->visited);
	}
}

void	free_all(t_game *gamyun)
{
	if (gamyun->mlx && gamyun->player)
		mlx_destroy_image(gamyun->mlx, gamyun->player);
	if (gamyun->mlx && gamyun->hediye)
		mlx_destroy_image(gamyun->mlx, gamyun->hediye);
	if (gamyun->mlx && gamyun->duvar)
		mlx_destroy_image(gamyun->mlx, gamyun->duvar);
	if (gamyun->mlx && gamyun->cikis)
		mlx_destroy_image(gamyun->mlx, gamyun->cikis);
	if (gamyun->mlx && gamyun->zemin)
		mlx_destroy_image(gamyun->mlx, gamyun->zemin);
	if (gamyun->mlx && gamyun->mlx_win)
		mlx_destroy_window(gamyun->mlx, gamyun->mlx_win);
	free_all_child(gamyun);
	if (gamyun->success)
		ft_printf("Başardınız Skorunuz : %d\nYour Score : %d\n", \
			++gamyun->count, gamyun->count);
	if (gamyun->fail)
		ft_printf("Tekrar Deneyiniz!\nTry again!\n");
}

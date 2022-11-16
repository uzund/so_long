/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:15 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 09:55:43 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *gamyun, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(gamyun->mlx, path, &width, &height);
	if (!(*image))
	{
		free_all(gamyun);
		exit_error(gamyun, "Görüntü başlatma sorunu / \
Image initialization problem", 0);
	}
}

int	keypress(int code, t_game *gamyun)
{
	if (code == 13 || code == 126)
	{
		if (move_up(gamyun))
			ft_printf("%d\n", ++gamyun->count);
	}
	if (code == 0 || code == 123)
	{
		if (move_left(gamyun))
			ft_printf("%d\n", ++gamyun->count);
	}
	if (code == 1 || code == 125)
	{
		if (move_down(gamyun))
			ft_printf("%d\n", ++gamyun->count);
	}
	if (code == 2 || code == 124)
	{
		if (move_right(gamyun))
			ft_printf("%d\n", ++gamyun->count);
	}
	if (code == 53)
		free_all_exit(gamyun);
	return (0);
}

int	free_all_exit(t_game *gamyun)
{
	free_all(gamyun);
	system("leaks so_long");
	exit(0);
}

void	exit_error(t_game *gamyun, char *msg, int code)
{
	ft_putendl_fd(msg, 2);
	free_all(gamyun);
	system("leaks so_long");
	exit(code);
}

// void	free_all_child(t_game *gamyun)
// {
// 	int	i;

// 	i = -1;
// 	if (gamyun->mlx && gamyun->map)
// 	{
// 		while (gamyun->map[++i])
// 			free(gamyun->map[i]);
// 		free(gamyun->map);
// 		i = -1;
// 		while (gamyun->mat[++i])
// 			free(gamyun->mat[i]);
// 		free(gamyun->mat);
// 		i = -1;
// 		while (gamyun->visited[++i])
// 			free(gamyun->visited[i]);
// 		free(gamyun->visited);
// 	}
// }

// void	free_all(t_game *gamyun)
// {
// 	if (gamyun->mlx && gamyun->player)
// 		mlx_destroy_image(gamyun->mlx, gamyun->player);
// 	if (gamyun->mlx && gamyun->hediye)
// 		mlx_destroy_image(gamyun->mlx, gamyun->hediye);
// 	if (gamyun->mlx && gamyun->duvar)
// 		mlx_destroy_image(gamyun->mlx, gamyun->duvar);
// 	if (gamyun->mlx && gamyun->cikis)
// 		mlx_destroy_image(gamyun->mlx, gamyun->cikis);
// 	if (gamyun->mlx && gamyun->zemin)
// 		mlx_destroy_image(gamyun->mlx, gamyun->zemin);
// 	if (gamyun->mlx && gamyun->mlx_win)
// 		mlx_destroy_window(gamyun->mlx, gamyun->mlx_win);
// 	free_all_child(gamyun);
// 	if (gamyun->success)
// 		ft_printf("Başardınız Skorunuz : %d\nYour Score : %d\n", \
// 			++gamyun->count, gamyun->count);
// 	if (gamyun->fail)
// 		ft_printf("Tekrar Deneyiniz!\nTry again!\n");
// }
// 	// if (gamyun->mlx && gamyun->map)
// 	// {
// 	// 	while (gamyun->map[++i])
// 	// 		free(gamyun->map[i]);
// 	// 	free(gamyun->map);
// 	// 	i = -1;
// 	// 	while (gamyun->mat[++i])
// 	// 		free(gamyun->mat[i]);
// 	// 	free(gamyun->mat);
// 	// 	i = -1;
// 	// 	while (gamyun->visited[++i])
// 	// 		free(gamyun->visited[i]);
// 	// 	free(gamyun->visited);
// 	// }
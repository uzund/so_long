/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:15 by duzun             #+#    #+#             */
/*   Updated: 2022/11/13 19:42:54 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *oyun, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(oyun->mlx, path, &width, &height);
	if (!(*image))
	{
		free_all(oyun);
		ft_putendl_fd("Görüntü başlatma sorunu", 2);
		exit(0);
	}
}

int	keypress(int code, t_game *oyun)
{
	if (code == 13 || code == 126)
	{
		if (move_up(oyun))
			ft_printf("%d\n", ++oyun->count);
	}
	if (code == 0 || code == 123)
	{
		if (move_left(oyun))
			ft_printf("%d\n", ++oyun->count);
	}
	if (code == 1 || code == 125)
	{
		if (move_down(oyun))
			ft_printf("%d\n", ++oyun->count);
	}
	if (code == 2 || code == 124)
	{
		if (move_right(oyun))
			ft_printf("%d\n", ++oyun->count);
	}
	if (code == 53)
		free_all_exit(oyun);
	return (0);
}

int	free_all_exit(t_game *oyun)
{
	free_all(oyun);
	exit(0);
}

void	exit_error(char *msg, int code)
{
	ft_putendl_fd(msg, 2);
	exit(code);
}

void	free_all(t_game *oyun)
{
	int	i;

	i = -1;
	mlx_destroy_image(oyun->mlx, oyun->player);
	mlx_destroy_image(oyun->mlx, oyun->hediye);
	mlx_destroy_image(oyun->mlx, oyun->duvar);
	mlx_destroy_image(oyun->mlx, oyun->cikis);
	mlx_destroy_image(oyun->mlx, oyun->zemin);
	mlx_destroy_window(oyun->mlx, oyun->mlx_win);
	while (oyun->map[++i])
		free(oyun->map[i]);
	free(oyun->map);
	if (oyun->success)
		ft_printf("Başardınız Skorunuz\nYour Score %d\n", ++oyun->count);
	if (oyun->fail)
		ft_printf("Tekrar Deneyiniz!\nTry again!\n");
}

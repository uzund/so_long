/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <ditko73@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:15 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 17:44:24 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_param *param, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(param->mlx, path, &width, &height);
	if (!(*image))
	{
		free_all(param);
		ft_putendl_fd("Görüntü başlatma sorunu", 2);
		exit(0);
	}
}

int	keypress(int code, t_param *param)
{
	if (code == 13 || code == 126)
	{
		if (move_up(param))
			ft_printf("%d\n", ++param->count);
	}
	if (code == 0 || code == 123)
	{
		if (move_left(param))
			ft_printf("%d\n", ++param->count);
	}
	if (code == 1 || code == 125)
	{
		if (move_down(param))
			ft_printf("%d\n", ++param->count);
	}
	if (code == 2 || code == 124)
	{
		if (move_right(param))
			ft_printf("%d\n", ++param->count);
	}
	if (code == 53)
		free_all_exit(param);
	return (0);
}

int	free_all_exit(t_param *param)
{
	free_all(param);
	exit(0);
}

void	exit_error(char *msg, int code)
{
	ft_putendl_fd(msg, 2);
	exit(code);
}

void	free_all(t_param *param)
{
	int	i;

	i = -1;
	mlx_destroy_image(param->mlx, param->player);
	mlx_destroy_image(param->mlx, param->pokeball);
	mlx_destroy_image(param->mlx, param->grass);
	mlx_destroy_image(param->mlx, param->pikachu);
	mlx_destroy_image(param->mlx, param->ground);
	mlx_destroy_window(param->mlx, param->mlx_win);
	while (param->map[++i])
		free(param->map[i]);
	free(param->map);
	if (param->success)
		ft_printf("Başardınız! Skorunuz: %d\n", ++param->count);
	if (param->fail)
		ft_printf("Tekrar Deneyiniz!\n");
}

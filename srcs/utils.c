/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:15 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 10:31:02 by duzun            ###   ########.fr       */
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
		exit_error(gamyun, "Görüntü başlatma sorunu: Görüntü dosyalarını \
kontrol edin.\nImage initialization problem: Check the image files.", 0);
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
	// system("leaks so_long");
	exit(0);
}

void	exit_error(t_game *gamyun, char *msg, int code)
{
	ft_putendl_fd(msg, 2);
	free_all(gamyun);
	// system("leaks so_long");
	exit(code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:37 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 22:11:13 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*init_param(t_game *oyun)
{
	oyun->player_x = 0;
	oyun->player_y = 0;
	oyun->map = NULL;
	oyun->width = 0;
	oyun->height = 0;
	oyun->mlx = NULL;
	oyun->mlx_win = NULL;
	oyun->mlx_img = NULL;
	oyun->count = 0;
	oyun->c = 0;
	oyun->e = 0;
	oyun->p = 0;
	oyun->player = NULL;
	oyun->grass = NULL;
	oyun->pikachu = NULL;
	oyun->ground = NULL;
	oyun->pokeball = NULL;
	oyun->success = 0;
	oyun->fail = 0;
	return (oyun);
}

static int	check_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] != '.')
		i++;
	if (ft_strncmp((argv + i), ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*oyun;

	if (argc != 2)
		exit_error("Error! Use: ./so_long <map.ber>", 0);
	if (!check_file(argv[1]))
		exit_error(".ber uzantılı dosya bulunamadı.", 0);
	oyun = (t_game *)malloc(sizeof(t_game));
	oyun = init_param(oyun);
	build_map(argv[1], oyun);
	so_long(oyun);
	return (0);
}

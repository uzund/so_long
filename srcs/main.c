/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:37 by duzun             #+#    #+#             */
/*   Updated: 2022/11/15 21:22:43 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_game *gamyun)
{
	gamyun->player_x = 0;
	gamyun->player_y = 0;
	gamyun->map = NULL;
	gamyun->width = 0;
	gamyun->height = 0;
	gamyun->mlx = NULL;
	gamyun->mlx_win = NULL;
	gamyun->mlx_img = NULL;
	gamyun->count = 0;
	gamyun->c = 0;
	gamyun->e = 0;
	gamyun->p = 0;
	gamyun->player = NULL;
	gamyun->duvar = NULL;
	gamyun->cikis = NULL;
	gamyun->zemin = NULL;
	gamyun->hediye = NULL;
	gamyun->success = 0;
	gamyun->fail = 0;
}

static int	check_file(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != '.')
		i++;
	if (ft_strncmp((av + i), ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*gamyun;

	if (ac != 2)
		exit_error("Hata! Kullanım: ./so_long <map.ber>\n\
		Error! Use: ./so_long <map.ber>\n", 0);
	if (!check_file(av[1]))
		exit_error(".ber uzantılı dosya bulunamadı.\n\
The .ber file was not found.", 0);
	gamyun = (t_game *)malloc(sizeof(t_game));
	init_param(gamyun);
	building_map(av[1], gamyun);
	so_long(gamyun);
	return (0);
}

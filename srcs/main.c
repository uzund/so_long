/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:37 by duzun             #+#    #+#             */
/*   Updated: 2022/11/13 23:17:38 by duzun            ###   ########.fr       */
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
	oyun->duvar = NULL;
	oyun->cikis = NULL;
	oyun->zemin = NULL;
	oyun->hediye = NULL;
	oyun->success = 0;
	oyun->fail = 0;
	return (oyun);
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
	t_game	*oyun;

	if (ac != 2)
		exit_error("Hata! Kullanım: ./so_long <map.ber>\n\
		Error! Use: ./so_long <map.ber>\n", 0);
	if (!check_file(av[1]))
		exit_error(".ber uzantılı dosya bulunamadı.\n\
		The .ber file was not found.\n", 0);
	oyun = (t_game *)malloc(sizeof(t_game));
	oyun = init_param(oyun);
	building_map(av[1], oyun);
	so_long(oyun);
	return (0);
}

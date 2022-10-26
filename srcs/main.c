/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:37 by duzun             #+#    #+#             */
/*   Updated: 2022/10/26 21:28:39 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon.h"

static t_param	*init_param(t_param *param)
{
	param->player_x = 0;
	param->player_y = 0;
	param->map = NULL;
	param->width = 0;
	param->height = 0;
	param->mlx = NULL;
	param->mlx_win = NULL;
	param->mlx_img = NULL;
	param->count = 0;
	param->c = 0;
	param->e = 0;
	param->p = 0;
	param->player = NULL;
	param->grass = NULL;
	param->pikachu = NULL;
	param->ground = NULL;
	param->pokeball = NULL;
	param->success = 0;
	param->fail = 0;
	return (param);
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
	t_param	*param;

	if (argc != 2)
		exit_error("ERROR! FORMAT: ./POKEMON <MAP.BER>", 0);
	if (!check_file(argv[1]))
		exit_error("File is not .ber", 0);
	param = (t_param *)malloc(sizeof(t_param));
	param = init_param(param);
	build_map(argv[1], param);
	pokemon(param);
	return (0);
}

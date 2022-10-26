/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:27 by duzun             #+#    #+#             */
/*   Updated: 2022/10/26 21:28:30 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon.h"

static void	check_border(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->height)
	{
		if (param->map[i][0] != '1' || param->map[i][param->width -1] != '1')
			exit_error("INVALID MAP: BORDERS MUST BE CLOSED", 0);
	}
	i = -1;
	while (param->map[0][++i])
	{
		if (param->map[0][i] != '1')
			exit_error("INVALID MAP: BORDERS MUST BE CLOSED", 0);
	}
	i = -1;
	while (param->map[param->height][++i])
	{
		if (param->map[param->height][i] != '1')
			exit_error("INVALID MAP: BORDERS MUST BE CLOSED", 0);
	}
}

static void	check_char(t_param *param)
{
	int	i;
	int	j;

	i = -1;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->map[i][j] == 'C')
				param->c++;
			if (param->map[i][j] == 'E')
				param->e++;
			if (param->map[i][j] == 'P')
				param->p++;
		}
	}
	if (!param->c)
		exit_error("INVALID MAP : NO ITEMS TO COLLECT", 0);
	if (param->e != 1)
		exit_error("INVALID MAP : TOO MANY OR NO EXIT", 0);
	if (param->p != 1)
		exit_error("INVALID MAP : TOO MANY OR NO PLAYER", 0);
}

void	check_map(t_param *param)
{
	check_border(param);
	check_char(param);
}

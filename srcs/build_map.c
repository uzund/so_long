/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <ditko73@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:13 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 17:23:04 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_param	*get_wh(t_param *param)
{
	param->width = ft_strlen(param->map[0]);
	while (param->map[param->height])
		param->height++;
	param->height--;
	return (param);
}

static void	check_line(char *line, size_t size, size_t row)
{
	int	i;

	i = -1;
	if (row != size)
		exit_error("Invalid map : every row must have the same length", 0);
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
		{
			ft_printf("Unknown caracter %c\n", line[i]);
			exit_error("Error: unidentified map caracter", 0);
		}
	}
}

static char	*get_data(int fd)
{
	char		*line;
	char		*data;
	size_t		size;
	size_t		row;

	line = get_next_line(fd);
	if (line == NULL)
		exit_error("EMPTY FILE", 0);
	size = ft_strlen(line);
	data = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			row = ft_strlen(line);
			check_line(line, size, row);
			data = ft_strjoin(data, line);
			free(line);
		}
	}
	return (data);
}

void	build_map(char *argv, t_param *param)
{
	int		fd;
	char	*path;
	char	*data;

	path = ft_strjoin("./maps/", argv);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("INEXISTENT OR INVALID MAP", 0);
	data = get_data(fd);
	param->map = ft_split(data, '\n');
	close(fd);
	free(data);
	param = get_wh(param);
	check_map(param);
}

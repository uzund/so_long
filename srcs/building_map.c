/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:13 by duzun             #+#    #+#             */
/*   Updated: 2022/10/28 03:49:34 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*get_wh(t_game *oyun)
{
	oyun->width = ft_strlen(oyun->map[0]);
	while (oyun->map[oyun->height])
		oyun->height++;
	oyun->height--;
	return (oyun);
}

static void	check_line(char *line, size_t size, size_t row)
{
	int	i;

	i = -1;
	if (row != size)
		exit_error("Geçersiz harita: her satır aynı uzunlukta olmalı.", 0);
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
		{
			ft_printf("Geçersiz karakter %c\n", line[i]);
			exit_error("Hata: tanımlanmayan harita karakteri", 0);
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
		exit_error("Dosya boş", 0);
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

void	building_map(char *av, t_game *oyun)
{
	int		fd;
	char	*path;
	char	*data;

	path = ft_strjoin("./maps/", av);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("Geçersiz veya hatalı harita", 0);
	data = get_data(fd);
	oyun->map = ft_split(data, '\n');
	close(fd);
	free(data);
	oyun = get_wh(oyun);
	check_map(oyun);
}

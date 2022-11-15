/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:28:13 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 00:38:29 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_game	*get_wh(t_game *gamyun)
{
	gamyun->width = ft_strlen(gamyun->map[0]);
	while (gamyun->map[gamyun->height])
		gamyun->height++;
	gamyun->height--;
	gamyun->mat_y = gamyun->height;
	gamyun->mat_x = gamyun->width - 1;
	return (gamyun);
}

static	void	check_line(char *line, size_t size, size_t row)
{
	int	i;

	i = -1;
	if (row != size)
		exit_error("Geçersiz harita: her satır aynı uzunlukta olmalı.\n\
Invalid map: each line must be the same length.", 0);
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != \
		'E' && line[i] != 'P' && line[i] != '\n')
		{
			ft_printf("Geçersiz karakter / Invalid character : %c\n", line[i]);
			exit_error("Hata: tanımlanmayan harita karakteri\n\
Error: undefined map character", 0);
		}
	}
}

void	x_free(char *line, char *tmp)
{
	free(line);
	free(tmp);
}

static char	*get_data(int fd)
{
	char	*line;
	char	*data;
	size_t	size;
	size_t	row;
	char	*tmp;

	line = get_next_line(fd);
	if (line == NULL)
		exit_error("Dosya boş.\nFile is empty.", 0);
	free(line);
	size = ft_strlen(line);
	data = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			row = ft_strlen(line);
			check_line(line, size, row);
			tmp = data;
			data = ft_strjoin(data, line);
			x_free(line, tmp);
		}
	}
	return (data);
}

void	building_map(char *av, t_game *gamyun)
{
	int		fd;
	char	*path;
	char	*data;

	path = ft_strjoin("./maps/", av);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("Geçersiz veya hatalı harita\nInvalid or incorrect map", 0);
	free(path);
	data = get_data(fd);
	gamyun->map = ft_split(data, '\n');
	gamyun->mat = ft_split(data, '\n');
	gamyun->visited = ft_split(data, '\n');
	close(fd);
	free(data);
	gamyun = get_wh(gamyun);
	check_map(gamyun);
}

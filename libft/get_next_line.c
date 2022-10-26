/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:14:12 by duzun             #+#    #+#             */
/*   Updated: 2022/08/20 12:14:12 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_satir_yap(char **str, int chrlen, char **buf)
{
	int		i;
	char	*line;
	char	*tmp;

	free(*buf);
	tmp = NULL;
	if (chrlen < 0 || *str == NULL)
		return (NULL);
	if (!chrlen && !ft_strchr(*str, '\n'))
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	i = 0;
	while ((*str)[i] != '\n')
		i++;
	line = ft_substr(*str, 0, i + 1);
	if ((int)ft_strlen(*str) - i - 1)
		tmp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	int			chrlen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	chrlen = read(fd, buf, BUFFER_SIZE);
	while (chrlen > 0)
	{
		buf[chrlen] = '\0';
		if (!str)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(str, buf);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
		chrlen = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_satir_yap(&str, chrlen, &buf));
}

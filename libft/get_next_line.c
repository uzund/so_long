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

static void	ft_strcpy(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

static char	*ft_read(int fd, char *str, int ret, char *buf)
{
	char	*tmp;

	while (ret > 0 && str[ft_strlen(str) - 1] != '\n')
	{
		if (!*str)
			ft_strcpy(buf, str);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static int	ret;
	char		*str;
	static char	c[2];

	if (fd == -1 || read(fd, c, 0) == -1)
		return (NULL);
	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (ret == 0)
	{
		ret = read(fd, c, 1);
		c[ret] = '\0';
	}
	if (ret > 0 && c[0] != '\0')
		str = ft_read(fd, str, ret, c);
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <ditko73@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:03 by duzun             #+#    #+#             */
/*   Updated: 2022/10/27 17:47:23 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_param
{
	int		player_x;
	int		player_y;
	char	**map ;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		count;
	int		c;
	int		e;
	int		p;
	void	*player;
	void	*grass;
	void	*pikachu;
	void	*ground;
	void	*pokeball;
	int		success;
	int		fail;
}	t_param;

void	build_map(char *argv, t_param *param);
void	check_map(t_param *param);
void	so_long(t_param *param);
int		init_map(t_param *param);
int		move_up(t_param *param);
int		move_down(t_param *param);
int		move_left(t_param *param);
int		move_right(t_param *param);
void	exit_error(char *msg, int code);
void	free_all(t_param *param);
void	put_image(t_param *param, void **image, char *path);
int		keypress(int code, t_param *param);
int		free_all_exit(t_param *param);

#endif

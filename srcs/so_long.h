/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:03 by duzun             #+#    #+#             */
/*   Updated: 2022/11/16 00:11:46 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <fcntl.h>

typedef struct s_game
{
	char	**visited;
	char	**mat;
	int		mat_y;
	int		mat_x;
	int		player_x;
	int		player_y;
	char	**map;
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
	void	*duvar;
	void	*cikis;
	void	*zemin;
	void	*hediye;
	int		success;
	int		fail;

}	t_game;

void	building_map(char *av, t_game *gamyun);
void	check_map(t_game *gamyun);
void	so_long(t_game *gamyun);
int		init_map(t_game *gamyun);
int		move_up(t_game *gamyun);
int		move_down(t_game *gamyun);
int		move_left(t_game *gamyun);
int		move_right(t_game *gamyun);
void	exit_error(char *msg, int code);
void	free_all(t_game *gamyun);
void	put_image(t_game *gamyun, void **image, char *path);
int		keypress(int code, t_game *gamyun);
int		free_all_exit(t_game *gamyun);
void	init_matrix(t_game *gamyun);
void	map_exit_chack(int i, int j, t_game *gamyun);
void	ft_path_find(t_game *gamyun);
int		ft_path(int y, int x, t_game *oyun);
void	ft_paht_put(int result);
void	init_matrix_tmp_child(int i, int j, t_game *gamyun);
int		ft_safe(int y, int j, t_game *gamyun);
void	ft_visited_clear(t_game *gamyun);

#endif

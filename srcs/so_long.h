/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:29:03 by duzun             #+#    #+#             */
/*   Updated: 2022/11/13 19:34:02 by duzun            ###   ########.fr       */
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

void	building_map(char *av, t_game *oyun);
void	check_map(t_game *oyun);
void	so_long(t_game *oyun);
int		init_map(t_game *oyun);
int		move_up(t_game *oyun);
int		move_down(t_game *oyun);
int		move_left(t_game *oyun);
int		move_right(t_game *oyun);
void	exit_error(char *msg, int code);
void	free_all(t_game *oyun);
void	put_image(t_game *oyun, void **image, char *path);
int		keypress(int code, t_game *oyun);
int		free_all_exit(t_game *oyun);
void	ft_chance(t_game *oyun);
void	check_map(t_game *oyun);
void	init_matrix_print(void);

#endif

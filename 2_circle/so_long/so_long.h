/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:16:25 by jibae             #+#    #+#             */
/*   Updated: 2022/06/24 14:34:48 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define NOT_PLAYER_MOVE	-1
# define BER_FILE_LENGTH	4

# define SPACE		'0'
# define WALL		'1'
# define COLLECT	'C'
# define EXIT		'E'
# define PLAYER		'P'

typedef struct s_image
{
	void	*player_w;
	void	*player_s;
	void	*player_a;
	void	*player_d;
	void	*wall;
	void	*collect_0;
	void	*collect_1;
	void	*collect_2;
	void	*collect_3;
	void	*collect_4;
	void	*space;
	void	*exit_0;
	void	*exit_1;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	image;
	int		x;
	int		y;
	char	*line;
	int		movement_count;
	int		object_count;
	int		total_object;
}	t_game;

void	set_image(void *mlx, t_image *image);

void	map_read(char *map_name, t_game *game);
void	put_map(t_game *g, int x, int y, int key);
void	set_map(t_game *game, int key);
void	put_map_player(t_game *g, int x, int y, int key);
void	put_map_collect(t_game *g, int x, int y);

void	map_error_check(t_game *game);
void	check_rectangle(t_game *game);
void	check_wall(t_game *game);
void	check_count(t_game *game);
void	check_invalid_char(t_game *game);

char	*sl_strjoin(char *s1, char *s2);
char	*sl_strncpy(char *dst, char *src, size_t len);
char	*sl_strdup(char *str);
void	sl_error(char *str);

void	key_w(t_game *game);
void	key_s(t_game *game);
void	key_a(t_game *game);
void	key_d(t_game *game);

#endif
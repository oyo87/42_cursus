/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:28:48 by jibae             #+#    #+#             */
/*   Updated: 2022/05/23 17:54:09 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *map_name, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		sl_error("File open failed.\n");
	line = get_next_line(fd);
	game->movement_count = 0;
	game->y = 0;
	game->x = ft_strlen(line);
	if (game->x != 0)
		game->x--;
	game->line = sl_strdup(line);
	if (game->line == NULL)
		sl_error("The map file is empty or directory.\n");
	while (line)
	{
		free (line);
		game->y++;
		line = get_next_line(fd);
		if (line)
			game->line = sl_strjoin(game->line, line);
	}
	close(fd);
}

void	put_map_collect(t_game *g, int x, int y)
{
	size_t	random_value;
	void	*collect_num;

	random_value = (x + y) % 5;
	if (1 <= random_value && random_value <= 4)
	{
		if (random_value == 1)
			collect_num = g->image.collect_1;
		if (random_value == 2)
			collect_num = g->image.collect_2;
		if (random_value == 3)
			collect_num = g->image.collect_3;
		if (random_value == 4)
			collect_num = g->image.collect_4;
	}
	else
		collect_num = g->image.collect_0;
	mlx_put_image_to_window(g->mlx, g->win,
		collect_num, x * 64, y * 64);
}

void	put_map(t_game *g, int x, int y, int key)
{
	if (g->line[g->x * y + x] == WALL)
		mlx_put_image_to_window(g->mlx, g->win, g->image.wall, x * 64, y * 64);
	else if (g->line[g->x * y + x] == SPACE)
		mlx_put_image_to_window(g->mlx, g->win, g->image.space, x * 64, y * 64);
	else if (g->line[g->x * y + x] == COLLECT)
		put_map_collect(g, x, y);
	else if (g->line[g->x * y + x] == EXIT
		&& g->object_count == g->total_object)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.exit_1, x * 64, y * 64);
	else if (g->line[g->x * y + x] == EXIT)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.exit_0, x * 64, y * 64);
	else if (g->line[g->x * y + x] == PLAYER)
	{
		if (key == NOT_PLAYER_MOVE)
			mlx_put_image_to_window(g->mlx, g->win,
				g->image.player_s, x * 64, y * 64);
		else
			put_map_player(g, x, y, key);
	}
}

void	put_map_player(t_game *g, int x, int y, int key)
{
	if (g->line[g->x * y + x] == PLAYER && key == KEY_W)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.player_w, x * 64, y * 64);
	else if (g->line[g->x * y + x] == PLAYER && key == KEY_S)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.player_s, x * 64, y * 64);
	else if (g->line[g->x * y + x] == PLAYER && key == KEY_A)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.player_a, x * 64, y * 64);
	else if (g->line[g->x * y + x] == PLAYER && key == KEY_D)
		mlx_put_image_to_window(g->mlx, g->win,
			g->image.player_d, x * 64, y * 64);
	else if (g->line[g->x * y + x] == SPACE)
		mlx_put_image_to_window(g->mlx, g->win, g->image.space, x * 64, y * 64);
}

void	set_map(t_game *game, int key)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			put_map(game, x, y, key);
			x++;
		}
		y++;
	}
}

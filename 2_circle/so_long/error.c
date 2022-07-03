/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:56 by jibae             #+#    #+#             */
/*   Updated: 2022/05/23 19:35:23 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error_check(t_game *game)
{
	check_invalid_char(game);
	check_rectangle(game);
	check_wall(game);
	check_count(game);
}

void	check_invalid_char(t_game *game)
{
	char	*line;
	int		i;

	line = game->line;
	i = 0;
	while (line[i])
	{
		if (line[i] == SPACE)
			i++;
		else if (line[i] == WALL)
			i++;
		else if (line[i] == COLLECT)
			i++;
		else if (line[i] == EXIT)
			i++;
		else if (line[i] == PLAYER)
			i++;
		else if (line[i] == '\n')
			i++;
		else
			sl_error("An undefined element exists in the map file.\n");
	}
}

void	check_rectangle(t_game *game)
{
	if (game->x * game->y != (int)ft_strlen(game->line))
		sl_error("The map must be rectangular.\n");
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->line))
	{
		if (i < game->x)
		{
			if (game->line[i] != WALL)
				sl_error("Map must be closed/surrounded by walls.\n");
		}
		else if (i % game->x == 0 || i % game->x == game->x - 1)
		{
			if (game->line[i] != WALL)
				sl_error("Map must be closed/surrounded by walls.\n");
		}
		else if ((int)ft_strlen(game->line) - game->x < i)
		{
			if (game->line[i] != WALL)
				sl_error("Map must be closed/surrounded by walls.\n");
		}
		i++;
	}
}

void	check_count(t_game *game)
{
	int	i;
	int	exit_count;
	int	player_count;

	i = 0;
	exit_count = 0;
	player_count = 0;
	game->object_count = 0;
	game->total_object = 0;
	while (i < (int)ft_strlen(game->line))
	{
		if (game->line[i] == EXIT)
			exit_count++;
		else if (game->line[i] == PLAYER)
			player_count++;
		else if (game->line[i] == COLLECT)
			game->total_object++;
		i++;
	}
	if (exit_count == 0)
		sl_error("Map must have at least one exit.\n");
	if (game->total_object == 0)
		sl_error("Map must have at least one collectible.\n");
	if (player_count != 1)
		sl_error("Map must have one starting position.\n");
}

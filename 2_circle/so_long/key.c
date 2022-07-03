/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:06:34 by jibae             #+#    #+#             */
/*   Updated: 2022/05/23 19:49:18 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_clear(t_game *game)
{
	game->movement_count++;
	printf("Clear!! your movement count is %d.\n", game->movement_count);
	exit (0);
}

void	key_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->line))
	{
		if (game->line[i] == PLAYER)
			break ;
	}
	if (game->line[i - game->x] == COLLECT)
		game->object_count++;
	if (game->line[i - game->x] == EXIT
		&& game->total_object == game->object_count)
		game_clear(game);
	else if (game->line[i - game->x] != WALL
		&& game->line[i - game->x] != EXIT)
	{
		game->line[i] = SPACE;
		game->line[i - game->x] = PLAYER;
		game->movement_count++;
		printf("Your movement count is %d.\n", game->movement_count);
		set_map(game, KEY_W);
	}
}

void	key_s(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->line))
	{
		if (game->line[i] == PLAYER)
			break ;
	}
	if (game->line[i + game->x] == COLLECT)
		game->object_count++;
	if (game->line[i + game->x] == EXIT
		&& game->total_object == game->object_count)
		game_clear(game);
	else if (game->line[i + game->x] != WALL
		&& game->line[i + game->x] != EXIT)
	{
		game->line[i] = SPACE;
		game->line[i + game->x] = PLAYER;
		game->movement_count++;
		printf("Your movement count is %d.\n", game->movement_count);
		set_map(game, KEY_S);
	}
}

void	key_a(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->line))
	{
		if (game->line[i] == PLAYER)
			break ;
	}
	if (game->line[i - 1] == COLLECT)
		game->object_count++;
	if (game->line[i - 1] == EXIT
		&& game->total_object == game->object_count)
		game_clear(game);
	else if (game->line[i - 1] != WALL
		&& game->line[i - 1] != EXIT)
	{
		game->line[i] = SPACE;
		game->line[i - 1] = PLAYER;
		game->movement_count++;
		printf("Your movement count is %d.\n", game->movement_count);
		set_map(game, KEY_A);
	}
}

void	key_d(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->line))
	{
		if (game->line[i] == PLAYER)
			break ;
	}
	if (game->line[i + 1] == COLLECT)
		game->object_count++;
	if (game->line[i + 1] == EXIT
		&& game->total_object == game->object_count)
		game_clear(game);
	else if (game->line[i + 1] != WALL
		&& game->line[i + 1] != EXIT)
	{
		game->line[i] = SPACE;
		game->line[i + 1] = PLAYER;
		game->movement_count++;
		printf("Your movement count is %d.\n", game->movement_count);
		set_map(game, KEY_D);
	}
}

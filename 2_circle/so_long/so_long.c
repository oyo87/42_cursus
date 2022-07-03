/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:50:01 by jibae             #+#    #+#             */
/*   Updated: 2022/06/24 14:33:34 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ber_check(char *map_filename)
{
	char		*ber;
	size_t		i;
	int			is_ber;

	ber = ".ber";
	i = ft_strlen(map_filename);
	if (i <= BER_FILE_LENGTH)
		sl_error("You need to run the .ber file.\n");
	i = i - BER_FILE_LENGTH;
	map_filename = map_filename + i;
	is_ber = ft_strncmp(map_filename, ber, BER_FILE_LENGTH);
	if (is_ber != 0)
		sl_error("You need to run the .ber file.\n");
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit (1);
	set_image(game->mlx, &game->image);
	game->win = mlx_new_window(game->mlx, game->x * 64,
			game->y * 64, "so_long");
	if (game->win == NULL)
		exit (1);
	set_map(game, NOT_PLAYER_MOVE);
}

static int	hook_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static int	hook_key(int press_key, t_game *game)
{
	if (press_key == KEY_W)
		key_w(game);
	else if (press_key == KEY_S)
		key_s(game);
	else if (press_key == KEY_A)
		key_a(game);
	else if (press_key == KEY_D)
		key_d(game);
	else if (press_key == KEY_ESC)
		hook_exit(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		sl_error("Run with only one map file.\n");
	game = malloc(sizeof(t_game));
	if (game == NULL)
		exit (1);
	ber_check(argv[1]);
	map_read(argv[1], game);
	map_error_check(game);
	game_init(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &hook_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &hook_exit, game);
	mlx_loop(game->mlx);
	return (0);
}

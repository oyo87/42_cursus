/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:54:57 by jibae             #+#    #+#             */
/*   Updated: 2022/06/24 14:29:52 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(void *mlx, t_image *img)
{
	int		x;
	int		y;


	img->player_s = mlx_xpm_file_to_image(mlx, "./images/player_s.xpm", &x, &y);
	img->player_w = mlx_xpm_file_to_image(mlx, "./images/player_w.xpm", &x, &y);
	img->player_a = mlx_xpm_file_to_image(mlx, "./images/player_a.xpm", &x, &y);
	img->player_d = mlx_xpm_file_to_image(mlx, "./images/player_d.xpm", &x, &y);
	img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &x, &y);
	img->collect_0 = mlx_xpm_file_to_image(mlx,
			"./images/collect_0.xpm", &x, &y);
	img->collect_1 = mlx_xpm_file_to_image(mlx,
			"./images/collect_1.xpm", &x, &y);
	img->collect_2 = mlx_xpm_file_to_image(mlx,
			"./images/collect_2.xpm", &x, &y);
	img->collect_3 = mlx_xpm_file_to_image(mlx,
			"./images/collect_3.xpm", &x, &y);
	img->collect_4 = mlx_xpm_file_to_image(mlx,
			"./images/collect_4.xpm", &x, &y);
	img->space = mlx_xpm_file_to_image(mlx, "./images/space.xpm", &x, &y);
	img->exit_0 = mlx_xpm_file_to_image(mlx, "./images/exit_0.xpm", &x, &y);
	img->exit_1 = mlx_xpm_file_to_image(mlx, "./images/exit_1.xpm", &x, &y);
}

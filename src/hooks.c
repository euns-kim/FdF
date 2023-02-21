/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:46:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/18 22:11:14 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (ydelta > 0)
		zoom(xdelta, ydelta, map);
	else if (ydelta < 0)
		zoom(xdelta, ydelta, map);
	if (xdelta < 0)
		zoom(xdelta, ydelta, map);
	else if (xdelta > 0)
		zoom(xdelta, ydelta, map);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_x += 40;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_x -= 40;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_y += 40;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_y -= 40;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_z += 40;
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS \
	&& keydata.modifier == MLX_CONTROL)
		map->rotate_z -= 40;
}

void	hook2(void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		rule_translate(MLX_KEY_RIGHT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		rule_translate(MLX_KEY_LEFT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		rule_translate(MLX_KEY_UP, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		rule_translate(MLX_KEY_DOWN, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_1))
		parallel_map(MLX_KEY_1, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_2))
		parallel_map(MLX_KEY_2, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_3))
		parallel_map(MLX_KEY_3, map);
}

void	hook(void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
		rule_rotate(MLX_KEY_Q, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		rule_rotate(MLX_KEY_W, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		rule_rotate(MLX_KEY_A, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		rule_rotate(MLX_KEY_S, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Z))
		rule_rotate(MLX_KEY_Z, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_X))
		rule_rotate(MLX_KEY_X, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		to_default(MLX_KEY_D, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT_BRACKET))
		manipulate_z(MLX_KEY_LEFT_BRACKET, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT_BRACKET))
		manipulate_z(MLX_KEY_RIGHT_BRACKET, map);
}

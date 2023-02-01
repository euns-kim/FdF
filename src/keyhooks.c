/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:46:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/01 12:16:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// MLX_KEY_IS_DOWN
// Q / W : X_AXIS ROTATION
// A / S : Y_AXIS ROTATION
// Z / X : Z_AXIS ROTATION
// CMD+ : ROTATION OF 45 DEGREE ANGLE
// ZOOM IN/OUT : SCROLL
// D : TO DEFAULT

// static void	rule_rotate(int32_t key, t_map *map)
// {
// 	if (key == MLX_KEY_Q)
// 		map->rotate_x += 5;
// 	if (key == MLX_KEY_W)
// 		map->rotate_x -= 5;
// 	if (key == MLX_KEY_A)
// 		map->rotate_y += 5;
// 	if (key == MLX_KEY_S)
// 		map->rotate_y += 5;
// 	if (key == MLX_KEY_Z)
// 		map->rotate_z += 5;
// 	if (key == MLX_KEY_X)
// 		map->rotate_z += 5;
// }

static void	translate(int32_t key, t_map *map)
{
	if (key == MLX_KEY_RIGHT)
		map->x_offset += 8;
	if (key == MLX_KEY_LEFT)
		map->x_offset -= 8;
	if (key == MLX_KEY_UP)
		map->y_offset -= 8;
	if (key == MLX_KEY_DOWN)
		map->y_offset += 8;
	ft_memset(map->img->pixels, 255, map->img->width * map->img->height * BPP);
	draw_map(map);
}

void	keyhook(void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
	// 	rule_rotate(MLX_KEY_Q, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	// 	rule_rotate(MLX_KEY_W, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	// 	rule_rotate(MLX_KEY_A, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	// 	rule_rotate(MLX_KEY_S, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_Z))
	// 	rule_rotate(MLX_KEY_Z, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_X))
	// 	rule_rotate(MLX_KEY_X, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		translate(MLX_KEY_RIGHT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		translate(MLX_KEY_LEFT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		translate(MLX_KEY_UP, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		translate(MLX_KEY_DOWN, map);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;
	
	map = (t_map *) param;
	if (ydelta > 0)
		map->factor += 0.5;
	else if (ydelta < 0)
	{
		map->factor -= 0.5;
		if (map->factor < 1)
			map->factor = 1;
	}
	if (xdelta < 0)
		map->factor -= 5;
	else if (xdelta > 0)
		map->factor += 5;
	ft_memset(map->img->pixels, 255, map->img->width * map->img->height * BPP);
	draw_map(map);
}
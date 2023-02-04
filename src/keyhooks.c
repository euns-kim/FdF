/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:46:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/04 00:54:27 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// MLX_KEY_IS_DOWN
// Q / W : X_AXIS ROTATION
// A / S : Y_AXIS ROTATION
// Z / X : Z_AXIS ROTATION
// ARROW : TRANSLATION (VERTICAL & HORIZONTAL)
// CMD+ : ROTATION OF 45 DEGREE ANGLE
// ZOOM IN/OUT : SCROLL
// ZOOM IN/OUT (FASTER) : SCROLL + SHIFT
// D : TO DEFAULT

// static void	draw_default_map(t_map *map)
// {
// 	int32_t	i;
// 	int32_t	j;

// 	i = -1;
// 	while (++i < map->row - 1)
// 	{
// 		j = -1;
// 		while (++j < map->column - 1)
// 		{
// 			draw_line(map, update_pixel((*map), map->map_array[i][j]), \
// 			update_pixel((*map), map->map_array[i + 1][j]));
// 			draw_line(map, update_pixel((*map), map->map_array[i][j]), \
// 			update_pixel((*map), map->map_array[i][j + 1]));
// 		}
// 		draw_line(map, update_pixel((*map), map->map_array[i][j]), \
// 		update_pixel((*map), map->map_array[i + 1][j]));
// 	}
// 	j = -1;
// 	while (++j < map->column - 1)
// 	{
// 		draw_line(map, update_pixel((*map), map->map_array[i][j]), \
// 		update_pixel((*map), map->map_array[i][j + 1]));
// 	}
// }

// static void to_default(int32_t key, t_map *map)
// {
// 	if (key == MLX_KEY_D)
// 	{
		
// 	}


// }

static void	rule_rotate(int32_t key, t_map *map)
{
	if (key == MLX_KEY_Q)
		map->rotate_x += 5;
	if (key == MLX_KEY_W)
		map->rotate_x -= 5;
	if (key == MLX_KEY_A)
		map->rotate_y += 5;
	if (key == MLX_KEY_S)
		map->rotate_y -= 5;
	if (key == MLX_KEY_Z)
		map->rotate_z += 5;
	if (key == MLX_KEY_X)
		map->rotate_z -= 5;
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_map(map);
}

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
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_map(map);
}

void	keyhook(void *param)
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
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		translate(MLX_KEY_RIGHT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		translate(MLX_KEY_LEFT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		translate(MLX_KEY_UP, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		translate(MLX_KEY_DOWN, map);
	// if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	// 	to_default(MLX_KEY_D, map);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (ydelta > 0)
		map->factor += 1;
	else if (ydelta < 0)
	{
		map->factor -= 1;
		if (map->factor < 1)
			map->factor = 1;
	}
	if (xdelta < 0)
	{	
		map->factor -= 7;
		if (map->factor < 1)
			map->factor = 1;
	}
	else if (xdelta > 0)
		map->factor += 7;
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_map(map);
}

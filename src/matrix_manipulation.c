/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:01:46 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/16 16:07:03 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_default(int32_t key, t_map *map)
{
	if (key == MLX_KEY_D)
	{
		map->rotate_x = 0;
		map->rotate_y = 0;
		map->rotate_z = 0;
		map->x_offset = 0;
		map->y_offset = 0;
		map->z_inc = 1;
		scale(map);
	}
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_map(map);
}

void	manipulate_z(int32_t key, t_map *map)
{
	if (key == MLX_KEY_LEFT_BRACKET)
		map->z_inc -= 0.05;
	if (key == MLX_KEY_RIGHT_BRACKET)
		map->z_inc += 0.05;
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_map(map);
}

void	rule_translate(int32_t key, t_map *map)
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

void	rule_rotate(int32_t key, t_map *map)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:27:58 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/11 22:58:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d	parallel_projection(int32_t key, t_map *map, t_coordis map_struct)
{
	t_2d	pixel;

	if (key == MLX_KEY_1)
	{
		pixel.x = map_struct.x * map->scale_p + map->new_axis;
		pixel.y = map_struct.y * map->scale_p + map->new_ordinate;
	}
	else if (key == MLX_KEY_2)
	{
		pixel.x = map_struct.x * map->scale_p + map->new_axis;
		pixel.y = -map_struct.z * map->scale_p + map->new_ordinate;
	}
	else if (key == MLX_KEY_3)
	{
		pixel.x = map_struct.y * map->scale_p + map->new_axis;
		pixel.y = -map_struct.z * map->scale_p + map->new_ordinate;
	}
	pixel.color = map_struct.color;
	return (pixel);
}

void	draw_parallel_map(int32_t key, t_map *map)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < map->row - 1)
	{
		j = -1;
		while (++j < map->column - 1)
		{
			draw_line(map, parallel_projection(key, map, map->map_array[i][j]), \
			parallel_projection(key, map, map->map_array[i + 1][j]));
			draw_line(map, parallel_projection(key, map, map->map_array[i][j]), \
			parallel_projection(key, map, map->map_array[i][j + 1]));
		}
		draw_line(map, parallel_projection(key, map, map->map_array[i][j]), \
		parallel_projection(key, map, map->map_array[i + 1][j]));
	}
	j = -1;
	while (++j < map->column - 1)
	{
		draw_line(map, parallel_projection(key, map, map->map_array[i][j]), \
		parallel_projection(key, map, map->map_array[i][j + 1]));
	}
}

static void	max_xy_parallel(int32_t key, t_coordis map_struct, \
double *max_x, double *max_y)
{
	double	current_x;
	double	current_y;

	if (key == MLX_KEY_1)
	{
		current_x = map_struct.x;
		current_y = map_struct.y;
	}
	else if (key == MLX_KEY_2)
	{
		current_x = map_struct.x;
		current_y = -map_struct.z;
	}
	else
	{
		current_x = map_struct.y;
		current_y = -map_struct.z;
	}
	if (*max_x < fabs(current_x))
		*max_x = fabs(current_x);
	if (*max_y < fabs(current_y))
		*max_y = fabs(current_y);
}

void	scale_parallel_projection(int32_t key, t_map *map)
{
	int32_t	i;
	int32_t	j;
	double	max_x;
	double	max_y;

	i = 0;
	max_x = 0;
	max_y = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			max_xy_parallel(key, map->map_array[i][j], &max_x, &max_y);
			j++;
		}
		i++;
	}
	map->scale_p = get_scale(max_x, max_y);
}

void	parallel_map(int32_t key, t_map *map)
{
	scale_parallel_projection(key, map);
	ft_bzero(map->img->pixels, map->img->width * map->img->height * BPP);
	draw_parallel_map(key, map);
}

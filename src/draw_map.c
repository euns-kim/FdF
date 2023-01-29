/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:39:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/29 20:24:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(mlx_image_t *img, t_2d point)
{
	// if (point.x >= -(HEIGHT / 2) && point.x <= (HEIGHT / 2) \
	// && point.y >= -(WIDTH / 2) && point.y <= (WIDTH / 2))
	// {
	mlx_put_pixel(img, point.x, point.y, 0xEE4B2BFF);
	// }
}

static void	draw_line_low(t_map *map, t_2d point, t_2d next_point)
{
	int32_t	yi;
	int32_t	p;

	map->dx = next_point.x - point.x;
	map->dy = next_point.y - point.y;
	yi = 1;
	if (map->dy < 0)
	{
		yi = -1;
		map->dy = -(map->dy);
	}
	p = (2 * (map->dy)) - map->dx;
	while (point.x <= next_point.x)
	{
		put_pixel(map->img, point);
		point.x += 1;
		if (p > 0)
		{
			p = p + 2 * (map->dy - map->dx);
			point.y = point.y + yi;
		}
		else
			p = p + (2 * map->dy);
	}
}

static void	draw_line_high(t_map *map, t_2d point, t_2d next_point)
{
	int32_t	xi;
	int32_t	p;

	map->dx = next_point.x - point.x;
	map->dy = next_point.y - point.y;
	xi = 1;
	if (map->dx < 0)
	{
		xi = -1;
		map->dx = -(map->dx);
	}
	p = (2 * (map->dx)) - map->dy;
	while (point.y <= next_point.y)
	{
		put_pixel(map->img, point);
		point.y += 1;
		if (p > 0)
		{
			p = p + 2 * (map->dx - map->dy);
			point.x = point.x + xi;
		}
		else
			p = p + (2 * map->dx);
	}	
}

static void	draw_line(t_map *map, t_2d point, t_2d next_point)
{
	if (fabs(next_point.y - point.y) < fabs(next_point.x - point.x))
	{
		if (point.x > next_point.x)
			draw_line_low(map, next_point, point);
		else
			draw_line_low(map, point, next_point);
	}
	else
	{
		if (point.y > next_point.y)
			draw_line_high(map, next_point, point);
		else
			draw_line_high(map, point, next_point);
	}
}

void	draw_map(t_map *map)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->column - 1)
		{
			draw_line(map, update_point((*map), map->map_array[i][j]), update_point((*map), map->map_array[i + 1][j]));
			draw_line(map, update_point((*map), map->map_array[i][j]), update_point((*map), map->map_array[i][j + 1]));
			j++;
		}
		i++;
	}
	i = 0;
	j = map->column - 1;
	while (i < map->row - 1)
	{
		draw_line(map, update_point((*map), map->map_array[i][j]), update_point((*map), map->map_array[i + 1][j]));
		i++;
	}
	i = map->row - 1;
	j = 0;
	while (j < map->column - 1)
	{
		draw_line(map, update_point((*map), map->map_array[i][j]), update_point((*map), map->map_array[i][j + 1]));
		j++;
	}
}

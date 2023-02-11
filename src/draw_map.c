/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:39:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/11 22:44:58 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(mlx_image_t *img, t_2d point, int32_t gradient_color)
{
	if (point.x > 0 && point.x < WIDTH \
	&& point.y > 0 && point.y < HEIGHT)
	{
		mlx_put_pixel(img, point.x, point.y, gradient_color);
	}
}

static void	draw_line_low(t_map *map, t_2d point, t_2d next_point)
{
	int32_t	p;
	int32_t	yi;
	t_2d	start_point;

	yi = 1;
	start_point = point;
	if (map->dy < 0)
	{
		yi = -1;
		map->dy = -(map->dy);
	}
	p = (2 * (map->dy)) - map->dx;
	while (point.x <= next_point.x)
	{
		map->gradient_color = coloring(map, start_point, point, next_point);
		put_pixel(map->img, point, map->gradient_color);
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
	int32_t	p;
	int32_t	xi;
	t_2d	start_point;

	xi = 1;
	start_point = point;
	if (map->dx < 0)
	{
		xi = -1;
		map->dx = -(map->dx);
	}
	p = (2 * (map->dx)) - map->dy;
	while (point.y <= next_point.y)
	{
		map->gradient_color = coloring(map, start_point, point, next_point);
		put_pixel(map->img, point, map->gradient_color);
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

void	draw_line(t_map *map, t_2d point, t_2d next_point)
{
	map->dx = next_point.x - point.x;
	map->dy = next_point.y - point.y;
	if (abs(map->dy) < abs(map->dx))
	{
		if (point.x > next_point.x)
		{
			map->dx *= -1;
			map->dy *= -1;
			draw_line_low(map, next_point, point);
		}			
		else
			draw_line_low(map, point, next_point);
	}
	else
	{
		if (point.y > next_point.y)
		{
			map->dx *= -1;
			map->dy *= -1;
			draw_line_high(map, next_point, point);
		}
		else
			draw_line_high(map, point, next_point);
	}
}

void	draw_map(t_map *map)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < map->row - 1)
	{
		j = -1;
		while (++j < map->column - 1)
		{
			draw_line(map, update_pixel((*map), map->map_array[i][j]), \
			update_pixel((*map), map->map_array[i + 1][j]));
			draw_line(map, update_pixel((*map), map->map_array[i][j]), \
			update_pixel((*map), map->map_array[i][j + 1]));
		}
		draw_line(map, update_pixel((*map), map->map_array[i][j]), \
		update_pixel((*map), map->map_array[i + 1][j]));
	}
	j = -1;
	while (++j < map->column - 1)
	{
		draw_line(map, update_pixel((*map), map->map_array[i][j]), \
		update_pixel((*map), map->map_array[i][j + 1]));
	}
}

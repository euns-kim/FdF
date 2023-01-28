/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:39:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/29 00:24:09 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(mlx_image_t *img, int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	yi;
	int32_t	p;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = (2 * dy) - dx;
	while (x0 <= x1)
	{
		mlx_put_pixel(img, x0, y0, 0xEE4B2BFF);
		x0++;
		if (p > 0)
		{
			p = p + 2 * (dy - dx);
			y0 = y0 + yi;
		}
		else
			p = p + (2 * dy);
	}
}

static void	draw_line_high(mlx_image_t *img, int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	xi;
	int32_t	p;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = (2 * dx) - dy;
	while (y0 <= y1)
	{
		mlx_put_pixel(img, x0, y0, 0xEE4B2BFF);
		y0++;
		if (p > 0)
		{
			p = p + 2 * (dx - dy);
			x0 = x0 + xi;
		}
		else
			p = p + (2 * dx);
	}	
}

static void	draw_line(mlx_image_t *img, int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			draw_line_low(img, x1, y1, x0, y0);
		else
			draw_line_low(img, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			draw_line_high(img, x1, y1, x0, y0);
		else
			draw_line_high(img, x0, y0, x1, y1);
	}
}


void	draw_map(mlx_image_t *img, t_map map, t_2d **point)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < map.row - 1)
	{
		j = 0;
		while (j < map.column - 1)
		{
			draw_line(img, point[i][j].x, point[i][j].y, point[i + 1][j].x, point[i + 1][j].y);
			draw_line(img, point[i][j].x, point[i][j].y, point[i][j + 1].x, point[i][j + 1].y);
			j++;
		}
		i++;
	}
}


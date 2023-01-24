/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:24:05 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/17 00:08:40 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	yi;
	int	p;

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
		mlx_put_pixel(g_img, x0, y0, 0xEE4B2BFF);
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

static void	draw_line_high(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	xi;
	int	p;

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
		mlx_put_pixel(g_img, x0, y0, 0xEE4B2BFF);
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

void	draw_line(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			draw_line_low(g_img, x1, y1, x0, y0);
		else
			draw_line_low(g_img, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			draw_line_high(g_img, x1, y1, x0, y0);
		else
			draw_line_high(g_img, x0, y0, x1, y1);
	}
}

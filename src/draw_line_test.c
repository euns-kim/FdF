/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:24:05 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/14 00:33:29 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
// #include <stdlib.h>
// #include <memory.h>
// #define WIDTH 1000
// #define HEIGHT 600
// #define BPP sizeof(int32_t)

void	draw_line_low(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
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

void	draw_line_high(mlx_image_t *g_img, int x0, int y0, int x1, int y1)
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

// int32_t	main(void)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*g_img;

// 	mlx = mlx_init(WIDTH, HEIGHT, "BRESENHAM", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!g_img)
// 		exit(EXIT_FAILURE);
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
// 	if (mlx_image_to_window(mlx, g_img, 0, 0) < 0)
// 		exit(EXIT_FAILURE);
// 	draw_line(g_img, 100, 100, 200, 300);
// 	draw_line(g_img, 100, 100, 300, 100);
// 	draw_line(g_img, 100, 100, 100, 300);
// 	draw_line(g_img, 100, 300, 300, 300);
// 	draw_line(g_img, 300, 100, 300, 300);
// 	draw_line(g_img, 100, 100, 300, 300);
// 	draw_line(g_img, 100, 300, 300, 100);
// 	draw_line(g_img, 100, 100, 300, 150);
// 	draw_line(g_img, 150, 100, 100, 300);
// 	draw_line(g_img, 100, 300, 300, 200);
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, g_img);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

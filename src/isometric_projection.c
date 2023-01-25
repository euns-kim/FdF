/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:39:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/25 18:41:02 by eunskim          ###   ########.fr       */
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


static void	draw_map(mlx_image_t *img, t_map map, t_2d **point)
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

void	free_array2(int i, t_2d **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static t_2d	**isometric_projection(t_map map, t_coordis **map_array, t_2d **point)
{
	int32_t	i;
	int32_t j;
	double	new_axis;
	double	new_ordinate;
	
	i = 0;
	new_axis = WIDTH / 2;
	new_ordinate = HEIGHT / 2;
	point = malloc(map.row * sizeof(t_2d *));
	if (point == NULL)
		exit(EXIT_FAILURE);
	while (i < map.row)
	{
		point[i] = malloc(map.column * sizeof(t_2d));
		if (point[i] == NULL)
		{
			free_array2(i - 1, point);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < map.row)
	{	
		j = 0;
		while (j < map.column)
		{
			point[i][j].x = round(new_axis + (map_array[i][j].x - map_array[i][j].y) * cos(0.46365) * (double) 20);
			point[i][j].y = round(new_ordinate + ((map_array[i][j].x + map_array[i][j].y) * sin(0.46365) - map_array[i][j].z) * (double) 20);
			j++;	
		}
		i++;
	}
	return (point);
}

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		new_axis;
	double		new_ordinate;
	t_map		*map;
}	t_data;

typedef struct s_rule
{
	double		factor; // zoom in/out
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
}	t_rule;

int32_t	mlx_start(t_map map, t_coordis **map_array)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_2d		**point;

	mlx = mlx_init(WIDTH, HEIGHT, "FdF - eunskim", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		exit(EXIT_FAILURE);
	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	point = isometric_projection(map, map_array, NULL);
	draw_map(img, map, point);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	// system("leaks fdf");
	return (EXIT_SUCCESS);
}

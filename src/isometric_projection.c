/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:41:42 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/17 00:09:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*img;

t_isometric	isometric_projection(int x, int y, int z)
{
	t_isometric point;
	int			new_axis;
	int			new_ordinate;

	new_axis = WIDTH / 2;
	new_ordinate = HEIGHT / 2;
	point.x = new_axis + (x - y) * cos(0.46365);
	point.y = new_ordinate + ((x + y) * sin(0.46365) - z);
	return (point);
}

void	draw_cube(mlx_image_t *img)
{
	t_isometric	point1;
	t_isometric	point2;
	t_isometric	point3;
	t_isometric	point4;
	t_isometric	point5;
	t_isometric	point6;
	t_isometric	point7;
	t_isometric	point8;
	
	// point1 = isometric_projection(200, 200, 0);
	// point2 = isometric_projection(500, 200, 0);
	// point3 = isometric_projection(200, 500, 0);
	// point4 = isometric_projection(500, 500, 0);
	// point5 = isometric_projection(200, 200, 400);
	// point6 = isometric_projection(500, 200, 400);
	// point7 = isometric_projection(200, 500, 400);
	// point8 = isometric_projection(500, 500, 400);

	point1 = isometric_projection(0, 0, 0);
	point2 = isometric_projection(100, 0, 0);
	point3 = isometric_projection(0, 50, 0);
	point4 = isometric_projection(100, 50, 0);
	point5 = isometric_projection(0, 0, 30);
	point6 = isometric_projection(100, 0, 30);
	point7 = isometric_projection(0, 50, 30);
	point8 = isometric_projection(100, 50, 30);


	draw_line(img, point1.x, point1.y, point2.x, point2.y);
	draw_line(img, point1.x, point1.y, point3.x, point3.y);
	draw_line(img, point1.x, point1.y, point5.x, point5.y);
	draw_line(img, point5.x, point5.y, point6.x, point6.y);
	draw_line(img, point5.x, point5.y, point7.x, point7.y);
	draw_line(img, point2.x, point2.y, point4.x, point4.y);
	draw_line(img, point2.x, point2.y, point6.x, point6.y);
	draw_line(img, point3.x, point3.y, point4.x, point4.y);
	draw_line(img, point3.x, point3.y, point7.x, point7.y);
	draw_line(img, point4.x, point4.y, point8.x, point8.y);
	draw_line(img, point6.x, point6.y, point8.x, point8.y);
	draw_line(img, point7.x, point7.y, point8.x, point8.y);
}

int32_t	main(void)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_cube(img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

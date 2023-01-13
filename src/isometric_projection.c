/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:41:42 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/14 00:43:54 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 1540
#define HEIGHT 1028
#define BPP sizeof(int32_t)

typedef struct s_isometric {
	int	x;
	int	y;
}	t_isometric;

int32_t isometric_projection(int x, int y, int z)
{
	t_isometric point;
	int			new_axis;
	int			new_ordinate;
	
	new_axis = WIDTH / 2;
	new_ordinate = HEIGHT / 2;
	point.x = new_axis + (x - y) * cos(0.46365);
	point.y = new_ordinate + ((x + y) * sin(0.46365) - z);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
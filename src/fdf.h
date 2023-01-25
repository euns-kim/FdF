/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/25 18:51:47 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 1540
#define HEIGHT 1028
#define BPP sizeof(int32_t)

typedef struct s_map {
	double	row;
	double	column;
}	t_map;

typedef struct s_coordis {
	double	x;
	double	y;
	double	z;
	t_2d	pixel
}	t_coordis;

typedef struct s_2d {
	int32_t	x;
	int32_t	y;
}	t_2d;

// typedef struct s_isometric {
// 	int	x;
// 	int	y;
// }	t_isometric;

/* main */
int32_t 	main(int32_t argc, char **argv);

/* get_map */
void		get_map_size(int32_t fd, t_map *map);
t_coordis	**get_map(int32_t fd, t_map map, t_coordis **map_array);

/* get_map_utils*/
int32_t		fdf_atoi(char **str);
void		free_p(char	*p);
void		free_array(int32_t i, t_coordis **array);
int32_t		mlx_start(t_map map, t_coordis **map_array);


// void			draw_line(mlx_image_t *g_img, int x0, int y0, int x1, int y1);
// void			draw_cube(mlx_image_t *img);
// void			rotate(void);
// t_isometric	isometric_projection(int x, int y, int z);

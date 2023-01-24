/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/24 01:51:30 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/get_next_line/get_next_line.h"
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
	float	row;
	float	column;
}	t_map;

typedef struct s_coordis {
	float	x;
	float	y;
	float	z;
//	t_2d	pixel;
}	t_coordis;

// typedef struct s_2d {
// 	float	x;
// 	float	y;
// }	t_2d;

// typedef struct s_isometric {
// 	int	x;
// 	int	y;
// }	t_isometric;

// typedef struct s_coordinates {
// 	int x;
// 	int y;
// 	int z;
// }	t_coordinates;

/* main */
int 		fdf(int argc, char **argv);

/* get_map */
void		get_map_size(int fd, t_map *map);
t_coordis	**get_map(int fd, t_map map, t_coordis **map_array);

/* get_map_utils*/
int			fdf_atoi(char **str);
void		free_p(char	*p);
void		free_array(int i, t_coordis **array);

// void			draw_line(mlx_image_t *g_img, int x0, int y0, int x1, int y1);
// void			draw_cube(mlx_image_t *img);
// void			rotate(void);
// t_isometric	isometric_projection(int x, int y, int z);

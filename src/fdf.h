/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/29 00:15:58 by eunskim          ###   ########.fr       */
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
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*filename;
	double		row;
	double		column;
	double		factor;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
}	t_map;

typedef struct s_coordis {
	double	x;
	double	y;
	double	z;
}	t_coordis;

typedef struct s_2d {
	int32_t	x;
	int32_t	y;
}	t_2d;


/* main */
int32_t 	main(int32_t argc, char **argv);
// void		free_all(t_map map, t_coordis **map_array, t_2d **point_array);

/* get_map */
void		get_map_size(t_map *map);
t_coordis	**get_map(t_map map, t_coordis **map_array);

/* get_map_utils*/
int32_t		fdf_atoi(char **str);
void		free_p(char	*p);
void		free_array(int32_t i, t_coordis **array);


void		hook(void *param);

// t_2d		**isometric_projection(t_map map, t_coordis **map_array, t_2d **point);
// t_coordis	**rotate(t_map map, t_coordis **map_array);

// t_2d		**update_point(t_map *map, t_coordis **map_array, t_2d **point);
// void		free_array2(int32_t i, t_2d **array);
// void		draw_map(mlx_image_t *img, t_map map, t_2d **point);

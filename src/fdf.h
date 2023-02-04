/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/04 23:11:49 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# define WIDTH 1540
# define HEIGHT 1028
# define BPP 4

typedef struct s_coordis {
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}	t_coordis;

typedef struct s_map {
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*filename;
	double		row;
	double		column;
	double		new_axis;
	double		new_ordinate;
	double		factor;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	int32_t		x_offset;
	int32_t		y_offset;
	int32_t		dx;
	int32_t		dy;
	t_coordis	**map_array;
}	t_map;

typedef struct s_2d {
	double		x;
	double		y;
	uint32_t	color;
}	t_2d;

/* main */
int32_t		main(int32_t argc, char **argv);
// void		free_all(t_map map, t_coordis **map_array, t_2d **point_array);

/* get_map */
void		get_map_size(t_map *map);
void		get_map(t_map *map);

/* get_map_utils*/
uint32_t	get_color(char **str);
int32_t		fdf_atoi(char **str);
void		free_p(char	*p);
void		free_array(int32_t i, t_coordis **array);

/* matrix manipulation */
void		keyhook(void *param);
void		scrollhook(double xdelta, double ydelta, void *param);
t_coordis	rotate(t_map map, t_coordis vector);

/* get actual 2d point */
t_2d		update_pixel(t_map map, t_coordis map_struct);

/* draw */
void		draw_map(t_map *map);

/* coloring */
int32_t	coloring(t_map *map, t_2d start, t_2d current, t_2d end);

#endif

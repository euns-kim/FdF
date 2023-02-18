/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/18 22:05:54 by eunskim          ###   ########.fr       */
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

typedef struct s_2d {
	double		x;
	double		y;
	uint32_t	color;
}	t_2d;

typedef struct s_map {
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*filename;
	double		row;
	double		column;
	double		new_axis;
	double		new_ordinate;
	double		factor;
	double		z_inc;
	double		scale_p;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	int32_t		x_offset;
	int32_t		y_offset;
	int32_t		dx;
	int32_t		dy;
	int32_t		gradient_color;
	t_coordis	**map_array;
}	t_map;

/* main */
int32_t		main(int32_t argc, char **argv);

/* get_map */
void		get_map_size(t_map *map);
void		get_map(t_map *map);

/* get_map_utils*/
int32_t		fdf_atoi(char **str);
uint32_t	get_color(char **str);
void		save_values(t_map *map);
void		free_p(char	*p);
void		free_array(int32_t i, t_coordis **array);

/* scale */
void		scale(t_map *map);
double		get_scale(double max_x, double max_y);
void		scale_parallel_projection(int32_t key, t_map *map);

/* hooks */
void		hook(void *param);
void		hook2(void *param);
void		keyhook(mlx_key_data_t keydata, void *param);
void		scrollhook(double xdelta, double ydelta, void *param);

/* matrix manipulation */
void		rule_rotate(int32_t key, t_map *map);
t_coordis	rotate(t_map map, t_coordis vector);
void		rule_translate(int32_t key, t_map *map);
void		manipulate_z(int32_t key, t_map *map);
void		to_default(int32_t key, t_map *map);
void		zoom(double xdelta, double ydelta, t_map *map);

/* get actual 2d point */
t_2d		update_pixel(t_map map, t_coordis map_struct);

/* draw */
void		draw_map(t_map *map);
void		draw_parallel_map(int32_t key, t_map *map);
void		draw_line(t_map *map, t_2d point, t_2d next_point);

/* gradient */
int32_t		coloring(t_map *map, t_2d start, t_2d current, t_2d end);

/* parallel projection */
void		parallel_map(int32_t key, t_map *map);
t_2d		parallel_projection(int32_t key, t_map *map, t_coordis map_struct);

/* manual */
void		print_manual(void);

#endif

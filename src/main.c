/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:30:58 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/31 22:29:30 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	free_all(t_map map, t_coordis **map_array, t_2d **point_array)
// {
// 	free_array(map.row - 1, map_array);
// 	free_array2(map.row - 1, point_array);
// }

static void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF - eunskim", true);
	if (!(map->mlx))
	{
		printf("MLX failed");
		exit(EXIT_FAILURE);
	}
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!(map->img))
	{
		printf("MLX failed");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
	{
		printf("MLX failed");
		exit(EXIT_FAILURE);
	}
}

static void	init_map(t_map *map, char *arg)
{
	map->new_axis = WIDTH / 2;
	map->new_ordinate = HEIGHT / 2;
	map->factor = 20;
	map->rotate_x = 0;
	map->rotate_y = 0;
	map->rotate_z = 0;
	map->x_offset = 0;
	map->y_offset = 0;
	map->filename = arg;
	map->map_array = NULL;
}

static int32_t	extension_check(const char *arg)
{
	size_t	i;
	size_t	j;
	char	*extension;

	i = 0;
	j = 0;
	extension = ".fdf";
	while (*(arg + i + 1) != '\0')
		i++;
	while (j < 4)
	{
		if (*(arg + i - j) != extension[3 - j])
			return (0);
		j++;
	}
	return (1);
}

static void	arg_check(int32_t argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./fdf [filename].fdf");
		exit(EXIT_FAILURE);
	}
	if (extension_check(argv[1]) == 0)
	{
		printf("Wrong file extension. Should be a .fdf file.");
		exit(EXIT_FAILURE);
	}
}

int32_t	main(int32_t argc, char **argv)
{
	t_map		map;

	arg_check(argc, argv);
	init_map(&map, argv[1]);
	get_map_size(&map);
	get_map(&map);
	mlx_start(&map);
	memset(map.img->pixels, 255, map.img->width * map.img->height * BPP);
	draw_map(&map);
	mlx_loop_hook(map.mlx, &keyhook, &map);
	mlx_scroll_hook(map.mlx, &scrollhook, &map);
	mlx_loop(map.mlx);
	mlx_delete_image(map.mlx, map.img);
	mlx_terminate(map.mlx);
	free_array(map.row - 1, map.map_array);
	exit(EXIT_SUCCESS);
}

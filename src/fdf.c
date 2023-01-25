/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:30:58 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/25 15:32:21 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t main(int32_t argc, char **argv)
{
	int32_t		fd;
	t_map		map;
	t_coordis	**map_array;

	if (argc != 2)
	{
		printf("Usage: ./fdf [filename].fdf");
		exit(EXIT_FAILURE);
	}
	// if (argv[1] != "[filename].fdf")
	// 	exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}
	get_map_size(fd, &map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}
	map_array = NULL;
	map_array = get_map(fd, map, map_array);
	close(fd);
	// print_map(map, map_array);
	mlx_start(map, map_array);
	free_array(map.row - 1, map_array);
	exit(EXIT_SUCCESS);
}

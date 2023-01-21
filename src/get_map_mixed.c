/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:51:37 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/21 19:42:46 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_map {
	int		row;
	int		column;
}	t_map;

typedef struct s_coordis {
	float	x;
	float	y;
	float	z;
//	t_2d	pixel;
}	t_coordis;

// typedef struct s_2d {
// 	int	x;
// 	int y;
// }	t_2d;

static int	fdf_atoi(char **str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		sum = sum * 10 + (**str - '0');
		(*str)++;
	}
	return (sum * sign);
}

static void	ignore_color(char **str)
{	
	if (**str == ',')
	{
		while (**(str + 1) != ' ' && **(str + 1) != '\n')
			(*str)++;
	}
}

void	print_map(t_map *map, t_coordis **map_array)
{
	int i = 0;
	int j = 0;
	while (i < map->row)
	{
		j = 0;
		printf("\n");
		while (j < map->column)
		{
			printf("%d ", (int) map_array[i][j].z);
			j++;	
		}
		i++;
	}
}

static t_coordis	**get_map(char *line, t_map *map, t_coordis **temp_array)
{
	int	i;
	int	j;
	int	k;
	t_coordis coordis[map->column];

	k = 0;
	temp_array = get_map(line, map, temp_array);
	while (k < map->row)
	{
		*(map_array + k) = *(temp_array + k);
		k++;
	}		
	free(temp_array);
	return (map_array);

	i = map->row - 1;
	j = 0;
	temp_array = malloc(map->row * sizeof(t_coordis*));
	temp_array[i] = malloc(map->column * sizeof(t_coordis));
	*(temp_array[i]) = coordis[map->column];

	while (j < map->column)
	{
		while (*line == ' ')
			line++;
		if ((*line >= '0' && *line <= '9') || *line == '-')
		{
			temp_array[i][j].z = fdf_atoi(&line);
			j++;
		}
		ignore_color(&line);
	}
	return (temp_array);
}

t_coordis	*parse_line(char *line, t_map *map, t_coordis **map_array);


static void	get_column(char *line, t_map *map)
{
	map->column = 1;
	while (*line == ' ' && *(line + 1) != '\n')
		line++;
	while (*(line + 1) != '\n')
	{
		if (*line == ' ' && *(line + 1) != ' ')
			map->column++;
		line++;
	}
}

static void	get_map_size(int fd, t_map *map)
{
	char		*line;
	t_coordis	**map_array;
	
	map->row = 0;
	line = get_next_line(fd);
	map_array = NULL;
	while (line)
	{
		map->row++;
		get_column(line, map);
		get_map(line, map, map_array);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n%d\n", map->row);
	printf("\n%d\n", map->column);
	print_map(map, map_array);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (argc != 2)
		printf("Usage: ./fdf [filename].map");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printf("file open error\n");
	get_map_size(fd, &map);
	close(fd);
}

// main: argv = ".fdf"
// malloc fail
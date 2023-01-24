/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:51:37 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/24 01:42:10 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (**str == ',')
	{
		while (**str != ' ' && **str != '\n' && **str != '\0')
			(*str)++;
	}
	return (sum * sign);
}

// void	print_map(t_map map, t_coordis **map_array)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map.row)
// 	{
// 		j = 0;
// 		printf("\n");
// 		while (j < map.column)
// 		{
// 			// printf("%.2f\t%.2f\t%.2f\n", map_array[i][j].x, map_array[i][j].y, map_array[i][j].z);
// 			printf("%.2f\t", map_array[i][j].z);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// }

static void	free_p(char	*p)
{
	if (p)
		free(p);
}

static t_coordis	**parse_map(int fd, t_map map, t_coordis **map_array)
{
	int		i;
	int		j;
	char	*line;
	char	*line_cpy;

	i = -1;
	while (i++ < map.row)
	{
		j = -1;
		line = get_next_line(fd);
		line_cpy = line;
		while (j++ < map.column && line)
		{	
			while (*line == ' ')
				line++;
			if ((*line >= '0' && *line <= '9') || *line == '-')
			{
				map_array[i][j].x = i - (map.row / 2);
				map_array[i][j].y = j - (map.column / 2);
				map_array[i][j].z = fdf_atoi(&line);
			}
		}
		free_p(line_cpy);
	}
	return (map_array);
}

static void	free_array(int i, t_coordis **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static t_coordis	**get_map(int fd, t_map map, t_coordis **map_array)
{
	int	i;

	i = 0;
	map_array = malloc(map.row * sizeof(t_coordis *));
	if (map_array == NULL)
		exit(EXIT_FAILURE);
	while (i < map.row)
	{
		map_array[i] = malloc(map.column * sizeof(t_coordis));
		if (map_array[i] == NULL)
		{
			free_array(i - 1, map_array);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map_array = parse_map(fd, map, map_array);
	return (map_array);
}

static void	get_column(char *line, t_map *map)
{
	float	prev_column;

	if (map->row != 1)
		prev_column = map->column;
	map->column = 1;
	while (*line == ' ' && *(line + 1) != '\n')
		line++;
	while (*(line + 1) != '\n' && *(line + 1) != '\0')
	{
		if (*line == ' ' && *(line + 1) != ' ')
			map->column++;
		line++;
	}
	if (map->row != 1 && prev_column != map->column)
	{
		printf("Found wrong line length. Exiting.");
		exit(EXIT_FAILURE);
	}
	// printf("\n %fth row: column = %f \n", map->row, map->column);
}

static void	get_map_size(int fd, t_map *map)
{
	char		*line;

	map->row = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->row++;
		get_column(line, map);
		free(line);
		line = get_next_line(fd);
	}
	// printf("\n row = %.2f \n", map->row);
	// printf("\n column = %.2f \n\n", map->column);
}

int	main(int argc, char **argv)
{
	int			fd;
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
	free_array(map.row - 1, map_array);
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:42:19 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/24 01:44:06 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_coordis	**get_map(int fd, t_map map, t_coordis **map_array)
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
}

void	get_map_size(int fd, t_map *map)
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
}

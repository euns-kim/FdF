/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:42:19 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/11 21:42:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_map(int32_t fd, t_map *map)
{
	int32_t	i;
	int32_t	j;
	char	*line;
	char	*line_cpy;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		line = get_next_line(fd);
		line_cpy = line;
		while (++j < map->column && line)
		{	
			while (*line == ' ')
				line++;
			if ((*line >= '0' && *line <= '9') || *line == '-')
			{
				map->map_array[i][j].z = fdf_atoi(&line);
				if (*line == ',')
					map->map_array[i][j].color = get_color(&line);
			}
		}
		free_p(line_cpy);
	}
}

static t_coordis	**calloc_map(t_map map, t_coordis **map_array)
{
	int32_t	i;

	i = 0;
	map_array = ft_calloc(map.row, sizeof(t_coordis *));
	if (map_array == NULL)
	{
		ft_printf("Calloc failed.");
		// system("leaks fdf");
		exit(EXIT_FAILURE);
	}
	while (i < map.row)
	{
		map_array[i] = ft_calloc(map.column, sizeof(t_coordis));
		if (map_array[i] == NULL)
		{	
			free_array(i - 1, map_array);
			ft_printf("Calloc failed.");
			// system("leaks fdf");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map_array);
}

void	get_map(t_map *map)
{
	int32_t	fd;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file open error\n");
		// system("leaks fdf");
		exit(EXIT_FAILURE);
	}
	map->map_array = calloc_map((*map), map->map_array);
	parse_map(fd, map);
	save_values(map);
	if (close(fd) < 0)
	{
		free_array(map->row - 1, map->map_array);
		ft_printf("file close error\n");
		// system("leaks fdf");
		exit(EXIT_FAILURE);
	}
}

static int32_t	get_column(char *line, t_map *map)
{
	double	prev_column;
	char	*line_cpy;

	line_cpy = line;
	if (map->row != 1)
		prev_column = map->column;
	map->column = 1;
	while (*line == ' ' && *(line + 1) != '\n' && *(line + 1) != '\0')
		line++;
	while (*(line + 1) != '\n' && *(line + 1) != '\0')
	{
		if (*line == ' ' && *(line + 1) != ' ')
			map->column++;
		line++;
	}
	free(line_cpy);
	if (map->row != 1 && prev_column != map->column)
	{
		ft_printf("Found wrong line length. Exiting.");
		// system("leaks fdf");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	get_map_size(t_map *map)
{
	int32_t	fd;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file open error\n");
		// system("leaks fdf");
		exit(EXIT_FAILURE);
	}
	map->row = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->row++;
		if (get_column(line, map) == 1)
		{
			// system("leaks fdf");
			exit(EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
	{
		ft_printf("file close error\n");
		// system("leaks fdf");
		exit(EXIT_FAILURE);
	}
}

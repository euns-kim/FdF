/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:51:37 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/19 03:03:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_map {
	int		row;
	int		column;
}	t_map;

static void	get_column(char *line, t_map **map)
{
	(*map)->column = 1;
	while (*line == ' ' && *(line + 1) != '\0')
		line++;
	while (*(line + 1) != '\0' && *(line + 1) != '\n')
	{
		if (*line == ' ' && *(line + 1) != ' ')
			(*map)->column++;
		line++;
	}
}

static void	get_map_size(int fd, t_map *map)
{
	char	*line;

	map->row = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->row++;
		get_column(line, &map);
		get_map(line, &map);
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2)
		printf("Usage: ./map [filename].map");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printf("file open error\n");
	get_map_size(fd, &map);
	close(fd);
}

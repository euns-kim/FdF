
static void	print_map(t_map map, t_coordis **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		printf("\n");
		while (j < map.column)
		{
			printf("%.2f\t%.2f\t%.2f\n", map_array[i][j].x, map_array[i][j].y, map_array[i][j].z);
			// printf("%.2f\t", map_array[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

static void	print_map2(t_map map, t_2d **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		printf("\n");
		while (j < map.column)
		{
			printf("%d\t%df\n", map_array[i][j].x, map_array[i][j].y);
			// printf("%.2f\t", map_array[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

t_2d	**update_point(t_map *map, t_coordis **map_array, t_2d **point)
{
	map_array = rotate(*map, map_array);
	print_map(*map, map_array);
	point = isometric_projection(*map, map_array, point);
	print_map2(*map, point);
	draw_map(map->img, *map, point);
	return (point);
}


void	free_array2(int32_t i, t_2d **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}


t_2d	**isometric_projection(t_map map, t_coordis **map_array, t_2d **point)
{
	int32_t	i;
	int32_t j;
	double		new_axis;
	double		new_ordinate;

	i = 0;
	new_axis = WIDTH / 2;
	new_ordinate = HEIGHT / 2;
	while (i < map.row)
	{	
		j = 0;
		while (j < map.column)
		{
			point[i][j].x = round(new_axis + (map_array[i][j].x - map_array[i][j].y) * cos(0.46365));
			point[i][j].y = round(new_ordinate + ((map_array[i][j].x + map_array[i][j].y) * sin(0.46365) - map_array[i][j].z));
			j++;	
		}
		i++;
	}
	return (point);
}

static t_2d	**malloc_point(t_map map, t_2d **point_array)
{
	int i;

	i = 0;
	point_array = malloc(map.row * sizeof(t_2d *));
	if (point_array == NULL)
	{
		printf("Malloc failed.");
		exit(EXIT_FAILURE);
	}
	while (i < map.row)
	{
		point_array[i] = malloc(map.column * sizeof(t_2d));
		if (point_array[i] == NULL)
		{
			free_array2(i - 1, point_array);
			printf("Malloc failed.");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (point_array);
}

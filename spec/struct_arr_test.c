#include <stdio.h>
#include <stdlib.h>

typedef struct s_coordis {
	float	x;
	float	y;
	float	z;
//	t_2d	pixel;
}	t_coordis;

void	set_5(t_coordis *coords)
{
	coords->x = 5;
	coords->y = 5;
	coords->z = 5;
}

void	set_value(t_coordis *coords, float value)
{
	coords->x = value;
	coords->y = value;
	coords->z = value;
}

void	print_coord(t_coordis *coords)
{
	printf("%.2f\t%.2f\t%.2f\n", coords->x, coords->y, coords->z);
}

int	main(void)
{
	int			width = 10;
	int			height = 10;
	int			index = 0;
	int			w_index = 0;
	t_coordis	**arr;

	arr = malloc(height * sizeof(t_coordis *));
	while (index < height)
	{
		arr[index] = malloc(width * sizeof(t_coordis));
		w_index = 0;
		while (w_index < width)
		{
			arr[index][w_index].x = index;
			arr[index][w_index].y = index;
			arr[index][w_index].z = index;
			w_index++;
		}
		index++;
	}
	index = 0;
	while (index < height)
	{
		w_index = 0;
		while (w_index < width)
		{
			print_coord(&arr[index][w_index]);
			w_index++;
		}
		index++;
	}
	return (0);
}

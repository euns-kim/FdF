#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#define WIDTH 1540
#define HEIGHT 1028
#define BPP sizeof(int32_t)

typedef struct s_isometric {
	int	x;
	int	y;
}	t_isometric;

typedef struct s_coordinates {
	int x;
	int y;
	int z;
}	t_coordinates;

void		draw_line(mlx_image_t *g_img, int x0, int y0, int x1, int y1);
void		draw_cube(mlx_image_t *img);
void		rotate(void);
t_isometric	isometric_projection(int x, int y, int z);
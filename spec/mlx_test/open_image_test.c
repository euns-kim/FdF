#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define WIDTH 1300
#define HEIGHT 867

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
	if (!mlx)
		error();
	
	mlx_texture_t	*texture = mlx_load_png("./black_smoky.png");
	if (!texture)
		error();

	mlx_image_t	*img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1540
#define HEIGHT 1028
#define BPP sizeof(int32_t)

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 20;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 20;
}

// void	my_keyhook(mlx_key_data_t keydata, void *param)
// {
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
// }

// void	my_scrollhook(double xdelta, double ydelta, void *param)
// {
// 	if (ydelta > 0)
// 		puts("Up!");
// 	else if (ydelta < 0)
// 		puts("Down!");
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }

// void	key_hook(mlx_key_data_t keydata, void *param)
// {
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
// 		puts("Gotta grab it all!");
// }

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 128, 128);
	memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	// mlx_key_hook(mlx, &my_keyhook, NULL);
	// mlx_key_hook(mlx, &key_hook, NULL);
	// mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
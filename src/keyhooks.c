/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:46:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/29 17:14:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// MLX_KEY_IS_DOWN
// Q / W : X_AXIS ROTATION
// A / S : Y_AXIS ROTATION
// Z / X : Z_AXIS ROTATION
// CMD+ : ROTATION OF 45 DEGREE ANGLE
// D : TO DEFAULT

static void	rule_rotate(int32_t key, t_map *map)
{
	if (key == MLX_KEY_Q)
		map->rotate_x += 5;
	if (key == MLX_KEY_W)
		map->rotate_x -= 5;
	if (key == MLX_KEY_A)
		map->rotate_y += 5;
	if (key == MLX_KEY_S)
		map->rotate_y += 5;
	if (key == MLX_KEY_Z)
		map->rotate_y += 5;
	if (key == MLX_KEY_X)
		map->rotate_y += 5;
	draw_map(map);
}

void	hook(void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
		rule_rotate(MLX_KEY_Q, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		rule_rotate(MLX_KEY_W, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		rule_rotate(MLX_KEY_A, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		rule_rotate(MLX_KEY_S, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Z))
		rule_rotate(MLX_KEY_Z, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_X))
		rule_rotate(MLX_KEY_X, map);
}

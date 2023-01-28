/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:16:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/28 22:03:34 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordis	**rotate_x(t_map map, t_coordis **point, double alpha)
{
	int i;
	int	j;
	int prev_y;
	int prev_z;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.column)
		{
			prev_y = point[i][j].y;
			prev_z = point[i][j].z;
			point[i][j].x = prev_y * cos(alpha) + prev_z * sin(alpha);
			point[i][j].z = prev_y * -(sin(alpha)) + prev_z * cos(alpha);
			j++;
		}
		i++;
	}
	return (point);
}

t_coordis	**rotate_y(t_map map, t_coordis **point, double beta)
{
	int i;
	int	j;
	int prev_x;
	int prev_z;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.column)
		{
			prev_x = point[i][j].x;
			prev_z = point[i][j].z;
			point[i][j].x = prev_x * cos(beta) - prev_z * sin(beta);
			point[i][j].z = prev_z * sin(beta) + prev_z * cos(beta);
			j++;
		}
		i++;
	}
	return (point);
}

t_coordis	**rotate_z(t_map map, t_coordis **point, double gamma)
{
	int i;
	int	j;
	int prev_x;
	int prev_y;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.column)
		{
			prev_x = point[i][j].x;
			prev_y = point[i][j].y;
			point[i][j].x = prev_x * cos(gamma) + prev_y * sin(gamma);
			point[i][j].y = prev_x * -(sin(gamma)) + prev_y * cos(gamma);
			j++;
		}
		i++;
	}
	return (point);
}

t_coordis	**rotate(t_map map, t_coordis **map_array)
{
	double alpha = map.rule.rotate_x * (M_PI / 180);
	double beta = map.rule.rotate_y * (M_PI / 180);
	double gamma = map.rule.rotate_z * (M_PI / 180);

	printf("%f\t%f\t%f\n", alpha, beta, gamma);
	map_array = rotate_x(map, map_array, alpha);
	map_array = rotate_y(map, map_array, beta);
	map_array = rotate_z(map, map_array, gamma);
	return (map_array);
}

// MLX_KEY_IS_DOWN
// Q / W : X_AXIS ROTATION
// A / S : Y_AXIS ROTATION
// Z / S : Z_AXIS ROTATION
// C : 2D ROTATION (ORIGIN CENTERED)
// CMD+ : ROTATION OF 45 DEGREE ANGLE
// D : TO DEFAULT

// HOW TO GET THE ALPHA, BETA, GAMMA?
// NEED FUNCTIONS THAT CALCULATE THE ROTATION ANGLE EACH TIME KEY IS DOWN 
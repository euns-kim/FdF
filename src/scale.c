/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:07:38 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/09 19:12:15 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_scale(double max_x, double max_y)
{
	double	factor_x;
	double	factor_y;
	double	scale;

	factor_x = (WIDTH / 2 - WIDTH / 10) / max_x;
	factor_y = (HEIGHT / 2 - HEIGHT / 10) / max_y;
	scale = factor_x;
	if (factor_y < factor_x)
		scale = factor_y;
	return (scale);
}

static void	max_xy(t_coordis point, double *max_x, double *max_y)
{
	double	current_x;
	double	current_y;

	current_x = ((point.x - point.y) * cos(0.46365));
	if (*max_x < fabs(current_x))
		*max_x = fabs(current_x);
	current_y = ((point.x + point.y) * sin(0.46365) - point.z);
	if (*max_y < fabs(current_y))
		*max_y = fabs(current_y);
}

void	scale(t_map *map)
{
	int32_t	i;
	int32_t	j;
	double	max_x;
	double	max_y;

	i = 0;
	max_x = 0;
	max_y = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			max_xy(map->map_array[i][j], &max_x, &max_y);
			j++;
		}
		i++;
	}
	map->factor = get_scale(max_x, max_y);
}
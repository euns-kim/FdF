/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:15:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/04 23:15:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;

	if (distance == 0)
		return (1);
	else
		return (placement / distance);
}

static int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int32_t	coloring(t_map *map, t_2d start, t_2d current, t_2d end)
{
    uint8_t	red;
    uint8_t	green;
    uint8_t	blue;
	uint8_t	a;
    double  	percentage;

	if (current.color == end.color)
		return (current.color);
	if (map->dx > map->dy)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	a = 0xFF;
    return ((red << 24) | (green << 16) | (blue << 8) | a);
}
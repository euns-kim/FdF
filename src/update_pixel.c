/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:16:40 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/03 23:31:47 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d	update_pixel(t_map map, t_coordis map_struct)
{
	t_coordis	vector;
	t_2d		pixel;

	vector = map_struct;
	vector = rotate(map, vector);
	pixel.x = (vector.x - vector.y) * cos(0.46365);
	pixel.y = (vector.x + vector.y) * sin(0.46365) - vector.z;
	pixel.x *= map.factor;
	pixel.y *= map.factor;
	pixel.x += map.new_axis;
	pixel.y += map.new_ordinate;
	pixel.x += map.x_offset;
	pixel.y += map.y_offset;
	pixel.x = round(pixel.x);
	pixel.y = round(pixel.y);
	return (pixel);
}

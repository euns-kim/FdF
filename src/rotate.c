/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:16:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/11 22:14:26 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_coordis *vector, double gamma)
{
	double	prev_x;
	double	prev_y;

	prev_x = vector->x;
	prev_y = vector->y;
	vector->x = prev_x * cos(gamma) + prev_y * sin(gamma);
	vector->y = -prev_x * sin(gamma) + prev_y * cos(gamma);
}

static void	rotate_y(t_coordis *vector, double beta)
{
	double	prev_x;
	double	prev_z;

	prev_x = vector->x;
	prev_z = vector->z;
	vector->x = prev_x * cos(beta) - prev_z * sin(beta);
	vector->z = prev_x * sin(beta) + prev_z * cos(beta);
}

static void	rotate_x(t_coordis *vector, double alpha)
{
	double	prev_y;
	double	prev_z;

	prev_y = vector->y;
	prev_z = vector->z;
	vector->y = prev_y * cos(alpha) + prev_z * sin(alpha);
	vector->z = -prev_y * sin(alpha) + prev_z * cos(alpha);
}

t_coordis	rotate(t_map map, t_coordis vector)
{
	double	alpha;
	double	beta;
	double	gamma;

	alpha = map.rotate_x * (M_PI / 180);
	beta = map.rotate_y * (M_PI / 180);
	gamma = map.rotate_z * (M_PI / 180);
	rotate_x(&vector, alpha);
	rotate_y(&vector, beta);
	rotate_z(&vector, gamma);
	return (vector);
}

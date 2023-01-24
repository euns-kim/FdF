/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:16:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/17 03:22:14 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_coordinates *point, double alpha)
{
	int prev_y;
	int prev_z;

	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(alpha) + prev_z * sin(alpha);
	point->z = prev_y * -(sin(alpha)) + prev_z * cos(alpha);
}

static void	rotate_y(t_coordinates *point, double beta)
{
	int	prev_x;
	int	prev_z;

	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(beta) - prev_z * sin(beta);
	point->z = prev_x * sin(beta) + prev_z * cos(beta);	
}

static void	rotate_z(t_coordinates *point, double gamma)
{
	int prev_x;
	int prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(gamma) + prev_y * sin(gamma);
	point->y = prev_x * -(sin(gamma)) + prev_y * cos(gamma);
}

void	rotate(void)
{
	t_coordinates point;
	
	point.x = 300;
	point.y = 200;
	point.z = 350;

	double alpha = 60 * (M_PI / 180);
	double beta = 130 * (M_PI / 180);
	double gamma = 90 * (M_PI / 180);	
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
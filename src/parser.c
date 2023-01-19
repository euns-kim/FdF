/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:12:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/19 02:46:52 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_map {
	int		row;
	int		column;
}	t_map;

typedef struct s_coordinates {
	int		x;
	int		y;
	int		z;
//	t_2d	pixel;
}	t_coordinates;

// typedef struct s_2d {
// 	int	x;
// 	int y;
// }	t_2d;

int	fdf_atoi(char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	// if (*str == ',')
	// {
	// 	while (*(str + 1) != ' ' || *(str + 1) != '\0')
	// 		str++;
	// 	if (*str == ' ')
	// 		str++;
	// }
	return (sum * sign);
}

static void	ignore_color(char **line)
{
	if (*line == ' ')
	while (*line != ' ' && *line != '\0')
		line++;

}

static void	get_map(char *line, t_map **map)
{
	malloc((*map)->row * sizeof(t_coordinates**));
	malloc((*map)->column * sizeof(t_coordinates*))
}

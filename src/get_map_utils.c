/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:45:03 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/04 23:11:13 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_color(char **str)
{	
	uint32_t color_code;
	
	color_code = 0;
	(*str)++;
	if (**str == '0')
		(*str)++;
	if (**str == 'x' || **str == 'X')
		(*str)++;
	while (**str != ' ' && **str != '\n' && **str != '\0')
	{
		if (**str >= '0' && **str <= '9')
			color_code = color_code * 16 + (**str - '0');
		else if ((**str >= 'A' && **str <= 'F'))
			color_code = color_code * 16 + (**str - 'A') + 10;
		else if ((**str >= 'a' && **str <= 'f'))
			color_code = color_code * 16 + (**str - 'a') + 10;
		(*str)++;
	}
	return (color_code);
}

int32_t	fdf_atoi(char **str)
{
	int32_t	sum;
	int32_t	sign;

	sum = 0;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		sum = sum * 10 + (**str - '0');
		(*str)++;
	}
	return (sum * sign);
}

void	free_p(char	*p)
{
	if (p)
		free(p);
}

void	free_array(int32_t i, t_coordis **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

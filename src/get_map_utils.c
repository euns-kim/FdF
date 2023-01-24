/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:45:03 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/24 01:49:31 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_atoi(char **str)
{
	int	sum;
	int	sign;

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
	if (**str == ',')
	{
		while (**str != ' ' && **str != '\n' && **str != '\0')
			(*str)++;
	}
	return (sum * sign);
}

void	free_p(char	*p)
{
	if (p)
		free(p);
}

void	free_array(int i, t_coordis **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

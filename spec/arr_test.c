/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:18:53 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/29 19:32:59 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


// int **array = malloc(height * sizeof(int **));
// while(str && i< height)
// {
// 		*(array + i) = line_array = malloc(width * sizeof(int));
// 		!check_malloc_fail
// 			free(line_array);
// 			free(array);
// 		i++;
// }
// if (!array)
// 	return (0);
























int	**malloc_2d_int_array(int row, int column)
{
	int	**array_2d;
	int	*array_treated_as_int;
	int	i;

	array_2d = malloc(sizeof(int *) * row + sizeof(int) * row * column);
	array_treated_as_int = array_2d + row;
	i = 0;
	while (i < 4)
	{
		array_2d[i] =  array_treated_as_int + (i * column);
		i++;
	}
	return (array_2d);
}







int main(void)
{
	int	**array;
	
	printf("%lu\n", sizeof(int[4]));
	array = malloc_2d_int_array(4, 4);

	// int a[4] = {1, 2, 3, 4};
	// int b[4] = {5, 6, 7, 8};
	// int c[4] = {4, 3, 2, 1};
	// int d[4] = {1, 2, 4, 5};
	
	array[0][0] = 1;
	array[0][1] = 2;
	array[0][2] = 3;
	array[0][3] = 4;
	array[1][0] = 11;
	array[1][1] = 12;
	array[1][2] = 13;
	array[1][3] = 14;
	array[2][0] = 21;
	array[2][1] = 22;
	array[2][2] = 23;
	array[2][3] = 24;
	array[3][0] = 31;
	array[3][1] = 32;
	array[3][2] = 33;
	array[3][3] = 34;
	// array[4][0] = 41;
	// array[4][1] = 42;
	// array[4][2] = 43;
	// array[4][3] = 44;
	// array[1] = b;
	// array[2] = c;
	// array[3] = d;
	printf("%lu\n", sizeof(*array));
	printf("%lu\n", sizeof(**array)); //sizeof(int)
	
	int len = sizeof(*array) / sizeof(**array);
	printf("len:%d\n", len);
	
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			printf("%d\t", array[i][j]);
			j++;
		}
		printf("\n");
		i++;		
	}	
}
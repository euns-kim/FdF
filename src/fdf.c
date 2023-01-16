/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:30:58 by eunskim           #+#    #+#             */
/*   Updated: 2023/01/17 00:05:10 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	// if (argc != 2)
	// 	error();
	// if (argv[1] != "[filename].fdf")
	// 	error();	
}

how to init?

1. open the file (.fdf) // (file open error)

2. get the size of the map
	- height : the number of new lines
	- width : the number of integer elements
	// each of them better be saved in a struct?
	// (map error: each line should have the same width) - have to compare every row if all has the same number of elements.
	// for other possible edge cases just assume that files have the right format - NO ADDITIONAL WORK :D

3. allocate a double-dimensional integer array in the size of the map
	- malloc (width * height * sizeof(int))

4. parse intergers and save them into the array
	- ignore the spaces inbetween and just get the integers with small itoa-like function
	- save each to the array with a while loop

>> WE GOT A MAP ! <<

5. save the x, y, z value of each node of the map (int **map) in a struct (t_coordinates)
	and assign each into a same-sized double-dimensional array (t_coordinates **vectors)

typedef struct s_coordinates {
	int x;
	int y;
	int z;
}	t_coordinates;

6. think about matrix manipulation and key hooks (MLX42)

	- zoom in/out
	- translation
	- rotation

7. get 2D pixel points (t_pixel) out of t_coordiates **vectors with isometric projection calculation
	and assign each into a same-sized double-dimensional array (t_pixel **points)

typedef struct s_pixel {
	int x;
	int y;	
}	t_pixel;

8. think about centering : the x, y or the origin should be moved for certain distance
// do I want to change the size of the window each time?
// do I want to have a menu bar to display the usage?

>> WE GOT PIXELS TO DRAW <<

9. init mlx and img (MLX42) and draw lines with t_pixel **points
// always draw two lines from one point (x, y) to (x + 1, y) and to (x, y + 1)
// the last two edge lines could be drawn with extra function

FOR BONUS:

+ another pojection
+ coloring schemes (or anything else)
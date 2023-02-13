/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:33:35 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/13 16:05:02 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_manual(void)
{
	ft_printf("\n\n%37s\n\n", "<< Usage Guide >>");
	ft_printf("%25s : x rotation\n", "Q / W");
	ft_printf("%25s : y rotation\n", "A / S");
	ft_printf("%25s : z rotation\n", "Z / X");
	ft_printf("%25s : 45° rotation\n", "+CTRL");
	ft_printf("%25s : z value manipulation\n", "[ / ]");
	ft_printf("%25s : parallel projection\n", "1 / 2 / 3");
	ft_printf("%25s : translation\n", "ARROW");
	ft_printf("%25s : zoom in/out\n", "SCROLL");
	ft_printf("%25s : zoom in/out (faster)\n", "SCROLL + SHIFT");
	ft_printf("%25s : back to default map\n", "D");
	ft_printf("%25s : terminate program\n\n\n", "ESC");
}

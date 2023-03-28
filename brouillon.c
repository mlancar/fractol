/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:15:39 by malancar          #+#    #+#             */
/*   Updated: 2023/03/28 02:28:34 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		find_position(int color_per_gradient, int interval)
{
	int	x;
	
	x = 1;
	if (interval < color_per_gradient)
	{
		x = 16 * 16;
		printf("1\n");
	}
	else if (interval < color_per_gradient * 2)
	{
		x = -(16 * 16 * 16 * 16);
		printf("2\n");
	}
	else if (interval < (color_per_gradient * 3))
	{
			x = 1;
			printf("3\n");
	}
	else if (interval < (color_per_gradient * 4))
	{
		x = -(16 * 16);
		printf("4\n");
	}
	else if (interval < (color_per_gradient * 5))
	{
		x = 16 * 16 * 16 * 16;
		printf("5\n");
	}
	else if (interval < (color_per_gradient * 6))
	{
		x = -1;
		printf("6\n");
	}
	return (x);
}

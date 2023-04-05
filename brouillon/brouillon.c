/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:15:39 by malancar          #+#    #+#             */
/*   Updated: 2023/03/31 00:26:51 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_position(int color_per_gradient, int interval)
{
	int	x;
	
	x = 1;
	if (interval < color_per_gradient)
		x = 16 * 16;
	else if (interval < (color_per_gradient * 2))
		x = -(16 * 16 * 16 * 16);
	else if (interval < (color_per_gradient * 3))
			x = 1;
	else if (interval < (color_per_gradient * 4))
		x = -(16 * 16);
	else if (interval < (color_per_gradient * 5))
		x = 16 * 16 * 16 * 16;
	else if (interval < (color_per_gradient * 6))
		x = -1;
	return (x);
}

int		find_position2(int color_per_gradient, int interval)
{
	int	x;
	
	x = 1;
	if (interval < color_per_gradient)
		x = 16 * 16;
	else if (interval < (color_per_gradient * 2))
		x = -(16 * 16 * 16 * 16);
	return (x);
}

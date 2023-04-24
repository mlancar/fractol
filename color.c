/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:19:20 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 19:02:20 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	init_color_gradient(t_color color, t_graph *var)
{
	color.nbr = var->win_height;
	color.delta = 0xFF;
	color.pixel = YELLOW;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient;
	color.per_pixel = (double) var->win_height / color.nbr;
	return (color);
}

void	color_julia_set1(t_graph *var, t_set *z, t_color color)
{	
	int	change_red;

	change_red = 16 * 16 * 16 * 16;
	if (z->n == z->iteration_max)
	var->img.addr[var->img_height * var->win_width + var->img_width] = 0x000000;
	else
		color_julia(var, z, color, change_red);
}

void	color_julia(t_graph *var, t_set *z, t_color color, int change_red)
{
	if ((z->n / z->iteration_max) < 0.20)
	{
		color.pixel = 0x320053 + (int)(255 * z->n / z->iteration_max * 5) * change_red;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.20 && (z->n / z->iteration_max) < 0.40)
	{
		color.pixel = 0x320053 + (int)(255 * (z->n / z->iteration_max - 0.20) * 5) * change_red;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.40 && (z->n / z->iteration_max) < 0.60)
	{
	color.pixel = 0x320053 + (int)(255 * (z->n / z->iteration_max - 0.40) * 5) * change_red;
	var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.60 && (z->n / z->iteration_max) < 0.80)
	{
		color.pixel = 0x320053 + (int)(255 * (z->n / z->iteration_max - 0.60) * 5) * change_red;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.80 && (z->n / z->iteration_max) < 1)
	{
		color.pixel = 0x320053 + (int)(255 * (z->n / z->iteration_max - 0.80) * 5) * change_red;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
}

void	color_julia_set2(t_graph *var, t_set *z, t_color color)
{
	if (z->n == z->iteration_max)
	var->img.addr[var->img_height * var->win_width + var->img_width] = BLACK;
	else
		color_julia_2(var, z, color);
}

void	color_julia_2(t_graph *var, t_set *z, t_color color)
{
	if ((z->n / z->iteration_max) < 0.20)
	{
		color.pixel = BLACK + (int)(50 * z->n / z->iteration_max * 5);
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.20 && (z->n / z->iteration_max) < 0.40)
	{
		color.pixel = BLACK + (int)(50 * z->n / z->iteration_max * 5);
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.40 && (z->n / z->iteration_max) < 0.60)
	{
		color.pixel = BLACK + (int)(50 * z->n / z->iteration_max * 5);
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.60 && (z->n / z->iteration_max) < 0.80)
	{
		color.pixel = BLACK + (int)(50 * z->n / z->iteration_max * 5);
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
	else if ((z->n / z->iteration_max) > 0.80 && (z->n / z->iteration_max) < 1)
	{
		color.pixel = BLACK + (int)(50 * z->n / z->iteration_max * 5);
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
}

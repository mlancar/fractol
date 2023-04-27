/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:19:20 by malancar          #+#    #+#             */
/*   Updated: 2023/04/27 19:14:58 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color_gradient(t_color *color, t_graph *var)
{
	color->nbr = var->win_height;
	color->delta = 0xFF;
	color->pixel = YELLOW;
	color->gradient = 1;
	color->per_gradient = color->nbr / color->gradient;
	color->per_pixel = (double) var->win_height / color->nbr;
}

void	color_julia_set1(t_graph *var, t_set *z, t_color color)
{	
	int	red;

	color.p_i = z->n / z->iteration_max;
	color.index = var->img_height * var->win_width + var->img_width;
	red = 16 * 16 * 16 * 16;
	if (z->n == z->iteration_max)
	var->img.addr[color.index] = BLACK;
	else
		color_julia(var, color, red);
}

void	color_julia(t_graph *var, t_color color, int red)
{
	if ((color.p_i) < 0.20)
	{
		color.pixel = 0x320053 + (int)(255 * color.p_i * 5) *red;
		var->img.addr[color.index] = color.pixel;
	}
	else if ((color.p_i) > 0.20 && color.p_i < 0.40)
	{
		color.pixel = 0x320053 + (int)(255 * (color.p_i - 0.20) * 5) *red;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.40 && color.p_i < 0.60)
	{
	color.pixel = 0x320053 + (int)(255 * (color.p_i - 0.40) * 5) *red;
	var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.60 && color.p_i < 0.80)
	{
		color.pixel = 0x320053 + (int)(255 * (color.p_i - 0.60) * 5) *red;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.80 && color.p_i < 1)
	{
		color.pixel = 0x320053 + (int)(255 * (color.p_i - 0.80) * 5) *red;
		var->img.addr[color.index] = color.pixel;
	}
}

void	color_julia_set2(t_graph *var, t_set *z, t_color color)
{
	color.p_i = z->n / z->iteration_max;
	color.index = var->img_height * var->win_width + var->img_width;
	if (z->n == z->iteration_max)
	var->img.addr[color.index] = BLACK;
	else
		color_julia_2(var, color);
}

void	color_julia_2(t_graph *var, t_color color)
{
	if (color.p_i < 0.20)
	{
		color.pixel = BLACK + (int)(50 * color.p_i * 5);
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.20 && color.p_i < 0.40)
	{
		color.pixel = BLACK + (int)(50 * color.p_i * 5);
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.40 && color.p_i < 0.60)
	{
		color.pixel = BLACK + (int)(50 * color.p_i * 5);
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.60 && color.p_i < 0.80)
	{
		color.pixel = BLACK + (int)(50 * color.p_i * 5);
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.80 && color.p_i < 1)
	{
		color.pixel = BLACK + (int)(50 * color.p_i * 5);
		var->img.addr[color.index] = color.pixel;
	}
}

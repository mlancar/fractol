/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:19:20 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:50:49 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_set_1(t_graph *var, t_color color, int red)
{
	if ((color.p_i) < 1)
	{
		color.pixel = BLACK + (int)(255 * color.p_i * 4) *red;
		var->img.addr[color.index] = color.pixel;
	}
}

void	color_set_2(t_graph *var, t_color color, int green)
{
	if ((color.p_i) < 1)
	{
		color.pixel = BLACK + (int)(255 * color.p_i * 4) *green;
		var->img.addr[color.index] = color.pixel;
	}
}

void	color_set_3(t_graph *var, t_color color, int blue)
{
	if ((color.p_i) < 1)
	{
		color.pixel = BLACK + (int)(150 * color.p_i * 4) *blue;
		var->img.addr[color.index] = color.pixel;
	}
}

void	color_set_4(t_graph *var, t_color color, int red)
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

void	color_set_5(t_graph *var, t_color color, int red, int green)
{
	if (color.p_i < 0.20)
	{
		color.pixel = BLACK + (int)(255 * color.p_i * 5) *red;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.20 && color.p_i < 0.40)
	{
		color.pixel = RED + (int)(70 * color.p_i * 5) *green;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.40 && color.p_i < 0.60)
	{
		color.pixel = RED + (int)(70 * color.p_i * 5) *green;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.60 && color.p_i < 0.80)
	{
		color.pixel = RED + (int)(70 * color.p_i * 5) *green;
		var->img.addr[color.index] = color.pixel;
	}
	else if (color.p_i > 0.80 && color.p_i < 1)
	{
		color.pixel = RED + (int)(50 * color.p_i * 5) *green;
		var->img.addr[color.index] = color.pixel;
	}
}

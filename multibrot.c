/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:08:38 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:47:50 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_multibrot_graph(t_graph *var)
{
	var->x_min = -1.4;
	var->x_max = 1.3;
	var->y_min = -1.2;
	var->y_max = 1.2;
}

void	init_multibrot_set(t_set *z, t_graph *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->x_max - var->x_min;
	delta_y = var->y_max - var->y_min;
	var->x = var->x_min + (delta_x / var->win_width) * var->img_width;
	var->y = var->y_max - (delta_y / var->win_height) * var->img_height;
	z->c_r = var->x;
	z->c_i = var->y;
	z->r = 0;
	z->i = 0;
	z->n = 0;
	z->iteration_max = 130;
}

void	re_init_multibrot_set(t_set *z, t_graph *var)
{
	double	power;
	double	cosinus;
	double	atan;
	double	sinus;

	power = pow(sqrt(((z->r * z->r) + (z->i * z->i))), var->c.p);
	atan = atan2(z->i, z->r);
	cosinus = cos(var->c.p * atan);
	sinus = sin(var->c.p * atan);
	z->tmp = power * cosinus + z->c_r;
	z->i = power * sinus + z->c_i;
	z->r = z->tmp;
	z->n = z->n + 1;
}

void	color_multibrot_set(t_graph *var, t_set *z, t_color color)
{
	int		change_blue;
	int		index;

	color.p_i = z->n / z->iteration_max;
	index = var->img_height * var->win_width + var->img_width;
	change_blue = 1;
	if (z->n == z->iteration_max)
	var->img.addr[var->img_height * var->win_width + var->img_width] = 0x000000;
	else
	{
		if ((z->n / z->iteration_max) < 0.50)
		{
			color.pixel = BLACK + (int)(255 * color.p_i * 4) *change_blue;
			var->img.addr[index] = color.pixel;
		}
		else if ((z->n / z->iteration_max) > 0.50)
		{
			color.pixel = color.pixel + (int)(255 * color.p_i * 4) *change_blue;
			var->img.addr[index] = color.pixel;
		}
	}
}

void	multibrot(t_graph *var)
{
	t_color	color;
	t_set	z;

	var->img_height = 0;
	init_color_gradient(&color, var);
	while (var->img_height < var->win_height)
	{
		var->img_width = 0;
		while (var->img_width < var->win_width)
		{
			init_multibrot_set(&z, var);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_multibrot_set(&z, var);
			init_color_set(var, &z, color);
			var->img_width++;
		}
		var->img_height++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

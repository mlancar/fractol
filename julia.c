/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:02:58 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:47:36 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia_graph(t_graph *var)
{
	var->x_min = -1.6;
	var->x_max = 1.6;
	var->y_min = -1.6;
	var->y_max = 1.6;
}

void	init_julia_set(t_set *z, t_graph *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->x_max - var->x_min;
	delta_y = var->y_max - var->y_min;
	var->x = var->x_min + (delta_x / var->win_width) * var->img_width;
	var->y = var->y_max - (delta_y / var->win_height) * var->img_height;
	z->r = var->x;
	z->i = var->y;
	z->n = 0;
	z->iteration_max = 150;
}

void	re_init_julia_set(t_set *z, t_graph *var)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + var->c.r;
	z->i = (2 * z->i * z->tmp) + var->c.i;
	z->n = z->n + 1;
}

void	julia(t_graph *var)
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
			init_julia_set(&z, var);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_julia_set(&z, var);
			init_color_set(var, &z, color);
			var->img_width++;
		}
		var->img_height++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

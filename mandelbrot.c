/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:03:54 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:47:44 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot_graph(t_graph *var)
{
	var->x_min = -2.1;
	var->x_max = 0.6;
	var->y_min = -1.2;
	var->y_max = 1.2;
}

void	init_mandelbrot_set(t_set *z, t_graph *var)
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
	z->iteration_max = 150;
}

void	re_init_mandelbrot_set(t_set *z)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + z->c_r;
	z->i = (2 * z->i * z->tmp) + z->c_i;
	z->n = z->n + 1;
}

void	mandelbrot(t_graph *var)
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
			init_mandelbrot_set(&z, var);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_mandelbrot_set(&z);
			init_color_set(var, &z, color);
			var->img_width++;
		}
		var->img_height++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

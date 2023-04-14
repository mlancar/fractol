/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:03:54 by malancar          #+#    #+#             */
/*   Updated: 2023/04/14 23:17:06 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_mandelbrot_graph(t_graph *var)
{
	var->x_min = -2.1;
	var->x_max = 0.6;
	var->y_min = -1.2;
	var->y_max = 1.2;
}

void	init_mandelbrot_set(t_set *z, t_graph *var)
{
	var->x_min = var->x_min;
	var->x_max = var->x_max;
	var->y_min = var->y_min;
	var->y_max = var->y_max;
	var->x = var->x_min + ((var->x_max - var->x_min) / var->win_width) * var->img_width;
	var->y = var->y_max - ((var->y_max - var->y_min) / var->win_height) * var->img_height;
	z->c_r = var->x;//parametre
	z->c_i = var->y;//parametre
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

void	color_mandelbrot_set(t_graph *var, t_set *z, t_color color)
{
	if (z->n == z->iteration_max)
	var->img.addr[var->img_height * var->win_width + var->img_width] = 0x000000;
	else
	{
		if ((z->n / z->iteration_max) < 0.50)
		{
			color.pixel = BLUE;
			color.pixel = color.pixel + (int) (255 * z->n / z->iteration_max * 4) * CHANGE_BLUE;
			var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
		}
		else if ((z->n / z->iteration_max) > 0.50)
		{
			color.pixel = color.pixel + (int) (255 * z->n / z->iteration_max * 4) * CHANGE_BLUE;
			var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
		}
		
	}
}

void	mandelbrot(t_graph *var)
{
	t_color	color;
	t_set		z;
	
	var->img_height = 0;
	color = init_color_gradient(color, var);
	while (var->img_height < var->win_height)
	{
		var->img_width = 0;
		while (var->img_width < var->win_width)
		{
			init_mandelbrot_set(&z, var);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_mandelbrot_set(&z);
			color_mandelbrot_set(var, &z, color);
			var->img_width++;
		}
		var->img_height++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

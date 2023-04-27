/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:03:56 by malancar          #+#    #+#             */
/*   Updated: 2023/04/27 20:25:26 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_newton_graph(t_graph *var)
{
	var->x_min = -1.2;
	var->x_max = 1.2;
	var->y_min = -1.2;
	var->y_max = 1.2;
}

void	init_newton_set(t_set *z, t_graph *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->x_max - var->x_min;
	delta_y = var->y_max - var->y_min;
	var->x = var->x_min + (delta_x / var->win_width) * var->img_width;
	var->y = var->y_max - (delta_y / var->win_height) * var->img_height;
	z->r = var->x;
	z->i = var->y;
	z->c_r = -1;
	z->c_i = 0;
	z->n = 0;
	z->iteration_max = 150;
}

void	re_init_newton_set(t_set *z, t_graph *var)
{
	// printf("re init zr = %f\n", z->r);
	// printf("re init zi = %f\n", z->i);
	z->n = z->n + 1;
	var->tmp.a = z_power_n_real(z->r, z->i, var->c.p) + z->c_r;
	var->tmp.b = z_power_n_imaginary(z->r, z->i, var->c.p) + z->c_i;
	var->tmp.c = z_power_n_real(z->r, z->i, var->c.p - 1)  * var->c.p;
	var->tmp.d = z_power_n_imaginary(z->r, z->i, var->c.p - 1) * var->c.p;
	z->r = z->r - (((var->tmp.a * var->tmp.c) + (var->tmp.b * var->tmp.d)) / ((var->tmp.c * var->tmp.c) + (var->tmp.d * var->tmp.d)));
	z->i = z->i - (((var->tmp.b * var->tmp.c) - (var->tmp.a * var->tmp.d)) / ((var->tmp.c * var->tmp.c) + (var->tmp.d * var->tmp.d)));
	// printf("re init tmpa = %f\n", var->tmp.a);
	// printf("re init tmpb = %f\n", var->tmp.b);
	// printf("re init tmpc = %f\n", var->tmp.c);
	// printf("re init tmpd = %f\n\n", var->tmp.d);
	// printf("re init zr = %f\n", z->r);
	// printf("re init zi = %f\n", z->i);
	// printf("%f\n", ((var->tmp.a * var->tmp.c) - (var->tmp.b * var->tmp.d)) );
	// printf("%f\n", ((var->tmp.c * var->tmp.c) + (var->tmp.d * var->tmp.d)));
}


void	color_newton_set(t_graph *var, t_set *z, t_color color)
{
	int		change_blue;
	int		index;
	double	p_i;

	p_i = z->n / z->iteration_max;
	index = var->img_height * var->win_width + var->img_width;
	change_blue = 1;
	if (z->n == z->iteration_max)
	var->img.addr[var->img_height * var->win_width + var->img_width] = 0x000000;
	else
	{
		if ((z->n / z->iteration_max) < 0.50)
		{
			color.pixel = BLACK + (int)(255 * p_i * 4) *change_blue;
			var->img.addr[index] = color.pixel;
		}
		else if ((z->n / z->iteration_max) > 0.50)
		{
			color.pixel = color.pixel + (int)(255 * p_i * 4) *change_blue;
			var->img.addr[index] = color.pixel;
		}
	}
}

void	newton(t_graph *var)
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
			init_newton_set(&z, var);
			var->tmp.a = z_power_n_real(z.r, z.i, var->c.p) + z.c_r;
			var->tmp.b = z_power_n_imaginary(z.r, z.i, var->c.p) + z.c_i;
			//printf("tmpa = %f\n", var->tmp.a);
			//printf("tmpb = %f\n", var->tmp.b);
			while (((var->tmp.a * var->tmp.a) + (var->tmp.b * var->tmp.b)) > 0.1 && z.n < z.iteration_max)
				re_init_newton_set(&z, var);
			color_newton_set(var, &z, color);
			//printf("zn = %f\n", z.n);
			// printf("zi = %f\n", z.i);	
			// printf("tmpa = %f\n", var->tmp.a);
			// printf("tmpb = %f\n", var->tmp.b);
			// printf("tmpc = %f\n", var->tmp.c);
			// printf("tmpd = %f\n", var->tmp.d);
			var->img_width++;
		}
		var->img_height++;
	}
	printf("c.p= %f\n", var->c.p);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

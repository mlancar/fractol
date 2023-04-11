/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:02:58 by malancar          #+#    #+#             */
/*   Updated: 2023/04/11 19:01:44 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_julia_graph(t_graph *var)
{
	//printf("avant init%f\n", var->zoom);
	var->x_min = -1 + var->zoom;
	var->x_max = 1 + var->zoom;
	var->y_min = -1.2 + var->zoom;
	var->y_max = 1.2 + var->zoom;
	//printf("y_max init%f\n", var->y_max);
	
	var->x = var->x_min + ((var->x_max - var->x_min) / var->win_width) * var->img_width;
	var->y = var->y_max - ((var->y_max - var->y_min) / var->win_height) * var->img_height;
}

void	init_julia_set(t_set *z, t_graph *var)
{
	z->c_r = 0.285;//parametre
	z->c_i = 0.01;//parametre
	z->r = var->x;
	z->i = var->y;
	z->n = 0;
	z->iteration_max = 120;
}

void	re_init_julia_set(t_set *z)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + z->c_r;
	z->i = (2 * z->i * z->tmp) + z->c_i;
	z->n = z->n + 1;
}

void	color_julia_set(t_graph *var, t_set *z, t_color color)
{
	if (z->n == z->iteration_max)
		var->img.addr[var->img_height * var->win_width + var->img_width] = 0x000000;
	/*else
	{
		color.pixel =   0x94BCE0 + (int) (4000 * z->n / z->iteration_max) * CHANGE_GREEN;
		if (color.pixel == 0x9494E0)
			color.pixel =   0x9494E0 + (int) (4000 * z->n / z->iteration_max) * CHANGE_RED;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}*/
	else
	{
		color.pixel =   0x320053 + (int) (4000 * z->n / z->iteration_max) * CHANGE_RED;
		var->img.addr[var->img_height * var->win_width + var->img_width] = color.pixel;
	}
}

void	julia(t_graph *var)
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
			init_julia_graph(var);
			init_julia_set(&z, var);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_julia_set(&z);
			color_julia_set(var, &z, color);
			var->img_width++;
		}
		var->img_height++;
	}
	printf("%d\n", color.pixel);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
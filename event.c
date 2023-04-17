/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/17 17:54:42 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key_code, t_graph *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->x_max - var->x_min;
	delta_y = var->y_max - var-> y_min;
	//printf("%f\n", var->y_min);
	if (key_code == ESC) 
	{
		mlx_loop_end(var->mlx);
	}
	if (key_code == UP)
	{
		var->y_min = var->y_min + 0.01 * delta_y;
		var->y_max = var->y_max + 0.01 * delta_y;
		draw_fractal(var);
		
	}
	if (key_code == DOWN)
	{
		var->y_min = var->y_min - 0.01 * delta_y;
		var->y_max = var->y_max - 0.01 * delta_y;
		draw_fractal(var);
	}
	if (key_code == LEFT)
	{
		var->x_min = var->x_min - 0.01 * delta_x;
		var->x_max = var->x_max - 0.01 * delta_x;
		draw_fractal(var);
	}
	if (key_code == RIGHT)
	{
		var->x_min = var->x_min + 0.01 * delta_x;
		var->x_max = var->x_max + 0.01 * delta_x;
		draw_fractal(var);
	}
	return (0);
}


int	mouse_hook(int mouse_code, int x, int y, t_graph *var)
{
	if (mouse_code == 4)
	{
		var->zoom = 0.9;
		var->x_min = var->x_min * var->zoom;
		var->x_max = var->x_max * var->zoom;
		var->y_min = var->y_min * var->zoom;
		var->y_max = var->y_max * var->zoom;
		draw_fractal(var);
	}

	return (0);
	
}

int	close_window(t_graph *var)
{
	mlx_loop_end(var->mlx);
	return (0);
}


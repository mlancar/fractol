/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/21 18:53:31 by malancar         ###   ########.fr       */
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
	printf("x = %d\ny = %d\n", x, y);
	if (mouse_code == 5)
	{
		var->zoom = 0.9;
		var->x_min = var->x_min / var->zoom;
		var->x_max = var->x_max / var->zoom;
		var->y_min = var->y_min / var->zoom;
		var->y_max = var->y_max / var->zoom;
		draw_fractal(var);
	}
	if (mouse_code == 4)
	{
		var->zoom = 0.9;
		/*var->x_min = var->x_min * var->zoom;
		var->x_max = var->x_max * var->zoom;
		var->y_min = var->y_min * var->zoom;
		var->y_max = var->y_max * var->zoom;*/
		var->x_min =  (var->x_min - var->x_max) * (x / var->img_width) * (var->zoom);
		var->x_max = (var->x_max - var->x_max) * (x / var->img_width) * (var->zoom);
		var->y_min = (var->y_min - var->y_min) * (y / var->img_height) * (var->zoom);
		var->y_max = (var->y_max - var->y_max) * (y / var->img_height) * (var->zoom);
		draw_fractal(var);
	}
	
	return (0);
}
/*int	mouse_position(int mouse_pos, int x, int y, t_graph *var)
{
	printf("x = %d\ny = %d\n", x, y);
	if (x < var->img_width && y < var->img_height)
	{
		var->x_min =  (x / var->img_width) * var->zoom;
		var->x_max = (x / var->img_width) * var->zoom;
		var->y_min = (y / var->img_height) * var->zoom;
		var->y_max = (y / var->img_height) * var->zoom;
	}
	return (0);
}*/

int	close_window(t_graph *var)
{
	mlx_loop_end(var->mlx);
	return (0);
}


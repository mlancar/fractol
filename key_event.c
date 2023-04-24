/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:59:35 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 17:01:55 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key_code, t_graph *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->x_max - var->x_min;
	delta_y = var->y_max - var-> y_min;
	if (key_code == ESC)
		mlx_loop_end(var->mlx);
	if (key_pressed(key_code, var, delta_x, delta_y) == 1)
		draw_fractal(var);
	return (0);
}

int	key_pressed(int key_code, t_graph *var, double delta_x, double delta_y)
{
	if (key_code == UP)
	{
		var->y_min = var->y_min + 0.01 * delta_y;
		var->y_max = var->y_max + 0.01 * delta_y;
		return (1);
	}
	if (key_code == DOWN)
	{
		var->y_min = var->y_min - 0.01 * delta_y;
		var->y_max = var->y_max - 0.01 * delta_y;
		return (1);
	}
	if (key_code == LEFT)
	{
		var->x_min = var->x_min - 0.01 * delta_x;
		var->x_max = var->x_max - 0.01 * delta_x;
		return (1);
	}
	if (key_code == RIGHT)
	{
		var->x_min = var->x_min + 0.01 * delta_x;
		var->x_max = var->x_max + 0.01 * delta_x;
		return (1);
	}
	return (0);
}

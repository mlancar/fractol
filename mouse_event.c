/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:00:11 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 18:58:48 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_graph *var)
{
	double	d_x;
	double	d_y;

	if (mouse_code == 5)
	{
		zoom_out(x, y, var);
		draw_fractal(var);
	}
	if (mouse_code == 4)
	{
		zoom_in(x, y, var);
		draw_fractal(var);
	}
	return (0);
}

int	close_window(t_graph *var)
{
	mlx_loop_end(var->mlx);
	return (0);
}

void	zoom_out(int x, int y, t_graph *var)
{
	double	d_x;
	double	d_y;

	var->zoom = 1.1;
	d_x = 0;
	d_y = 0;
	d_x = (var->x_max - var->x_min) * (1 - var->zoom);
	d_y = (var->y_max - var->y_min) * (1 - var->zoom);
	var->x_min = var->x_min + ((double)x / var->win_width) * (2 * d_x);
	var->x_max = var->x_max - (1 - ((double)x / var->win_width)) * (2 * d_x);
	var->y_min = var->y_min + (1 - (double)y / var->win_height) * (2 * d_y);
	var->y_max = var->y_max - (((double)y / var->win_height)) * (2 * d_y);
}

void	zoom_in(int x, int y, t_graph *var)
{
	double	d_x;
	double	d_y;

	var->zoom = 0.9;
	d_x = 0;
	d_y = 0;
	d_x = (var->x_max - var->x_min) * (1 - var->zoom);
	d_y = (var->y_max - var->y_min) * (1 - var->zoom);
	var->x_min = var->x_min + ((double)x / var->win_width) * (2 * d_x);
	var->x_max = var->x_max - (1 - ((double)x / var->win_width)) * (2 * d_x);
	var->y_min = var->y_min + (1 - (double)y / var->win_height) * (2 * d_y);
	var->y_max = var->y_max - (((double)y / var->win_height)) * (2 * d_y);
}

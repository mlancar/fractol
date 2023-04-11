/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/11 18:27:40 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_graph *var)
{
	//printf("%f\n", var->y_min);
	if (keycode == 113) {
		mlx_loop_end(var);
	}
	if (keycode == UP)
	{
		printf("ymax%f\n", var->y_max);
		printf("%f\n", var->zoom);
		var->zoom = var->zoom + 1;
		printf("apres%f\n", var->zoom);
		
		julia(var);
		printf("ymax%f\n", var->y_max);
	}
	else if (keycode == DOWN)
		var->y_max  = var->y_max  + 1;
	else if (keycode == LEFT)
		var->x_min  = var->x_min + 1;
	else if (keycode == RIGHT)
		var->x_max = var->x_max + 1;
	//printf("%f\n",var->y_min);
	//printf("%d\n", keycode);
	return (0);
}

int	mouse_hook(int mousecode, t_graph *var)
{
	if (mousecode == 4)
		zoomin(var);
	//printf("%d\n", mousecode);
	return (0);
}

void	zoomin(t_graph *var)
{
	var->x_min = var->x_min + 1;
	var->y_min = var->y_min + 1;
	var->x_max = var->x_max + 1;
	var->y_max = var->y_max + 1;
}

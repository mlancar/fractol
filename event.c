/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/10 17:43:57 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *mlx)
{
	if (keycode == 113) {
		mlx_loop_end(mlx);
	}
	printf("%d\n", keycode);
	return (0);
}

int	mouse_hook(int mousecode, void *mlx)
{
	if ()
	printf("%d\n", mousecode);
	return (0);
}

void	zoomin(t_graph *x, t_graph *y)
{
	x->min = x->min + 0.1;
	y->min = y->min + 0.1;
	x->max = x->max + 0.1;
	y->max = y->max + 0.1;
}

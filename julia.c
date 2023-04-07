/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:02:58 by malancar          #+#    #+#             */
/*   Updated: 2023/04/07 18:53:39 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_julia_graph(t_graph *x, t_graph *y, t_size image, t_size window)
{
	x->min = -1;
	y->min = -1.2;
	y->max = 1.2;
	x->max = 1;
	x->x = x->min + ((x->max - x->min) / window.width) * image.width;
	y->y = y->max - ((y->max - y->min) / window.height) * image.height;
}

void	init_julia_set(t_set *z, t_graph *x, t_graph *y)
{
	z->c_r = 0.285;
	z->c_i = 0.01;
	z->r = x->x;
	z->i = y->y;
	z->n = 0;
	z->iteration_max = 100;
}

void	re_init_julia_set(t_set *z)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + z->c_r;
	z->i = (2 * z->i * z->tmp) + z->c_i;
	z->n = z->n + 1;
}

void	color_julia_set(t_data *img, t_size image, t_size window, t_set *z, t_color color)
{
	if (z->n == z->iteration_max)
		img->addr[image.height * window.width + image.width] = BLACK;
	else 
		img->addr[image.height * window.width + image.width] = BLUE + (int) (((double) color.delta / z->n) * (z->iteration_max)) * CHANGE_BLUE;
}

void	julia(t_data *img, void *mlx, void *win, t_size window)
{
	t_graph	x;
	t_graph	y;
	t_color	color;
	t_size	image;
	t_set		z;
	
	image.height = 0;
	color = init_color_gradient(color, window);
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			init_julia_graph(&x, &y, image, window);
			init_julia_set(&z, &x, &y);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
			{
				re_init_julia_set(&z);
				color_julia_set(img, image, window, &z, color);
			}
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
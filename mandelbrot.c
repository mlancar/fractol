/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:03:54 by malancar          #+#    #+#             */
/*   Updated: 2023/04/07 19:10:59 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_mandelbrot_graph(t_graph *x, t_graph *y, t_size image, t_size window)
{
	x->min = -2.1;
	y->min = -1.2;
	y->max = 1.2;
	x->max = 0.6;
	x->x= x->min + ((x->max - x->min) / window.width) * image.width;
	y->y = y->max - ((y->max - y->min) / window.height) * image.height;
}

void	init_mandelbrot_set(t_set *z, t_graph *x, t_graph *y)
{
	z->c_r = x->x;
	z->c_i = y->y;
	z->r = x->x;
	z->i = y->y;
	z->n = 0;
	z->iteration_max = 100;
}

void	re_init_mandelbrotset(t_set *z)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + z->c_r;
	z->i = (2 * z->i * z->tmp) + z->c_i;
	z->n = z->n + 1;
}

void	color_mandelbrot_set(t_data *img, t_size image, t_size window, t_set *z, t_color color)
{
	if (z->n == z->iteration_max)
		img->addr[image.height * window.width + image.width] = BLACK;
	else 
		img->addr[image.height * window.width + image.width] = BLUE + (int) (((double) color.delta / z->n) * (z->iteration_max)) * CHANGE_BLUE;
}

void	mandelbrot(t_data *img, void *mlx, void *win, t_size window)
{
	t_graph	x;
	t_graph	y;
	t_color	color;
	t_size	image;
	t_set	z;
	
	image.height = 0;
	z.iteration_max = 150;
	color = init_color_gradient(color, window);
	init_mandelbrot_graph(&x, &y, image, window);
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			init_mandelbrot_graph(&x, &y, image, window);
			init_mandelbrot_set(&z, &x, &y);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
			{
				re_init_mandelbrotset(&z);
				color_mandelbrot_set(img, image, window, &z, color);
			}
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}

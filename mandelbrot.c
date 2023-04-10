/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:03:54 by malancar          #+#    #+#             */
/*   Updated: 2023/04/10 16:28:28 by malancar         ###   ########.fr       */
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
	z->r = 0;
	z->i = 0;
	z->n = 0;
	z->iteration_max = 100;
}

void	re_init_mandelbrot_set(t_set *z)
{
	z->tmp = z->r;
	z->r = (z->r * z->r) - (z->i * z->i) + z->c_r;
	z->i = (2 * z->i * z->tmp) + z->c_i;
	z->n = z->n + 1;
}

void	color_mandelbrot_set(t_data *img, t_size image, t_size window, t_set *z, t_color color)
{
	double	line;
	
	if (z->n == z->iteration_max)
		img->addr[image.height * window.width + image.width] = BLACK;
	else
	{
		line = image.height/ color.per_pixel;
		img->addr[image.height * window.width + image.width] =  color.pixel;
		if (line > color.interval)
		{
			color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
			color.interval++;
		}
	}
}

void	mandelbrot(t_data *img, void *mlx, void *win, t_size window)
{
	t_graph	x;
	t_graph	y;
	t_color	color;
	t_size	image;
	t_set	z;
	double	line;
	
	image.height = 0;
	color = init_color_rainbow(color, window);
	init_mandelbrot_graph(&x, &y, image, window);
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			init_mandelbrot_graph(&x, &y, image, window);
			init_mandelbrot_set(&z, &x, &y);
			while (((z.r * z.r) + (z.i * z.i)) < 4 && z.n < z.iteration_max)
				re_init_mandelbrot_set(&z);
			//color_mandelbrot_set(img, image, window, &z, color);
			if (z.n == z.iteration_max)
			img->addr[image.height * window.width + image.width] = BLACK;
			else
			{
				line = image.height/ color.per_pixel;
				img->addr[image.height * window.width + image.width] =  color.pixel;
				if (line > color.interval)
				{
					color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
					color.interval++;
				}
			}
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:08:11 by malancar          #+#    #+#             */
/*   Updated: 2023/04/07 19:13:27 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_graph(t_graph *x, t_graph *y)
{
	x->min = -5;
	y->min = -5;
	y->max = 5;
	x->max = 5;
	x->center = 0;
	y->center = 0;
}

void	circle(t_data *img, void *mlx, void *win, t_size window)
{
	t_graph	x;
	t_graph	y;
	t_color	color;
	t_size	image;
	double	radius;
	
	color = init_color_gradient(color, window);
	init_graph(&x, &y);
	radius = 1.5;
	image.height = 0;
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			x.x = x.min + ((x.max - x.min) / window.width) * image.width;
			y.y = y.max - ((y.max - y.min) / window.height) * image.height;
			if (((radius * radius) - (((x.x - x.center) * (x.x - x.center)) + ((y.y - y.center) * (y.y - y.center))) >= -0.1) && ((radius * radius) - (((x.x - x.center) * (x.x - x.center)) + ((y.y - y.center) * (y.y - y.center))) >= -0.1))
			{
				color.pixel = RED;
				img->addr[image.height * window.width + image.width] = color.pixel + (int) (((double) color.delta / color.nbr) * (image.height)) * CHANGE_GREEN;
			}
			else
				img->addr[image.height * window.width + image.width] = color.pixel + (int) (((double) color.delta / color.nbr) * (image.height)) * -CHANGE_GREEN;
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}

void droite(t_data *img, void *mlx, void *win, t_size window)
{
	t_graph	x;
	t_graph	y;
	t_color	color;
	t_size	image;

	color = init_color_gradient(color, window);
	init_repere(&x, &y);
	image.height = 0;
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width <window.width)
		{
			x.x = x.min + ((x.max - x.min) /window.width) * image.width;
			y.y = y.max - ((y.max - y.min) / window.height) * image.height;
			if (y.y- (2 * x.x + 2) >= 0 && y.y- (2 * x.x + 2) <= 0.1)
			{
				img->addr[image.height * window.width + image.width] = color.pixel;
			}
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
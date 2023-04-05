/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:19:20 by malancar          #+#    #+#             */
/*   Updated: 2023/04/05 17:41:42 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gradient (t_data *img, void *mlx, void *win, t_size window)
{
	t_color	color;
	t_size	image;
	int	position;

	position = CHANGE_RED;
	image.height = 0;
	color = init_color_gradient(color, window);
	while (image.height< window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			img->addr[image.height * window.width + image.width] = color.pixel + (int) (((double) color.delta / color.nbr) * (image.height)) * position;
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}

void	rainbow(t_data *img, void *mlx, void *win, t_size window)
{
	t_color	color;
	t_size	image;
	double	line;
	
	image.height= 0;
	color = init_color_rainbow(color, window);
	while (image.height < window.height)
	{
		image.width = 0;
		while (image.width < window.width)
		{
			line = image.height/ color.per_pixel;
			img->addr[image.height * window.width + image.width] =  color.pixel;
			if (line > color.interval)
			{
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			image.width++;
		}
		image.height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
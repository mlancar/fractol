/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:19:20 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 19:26:02 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gradient (t_data *img, void *mlx, void *win)
{
	t_color	color;
	t_size	height;
	t_size	width;
	int	position;

	height.window = 1440;
	width.window = 2560;
	position = -CHANGE_RED;
	height.image = 0;
	color = init_color_gradient(color, height);
	while (height.image < height.window)
	{
		width.image = 0;
		while (width.image < width.window)
		{
			img->addr[height.image * width.window + width.image] = color.pixel + (int) (((double) color.delta / color.nbr) * (height.image)) * position;
			width.image++;
		}
		height.image++;
	}
}

void	rainbow(t_data *img, void *mlx, void *win)
{
	t_color	color;
	t_size	height;
	t_size	width;
	double	line;
	
	height.window = 1440;
	width.window = 2560;
	height.image = 0;
	color = init_color_rainbow(color, height);
	while (height.image < height.window)
	{
		width.image = 0;
		while (width.image < width.window)
		{
			line = height.image / color.per_pixel;
			img->addr[height.image * width.window + width.image] =  color.pixel;
			if (line > color.interval)
			{
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			width.image++;
		}
		height.image++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
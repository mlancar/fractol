/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:04:24 by malancar          #+#    #+#             */
/*   Updated: 2023/04/05 16:18:55 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>


int main()
{
	t_data	img;
	t_color	color;
	t_size	height;
	t_size	width;
	
	void	*mlx;
	void	*win;
	
	double		line;
	
	t_nbr	x;
	t_nbr	y;


	height.window = 1000;
	width.window = 1000;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, width.window, height.window, "RAINBOW");
	mlx_key_hook(win, key_hook, mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);

	img.img = mlx_new_image(mlx, width.window, height.window);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	height.image = 0;
	
	color.nbr = height.window;
	color.delta = 0xFF;
	color.pixel = 0xFF0000;
	color.gradient = 6;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) height.window / color.nbr;
	color.interval = 0;
	while (height.image < height.window)
	{
		width.image = 0;
		while (width.image < width.window)
		{
			line = height.image / color.per_pixel;
			img.addr[height.image * width.window + width.image] =  color.pixel;
			if (line > color.interval)
			{
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			width.image++;
		}
		height.image++;
	}
	int position = CHANGE_RED;
	color.nbr = height.window;
	color.delta = 0xFF;
	color.pixel = BLUE;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) height.window / color.nbr;
	//DROITE ET CERCLE :
	color.pixel = BLACK;
	height.image = 0;
	//MON REPERE :
	y.min = -5;
	x.min = -5;
	y.max = 5;
	x.max = 5;
	//EQUATION DROITE : y = ax + b => (y - ax + b) entre 0 et 0.1
	//CERCLE : (x - xc)^2 + (y - yc)^2 = R^2
	x.center = 0;
	y.center = 0;
	double radius = 1.5;
	while (height.image < height.window)
	{
		width.image = 0;
		while (width.image < width.window)
		{
			x.x = x.min + ((x.max - x.min) / width.window) * width.image;
			y.y = y.max - ((y.max - y.min) / height.window) * height.image;
			if (((radius * radius) - (((x.x - x.center) * (x.x - x.center)) + ((y.y - y.center) * (y.y - y.center))) >= -0.1) && ((radius * radius) - (((x.x - x.center) * (x.x - x.center)) + ((y.y - y.center) * (y.y - y.center))) >= -0.1))
			{
				color.pixel =  (int) (((double) color.delta / color.nbr) * (height.image)) * position;
				img.addr[height.image * width.window + width.image] = color.pixel;
			}
			width.image++;
		}
		height.image++;
	}
	
	/*while (height.image < height.window)
	{
		width.image = 0;
		while (width.image < width.window)
		{
			x = min.x + ((max.x - min.x) / width.window) * width.image;
			y = max.y - ((max.y - min.y) / height.window) * height.image;
			if (y - (2 * x + 2) >= 0 && y - (2 * x + 2) <= 0.1)
			{
				img.addr[height.image * width.window + width.image] = color.pixel;
			}
			width.image++;
		}
		height.image++;
	}*/

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);

}

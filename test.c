/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:04:24 by malancar          #+#    #+#             */
/*   Updated: 2023/03/31 00:53:03 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

int	close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	key_hook(int keycode, void *mlx)
{
	if (keycode == 113)
		close(mlx);
	return (0);
}


int main()
{
	t_data	img;
	t_color	color;
	void	*mlx;
	void	*win;
	double		line;
	int		win_height;
	int		win_width;
	int		img_height;
	int		img_width;
	int		gradient;
	double	x;
	double	y;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	

	win_height = 1440;
	win_width	= 2560;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "RAINBOW");
	mlx_key_hook(win, key_hook, mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);

	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img_height = 0;
	
	color.nbr = win_height;
	color.delta = 0xFF;
	color.pixel = 0xFF0000;
	color.gradient = 6;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) win_height / color.nbr;
	color.interval = 0;
	while (img_height < win_height)
	{
		img_width = 0;
		while (img_width < win_width)
		{
			line = img_height / color.per_pixel;
			img.addr[img_height * win_width + img_width] =  color.pixel;
			if (line > color.interval)
			{
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			img_width++;
		}
		img_height++;
	}
	color.pixel = BLACK;
	img_height = 0;
	x_min = -5;
	y_min = -5;
	x_max = 5;
	y_max = 5;
	while (img_height < win_height)
	{
		img_width = 0;
		while (img_width < win_width)
		{
			x = x_min + ((x_max - x_min) / win_width) * img_width;
			y = y_max - ((y_max - y_min) / win_height) * img_height; 
			if (y - (2 * x + 2) >= 0 && y - (2 * x + 2) <= 0.1)
			{
				img.addr[img_height * win_width + img_width] = color.pixel;
			}
			img_width++;
		}
		img_height++;
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);

}

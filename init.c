/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 19:28:02 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_color	init_color_rainbow(t_color color, t_size height)
{
	printf("height %d\n", height.window);
	color.nbr = height.window;
	color.delta = 0xFF;
	color.pixel = 0xFF0000;
	color.gradient = 6;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) height.window / color.nbr;
	color.interval = 0;
	/*printf("color.nbr %d\n", color.nbr);
	printf("color.delta %d\n", color.delta);
	printf("color.pixel %d\n", color.pixel);
	printf("color.gradient %d\n", color.gradient);
	printf("color.per_gradient%d\n", color.per_gradient);
	printf("color.per_pixel %f\n", color.per_pixel);
	printf("color.interval %d\n\n", color.interval);*/
	return (color);
	
}

t_color	init_color_gradient(t_color color, t_size height)
{
	color.nbr = height.window;
	color.delta = 0xFF;
	color.pixel = BLUE;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) height.window / color.nbr;
	printf("color.nbr %d\n", color.nbr);
	printf("color.delta %d\n", color.delta);
	printf("color.pixel %d\n", color.pixel);
	printf("color.gradient %d\n", color.gradient);
	printf("color.per_gradient%d\n", color.per_gradient);
	printf("color.per_pixel %f\n", color.per_pixel);
	//printf("color.interval %d\n\n", color.interval);
	return (color);
}
void	init_win_and_img(t_data *img, void *mlx, void *win)
{
	t_size	height;
	t_size	width;
	
	height.window = 1440;
	width.window = 2560;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width.window, height.window, "TEST");
	mlx_key_hook(win, key_hook, mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);
	img->img = mlx_new_image(mlx, width.window, height.window);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	//rainbow(img, mlx, win);
	gradient(img, mlx, win);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
}

int	main()
{
	t_data	img;
	void	*mlx;
	void	*win;

	mlx = NULL;
	win = NULL;
	init_win_and_img(&img, &mlx, &win);
	//rainbow(&img, mlx, win);
	
}
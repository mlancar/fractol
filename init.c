/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/04/05 19:05:37 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_color	init_color_rainbow(t_color color, t_size window)
{
	color.nbr = window.height;
	color.delta = 0xFF;
	color.pixel = RED;
	color.gradient = 6;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) window.height / color.nbr;
	color.interval = 0;
	return (color);
	
}

t_color	init_color_gradient(t_color color, t_size window)
{
	color.nbr = window.height;
	color.delta = 0xFF;
	color.pixel = YELLOW;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) window.height/ color.nbr;
	return (color);
}
void	init_win_and_img(t_data *img, void **mlx, void **win)
{
	t_size	window;
	
	window.height = 1000;
	window.width = 1000;
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, window.width, window.height, "TEST");
	mlx_key_hook(*win, key_hook, *mlx);
	//mlx_hook(*win, 113, 1L<<0, close, *mlx);
	img->img = mlx_new_image(*mlx, window.width, window.height);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	//rainbow(img, mlx, win, window);
	//gradient(img, mlx, win, window);
	
	circle(img, *mlx, *win, window);
	
}

int	main()
{
	t_data	img;
	void	*mlx;
	void	*win;

	mlx = NULL;
	win = NULL;
	
	init_win_and_img(&img, &mlx, &win);
	printf("dans main = %p\n", mlx);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_window(mlx, win);
	//mlx_clear_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
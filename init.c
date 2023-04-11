/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/04/11 18:35:18 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_win_and_img(t_graph *var)
{
		
	var->win_height = 1000;
	var->win_width = 1000;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->win_width, var->win_height, "TEST");
	mlx_key_hook(var->win, key_hook, var->mlx);
	mlx_mouse_hook(var->win, mouse_hook, var->mlx);
	var->img.img = mlx_new_image(var->mlx, var->win_width, var->win_height);
	var->img.addr = (int *)mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
	//rainbow(img, *mlx, *win, window);
	//gradient(img, *mlx, *win, window);
	//circle(img, *mlx, *win, window);
	//mandelbrot(img, *mlx, *win, window);
	julia(var);
	
}

int	main()
{
	t_graph	var;

	var.mlx = NULL;
	var.win = NULL;
	var.zoom = 0;
	
	init_win_and_img(&var);
	mlx_loop(var.mlx);
	mlx_destroy_image(var.mlx, var.img.img);
	mlx_destroy_window(var.mlx, var.win);
	//mlx_clear_window(mlx, win);
	mlx_destroy_display(var.mlx);
	free(var.mlx);
}
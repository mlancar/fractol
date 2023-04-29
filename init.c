/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:51:07 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_win_and_img(t_graph *var, char *av2, char *av3)
{
	var->win_height = 1000;
	var->win_width = 1000;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->win_width, var->win_height,
			"FRACTOL");
	mlx_key_hook(var->win, key_hook, var);
	mlx_mouse_hook(var->win, mouse_hook, var);
	mlx_hook(var->win, 17, (1L << 2), close_window, var);
	var->img.img = mlx_new_image(var->mlx, var->win_width, var->win_height);
	var->img.addr = (int *)mlx_get_data_addr(var->img.img,
			&var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
	init_fractal(var, av2, av3);
	draw_fractal(var);
}

void	init_fractal(t_graph *var, char *av2, char *av3)
{
	if (check_name(var) == 'J')
	{
		var->c.r = ft_atof(av2);
		var->c.i = ft_atof(av3);
		init_julia_graph(var);
	}
	else if (check_name(var) == 'M')
		init_mandelbrot_graph(var);
	else if (check_name(var) == 'X')
	{
		var->c.p = ft_atoi(av2);
		init_multibrot_graph(var);
	}
	else if (check_name(var) == 'N')
	{
		var->c.p = ft_atoi(av2);
		init_newton_graph(var);
	}
}

void	init_color_gradient(t_color *color, t_graph *var)
{
	color->nbr = var->win_height;
	color->delta = 0xFF;
	color->pixel = YELLOW;
	color->gradient = 1;
	color->per_gradient = color->nbr / color->gradient;
	color->per_pixel = (double) var->win_height / color->nbr;
}

void	init_color_set(t_graph *var, t_set *z, t_color color)
{	
	int	red;
	int	blue;
	int	green;

	color.p_i = z->n / z->iteration_max;
	color.index = var->img_height * var->win_width + var->img_width;
	red = 16 * 16 * 16 * 16;
	blue = 1;
	green = 16 * 16;
	if (z->n == z->iteration_max)
		var->img.addr[color.index] = BLACK;
	else
	{
		if (var->color_set == 1)
			color_set_1(var, color, red);
		else if (var->color_set == 2)
			color_set_2(var, color, green);
		else if (var->color_set == 3)
			color_set_3(var, color, blue);
		else if (var->color_set == 4)
			color_set_4(var, color, red);
		else if (var->color_set == 5)
			color_set_5(var, color, red, green);
	}
}

void	draw_fractal(t_graph *var)
{
	if (check_name(var) == 'J')
		julia(var);
	else if (check_name(var) == 'M')
		mandelbrot(var);
	else if (check_name(var) == 'X')
		multibrot(var);
	else if (check_name(var) == 'N')
		newton(var);
}

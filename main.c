/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:37 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:53:44 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_graph	var;

	var.mlx = NULL;
	var.win = NULL;
	var.zoom = 1;
	var.img.name = av[1];
	if (!check_args(ac, av, &var))
		return (0);
	else
	{
		init_win_and_img(&var, av[2], av[3]);
		mlx_loop(var.mlx);
		mlx_destroy_image(var.mlx, var.img.img);
		mlx_destroy_window(var.mlx, var.win);
		mlx_destroy_display(var.mlx);
		free(var.mlx);
	}
}
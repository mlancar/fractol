/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:51:52 by malancar          #+#    #+#             */
/*   Updated: 2023/04/17 17:33:21 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int ac, char **av)
{
	int		i;
	char	*julia;
	char	*mandelbrot;

	julia = "Julia";
	mandelbrot = "Mandelbrot";
	if (ac < 2)
	{
		ft_putstr("Please enter a fractal name :\n-Julia\n-Mandelbrot\n");
		return (0);
	}
	if ((ft_strcmp(av[1], julia) != 0) && (ft_strcmp(av[1], mandelbrot) != 0))
	{
		ft_putstr("Wrong fractal name. Did you mean \"Julia\" ? Or \"Mandelbrot\" ?\n");
		return (0);
	}
	return (1);
}

char	check_name(t_graph *var)
{
	if (ft_strcmp(var->img.name, "Julia") == 0)
		return('J');
	else if (ft_strcmp(var->img.name, "Mandelbrot") == 0)
		return('M');
	return ('X');
}
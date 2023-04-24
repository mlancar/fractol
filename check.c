/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:51:52 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 19:00:41 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int ac, char **av, t_graph *var)
{
	char	*julia;
	char	*mandelbrot;

	julia = "Julia";
	mandelbrot = "Mandelbrot";
	if (ac < 2)
	{
		ft_put_error("Please enter a fractal name :\n-Julia\n-Mandelbrot\n");
		return (0);
	}
	if ((ft_strcmp(av[1], julia) != 0) && (ft_strcmp(av[1], mandelbrot) != 0))
	{
		ft_put_error("Wrong fractal name.");
		ft_put_error("Did you mean \"Julia\" ? Or \"Mandelbrot\" ?\n");
		return (0);
	}
	if ((ac < 4) || check_param(av, var) == 0)
		return (ft_put_error("parameter is not valid\n"), 0);
	if ((ac < 5) || check_color_set(av, var) == 0)
		return (ft_put_error("Choose \"color set 1\" or \"color set 2\".\n"), 0);
	return (1);
}

char	check_name(t_graph *var)
{
	if (ft_strcmp(var->img.name, "Julia") == 0)
		return ('J');
	else if (ft_strcmp(var->img.name, "Mandelbrot") == 0)
		return ('M');
	return ('X');
}

int	check_param(char **av, t_graph *var)
{	
	if (check_name(var) == 'J')
	{
		if (((ft_strcmp(av[2], "0.285") != 0)
				|| (ft_strcmp(av[3], "0.01") != 0))
			&& ((ft_strcmp(av[2], "-0.835") != 0)
				|| (ft_strcmp(av[3], "-0.232")) != 0)
			&& ((ft_strcmp(av[2], "-0.7269") != 0)
				|| (ft_strcmp(av[3], "0.01889") != 0))
			&& ((ft_strcmp(av[2], "-0.70176") != 0)
				|| (ft_strcmp(av[3], "-0.3842") != 0))
			&& ((ft_strcmp(av[2], "-0.8") != 0)
				|| (ft_strcmp(av[3], "0.156") != 0))
			&& ((ft_strcmp(av[2], "-0.8") != 0)
				|| (ft_strcmp(av[3], "0") != 0)))
		{
			return (0);
		}
	}
	else if (check_name(var) == 'M')
	{
		if ((ft_strcmp(av[2], "0") != 0) || (ft_strcmp(av[3], "0") != 0))
			return (0);
	}
	return (1);
}

int	check_color_set(char **av, t_graph *var)
{
	if (ft_strcmp(av[4], "color set 1") == 0)
	{
		var->set.color = 1;
		return (1);
	}
	else if (ft_strcmp(av[4], "color set 2") == 0)
	{
		var->set.color = 2;
		return (1);
	}
	return (0);
}

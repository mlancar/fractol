/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:51:52 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 20:04:51 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int ac, char **av, t_graph *var)
{
	if (ac < 2)
		return (put_info(), 0);
	if ((ft_strcmp(av[1], "Julia") != 0) && (ft_strcmp(av[1], "Newton") != 0)
		&& (ft_strcmp(av[1], "Mandelbrot") != 0)
		&& (ft_strcmp(av[1], "Multibrot") != 0))
	{
		return (0);
	}
	if (ac != 5)
		return (ft_put_error("Not enought paramters.\n"), 0);
	if (check_param(av, var) == 0)
		return (ft_put_error("parameter is not valid\n"), 0);
	if (check_color_set(av, var) == 0)
		return (ft_put_error("Choose \"purple\", \"blue\", \"red\".\n"), 0);
	return (1);
}

int	check_name(t_graph *var)
{
	if (ft_strcmp(var->img.name, "Julia") == 0)
		return ('J');
	else if (ft_strcmp(var->img.name, "Mandelbrot") == 0)
		return ('M');
	else if (ft_strcmp(var->img.name, "Multibrot") == 0)
		return ('X');
	else if (ft_strcmp(var->img.name, "Newton") == 0)
		return ('N');
	return ('z');
}

int	check_param(char **av, t_graph *var)
{	
	int	param;

	if (check_name(var) == 'J')
	{
		if (check_julia_param(av) != 0)
			return (1);
	}
	else if (check_name(var) == 'M')
	{
		if ((ft_strcmp(av[2], "0") == 0) && (ft_strcmp(av[3], "0") == 0))
			return (1);
	}
	else if (check_name(var) == 'X')
	{
		param = ft_atoi(av[2]);
		if ((param > 2 && param < 100) && (ft_strcmp(av[3], "0") == 0))
			return (1);
	}
	else if (check_name(var) == 'N')
	{
		param = ft_atoi(av[2]);
		if ((param > 2 && param < 100) && (ft_strcmp(av[3], "0") == 0))
			return (1);
	}
	return (0);
}

int	check_julia_param(char **av)
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
	return (1);
}

int	check_color_set(char **av, t_graph *var)
{
	if (ft_strcmp(av[4], "red") == 0)
		return ((var->color_set = 1), 1);
	else if (ft_strcmp(av[4], "green") == 0)
		return ((var->color_set = 2), 1);
	else if (ft_strcmp(av[4], "blue") == 0)
		return ((var->color_set = 3), 1);
	else if (ft_strcmp(av[4], "purple") == 0)
		return ((var->color_set = 4), 1);
	else if (ft_strcmp(av[4], "lava") == 0)
		return ((var->color_set = 5), 1);
	return (0);
}

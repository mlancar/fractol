/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:54:54 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 16:47:07 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int		i;
	char	*julia;
	char	*mandelbrot;

	i = 1;
	julia = "Julia";
	mandelbrot = "Mandelbrot";
	if (ac < 2)
	{
		ft_putstr("Please enter a fractal name\n");
		return (0);
	}
	if ((ft_strcmp(av[1], julia) != 0) && (ft_strcmp(av[1], mandelbrot) != 0))
	{
		ft_putstr("Wrong fractal name. Did you mean \"Julia\" ? Or \"Mandelbrot\" ?\n");
		return (0);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:29:46 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:52:47 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	put_info(void)
{
	ft_put_error("[fractal name] [param1] [param2] [color]\n\n");
	ft_put_error("Fractal name :\n-Julia\n-Mandelbrot\n-Multibrot\n-Newton\n\n");
	ft_put_error("Param for Julia :\n 0.285 0.01\n-0.835 -0.232\n");
	ft_put_error("-0.70176 -0.3842\n-0.8 0.156\n-0.7269 0.1889\n-0.8 0\n");
	ft_put_error("Param for Mandelbrot : 0 0\n\n");
	ft_put_error("Param for Multibrot : [2->100] 0\n\n");
	ft_put_error("Param for Newton : [2->100] 0\n\n");
	ft_put_error("Color set :\n-red\n-green\n-blue\n-purple\n-lave\n");
}

double	z_power_n_real( double real, double imaginary, double power)
{
	double	p;
	double	cosinus;
	double	atan;
	double	n_real;

	p = pow(sqrt(((real * real) + (imaginary * imaginary))), power);
	atan = atan2(imaginary, real);
	cosinus = cos(power * atan);
	n_real = p * cosinus;
	return (n_real);
}

double	z_power_n_imaginary(double real, double imaginary, double power)
{
	double	p;
	double	sinus;
	double	atan;
	double	n_imaginary;

	p = pow(sqrt(((real * real) + (imaginary * imaginary))), power);
	atan = atan2(imaginary, real);
	sinus = sin(power * atan);
	n_imaginary = p * sinus;
	return (n_imaginary);
}

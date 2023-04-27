/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:29:46 by malancar          #+#    #+#             */
/*   Updated: 2023/04/27 20:03:46 by malancar         ###   ########.fr       */
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

double	z_power_n_real( double real, double imaginary, double power)
{
	double	p;
	double	cosinus;
	double	atan;
	double	n_real;

	p = pow(sqrt(((real * real) + (imaginary* imaginary))), power);
	atan = atan2(imaginary, real);
	cosinus = cos(power * atan);
	
	n_real= p * cosinus;
	//printf("n_real = %f\n", n_real);
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
	
	
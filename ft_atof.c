/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:14:15 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:47 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_recursive_power(int nb, int power)
{	
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

double	ft_atof(char *str)
{
	int		i;
	int		j;
	int		sign;
	double	before;
	double	after;

	i = 0;
	j = 0;
	sign = 1;
	before = 0;
	after = 0;
	before = ft_atoi(str);
	if (str[i] == '-')
		sign = -1;
	while (str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		after = (after * 10) + (str[i] - 48);
		i++;
		j++;
	}
	return ((before + (after / ft_recursive_power(10, j))) * sign);
}

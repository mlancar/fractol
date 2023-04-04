/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:29:46 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 19:20:11 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


int		find_position(int color_per_gradient, int interval)
{
	int	x;
	
	x = 1;
	if (interval < color_per_gradient)
		x = 16 * 16;
	else if (interval < (color_per_gradient * 2))
		x = -(16 * 16 * 16 * 16);
	else if (interval < (color_per_gradient * 3))
			x = 1;
	else if (interval < (color_per_gradient * 4))
		x = -(16 * 16);
	else if (interval < (color_per_gradient * 5))
		x = 16 * 16 * 16 * 16;
	else if (interval < (color_per_gradient * 6))
		x = -1;
	return (x);
}
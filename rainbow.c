/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:50:14 by malancar          #+#    #+#             */
/*   Updated: 2023/04/24 18:52:06 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color	init_color_rainbow(t_color color, t_graph *var)
{
	color.nbr = var->win_height;
	color.delta = 0xFF;
	color.pixel = RED;
	color.gradient = 6;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) var->win_height / color.nbr;
	color.interval = 0;
	return (color);
}

void	rainbow(t_graph *var)
{
	t_color	color;
	double	line;
	
	var->img_height= 0;
	color = init_color_rainbow(color, var);
	while (var->img_height < var->win_height)
	{
		var->img_width = 0;
		while (var->img_width < var->win_width)
		{
			line = var->img_height/ color.per_pixel;
			var->img.addr[var->img_height * var->win_width + var->img_width] =  color.pixel;
			if (line > color.interval)
			{
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			var->img_width++;
		}
		var->img_height++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:04:24 by malancar          #+#    #+#             */
/*   Updated: 2023/03/28 03:02:21 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>
/*typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
*/

int main()
{
	t_data	img;
	t_color	color;
	void	*mlx;
	void	*win;
	double		line;
	int		win_height;
	int		win_width;
	int		img_height;
	int		img_width;
	int		gradient;
	

	win_height = 1440;
	win_width	= 2560;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "TEST");

	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img_height = 0;
	
	color.nbr = win_height;
	color.delta = 0xFF;
	color.pixel = 0xFF0000;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) win_height / color.nbr;
	color.interval = 0;
	while (img_height < win_height)
	{
		img_width = 0;
		while (img_width < win_width)
		{
			line = img_height / color.per_pixel;
			img.addr[img_height * win_width + img_width] =  color.pixel;
			if (line > color.interval)
			{
				printf("line double =%f\n", line);
				printf("interval = %d\n", color.interval);
				printf("color per gradient = %d\n", color.per_gradient);
				printf("%X\n", color.pixel);
				//printf("%d\n", (int)((double) color.delta / color.per_gradient));
				color.pixel = color.pixel + color.delta / color.per_gradient * find_position(color.per_gradient, color.interval);
				color.interval++;
			}
			img_width++;
		}
		img_height++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	
	
}

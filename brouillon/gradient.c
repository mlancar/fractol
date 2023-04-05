/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:07:32 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 19:27:41 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	int		position;
	

	win_height = 1000;
	win_width	= 2000;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "TEST");
	mlx_key_hook(win, key_hook, mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);
	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img_height = 0;
	position = CHANGE_RED;
	color.nbr = win_height;
	color.delta = 0xFF;
	color.pixel = BLUE;
	color.gradient = 1;
	color.per_gradient = color.nbr / color.gradient; 
	color.per_pixel = (double) win_height / color.nbr;
	printf("color.nbr %d\n", color.nbr);
	printf("color.delta %d\n", color.delta);
	printf("color.pixel %d\n", color.pixel);
	printf("color.gradient %d\n", color.gradient);
	printf("color.per_gradient%d\n", color.per_gradient);
	printf("color.per_pixel %f\n", color.per_pixel);
	//printf("color.interval %d\n", color.interval);
	//color.interval = 1000;
	while (img_height < win_height)
	{
		img_width = 0;
		while (img_width < win_width)
		{
			img.addr[img_height * win_width + img_width] = color.pixel + (int) (((double) color.delta / color.nbr) * (img_height)) * position;
			img_width++;
		}
		img_height++;
	}
	
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);

}
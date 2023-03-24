/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/03/24 17:40:51 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_win_and_img(t_data *img, void *mlx, void *win)
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "TEST");
	img->img = mlx_new_image(mlx, 1000, 1000);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	put_pixel(t_data *img, void *mlx, void 	*win)
{
	t_color	color;	
	int		img_height;
	int		img_width;
	
	color.finish = 255;
	color.start = 0xFF0000;
	color.interval = 1440;
	img_height = 0;
	while (img_height < 1000)
	{
		img_width = 0;
		while (img_width < 1000)
		{
			
			img->addr[img_height * 1000 + img_width] = (int) (((double) color.finish / color.interval) * (img_height)) * 256 + color.start;
			img_width++;
		}
		img_height++;
	}
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
	mlx_loop(mlx);
}

int	main()
{
	t_data	img;
	void	*mlx;
	void	*win;

	mlx = NULL;
	win = NULL;
	init_win_and_img(&img, &mlx, &win);
	put_pixel(&img, mlx, win);
	
}
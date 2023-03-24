/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:38:17 by malancar          #+#    #+#             */
/*   Updated: 2023/03/23 05:50:08 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_win_and_img(t_data *img, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "TEST");
	img->img = mlx_new_image(mlx->mlx, 1000, 1000);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	put_pixel(t_data *img, t_mlx mlx)
{
	t_color	color;
	
	img->height = 0;
	color.finish = 255;
	color.start = 0xFF0000;
	color.interval = 1440;
	while (img->height < 1440)
	{
		img->width = 0;
		while (img->width < 2560)
		{
			
			img->addr[img->height * 2560 + img->width] = (int) (((double) color.finish / color.interval) * (img->height)) * 256 + color.start;
			img->width++;
		}
		img->height++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img->img, 0, 0);
	mlx_loop(mlx.mlx);
}

int	main()
{
	t_data	img;
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	init_win_and_img(&img, &mlx);
	put_pixel(&img, mlx);
	
}
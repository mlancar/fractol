/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:04:24 by malancar          #+#    #+#             */
/*   Updated: 2023/03/23 05:52:33 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"


typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		img_width;
	int		img_height;
	int		max;
	int		color_start;
	int		inter;

	relative_path = "./isaac.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2560, 1440, "TEST");
	img.img = mlx_new_image(mlx, 2560, 1440);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img_height = 0;
	max = 255;
	color_start = 0xFF0000;
	inter = 1440;
	
	while (img_height < 1440)
	{
		img_width = 0;
		while (img_width < 2560)
		{
			
			img.addr[img_height * 2560 + img_width] = (int) (((double) max / inter) * (img_height)) * 256 + color_start;
			img_width++;
		}
		img_height++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

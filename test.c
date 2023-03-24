/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:04:24 by malancar          #+#    #+#             */
/*   Updated: 2023/03/24 18:00:27 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

/*typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
*/
int	close(void *win, int keycode, void *mlx)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int main()
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_color		color;
	int			win_height;
	int			win_width;
	int			img_height;
	int			img_width;

	win_height = 1440;
	win_width	= 2560;
	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "TEST");

	mlx_hook(win, KEY_Q, 1L<<0, close, &mlx);
	//mlx_key_hook(win, close, mlx);
	//mlx_mouse_hook(win, close, &mlx);
	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img_height = 0;
	color.finish = 255;
	color.start = 0xFF0000;
	color.interval = 1440;
	
	while (img_height < win_height)
	{
		img_width = 0;
		while (img_width < win_width)
		{
			
			img.addr[img_height * win_width + img_width] = (int) (((double) color.finish / color.interval) * (img_height)) * 256 + color.start;
			img_width++;
		}
		img_height++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	
	
}

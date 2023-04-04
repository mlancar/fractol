/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/04 19:28:32 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#define KEY_Q 113
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define PINK 0xFF00FF
#define CYAN 0x00FFFF
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define CHANGE_RED 16 * 16 * 16 * 16
#define CHANGE_GREEN 16 * 16
#define CHANGE_BLUE 1

#include "mlx/mlx.h"
#include <stddef.h>

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_size {
	int		image;
	int		window;
}	t_size;

typedef struct s_color {
	int			nbr;
	int			delta;
	int			pixel;
	int			finish;
	int			interval;
	int			gradient;
	int			per_gradient;
	double		per_pixel;
}	t_color;

typedef struct s_nbr {
	double	x;
	double	y;
}	t_nbr;

int		key_hook(int keycode, void *mlx);
int		close(void *mlx);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	init_win_and_img(t_data *img, void *mlx, void *win);
void	put_pixel(t_data *img, void *mlx, void *win);
int		find_position(int color_per_gradient, int interval);
int		find_position2(int color_per_gradient, int interval);
void	rainbow(t_data *img, void *mlx, void *win);
void	gradient (t_data *img, void *mlx, void *win);
t_color	init_color_rainbow(t_color color, t_size height);
t_color	init_color_gradient(t_color color, t_size height);

# endif

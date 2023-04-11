/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/11 17:30:34 by malancar         ###   ########.fr       */
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
#define	UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307
#define CLICKRIGHT 3
#define CLICKLEFT 1
#define ZOOMIN 4
#define ZOMMOUT 5

#include "mlx/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

typedef struct s_graph {
	double	x;
	double	y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	center;
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	int		img_height;
	int		img_width;
	double	zoom;
	t_data	img;
}	t_graph;

typedef struct s_set {
	double	r;
	double	i;
	double	n;
	double	c_i;
	double	c_r;
	double	tmp;
	double	iteration_max;
}	t_set;

void	zoomin(t_graph *var);
int		mouse_hook(int mousecode, t_graph *var);
int		key_hook(int keycode, t_graph *var);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	init_win_and_img(t_graph *var);
int		find_position(int color_per_gradient, int interval);
t_color	init_color_rainbow(t_color color, t_graph *var);
t_color	init_color_gradient(t_color color, t_graph *var);
void	rainbow(t_graph *var);
void	gradient (t_graph *var);
void	circle(t_graph *var);
void 	init_graph(t_graph *var);
void	init_mandelbrot_graph(t_graph *var);
void	init_mandelbrot_set(t_set *z, t_graph *var);
void	re_init_mandelbrot_set(t_set *z);
void	color_mandelbrot_set(t_graph *var, t_set *z, t_color color);
void	mandelbrot(t_graph *var);
void	init_julia_graph(t_graph *var);
void	init_julia_set(t_set *z, t_graph *var);
void	re_init_julia_set(t_set *z);
void	color_julia_set(t_graph *var, t_set *z, t_color color);
void	julia(t_graph *var);

# endif

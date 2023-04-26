/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/26 19:25:16 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define KEY_Q 113
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PINK 0xFF00FF
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define CLICKRIGHT 3
# define CLICKLEFT 1
# define ZOOMIN 4
# define ZOMMOUT 5

# include "mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
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

typedef struct s_set {
	int		color;
	int		p;
	double	r;
	double	i;
	double	n;
	double	c_i;
	double	c_r;
	double	tmp;
	double	iteration_max;
}	t_set;

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
	t_set	c;
	t_set	set;
}	t_graph;

int		ft_atoi(char *str);
void	z_puissance_3(t_set *z, t_graph *var);
void	color_julia(t_graph *var, t_set *z, t_color color, int change_red);
void	color_julia_2(t_graph *var, t_set *z, t_color color);
int		check_color_set(char **av, t_graph *var);
void	color_julia_set1(t_graph *var, t_set *z, t_color color);
void	color_julia_set2(t_graph *var, t_set *z, t_color color);
void	zoom_out(int x, int y, t_graph *var);
void	zoom_in(int x, int y, t_graph *var);
int		key_pressed(int key_code, t_graph *var, double delta_x, double delta_y);
int		mouse_position(int mouse_pos, int x, int y, t_graph *var);
int		check_param(char **av, t_graph *var);
double	ft_atof(char *str);
char	check_name(t_graph *var);
int		check_args(int ac, char **av, t_graph *var);
void	draw_fractal(t_graph *var);
int		close_window(t_graph *var);
int		mouse_hook(int mouse_code, int x, int y, t_graph *var);
int		key_hook(int key_code, t_graph *var);
int		ft_strcmp(char *s1, char *s2);
void	ft_put_error(char *str);
void	init_win_and_img(t_graph *var, char *s1, char *s2);
int		find_position(int color_per_gradient, int interval);
t_color	init_color_rainbow(t_color color, t_graph *var);
t_color	init_color_gradient(t_color color, t_graph *var);
void	rainbow(t_graph *var);
void	gradient(t_graph *var);
void	init_mandelbrot_graph(t_graph *var);
void	init_mandelbrot_set(t_set *z, t_graph *var);
void	re_init_mandelbrot_set(t_set *z);
void	color_mandelbrot_set(t_graph *var, t_set *z, t_color color);
void	mandelbrot(t_graph *var);
void	init_julia_graph(t_graph *var);
void	init_julia_set(t_set *z, t_graph *var);
void	re_init_julia_set(t_set *z, t_graph *var);
void	color_julia_set(t_graph *var, t_set *z, t_color color);
void	julia(t_graph *var);

#endif

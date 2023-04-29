/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/04/29 19:47:21 by malancar         ###   ########.fr       */
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
# include <unistd.h>

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
}	t_data;

typedef struct s_color {
	int		index;
	int		nbr;
	int		set;
	int		delta;
	int		pixel;
	int		finish;
	int		interval;
	int		gradient;
	int		per_gradient;
	double	per_pixel;
	double	p_i;
}	t_color;

typedef struct s_set {
	double	p;
	double	r;
	double	i;
	double	n;
	double	c_i;
	double	c_r;
	double	tmp;
	double	iteration_max;
	double	a;
	double	b;
	double	c;
	double	d;
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
	int		color_set;
	t_data	img;
	t_set	c;
	t_set	set;
	t_set	tmp;
}	t_graph;

void	init_color_gradient(t_color *color, t_graph *var);
void	init_color_set(t_graph *var, t_set *z, t_color color);
void	color_set_1(t_graph *var, t_color color, int red);
void	color_set_2(t_graph *var, t_color color, int green);
void	color_set_3(t_graph *var, t_color color, int blue);
void	color_set_4(t_graph *var, t_color color, int red);
void	color_set_5(t_graph *var, t_color color, int red, int green);

double	z_power_n_real(double real, double imaginary, double power);
double	z_power_n_imaginary(double real, double imaginary, double power);
int		ft_strcmp(char *s1, char *s2);
void	ft_put_error(char *str);
void	put_info(void);

int		ft_atoi(char *str);
double	ft_atof(char *str);

void	zoom_out(int x, int y, t_graph *var);
void	zoom_in(int x, int y, t_graph *var);
int		key_pressed(int key_code, t_graph *var, double delta_x, double delta_y);
int		mouse_hook(int mouse_code, int x, int y, t_graph *var);
int		key_hook(int key_code, t_graph *var);
int		close_window(t_graph *var);

int		check_param(char **av, t_graph *var);
int		check_name(t_graph *var);
int		check_args(int ac, char **av, t_graph *var);
int		check_color_set(char **av, t_graph *var);
int		check_julia_param(char **av);

void	init_win_and_img(t_graph *var, char *av2, char *av3);
void	init_fractal(t_graph *var, char *av2, char *av3);
void	draw_fractal(t_graph *var);

void	init_newton_graph(t_graph *var);
void	init_newton_set(t_set *z, t_graph *var);
void	re_init_newton_set(t_set *z, t_graph *var);
void	newton(t_graph *var);

void	multibrot(t_graph *var);
void	init_multibrot_graph(t_graph *var);
void	re_init_multibrot_set(t_set *z, t_graph *var);
void	init_multibrot_set(t_set *z, t_graph *var);

void	init_mandelbrot_graph(t_graph *var);
void	init_mandelbrot_set(t_set *z, t_graph *var);
void	re_init_mandelbrot_set(t_set *z);
void	mandelbrot(t_graph *var);

void	init_julia_graph(t_graph *var);
void	init_julia_set(t_set *z, t_graph *var);
void	re_init_julia_set(t_set *z, t_graph *var);
void	julia(t_graph *var);

#endif

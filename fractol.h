/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/03/30 22:54:55 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#define KEY_Q 81
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
	int		height;
	int		width;
}	t_size;

typedef struct s_color {
	int		nbr;
	int		delta;
	int		pixel;
	int		finish;
	int		interval;
	int		gradient;
	int		per_gradient;
	double		per_pixel;
}	t_color;

void	init_win_and_img(t_data *img, void *mlx, void *win);
void	put_pixel(t_data *img, void *mlx, void *win);
int		find_position(int color_per_gradient, int interval);
int		find_position2(int color_per_gradient, int interval);

# endif

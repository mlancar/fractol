/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:48:45 by malancar          #+#    #+#             */
/*   Updated: 2023/03/24 18:03:47 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#define KEY_Q 113

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
	int		pixel;
	int		start;
	int		finish;
	int		interval;
}	t_color;

void	init_win_and_img(t_data *img, void *mlx, void *win);
void	put_pixel(t_data *img, void *mlx, void *win);

# endif

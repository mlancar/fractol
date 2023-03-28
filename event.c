/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/03/28 06:40:43 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

int	close(void *win, void *mlx)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int	key_hook(int keycode, void *mlx, void *win)
{
	if (keycode == 113)
		close(win, mlx);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "Hello world!");
	mlx_key_hook(win, key_hook, &mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);
	mlx_loop(mlx);
}

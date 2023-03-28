/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/03/28 06:57:49 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

int	close(void *mlx)
{
	printf("coucou\n");
	mlx_loop_end(mlx);
	return (0);
}

int	key_hook(int keycode, void *mlx)
{
	if (keycode == 113)
		close(mlx);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "Hello world!");
	mlx_key_hook(win, key_hook, mlx);
	mlx_hook(win, 113, 1L<<0, close, &mlx);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malancar <malancar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:45 by malancar          #+#    #+#             */
/*   Updated: 2023/03/27 21:57:42 by malancar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	close(void *win, int keycode, void *mlx)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int	no_event(void *mlx)
{
	return(0);
}

int	key_pressed(void *win, int key_code, void *mlx)
{
	if (key_code == XK_q)
		mlx_destroy_window(mlx, win);
	printf("key_pressed = %d\n", key_code);
	return (0);
}

int	key_released(void *win, int key_code, void *mlx)
{
	printf("key_released = %d\n", key_code);
	return (0);
}


mlx_hook(win, 2, 1L<<0, close, &mlx);
mlx_key_hook(win, mlx_hook, &mlx);
mlx_mouse_hook(win, close, &mlx);
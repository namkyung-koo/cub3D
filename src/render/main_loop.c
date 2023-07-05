/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:07:45 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/05 15:23:28 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->screen_img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

static void	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	else if (keycode == KEY_W)
		;
	else if (keycode == KEY_A)
		;
	else if (keycode == KEY_S)
		;
	else if (keycode == KEY_D)
		;
	else if (keycode == KEY_UP)
		;
	else if (keycode == KEY_DOWN)
		;
	else if (keycode == KEY_LEFT)
		;
	else if (keycode == KEY_RIGHT)
		;
	mlx_clear_window(data->mlx, data->win);
}

void	main_loop(t_data *data)
{
	raycasting(data);
	draw_map(data);
}

void	ft_mlx_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &main_loop, &data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, key_press, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, ft_close, data);
	mlx_loop(data->mlx);
}
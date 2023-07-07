/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:07:45 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/07 18:48:56 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->screen_img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

static int	key_press(int keycode, t_data *data)
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
	return (0);
}

int	main_loop(t_data *data)
{
	draw_floor_ceiling(data);
	raycasting(data);
	draw_map(data);
	return (0);
}

void	ft_mlx_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, main_loop, data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, key_press, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, ft_close, data);
	mlx_loop(data->mlx);
}

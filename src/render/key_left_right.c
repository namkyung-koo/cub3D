/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_left_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:21:44 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/09 19:38:40 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(data->player.rot_speed) - \
	data->player.dir_y * sin(data->player.rot_speed);
	data->player.dir_y = old_dir_x * sin(data->player.rot_speed) + \
	data->player.dir_y * cos(data->player.rot_speed);
	data->player.plane_x = data->player.plane_x * cos (data->player.rot_speed) \
	- data->player.plane_y * sin(data->player.rot_speed);
	data->player.plane_y = old_plane_x * sin(data->player.rot_speed) + \
	data->player.plane_y * cos(data->player.rot_speed);
}

void	key_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-data->player.rot_speed) - \
	data->player.dir_y * sin(-data->player.rot_speed);
	data->player.dir_y = old_dir_x * sin(-data->player.rot_speed) + \
	data->player.dir_y * cos(-data->player.rot_speed);
	data->player.plane_x = data->player.plane_x * cos (-data->player.rot_speed) \
	- data->player.plane_y * sin(-data->player.rot_speed);
	data->player.plane_y = old_plane_x * sin(-data->player.rot_speed) + \
	data->player.plane_y * cos(-data->player.rot_speed);
}

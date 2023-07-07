/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:55:45 by nakoo             #+#    #+#             */
/*   Updated: 2023/07/07 22:31:05 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player(t_player *player, t_map *map)
{
	if (map->view_dir == NORTH)
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	if (map->view_dir == SOUTH)
	{
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	if (map->view_dir == WEST)
	{
		player->dir_x = -1;
		player->plane_y = 0.66;
	}
	if (map->view_dir == EAST)
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
}

void	set_player(t_player *player, t_map *map)
{
	player->pos_x = map->player_x + 0.5;
	player->pos_y = map->player_y + 0.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
	check_player(player, map);
}

void	ft_init_buffer(t_data *data)
{
	int	idx;

	data->buffer = (int **)malloc(sizeof(int *) * screen_height);
	if (!data->buffer)
		exit(1);
	idx = 0;
	while (idx < screen_height)
	{
		data->buffer[idx] = (int *)malloc(sizeof(int) * screen_width);
		if (!data->buffer[idx])
			exit(1);
		idx++;	
	}
}

void	set_data(t_data *data)
{
	set_player(&data->player, &data->map);
	ft_init_buffer(data);
	make_texture_arr(data);
	load_texture(data);
}

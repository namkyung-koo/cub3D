/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:19:59 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/30 16:56:11 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player(t_player *player, t_map *map)
{
	if (map->view_dir == "78")
	{
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	if (map->view_dir == "83")
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	if (map->view_dir == "87")
	{
		player->dir_x = -1;
		player->plane_y = 0.66;
	}
	if (map->view_dir == "69")
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
}

void	set_player(t_player *player, t_map *map)
{
	t_map	map;

	player->pos_x = map->character_x + 0.5;
	player->pos_y = map->character_y + 0.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	check_player(player, map);
}

void	set_info(t_info *info, t_data *data)
{
	set_player(&info->player, &data->map_info);
	make_texture_arr(info);
	load_texture(info);
}
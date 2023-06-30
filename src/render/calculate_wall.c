/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:11:36 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/30 16:20:48 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_start_and_endpoint(t_ray *ray)
{
	ray->start_point = ((screenHeight / 2) - (ray->line_height / 2));
	if (ray->start_point < 0)
		ray->start_point = 0;
	ray->end_point = ((ray->line_height / 2) + (screenHeight / 2));
	if (ray->end_point >= screenHeight)
		ray->end_point = screenHeight - 1;
}

double	calculate_perpwalldist(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		return ((ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x);
	else
		return ((ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y);
}

void	calculate_wall(t_player *player, t_ray *ray)
{
	ray->perpwalldist = calculate_perpwalldist(player, ray);
	ray->line_height = (int)(screenHeight / ray->perpwalldist);
	calculate_start_and_endpoint(ray);
}
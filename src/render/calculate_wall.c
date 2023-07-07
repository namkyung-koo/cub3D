/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:11:36 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/07 21:33:17 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_start_and_endpoint(t_ray *ray)
{
	ray->start_point = ((screen_height / 2) - (ray->line_height / 2));
	if (ray->start_point < 0)
		ray->start_point = 0;
	ray->end_point = ((ray->line_height / 2) + (screen_height / 2));
	if (ray->end_point >= screen_height)
		ray->end_point = screen_height - 1;
}

double	calculate_perpwalldist(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		return ((ray->map_x - player->pos_x + \
		(1 - ray->step_x) / 2) / ray->raydir_x);
	else
		return ((ray->map_y - player->pos_y + \
		(1 - ray->step_y) / 2) / ray->raydir_y);
}

void	calculate_wall(t_player *player, t_ray *ray)
{
	ray->perpwalldist = calculate_perpwalldist(player, ray);
	printf("perpwalldist : %f\n", ray->perpwalldist);
	ray->line_height = (int)(screen_height / ray->perpwalldist);
	calculate_start_and_endpoint(ray);
}

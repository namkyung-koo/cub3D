/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:31:10 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/06 21:05:06 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dir(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->raydir_y > 0)
			return (0);
		else
			return (1);
	}
	else if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			return (2);
		else
			return (3);
	}
}

void	calculate_wall_x(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->perpwalldist * ray->raydir_y + data->player.pos_y;
	else
		ray->wall_x = ray->perpwalldist * ray->raydir_x + data->player.pos_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_texture_x(t_ray *ray)
{
	ray->texture_x = (int)(ray->wall_x * (double)tex_width);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->texture_x = tex_width - ray->texture_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->texture_x = tex_width - ray->texture_x - 1;
}

void	select_texture(t_data *data, t_ray *ray)
{
	ray->tex_num = check_dir(ray);
	calculate_wall_x(data, ray);
	calculate_texture_x(ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:31:10 by jisulee           #+#    #+#             */
/*   Updated: 2023/07/05 19:19:47 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_texture(t_data *data, t_ray *ray)
{
	ray->tex_num = data->map.frame[ray->map_x][ray->map_y] - 1;
	
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:07:45 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/30 17:39:06 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	main_loop(t_data *data)
{
	raycasting(data);
	draw_map(data);
}

void	ft_mlx_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &main_loop, &data);
	//mlx_hook(data->win, 2, 0, &key_press, &data);
	mlx_loop(data->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:07:45 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/30 21:17:01 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
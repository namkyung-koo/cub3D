/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:07:45 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/27 18:03:52 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	main_loop(t_info *info)
{
	raycasting(info);
	draw_map(info);
}

void	ft_mlx_loop(t_info *info)
{
	mlx_loop_hook(info->mlx, &main_loop, &info);
	//mlx_hook(info->win, 2, 0, &key_press, &info);
	mlx_loop(info->mlx);
}
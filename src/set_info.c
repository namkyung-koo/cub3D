/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:19:59 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/26 22:37:46 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_player *player)
{
	t_map	map;
	
	player->posX = 0.0;
	player->posY = 0.0;
	if (map.dir == "87")
	{
		player->dir_vectorX = -1;
		player->dir_vectorY = 0;		
	}
	if (map.dir == "83")
	{
		player->dir_vectorX = 0;
		player->dir_vectorY = -1;		
	}
	if (map.dir == "69")
	{
		player->dir_vectorX = 1;
		player->dir_vectorY = 0;		
	}
	if (map.dir == "78")
	{
		player->dir_vectorX = 0;
		player->dir_vectorY = 1;		
	}
	if (player->dir_vectorX == 0)
	{
		player->planeX = 0.66;
		player->planeY = 0.0;
	}
	else
	{
		player->planeX = 0.66;
		player->planeY = 0.0;
	}
}

void	set_texture(t_info *info)
{
	int	idx;
	
	idx = 0;
	info->texture = malloc(sizeof(int *) * 4);
	if (!info->texture)
		exit (1);
	while (idx < 4)
	{
		info->texture[idx] = malloc(sizeof (int *) * (tex_height * tex_width));
		if (!info->texture[idx])
			exit (1);
		idx++;
	}
}

void	load_image(t_info *info, t_image *image, int *texture, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	image->img = mlx_xpm_file_to_image(info->mlx, &image->img_width, &image->img_height);
	image->data = (int *)mlx_get_data_addr(image->img, &image->size, &image->bpp, &image->endian);
	while (i < image->img_height)
	{
		j = 0;
		while (j < image->img_width)
		{
			texture[image->img_width * i + j] = image->data[image->img_width * i + j];
			j++;
		}
		i++;	
	}
	mlx_destroy_image(info->mlx, image->img);
}

void	load_texture(t_info *info)
{
	t_data data;
	t_image	image;
	
	load_image(info, &image, info->texture[0], data.no_texture_path);
	load_image(info, &image, info->texture[1], data.so_texture_path);
	load_image(info, &image, info->texture[2], data.so_texture_path);
	load_image(info, &image, info->texture[3], data.we_texture_path);
}

void	set_info(t_info *info)
{
	set_player(&info->player);
	set_texture(&info);
	load_texture(&info);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:40:37 by jisulee           #+#    #+#             */
/*   Updated: 2023/06/30 21:16:58 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_texture_arr(t_data *data)
{
	int	idx;
	
	idx = 0;
	data->texture = malloc(sizeof(int *) * 4);
	if (!data->texture)
		exit (1);
	while (idx < 4)
	{
		data->texture[idx] = malloc(sizeof (int *) * (tex_height * tex_width));
		if (!data->texture[idx])
			exit (1);
		idx++;
	}
}

void	load_image(t_data *data, t_image *image, int *texture, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	image->img = mlx_xpm_file_to_image(data->mlx, &image->img_width, &image->img_height);
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
	mlx_destroy_image(data->mlx, image->img);
}

void	load_texture(t_data *data)
{
	t_data data;
	t_image	image;
	
	load_image(data, &image, data->texture[0], data.no_texture_path);
	load_image(data, &image, data->texture[1], data.so_texture_path);
	load_image(data, &image, data->texture[2], data.so_texture_path);
	load_image(data, &image, data->texture[3], data.we_texture_path);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:56:30 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/27 23:21:38 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_identified(t_data **data, char *temp)
{
	if (ft_strcmp(temp, "NO") == 0)
		(*data)->file.is_north_texture++;
	else if (ft_strcmp(temp, "SO") == 0)
		(*data)->file.is_south_texture++;
	else if (ft_strcmp(temp, "WE") == 0)
		(*data)->file.is_west_texture++;
	else if (ft_strcmp(temp, "EA") == 0)
		(*data)->file.is_east_texture++;
	else if (ft_strcmp(temp, "F") == 0)
		(*data)->file.is_floor++;
	else if (ft_strcmp(temp, "C") == 0)
		(*data)->file.is_ceiling++;
}

static int	save_texture_path(t_data **data, char **temp)
{
	char	*texture;

	if (open(temp[1], O_RDONLY) == -1)
		return (print_error("Failed to open \"texture file.\"", -1, NULL));
	while (*(temp[1]) == '.')
		temp[1]++;
	if (check_extension(temp[1], "xpm") == -1)
		return (print_error("The texture's extension must be xpm.", -1, NULL));
	texture = (char *)malloc(sizeof(char) * ft_strlen(temp[1]));
	if (texture == NULL)
		return (print_error("Failed to allocate memory.", -1, NULL));
	if ((*data)->file.is_north_texture == 1 && (!(*data)->no_texture_path))
		(*data)->no_texture_path = texture;
	else if ((*data)->file.is_south_texture == 1 && (!(*data)->so_texture_path))
		(*data)->so_texture_path = texture;
	else if ((*data)->file.is_west_texture == 1 && (!(*data)->we_texture_path))
		(*data)->we_texture_path = texture;
	else if ((*data)->file.is_east_texture == 1 && (!(*data)->ea_texture_path))
		(*data)->ea_texture_path = texture;
	return (0);
}

static int	save_rgb_color(t_data **data, char **temp)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(temp[1], ',');
	if (rgb == NULL)
		return (print_error("Failed to split a \"rgb part.\"", -1, NULL));
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		return (free_2d_array(rgb, -1));
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
		return (free_2d_array(rgb, -1));
	if ((*data)->file.is_floor == 1 && (*data)->floor_rgb == -2)
		(*data)->floor_rgb = ((r << 16) + (g << 8) + b);
	else if ((*data)->file.is_ceiling == 1 && (*data)->ceiling_rgb == -2)
		(*data)->ceiling_rgb = ((r << 16) + (g << 8) + b);
	return (free_2d_array(rgb, 0));
}

int	check_identifier(t_data **data)
{
	if ((*data)->file.is_floor == 1 && (*data)->file.is_ceiling == 1 && \
	(*data)->file.is_south_texture == 1 && \
	(*data)->file.is_west_texture == 1 && \
	(*data)->file.is_east_texture == 1 && \
	(*data)->file.is_north_texture == 1)
		return (1);
	return (0);
}

int	fill_identifier(t_data **data, char **line)
{
	char	**temp;

	temp = ft_split(*line, ' ');
	if (temp == NULL)
		return (print_error("Failed to split a line.", -1, NULL));
	if (temp[0] == NULL || temp[1] == NULL || temp[2] != NULL)
		return (free_2d_array(temp, -1));
	find_identified(data, temp[0]);
	if ((*data)->file.is_north_texture == 1 || \
	(*data)->file.is_south_texture == 1 \
	|| (*data)->file.is_east_texture == 1 || (*data)->file.is_west_texture == 1)
	{
		if (save_texture_path(data, temp) == -1)
			return (free_2d_array(temp, -1));
	}
	if ((*data)->file.is_floor == 1 || (*data)->file.is_ceiling == 1)
	{
		if (save_rgb_color(data, temp) == -1)
			return (free_2d_array(temp, -1));
	}
	if (check_identifier(data))
		(*data)->file.over_identifier = TRUE;
	// return (free_2d_array(temp, 0));
	// 동적 할당 안해서 주소값 다 잃어버린듯
	// printf("%s%s%s%s", (*data)->no_texture_path, (*data)->so_texture_path, \
	(*data)->we_texture_path, (*data)->ea_texture_path);
	return (0);
}

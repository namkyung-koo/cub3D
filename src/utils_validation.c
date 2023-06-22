/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:56:30 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/22 20:35:00 by nakoo            ###   ########.fr       */
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
	{
		perror("Failed to open texture file ");
		return (-1);
	}
	if (check_extension(temp[1], "xpm") == -1)
		return (print_error("The texture's extension must be xpm.", -1, temp));
	texture = (char *)malloc(sizeof(char) * ft_strlen(temp[1]));
	if (texture == NULL)
		return (print_error("Failed to allocate memory.", -1, temp));
	if ((*data)->file.is_north_texture == 1)
		(*data)->north_texture_path = texture;
	else if ((*data)->file.is_south_texture == 1)
		(*data)->south_texture_path = texture;
	else if ((*data)->file.is_west_texture == 1)
		(*data)->west_texture_path = texture;
	else if ((*data)->file.is_east_texture == 1)
		(*data)->east_texture_path = texture;
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
		return (print_error("Failed to split a rgb part.", -1, NULL));
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		return (print_error("Value of rgb entered wrongly.", -1, rgb));
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
		return (print_error("", -1, rgb));
	if ((*data)->file.is_floor == 1)
		(*data)->floor_rgb = ((r << 16) + (g << 8) + b);
	else if ((*data)->file.is_ceiling == 1)
		(*data)->ceiling_rgb = ((r << 16) + (g << 8) + b);
	free(rgb);
	return (0);
}

int	split_space(t_data **data, char **line)
{
	char	**temp;

	temp = ft_split(*line, ' ');
	if (temp == NULL)
		return (print_error("Failed to split a line.", -1, NULL));
	if (temp[0] == NULL || temp[1] == NULL || temp[2] != NULL)
		return (print_error("", -1, temp));
	find_identified(data, temp[0]);
	if ((*data)->file.is_north_texture == 1 || \
	(*data)->file.is_south_texture == 1 \
	|| (*data)->file.is_east_texture == 1 || (*data)->file.is_west_texture == 1)
	{
		if (save_texture_path(data, temp) == -1)
			return (-1);
	}
	else if ((*data)->file.is_floor == 1 || (*data)->file.is_ceiling == 1)
	{
		if (save_rgb_color(data, temp) == -1)
			return (print_error("", -1, temp));
	}
	else
		return (print_error("", -1, temp));
	free(temp);
	return (0);
}

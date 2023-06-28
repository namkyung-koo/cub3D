/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/28 22:24:27 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	measure_array_width(t_data *data)
{
	t_list	*temp;
	int		comp;

	temp = *(data->map.lst);
	comp = 0;
	while (temp != NULL)
	{
		comp = ft_strlen(temp->content);
		if (comp > data->map.width)
			data->map.width = comp;
		temp = temp->next;
	}
}

static void	duplicate_to_array(t_data *data)
{
	t_list	*temp;
	int		i;

	data->map.arr = (char **)malloc(sizeof(char *) \
	* (data->map.height + 1));
	if (data->map.arr == NULL)
		error_and_exit("Failed to allocate memory.");
	data->map.arr[data->map.height] = NULL;
	measure_array_width(data);
	printf("%d", data->map.width);
	i = 0;
	while (data->map.arr[i] && *(data->map.lst) != NULL)
	{
		temp = *(data->map.lst);
		data->map.arr[i] = ft_strndup(temp->content, data->map.width);
		*(data->map.lst) = temp->next;
		free(temp);
		i++;
	}
	free(data->map.lst);
}

static void	check_4_dir(int x, int y, char *ptr, t_data *data)
{
	if (*ptr == 'N')
		data->map.view_dir = NORTH;
	else if (*ptr == 'S')
		data->map.view_dir = SOUTH;
	else if (*ptr == 'W')
		data->map.view_dir = WEST;
	else if (*ptr == 'E')
		data->map.view_dir = EAST;
	if (*ptr != '0')
	{
		(data->map.player)++;
		if (data->map.player != 1)
			error_and_exit("please, check the number of player.");
		data->map.player_x = x;
		data->map.player_y = y;
	}
	if (data->map.arr[y - 1][x] == ' ' \
	|| data->map.arr[y + 1][x] == ' ' \
	|| data->map.arr[y][x - 1] == ' ' \
	|| data->map.arr[y][x + 1] == ' ')
		error_and_exit("The map must be surrounded.");
}

void	check_map_data(t_data *data)
{
	char	*ptr;
	int		x;
	int		y;

	duplicate_to_array(data);
	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			ptr = ft_strchr("01 NSWE", data->map.arr[y][x]);
			if (ptr != NULL)
			{
				if (*ptr == 'N' || *ptr == 'S' || *ptr == 'W' || *ptr == 'E' \
				|| *ptr == '0')
					check_4_dir(x, y, ptr, data);
			}
			else
				error_and_exit("please, check the component of map.");
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/29 18:37:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_height_and_width(t_data *data)
{
	t_node	*temp;
	int		max;

	temp = data->map.list->head_node.next;
	max = 0;
	while (temp != NULL)
	{
		max = ft_strlen(temp->content);
		if (max > data->map.width)
			data->map.width = max;
		temp = temp->next;
	}
	data->map.height = data->map.list->node_count;
}

static void	duplicate_to_array(t_data *data)
{
	t_node	*temp;
	t_node	*del_node;
	int		i;

	get_height_and_width(data);
	data->map.arr = (char **)malloc(sizeof(char *) * (data->map.height + 1));
	if (data->map.arr == NULL)
		error_and_exit("Failed to allocate memory.");
	data->map.arr[data->map.height] = NULL;
	i = 0;
	temp = data->map.list->head_node.next;
	while (i < data->map.height && temp != NULL)
	{
		del_node = temp;
		data->map.arr[i] = ft_strndup(temp->content, data->map.width);
		temp = temp->next;
		free(del_node->content);
		free(del_node);
		i++;
	}
	free(data->map.list);
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
	if (x - 1 < 0 || x + 1 > data->map.width || \
	y - 1 < 0 || y + 1 > data->map.height)
		return ;
	else if (data->map.arr[y - 1][x] == ' ' \
	|| data->map.arr[y + 1][x] == ' ' \
	|| data->map.arr[y][x - 1] == ' ' \
	|| data->map.arr[y][x + 1] == ' ')
		error_and_exit("The map part entered wrongly.");
}

static void	chararr_to_intarr(t_data *data)
{
	size_t	len;
	int		i;
	int		j;

	data->map.frame = (int **)malloc(sizeof(int *) * data->map.height);
	if (data->map.frame == NULL)
		error_and_exit("Failed to allocate memory.");
	i = 0;
	while (i < data->map.height)
	{
		len = ft_strlen(data->map.arr[i]);
		data->map.frame[i] = (int *)malloc(sizeof(int) * len);
		if (data->map.frame[i] == NULL)
			error_and_exit("Failed to allocate memory.");
		j = 0;
		while (j < data->map.width)
		{
			data->map.frame[i][j] = data->map.arr[i][j];
			j++;
		}
		free(data->map.arr[i]);
		i++;
	}
	free(data->map.arr);
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
	chararr_to_intarr(data);
}

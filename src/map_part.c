/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:15:52 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/27 22:46:51 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	measure_array_width(t_data **data)
{
	t_list	*temp;
	int		comp;

	temp = (*(*data)->map_info.list);
	comp = 0;
	while (temp != NULL)
	{
		comp = ft_strlen(temp->content);
		if (comp > (*data)->map_info.width)
			(*data)->map_info.width = comp;
		temp = temp->next;
	}
}

static void	duplicate_to_array(t_data **data)
{
	t_list	*temp;
	int		i;

	(*data)->map_info.array = (char **)malloc(sizeof(char *) \
	* ((*data)->map_info.height + 1));
	if ((*data)->map_info.array == NULL)
		error_and_exit("Failed to allocate memory.");
	(*data)->map_info.array[(*data)->map_info.height] = NULL;
	measure_array_width(data);
	i = 0;
	while ((!(*data)->map_info.array[i]) && !(*(*data)->map_info.list))
	{
		(*data)->map_info.array[i] = \
		ft_strndup((*(*data)->map_info.list)->content, (*data)->map_info.width);
		temp = (*(*data)->map_info.list);
		(*(*data)->map_info.list) = (*(*data)->map_info.list)->next;
		free(temp);
		i++;
	}
	free((*data)->map_info.list);
}

static void	check_4_dir(int x, int y, char *ptr, t_data **data)
{
	if (*ptr == 'N')
		(*data)->map_info.view_dir = NORTH;
	else if (*ptr == 'S')
		(*data)->map_info.view_dir = SOUTH;
	else if (*ptr == 'W')
		(*data)->map_info.view_dir = WEST;
	else if (*ptr == 'E')
		(*data)->map_info.view_dir = EAST;
	if (*ptr != '0')
	{
		((*data)->map_info.player)++;
		if ((*data)->map_info.player != 1)
			error_and_exit("please, check the number of player.");
		(*data)->map_info.player_x = x;
		(*data)->map_info.player_y = y;
	}
	if ((*data)->map_info.map[y - 1][x] == ' ' \
	|| (*data)->map_info.map[y + 1][x] == ' ' \
	|| (*data)->map_info.map[y][x - 1] == ' ' \
	|| (*data)->map_info.map[y][x + 1] == ' ')
		error_and_exit("The map must be surrounded.");
}

void	check_map_data(t_data **data)
{
	char	*ptr;
	int		x;
	int		y;

	duplicate_to_array(data);
	y = -1;
	while (++y < (*data)->map_info.height)
	{
		x = -1;
		while (++x < (*data)->map_info.width)
		{
			ptr = ft_strchr("01 NSWE", (*data)->map_info.array[y][x]);
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

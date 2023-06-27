/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:39 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/27 21:48:21 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_part(t_data **data, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '1')
		{
			(*data)->file.is_map = TRUE;
			return (1);
		}
		else if (line[i] == ' ')
			i++;
		else
			error_and_exit("File contents are invalid.");
	}
	return (0);
}

static void	save_line_to_list(t_data **data, char *line)
{
	t_list	*new;

	if ((*data)->map_info.height == 0)
	{
		((*data)->map_info.list) = (t_list **)malloc(sizeof(t_list *));
		if ((*data)->map_info.list == NULL)
			error_and_exit("Failed to allocate memory.");
	}
	new = ft_lstnew(line);
	if (new == NULL)
		error_and_exit("Failed to allocate memory.");
	ft_lstadd_back((*data)->map_info.list, new);
	(*data)->map_info.height++;
}

int	fill_map(t_data **data, char **line)
{
	if ((*data)->file.over_identifier && !(*data)->file.is_map)
	{
		if (is_map_part(data, *line) == 0)
			return (0);
	}
	if ((*data)->file.over_identifier && (*data)->file.is_map)
		save_line_to_list(data, *line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:39 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/27 17:31:32 by nakoo            ###   ########.fr       */
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
			(*data)->is_map = TRUE;
			return (1);
		}
		else if (line[i] == ' ')
			i++;
		else
			exit(1);
	}
	return (0);
}

int	fill_map(t_data **data, char **line)
{
	if ((*data)->over_identifier && !(*data)->is_map)
	{
		if (is_map_part(data, *line) == 0)
			return (0);
	}
	if ((*data)->over_identifier && (*data)->is_map)
		
	return (0);
}

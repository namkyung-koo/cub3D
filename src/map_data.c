/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:39 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/23 14:15:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_identifier(t_data **data)
{
	if ((*data)->file.is_floor != 1 && (*data)->file.is_ceiling != 1 && \
	(*data)->file.is_south_texture != 1 && \
	(*data)->file.is_west_texture != 1 && \
	(*data)->file.is_east_texture != 1 && \
	(*data)->file.is_north_texture != 1)
		return (1);
	return (0);
}

static int	check_character(t_data **data, char **line)
{
	return (0);
}

int	fill_map(t_data **data, char **line)
{
	if (check_identifier(data))
		return (-1);
	// ' 01NSWE'가 중복되거나 이상한 게 들어온다면 error => dir이 없거나 중복x
	// NSWE가 하나만 있는지 확인
	// 맵이 벽으로 둘러 싸여있는지 확인
	// width와 height 넘겨주기 ?
	// (*data)->map_info.map에 동적 할당해서 넘겨주기
	// char ** or list
	if ((*data)->file.is_map == FALSE)
		(*data)->file.is_map = TRUE;
	return (0);
}

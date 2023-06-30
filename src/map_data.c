/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:08:39 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/26 22:47:55 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_character(t_data **data, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		temp = ft_strchr(" 01NSWE", (*line)[i]);
		if (temp == NULL)
			free_all("There are invalid characters.", -1, data);
		else
			continue ;
		i++;
	}
	(*data)->map_info.height++;
	return (0);
}

int	fill_map(t_data **data, char **line)
{
	if (check_identifier(data) == 0 || \
	((*data)->file.is_map == TRUE && (**line) == '\n'))
		return (free_all("", -1, data));
	// 맵 파트는 지정자 파트 뒤에 와야함 => check_identifier
	// 맵 중간에 '\n'이 오면 에러 => fill_map
	// ' 01NWSE'를 제외한 이상한 캐릭터가 들어오면 안된다 => check_character
	// NSWE가 하나만 있는지 확인 => 없거나 중복은 에러
	// 맵이 벽으로 둘러 싸여있는지 확인
	// int **map 배열로 넘겨주기(ascii code)
	// over_identifier == FALSE면 , skip_space => OK && 개행 => OK
	// over_identifier == TRUE면 , skip_space => NO && 개행 => OK 
	// over_identifier == TRUE && is_map == TRUE면, skip_space => NO && 개행 => NO 
	return (0);
}

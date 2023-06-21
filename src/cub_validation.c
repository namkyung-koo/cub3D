/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/21 17:31:27 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_identifier(t_data **data, char *line)
{
	if ((*data)->file.is_map == 1)
		return (-1);
	// 텍스쳐 파일 경로, 텍스쳐 파일 확장자 .xpm인지 확인
	// RGB값 256보다 작은지 확인
	return (0);
}

static int	check_map(t_data **data, char *line)
{
	// 맵 관련 데이터 추출
	return (0);
}

static t_data	*read_cub_file(int fd, t_data *data)
{
	char	*line;

	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (find_identifier(&data, line) == -1)
			return (free_and_msg(&line, "Type identifier entered wrongly."));
		if (data->file.is_floor == 1 && data->file.is_ceiling == 1 && \
		data->file.is_south_texture == 1 && data->file.is_west_texture == 1 && \
		data->file.is_east_texture == 1 && data->file.is_north_texture == 1)
		{
			if (check_map(&data, line) == -1)
				return (free_and_msg(&line, "Map entered wrongly."));
		}
		free(line);
	}
	return (data);
}

int	open_cub_file(const char *cub_file, t_data *data)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		perror("Failed to open cub file ");
	else
	{
		data = read_cub_file(fd, data);
		fd = close(fd);
		if (fd == -1)
			perror("Failed to close file ");
	}
	return (fd);
}

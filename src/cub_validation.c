/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/20 19:08:02 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_cub_file(int fd, char **buff)
{
	int	bytes;

	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buff == NULL)
	{
		perror("Failed to allocate memory ");
		return (-1);
	}
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, *buff, BUFFER_SIZE);
		if (bytes == -1 || *(buff[0]) == '\0')
		{
			perror("Failed to read file ");
			free_and_null(buff, -1);
		}
		*(buff[bytes]) = '\0';
	}
	return (0);
}

static int	check_element(t_element **element, char *buff)
{
	(*element)->north_texture = ft_strnstr(buff, "NO", 2);
	(*element)->south_texture = ft_strnstr(buff, "SO", 2);
	(*element)->west_texture = ft_strnstr(buff, "WE", 2);
	(*element)->east_texture = ft_strnstr(buff, "EA", 2);
	(*element)->floor = ft_strnstr(buff, "F", 1);
	(*element)->ceiling = ft_strnstr(buff, "C", 1);
	if ((!(*element)->north_texture) || (!(*element)->south_texture) || \
	(!(*element)->west_texture) || (!(*element)->east_texture) || \
	(!(*element)->floor) || (!(*element)->ceiling))
		return (print_error("Type specifier entered incorrectly.", -1));
	// ft_strnstr에서 예상치 못한 에러가 발생할수도 있음
	if (new_line_to_null((*element)->north_texture) || \
	new_line_to_null((*element)->south_texture) || \
	new_line_to_null((*element)->west_texture) || \
	new_line_to_null((*element)->east_texture) || \
	new_line_to_null((*element)->floor) || \
	new_line_to_null((*element)->ceiling))
		return (print_error("Map entered incorrectly.", -1));
	// 텍스쳐 파일 경로, 텍스쳐 파일 확장자 .xpm인지 확인
	// RGB값 256보다 작은지 확인
	return (0);
}

static int	check_map(t_element **element, char *buff)
{
	// 맵 관련 데이터 추출
	return (0);
}

int	open_cub_file(const char *cub_file, t_element *element)
{
	char		*buff;
	int			fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		perror("Failed to open cub file ");
	else
	{
		if (read_cub_file(fd, &buff) == -1)
			return (free_and_null(&buff, -1));
		if (check_element(&element, buff) == -1 || \
			check_map(&element, buff) == -1)
			return (free_and_null(&buff, -1));
		free(buff);
		fd = close(fd);
		if (fd == -1)
			perror("Failed to close file ");
	}
	return (fd);
}

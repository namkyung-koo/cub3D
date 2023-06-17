/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/17 12:45:21 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_cub_file(int fd, char **buff)
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

int	check_element(t_element **element, char *buff)
{
	// 엘리멘트 관련 데이터 추출
	return (0);
}

int	check_map(t_element **element, char *buff)
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

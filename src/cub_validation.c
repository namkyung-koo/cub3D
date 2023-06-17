/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/17 11:47:14 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_element(int fd, t_element *element)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
	{
		perror("Failed to allocate memory ");
		return (-1);
	}
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || buff[0] == '\0')
			break ;
	}
	return (0);
}

int	check_map(void)
{
	return (0);
}

int	open_cub_file(const char *cub_file)
{
	t_element	element;
	int			fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		perror("Failed to open cub file ");
	else
	{
		if (check_element(fd, &element) == -1)
			return (-1);
		if (check_map() == -1)
			return (-1);
		fd = close(fd);
		if (fd == -1)
			perror("Failed to close file ");
	}
	return (fd);
}

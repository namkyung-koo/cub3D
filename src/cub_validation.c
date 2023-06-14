/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/14 18:55:20 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_element(int fd, t_element *element)
{
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
		check_element(fd, &element);
		check_map();
		fd = close(fd);
		if (fd == -1)
			perror("Failed to close file ");
	}
	return (fd);
}

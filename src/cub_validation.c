/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/22 20:33:51 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_validation(t_data **data, char **line, int part)
{
	if (part == ELEMENT && (*data)->file.is_map != 0)
		return (-1);
	if (split_space(data, line) == -1)
		return (-1);
	return (0);
}

static int	manipulate_line(t_data **data, char **line)
{
	skip_space(line);
	if (ft_strncmp(*line, "NO ", 3) == 0 || ft_strncmp(*line, "SO ", 3) == 0 || \
	ft_strncmp(*line, "WE ", 3) == 0 || ft_strncmp(*line, "EA ", 3) == 0 || \
	ft_strncmp(*line, "F ", 2) == 0 || ft_strncmp(*line, "C ", 2) == 0)
	{
		if (check_validation(data, line, ELEMENT) == -1)
			return (-1);
	}
	else
		check_validation(data, line, MAP); // map part
	return (0);
}

// static int	check_map(t_data **data, char *line)
// {
// 	return (0);
// }

static int	read_cub_file(int fd, t_data **data)
{
	char	*line;

	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = newline_to_null(line);
		if (manipulate_line(data, &line) == -1)
			return (print_error("Type identifier entered wrongly.", -1, &line));
		if ((*data)->file.is_floor == 1 && (*data)->file.is_ceiling == 1 && \
		(*data)->file.is_south_texture == 1 && \
		(*data)->file.is_west_texture == 1 && \
		(*data)->file.is_east_texture == 1 && \
		(*data)->file.is_north_texture == 1)
		{
			// if (check_map(data, line) == -1)
			// 	return (print_error("Map entered wrongly.", -1, &line));
		}
		free(line);
	}
	return (0);
}

int	open_cub_file(const char *cub_file, t_data *data)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		perror("Failed to open cub file ");
	else
	{
		ft_memset(data, 0, sizeof(t_data));
		read_cub_file(fd, &data);
		fd = close(fd);
		if (fd == -1)
			perror("Failed to close file ");
	}
	return (fd);
}

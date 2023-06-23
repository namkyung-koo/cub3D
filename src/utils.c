/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:51:31 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/23 17:18:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *msg, int return_value, char **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (return_value);
}

int	free_all(char *msg, int return_value, t_data **data)
{
	if ((*data)->no_texture_path != NULL)
		free((*data)->no_texture_path);
	if ((*data)->so_texture_path != NULL)
		free((*data)->so_texture_path);
	if ((*data)->we_texture_path != NULL)
		free((*data)->we_texture_path);
	if ((*data)->ea_texture_path != NULL)
		free((*data)->ea_texture_path);
	if ((*data)->map_info.prototype != NULL)
		free((*data)->map_info.prototype);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (return_value);
}

int	check_extension(char *av, const char *extension)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '.')
		{
			flag = 1;
			break ;
		}
		else if (ft_isprint(av[i]) == 0)
			return (-1);
		i++;
	}
	if (flag == 0)
		return (-1);
	else
	{
		++i;
		if (ft_strcmp(&av[i], extension) != 0)
			return (-1);
	}
	return (0);
}

char	*newline_to_null(char *line)
{
	int	i;

	i = 0;
	while (*(line + i) != '\n' || (*line + i) != '\0')
		i++;
	if (*(line + i) == '\n')
		*(line + i) = '\0';
	return (line);
}

void	skip_space(char **line)
{
	while ((**line) == ' ')
		(*line)++;
}

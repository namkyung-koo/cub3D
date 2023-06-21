/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:56:30 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/21 16:22:13 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_address(t_data **data, char *line)
{
	int	i;

	i = 0;
	while (*line + i != '\0')
	{
		if (*line + i == ' ')
			i++;
	}
	return (0);
}

int	check_path_and_extension(char *ptr)
{
	return (0);
}

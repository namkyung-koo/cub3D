/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:56:30 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/20 19:10:24 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_line_to_null(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
			break ;
		i++;
	}
	if (ptr[i] == '\n')
	{
		ptr[i] = '\0';
		return (0);
	}
	return (1);
}

int	check_path_and_extension(char *ptr)
{
	return (0);
}

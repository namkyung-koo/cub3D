/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:51:31 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/14 17:27:30 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (1);
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
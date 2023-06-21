/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:50 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/21 15:36:11 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error("The number of argument must be one.", 1));
	if (check_extension(av[1], "cub") == -1)
		return (print_error("The argument's extension must be cub.", 1));
	if (open_cub_file(av[1], &data) == -1)
		return (1);
	return (0);
}

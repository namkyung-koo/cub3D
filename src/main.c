/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:50 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/28 18:01:56 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	leaks(void)
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_data	data;

	// atexit(leaks);
	if (ac != 2)
		return (print_error("The number of argument must be one.", 1, NULL));
	if (check_extension(av[1], "cub") == -1)
		return (print_error("The argument's extension must be cub.", 1, NULL));
	if (open_cub_file(av[1], &data) == -1)
		return (1);
	return (0);
}

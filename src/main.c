/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:50 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/14 17:28:52 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error("The number of argument must be one."));
	if (check_extension(av[1], "cub") == -1)
		return (print_error("The argument's extension must be cub."));
	if (open_cub_file(av[1]) == -1)
		return (1);
	// 레이 캐스팅
	// mlx hook
	// mlx loop
	return (0);
}

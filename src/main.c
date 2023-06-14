/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:50 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/14 15:45:18 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error("The number of argument must be one."));
	if (check_extension(av[1]) == -1)
		return (print_error("The argument's extension must be cub."));
	// .cub 파일 체크(open, read)

	// 레이 캐스팅
	// mlx hook ?
	return (0);
}

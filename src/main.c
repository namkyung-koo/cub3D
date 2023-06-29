/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:55:50 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/29 17:41:55 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	free_heap_section(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	free(data->no_texture_path);
// 	free(data->so_texture_path);
// 	free(data->we_texture_path);
// 	free(data->ea_texture_path);
// 	while (i < data->map.height)
// 	{
// 		free(data->map.frame[i]);
// 		i++;
// 	}
// 	free(data->map.frame);
// }

// void	leaks(void)
// {
// 	system("leaks cub3D");
// }

static void	display_data(t_data *data)
{
	// identifier part
	printf("north texture : %s\n", data->no_texture_path);
	printf("south texture : %s\n", data->so_texture_path);
	printf("west texture : %s\n", data->we_texture_path);
	printf("east texture : %s\n", data->ea_texture_path);
	printf("rgb of floor : %d\n", data->floor_rgb);
	printf("rgb of ceiling : %d\n", data->ceiling_rgb);
	// map part
	printf("플레이어 수 : %d\n", data->map.player);
	printf("x좌표 : %d(인덱스)\ny좌표 : %d(인덱스)\n", data->map.player_x, data->map.player_y);
	printf("view_dir : %d width : %d height : %d\n", data->map.view_dir, data->map.width, data->map.height);
	printf("\n<----------MAP---------->\n");
	for (int i = 0; i < data->map.height; i++)
	{
		for (int j = 0; j < data->map.width; j++)
			printf("%c", data->map.frame[i][j]);
		printf(".\n");
	}
}

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
	display_data(&data);
	// free_heap_section(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/21 17:23:03 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_file {
	int		is_north_texture;
	int		is_south_texture;
	int		is_west_texture;
	int		is_east_texture;
	int		is_floor;
	int		is_ceiling;
	int		is_map;
}	t_file;

typedef struct s_map {
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_data {
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int		floor_rgb;
	int		ceiling_rgb;
	t_map	map_info;
	t_file	file;
}	t_data;

// utils.c
int		print_error(char *msg, int return_value);
int		check_extension(char *av, const char *extension);
char	*free_and_msg(char **ptr, char *msg);

// cub_validation.c
int		open_cub_file(const char *cub_file, t_data *data);

// utils_validtion.c
int		find_address(t_data **data, char *line);
int		check_path_and_extension(char *ptr);
#endif
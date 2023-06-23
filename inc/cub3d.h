/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/23 14:40:03 by nakoo            ###   ########.fr       */
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
	int		dir;
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_data {
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	int		floor_rgb;
	int		ceiling_rgb;
	t_map	map_info;
	t_file	file;
}	t_data;

enum e_direction {
	NORTH,
	SOUTH,
	WEST,
	EAST
};

enum e_bool {
	FALSE,
	TRUE
};

// utils.c
int		print_error(char *msg, int return_value, char **ptr);
int		check_extension(char *av, const char *extension);
void	skip_space(char **line);
char	*newline_to_null(char *line);

// cub_validation.c
int		open_cub_file(const char *cub_file, t_data *data);

// identifier_data.c
int		fill_identifier(t_data **data, char **line);

// map_data.c
int		fill_map(t_data **data, char **line);

#endif
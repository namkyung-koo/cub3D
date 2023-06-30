/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/30 17:16:48 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_file {
	int		is_north_texture;
	int		is_south_texture;
	int		is_west_texture;
	int		is_east_texture;
	int		is_floor;
	int		is_ceiling;
	int		over_identifier;
	int		is_map;
}	t_flag;

typedef struct s_map {
	int		player;
	int		player_x;
	int		player_y;
	int		view_dir;
	int		width;
	int		height;
	int		**frame;
	char	**arr;
	t_list	*list;
}	t_map;

typedef struct s_data {
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	int		floor_rgb;
	int		ceiling_rgb;
	t_map	map;
	t_flag	flag;
}	t_data;

enum e_direction {
	NORTH = 78,
	SOUTH = 83,
	WEST = 87,
	EAST = 69
};

enum e_texture {
	tex_height = 64,
	tex_width = 64
};

enum e_screen {
	screenWidth = 640,
	screenHeight = 480
};

enum e_bool {
	FALSE,
	TRUE
};

// utils.c
int		free_2d_array(char **ptr, int return_value);
int		check_extension(char *str, const char *extension);
int		print_error(char *msg, int return_value, char *ptr);
void	error_and_exit(char *msg);
void	newline_to_null(char *line);

// file_validation.c
int		open_cub_file(const char *cub_file, t_data *data);

// identifier_part.c
int		check_identifier(t_data *data);
int		fill_identifier(t_data *data, char *line);

// middle_part.c
int		fill_map(t_data *data, char *line);

// map_part.c
void	check_map_data(t_data *data);

// set_value_utils.c
void	skip_space(char **line);
void	init_t_data(t_data *data);
void	get_height_and_width(t_data *data);
void	duplicate_to_array(t_data *data);
void	chararr_to_intarr(t_data *data);

void	set_info(t_info *info, t_data *data);

void	load_texture(t_info *info);
void	make_texture_arr(t_info *info);

void	calculate_wall(t_player *player, t_ray *ray);

void	ft_mlx_loop(t_info *info);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/30 17:04:04 by jisulee          ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef struct s_texture{
	int	tex_num;
	
}	t_texture;


typedef struct s_ray{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		start_point;
	int		end_point;
	int		tex_num;
}	t_ray;

typedef struct s_image{
	void	*img;
	int		*data;
	int		img_width;
	int		img_height;
	int		size;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_info {
	void		*mlx;
	void		*win;
	t_player	player;
	t_image		screen_img;
	t_ray		ray;
	int			**texture;
}	t_info;

typedef struct s_file {
	int		is_north_texture;
	int		is_south_texture;
	int		is_west_texture;
	int		is_east_texture;
	int		is_floor;
	int		is_ceiling;
	int		over_identifier;
	int		is_map;
}	t_file;

typedef struct s_map {
	int		character_x;
	int		character_y;
	int		view_dir;
	int		width;
	int		height;
	int		**map;
	char	**prototype;
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
int		check_extension(char *av, const char *extension);
int		print_error(char *msg, int return_value, char **ptr);
void	skip_space(char **line);
char	*newline_to_null(char *line);

// cub_validation.c
int		open_cub_file(const char *cub_file, t_data *data);

// identifier_data.c
int		check_identifier(t_data **data);
int		fill_identifier(t_data **data, char **line);

// map_data.c
int		fill_map(t_data **data, char **line);

void	set_info(t_info *info, t_data *data);

void	load_texture(t_info *info);
void	make_texture_arr(t_info *info);

void	calculate_wall(t_player *player, t_ray *ray);

void	ft_mlx_loop(t_info *info);

#endif
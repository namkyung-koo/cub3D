/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/26 22:43:34 by jisulee          ###   ########.fr       */
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
	double	posX;
	double	posY;
	double	dir_vectorX;
	double	dir_vectorY;
	double	planeX;
	double	planeY;
	
}	t_player;

typedef struct s_info {
	void		*mlx;
	void		*win;
	t_player	player;
	t_image		screen_img;
	int			**texture;
	
	
}	t_info;

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
int		check_extension(char *av, const char *extension);
int		print_error(char *msg, int return_value, char **ptr);
int		free_all(char *msg, int return_value, t_data **data);
void	skip_space(char **line);
char	*newline_to_null(char *line);

// cub_validation.c
int		open_cub_file(const char *cub_file, t_data *data);

// identifier_data.c
int		check_identifier(t_data **data);
int		fill_identifier(t_data **data, char **line);

// map_data.c
int		fill_map(t_data **data, char **line);

#endif
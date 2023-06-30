/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:18:29 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/30 20:19:52 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

#include "../libft/libft.h"

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
	void		*mlx;
	void		*win;
	char		*no_texture_path;
	char		*so_texture_path;
	char		*we_texture_path;
	char		*ea_texture_path;
	int			floor_rgb;
	int			ceiling_rgb;
	t_map		map;
	t_flag		flag;
	t_player	player;
	t_image		screen_img;
	t_ray		ray;
	int			**texture;
}	t_data;

#endif
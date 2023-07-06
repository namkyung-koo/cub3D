/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/07/06 21:47:12 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "enum.h"
# include "structure.h"
# include "../libft/libft.h"

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

void	set_data(t_data *data);

void	load_texture(t_data *data);
void	make_texture_arr(t_data *data);

void	calculate_wall(t_player *player, t_ray *ray);

void	ft_mlx_loop(t_data *data);

void	make_buffer(t_data *data, t_ray * ray, int screen_x);
void	draw_floor_ceiling(t_data *data);

#endif
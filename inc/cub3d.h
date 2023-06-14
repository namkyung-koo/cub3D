/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/14 17:28:19 by nakoo            ###   ########.fr       */
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

// typedef struct s_element {
// 	char	*north_texture;
// 	char	*south_texture;
// 	char	*west_texture;
// 	char	*east_texture;
// 	int		floor_r;
// 	int		floor_g;
// 	int		floor_b;
// 	int		ceiling_r;
// 	int		ceiling_g;
// 	int		ceiling_b;
// 	t_map	map;
// }	t_element;

// typedef struct s_map {
// 	char	dir;
// 	int		width;
// 	int		height;
// }	t_map;

// utils.c
int	print_error(char *msg);
int	check_extension(char *av, const char *extension);

#endif
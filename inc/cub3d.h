/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:56:19 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/20 19:09:58 by nakoo            ###   ########.fr       */
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

typedef struct s_element {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor;
	char	*ceiling;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	char	**map;
}	t_element;

// utils.c
int	print_error(char *msg, int return_value);
int	free_and_null(char **ptr, int return_value);
int	check_extension(char *av, const char *extension);

// cub_validation.c
int	open_cub_file(const char *cub_file, t_element *element);

// utils_validtion.c
int	new_line_to_null(char *ptr);
int	check_path_and_extension(char *ptr);
#endif
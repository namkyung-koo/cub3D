/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:23 by nakoo             #+#    #+#             */
/*   Updated: 2023/07/05 15:19:33 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

enum e_keycode {
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
};

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

#endif
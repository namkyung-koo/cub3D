/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:23 by nakoo             #+#    #+#             */
/*   Updated: 2023/07/07 21:50:37 by nakoo            ###   ########.fr       */
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
	screen_width = 640,
	screen_height = 480
};

enum e_bool {
	FALSE,
	TRUE
};

#endif
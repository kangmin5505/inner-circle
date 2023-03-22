/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:48:47 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 13:54:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* fractal name */
# define MANDELBROT				"mandelbrot"
# define JULIA					"julia"
# define BURNINGSHIP			"burningship"

/* etc */
# define SUCCESS				0
# define FAILURE				-1
/* fast version(small window) */
# define WIDTH					640
# define HEIGHT					360
/* slow version(big window) */
/*
# define WIDTH					1280
# define HEIGHT					720
*/
# define ITERATION_MAX			100

/* fractal */
# define MANDELBROT_CENTER_X	-0.5
# define MANDELBROT_CENTER_Y	0
# define JULIA_CENTER_X			0
# define JULIA_CENTER_Y			0
# define JULIA_CONST_X			-0.1875
# define JULIA_CONST_Y			-1.0944
# define BURNINGSHIP_CENTER_X	-0.5
# define BURNINGSHIP_CENTER_Y	-0.5

/* color */
# define OUT_R					0
# define OUT_G					0
# define OUT_B					120
# define IN_R					255
# define IN_G					255
# define IN_B					255
# define GRADATION				8

/* mlx_hook event, mask */
# define KEY_PRESS_EVENT		2
# define MOUSE_PRESS_EVENT		4
# define MOUSE_MOVE_EVENT		6

/* key, button */
# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126
# define MOUSE_LEFT_BUTTON		1
# define SCROLL_UP				4
# define SCROLL_DOWN			5
# define ZOOM_RATE				1.2
# define NUMPAD_2				84
# define NUMPAD_4				86
# define NUMPAD_6				88
# define NUMPAD_8				91

#endif

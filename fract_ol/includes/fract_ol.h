/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 14:41:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <math.h>

# include "mlx.h"
# include "constants.h"

typedef struct s_data	t_data;
typedef struct s_img	t_img;
typedef struct s_point	t_point;
typedef struct s_color	t_color;

struct	s_color
{
	int		color_arr[6];
	int		curr_idx;
};

struct	s_point
{
	double	x;
	double	y;
};

struct	s_img
{
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	fractal_name[12];
	void	(*init_fractal_func)(t_data *);
	int		(*fractal_func)(t_data *, int, int, int);
	double	ratio;
	t_point	center;
	t_point	plane_len;
	t_point	julia_const;
	int		julia_motion;
	t_point	mouse;
	t_color	color;
};

/* main.c */
int		main(int argc, char *argv[]);
int		parse_input(int argc, char *argv[], t_data *data);
void	start_fractal(t_data *data);

/* start_fractal_sub.c */
void	init_fractal(t_data *data);
void	exit_if_null(void *ptr);
void	draw_fractal(t_data *data);
void	put_color_pixel(t_img *img, int x, int y, int color);

/* color.c */
void	init_color(t_data *data);
int		set_color(int *color, int iteration);
void	info_color(t_data *data, int curr_idx);
void	change_rgb_ptr(int keycode, t_data *data);
void	change_rgb_value(int keycode, t_data *data);

/* control_mlx_hook.c */
int		keyboard_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		mouse_motion_hook(int x, int y, t_data *data);
void	move_center(t_data *data, int keycode);
void	destroy_data(t_data *data);

/* mandelbrot.c */
void	init_mandelbrot(t_data *data);
int		mandelbrot(t_data *data, int w, int h, int iteration);

/* julia.c */
void	init_julia(t_data *data);
int		julia(t_data *data, int w, int h, int iteration);

/* burningship.c */
void	init_burningship(t_data *data);
int		burningship(t_data *data, int w, int h, int iteration);

/* libft.c */
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif

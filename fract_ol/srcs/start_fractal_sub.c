/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractal_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:32:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 10:08:19 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_fractal(t_data *data)
{
	if (ft_strcmp(data->fractal_name, MANDELBROT) == 0)
		data->init_fractal_func = init_mandelbrot;
	else if (ft_strcmp(data->fractal_name, JULIA) == 0)
		data->init_fractal_func = init_julia;
	else if (ft_strcmp(data->fractal_name, BURNINGSHIP) == 0)
		data->init_fractal_func = init_burningship;
	data->init_fractal_func(data);
}

void	exit_if_null(void *ptr)
{
	if (ptr != NULL)
		return ;
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	draw_fractal(t_data *data)
{
	int	w;
	int	h;
	int	iteration;

	w = -1;
	while (++w < WIDTH)
	{
		h = -1;
		while (++h < HEIGHT)
		{
			iteration = data->fractal_func(data, w, h, 0);
			if (iteration < ITERATION_MAX)
				put_color_pixel(&data->img, w, h, \
								set_color(data->color.color_arr, iteration));
			else
				put_color_pixel(&data->img, w, h, 0x00000000);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, \
							0, 0);
}

void	put_color_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr_ptr + (y * img->size_line + \
							x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

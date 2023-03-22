/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:48:01 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 14:47:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_julia(t_data *data)
{
	data->fractal_func = julia;
	data->center.x = JULIA_CENTER_X;
	data->center.y = JULIA_CENTER_Y;
	data->ratio = WIDTH / 8;
	data->plane_len.x = WIDTH / data->ratio;
	data->plane_len.y = HEIGHT / data->ratio;
	data->julia_const.x = JULIA_CONST_X;
	data->julia_const.y = JULIA_CONST_Y;
	data->julia_motion = -1;
	init_color(data);
}

int	julia(t_data *data, int w, int h, int iteration)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp_z_x;

	z_x = data->center.x + (w / data->ratio) - (data->plane_len.x / 2);
	z_y = data->center.y + (data->plane_len.y / 2) - (h / data->ratio);
	c_re = data->julia_const.x;
	c_im = data->julia_const.y;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) < 4) && (iteration < ITERATION_MAX))
	{
		temp_z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * z_x * z_y + c_im;
		z_x = temp_z_x;
		iteration++;
	}
	return (iteration);
}

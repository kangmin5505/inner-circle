/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:03:28 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 15:08:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_burningship(t_data *data)
{
	data->fractal_func = burningship;
	data->center.x = BURNINGSHIP_CENTER_X;
	data->center.y = BURNINGSHIP_CENTER_Y;
	data->ratio = WIDTH / 4;
	data->plane_len.x = WIDTH / data->ratio;
	data->plane_len.y = HEIGHT / data->ratio;
	init_color(data);
}

int	burningship(t_data *data, int w, int h, int iteration)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp_z_x;

	z_x = 0;
	z_y = 0;
	c_re = data->center.x + (w / data->ratio) - (data->plane_len.x / 2);
	c_im = data->center.y + (data->plane_len.y / 2) - (h / data->ratio);
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) < 4) && (iteration < ITERATION_MAX))
	{
		temp_z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * fabs(z_x * z_y) + c_im;
		z_x = temp_z_x;
		iteration++;
	}
	return (iteration);
}

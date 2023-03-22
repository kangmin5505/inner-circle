/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:26:21 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:26:22 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setting.h"
#include "structure.h"

void	setting_default(t_data *data)
{
	t_setting	*myset;

	myset = malloc(sizeof(t_setting));
	if (myset == 0)
		exit(1);
	myset->row_resolution_render = 1;
	myset->render_resolution_x = \
		data->window.resolution_x / myset->row_resolution_render;
	myset->render_resolution_y = \
		data->window.resolution_y / myset->row_resolution_render;
	myset->use_dot_light_rgb = 0;
	myset->use_dot_light_specular = 1;
	myset->use_dot_light_diffuse = 1;
	myset->use_ambient = 1;
	myset->use_dist_lose = 0;
	myset->switch_phong_path = 0;
	myset->ignore_complict_distance = 0.001;
	myset->dot_light_diffuse_ratio = 0.4;
	myset->dot_light_specular_ratio = 0.4;
	myset->ambient_ratio = 0.2;
	myset->use_dist_show = 0;
	myset->use_normal_show = 0;
	myset->bump_ratio = 2;
	data->setting = myset;
}

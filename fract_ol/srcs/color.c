/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:17 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 15:11:08 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_color(t_data *data)
{
	data->color.color_arr[0] = OUT_R;
	data->color.color_arr[1] = OUT_G;
	data->color.color_arr[2] = OUT_B;
	data->color.color_arr[3] = IN_R;
	data->color.color_arr[4] = IN_G;
	data->color.color_arr[5] = IN_B;
	data->color.curr_idx = 0;
	printf("[Color change] - Numpad_4(left) Numpad_6(right)\n");
	printf("[Value change] - Numpad_2(minus) Numpad_8(plus)\n");
	info_color(data, data->color.curr_idx);
}

int	set_color(int *color_arr, int iteration)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color_arr[0] - (color_arr[0] / GRADATION * \
				fmod(iteration, GRADATION))) + \
				(int)(color_arr[3] / GRADATION * fmod(iteration, GRADATION));
	g = (int)(color_arr[1] - (color_arr[1] / GRADATION * \
				fmod(iteration, GRADATION))) + \
				(int)(color_arr[4] / GRADATION * fmod(iteration, GRADATION));
	b = (int)(color_arr[2] - (color_arr[2] / GRADATION * \
				fmod(iteration, GRADATION))) + \
				(int)(color_arr[5] / GRADATION * fmod(iteration, GRADATION));
	return (r << 16 | g << 8 | b);
}

void	info_color(t_data *data, int curr_idx)
{
	if (curr_idx == 0)
		printf("Select RGB : [\e[1;31mR\e[0m G B R G B]");
	else if (curr_idx == 1)
		printf("Select RGB : [R \e[1;32mG\e[0m B R G B]");
	else if (curr_idx == 2)
		printf("Select RGB : [R G \e[1;35mB\e[0m R G B]");
	else if (curr_idx == 3)
		printf("Select RGB : [R G B \e[1;31mR\e[0m G B]");
	else if (curr_idx == 4)
		printf("Select RGB : [R G B R \e[1;32mG\e[0m B]");
	else
		printf("Select RGB : [R G B R G \e[1;35mB\e[0m]");
	printf(" =>  %d\n", data->color.color_arr[curr_idx]);
}

void	change_rgb_ptr(int keycode, t_data *data)
{
	if (keycode == NUMPAD_4 && data->color.curr_idx > 0)
		data->color.curr_idx--;
	else if (keycode == NUMPAD_6 && data->color.curr_idx < 5)
		data->color.curr_idx++;
	info_color(data, data->color.curr_idx);
}

void	change_rgb_value(int keycode, t_data *data)
{
	int	curr_idx;

	curr_idx = data->color.curr_idx;
	if (keycode == NUMPAD_2 && data->color.color_arr[curr_idx] > 0)
		data->color.color_arr[curr_idx] -= 15;
	else if (keycode == NUMPAD_8 && data->color.color_arr[curr_idx] < 255)
		data->color.color_arr[curr_idx] += 15;
	info_color(data, data->color.curr_idx);
}

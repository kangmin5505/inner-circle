/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:21:51 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/14 10:08:29 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (parse_input(argc, argv, &data) == FAILURE)
	{
		printf("usage: %s [mandelbrot | julia | burningship]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	start_fractal(&data);
	return (0);
}

int	parse_input(int argc, char *argv[], t_data *data)
{
	char	*fractal_name;

	fractal_name = argv[1];
	if (argc < 2)
		return (FAILURE);
	if (ft_strcmp(fractal_name, MANDELBROT) == 0)
	{
		ft_strlcpy(data->fractal_name, MANDELBROT, ft_strlen(MANDELBROT) + 1);
		return (SUCCESS);
	}
	else if (ft_strcmp(fractal_name, JULIA) == 0)
	{
		ft_strlcpy(data->fractal_name, JULIA, ft_strlen(JULIA) + 1);
		return (SUCCESS);
	}
	else if (ft_strcmp(fractal_name, BURNINGSHIP) == 0)
	{
		ft_strlcpy(data->fractal_name, BURNINGSHIP, ft_strlen(BURNINGSHIP) + 1);
		return (SUCCESS);
	}
	return (FAILURE);
}

void	start_fractal(t_data *data)
{
	init_fractal(data);
	data->mlx_ptr = mlx_init();
	exit_if_null(data->mlx_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, \
									data->fractal_name);
	exit_if_null(data->win_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	exit_if_null(data->img.img_ptr);
	data->img.addr_ptr = mlx_get_data_addr(data->img.img_ptr, \
											&data->img.bits_per_pixel, \
											&data->img.size_line, \
											&data->img.endian);
	exit_if_null(data->img.addr_ptr);
	mlx_hook(data->win_ptr, KEY_PRESS_EVENT, 1L << 0, keyboard_hook, data);
	mlx_hook(data->win_ptr, MOUSE_PRESS_EVENT, 1L << 2, \
				mouse_hook, data);
	mlx_hook(data->win_ptr, MOUSE_MOVE_EVENT, 1L << 6, mouse_motion_hook, data);
	draw_fractal(data);
	mlx_loop(data->mlx_ptr);
}

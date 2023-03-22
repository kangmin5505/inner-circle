/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:00:28 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/18 15:45:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"
#include "parser_bonus.h"
#include "get_next_line.h"

static t_bool	parse_line(t_line_info *line_info, t_data *data)
{
	char	**args;
	t_bool	result;

	if (ft_strncmp(line_info->line, "\n", 1) == 0)
		return (TRUE);
	args = ft_split(line_info->line, ' ');
	if (args == NULL)
		return (FALSE);
	result = FALSE;
	if (ft_strcmp(args[0], "A") == 0)
		result = parse_ambient(line_info, args, data);
	else if (ft_strcmp(args[0], "C") == 0)
		result = parse_camera(line_info, args, data);
	else if (ft_strcmp(args[0], "L") == 0)
		result = parse_dot_light(line_info, args, data);
	else if (ft_strcmp(args[0], "sp") == 0)
		result = parse_sphere(args, data);
	else if (ft_strcmp(args[0], "pl") == 0)
		result = parse_plane(args, data);
	else if (ft_strcmp(args[0], "cy") == 0)
		result = parse_cylinder(args, data);
	else if (ft_strcmp(args[0], "cn") == 0)
		result = parse_cone(args, data);
	free_args(args);
	return (result);
}

static t_bool	check_components(t_element e)
{
	t_element	must_include_element;

	must_include_element = DUP_CHECK_AMBIENT | DUP_CHECK_CAMERA \
							| DUP_CHECK_LIGHT;
	if (e != must_include_element)
		return (FALSE);
	return (TRUE);
}

static t_bool	parse_lines(int fd, t_data *data)
{
	t_line_info	line_info;

	ft_memset(&line_info, 0, sizeof(t_line_info));
	while (1)
	{
		line_info.line = get_next_line(fd);
		if (line_info.line == NULL)
			break ;
		if (!parse_line(&line_info, data))
		{
			free(line_info.line);
			return (FALSE);
		}
		free(line_info.line);
	}
	if (!check_components(line_info.check_dup))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_rt_file(char *file_name, t_data *data)
{
	int	fd;

	fd = open_rt_file(file_name);
	if (fd < 0)
		return (FALSE);
	if (!parse_lines(fd, data))
	{
		ft_perror("parsing error");
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

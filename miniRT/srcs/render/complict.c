/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:26:05 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/26 13:31:56 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "float.h"
#include "ray.h"
#include "structure.h"
#include "objects_f.h"
#include "vec3.h"

static t_float	get_dist_from_object(t_ray ray, t_list *head)
{
	t_float	dist;

	dist = 0;
	if (head->type == SP)
		dist = hit_sphere(conv_sp(head)->origin, conv_sp(head)->radius, ray);
	else if (head->type == PL)
		dist = hit_plane(conv_pl(head)->origin, conv_pl(head)->normal, ray);
	else if (head->type == CY)
		dist = hit_cylinder(*conv_cy(head), ray);
	else if (head->type == CN)
		dist = hit_cone(conv_cn(head), ray);
	return (dist);
}

static t_float	complict_all(t_ray ray, t_list *head, t_list **hit_object)
{
	t_float	temp;
	t_float	dist;
	t_bool	is_hit;

	is_hit = FALSE;
	while (head)
	{
		temp = get_dist_from_object(ray, head);
		if (temp > 0)
		{
			if (is_hit == FALSE || temp < dist)
			{
				dist = temp;
				*hit_object = head;
			}
			is_hit = TRUE;
		}
		head = head->next;
	}
	if (is_hit == TRUE)
		return (dist);
	return (-1);
}

static void	set_hit_record_cy(t_cylinder *cy, t_hit_record *rec)
{
	rec->perpen = vec3_dot(vec3_minus(rec->hit_point, cy->origin), \
		cy->normal) / vec3_dot(cy->normal, cy->normal);
	rec->perpen_at = ray_at(ray(cy->origin, cy->normal), rec->perpen);
	if (rec->perpen <= 0.001)
		rec->normal_unit = vec3_mult_scalar(cy->normal, -1);
	else if (rec->perpen >= cy->height - 0.001)
		rec->normal_unit = cy->normal;
	else
		rec->normal_unit = \
		vec3_unit(vec3_minus(rec->hit_point, rec->perpen_at));
	rec->surf = cy->surf;
}

static void	set_hit_record( \
	t_ray ray, t_list *hit_object, t_hit_record *hit_record)
{
	hit_record->hit_point = ray_at(ray, hit_record->dist);
	hit_record->obj = hit_object;
	if (hit_object->type == SP)
	{
		hit_record->normal_unit = vec3_minus(\
			hit_record->hit_point, conv_sp(hit_object)->origin);
		hit_record->normal_unit = vec3_unit(hit_record->normal_unit);
		hit_record->surf = conv_sp(hit_object)->surf;
	}
	else if (hit_object->type == PL)
	{
		hit_record->normal_unit = conv_pl(hit_object)->normal;
		hit_record->surf = conv_pl(hit_object)->surf;
	}
	else if (hit_object->type == CY)
	{
		set_hit_record_cy(conv_cy(hit_object), hit_record);
	}
	else if (hit_object->type == CN)
	{
		set_hit_record_cn(conv_cn(hit_object), hit_record);
	}
}

int	complict(t_ray ray, t_data data, t_hit_record *hit_record)
{
	t_list	*hit_object;

	hit_object = 0;
	hit_record->dist = complict_all(ray, data.object_list, &hit_object);
	if (hit_object)
	{
		set_hit_record(ray, hit_object, hit_record);
		return (TRUE);
	}
	return (FALSE);
}

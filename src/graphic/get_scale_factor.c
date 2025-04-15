/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale_factor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:45:59 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 18:32:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_range_x(t_data *ptr_data);
static double	get_range_y(t_data *ptr_data);

void	get_scale_factor(t_data *ptr_data)
{
	double	range_x;
	double	range_y;

	range_x = get_range_x(ptr_data);
	range_y = get_range_y(ptr_data);
	range_x = (DEF_W - 0.1 * DEF_W) / range_x;
	range_y = (DEF_H - 0.1 * DEF_H) / range_y;
	if (range_x < range_y)
		ptr_data->default_scale_factor = range_x;
	else
		ptr_data->default_scale_factor = range_y;
}

static double	get_range_x(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;
	double	max_x;
	double	min_x;

	max_x = ((t_point *)((t_vector *)ptr_data->map.data)[0].data)[0].x;
	min_x = ((t_point *)((t_vector *)ptr_data->map.data)[0].data)[0].x;
	y_i = -1;
	while (++y_i < ptr_data->map.size)
	{
		x_i = -1;
		while (++x_i < ((t_vector *)ptr_data->map.data)[y_i].size)
		{
			if (((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x \
			> max_x)
				max_x = \
				((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x;
			if (((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x \
			< min_x)
				min_x = \
				((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x;
		}
	}
	return (max_x - min_x);
}

static double	get_range_y(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;
	double	max_y;
	double	min_y;

	max_y = ((t_point *)((t_vector *)ptr_data->map.data)[0].data)[0].y;
	min_y = ((t_point *)((t_vector *)ptr_data->map.data)[0].data)[0].y;
	y_i = -1;
	while (++y_i < ptr_data->map.size)
	{
		x_i = -1;
		while (++x_i < ((t_vector *)ptr_data->map.data)[y_i].size)
		{
			if (((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x \
			> max_y)
				max_y = \
				((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x;
			if (((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x \
			< min_y)
				min_y = \
				((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x;
		}
	}
	return (max_y - min_y);
}

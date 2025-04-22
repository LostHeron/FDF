/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:01:45 by jweber            #+#    #+#             */
/*   Updated: 2025/04/16 14:37:25 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "calculation.h"

static void	call_draw_func(size_t x_i, size_t y_i, t_data *ptr_data);

void	draw_points(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i < ptr_data->map_c.size)
	{
		x_i = 0;
		while (x_i < ((t_vector *)ptr_data->map_c.data)[y_i].size)
		{
			call_draw_func(x_i, y_i, ptr_data);
			x_i++;
		}
		y_i++;
	}
	draw_line(ptr_data, ptr_data->axis.pt_origin, ptr_data->axis.pt_axis_x, ptr_data->red);
	draw_line(ptr_data, ptr_data->axis.pt_origin, ptr_data->axis.pt_axis_y, ptr_data->red);
	draw_line(ptr_data, ptr_data->axis.pt_origin, ptr_data->axis.pt_axis_z, ptr_data->red);
}

static void	call_draw_func(size_t x_i, size_t y_i, t_data *ptr_data)
{
	if (y_i < ptr_data->map_c.size - 1)
		if (x_i < ((t_vector *)ptr_data->map_c.data)[y_i + 1].size)
			draw_line(ptr_data, \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i], \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i + 1].data)[x_i], ptr_data->white);
	if (x_i < ((t_vector *)ptr_data->map_c.data)[y_i].size - 1)
		draw_line(ptr_data, \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i], \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i + 1], ptr_data->white);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:36:22 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 18:38:26 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_points_axis(t_data *ptr_data, double rot[3][3]);
static void	init_points_calc(t_data *ptr_data);
static void	resize_points_calc(t_data *ptr_data);
static void	calc_new_val(size_t	x_i, size_t y_i,
				t_data *ptr_data, double rot[3][3]);

void	calc_points(t_data *ptr_data)
{
	init_points_calc(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	calc_points_axis(ptr_data, ptr_data->rot_z);
	resize_points_calc(ptr_data);
	return ;
}

static void	init_points_calc(t_data *ptr_data)
{
	size_t	y_i;
	size_t	x_i;

	y_i = 0;
	while (y_i < ptr_data->map.size)
	{
		x_i = 0;
		while (x_i < ((t_vector *)ptr_data->map.data)[y_i].size)
		{
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x = \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x;
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y = \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].y;
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z = \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].z * \
				ptr_data->height_factor;
			x_i++;
		}
		y_i++;
	}
}

static void	calc_points_axis(t_data *ptr_data, double rot[3][3])
{
	size_t	x_i;
	size_t	y_i;

	y_i = -1;
	while (++y_i < ptr_data->map_c.size)
	{
		x_i = -1;
		while (++x_i < ((t_vector *)ptr_data->map_c.data)[y_i].size)
		{
			calc_new_val(x_i, y_i, ptr_data, rot);
		}
	}
}

static void	calc_new_val(size_t	x_i, size_t y_i,
						t_data *ptr_data, double rot[3][3])
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = ((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x \
			* rot[0][0] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y \
			* rot[0][1] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z \
			* rot[0][2];
	tmp_y = ((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x \
			* rot[1][0] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y \
			* rot[1][1] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z \
			* rot[1][2];
	tmp_z = ((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x \
			* rot[2][0] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y \
			* rot[2][1] + \
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z \
			* rot[2][2];
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x = tmp_x;
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y = tmp_y;
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z = tmp_z;
}

static void	resize_points_calc(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;

	y_i = -1;
	while (++y_i < ptr_data->map_c.size)
	{
		x_i = -1;
		while (++x_i < ((t_vector *)ptr_data->map_c.data)[y_i].size)
		{
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x = \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x * \
				ptr_data->default_scale_factor * \
				ptr_data->zoom_factor + ptr_data->trans_x;
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y = \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].y * \
				ptr_data->default_scale_factor * \
				ptr_data->zoom_factor + ptr_data->trans_y;
			/*
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z = \
	((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].z * 40 * \
				ptr_data->zoom_factor + 562;
			*/
		}
	}
}

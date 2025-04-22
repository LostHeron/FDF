/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:36:22 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 12:04:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "calculation.h"

static void	init_points_calc(t_data *ptr_data);
static void	resize_points_calc(t_data *ptr_data);
static void	negate_x_values(t_data *ptr_data);

void	calc_points(t_data *ptr_data)
{
	init_points_calc(ptr_data);
	/*calc_points_axis(ptr_data, ptr_data->rot_x);*/
	/*calc_points_axis(ptr_data, ptr_data->rot_y);*/
	/*calc_points_axis(ptr_data, ptr_data->rot_z);*/
	//ptr_data->angle_x = (45 + 180) * PI / 180;
	// on tourne autour de x
	// pour aligner y_cam sur z_map,
	// pour aligner 
	ptr_data->angle_x = 90 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	//ptr_data->angle_y = (45 + 180) * PI / 180;
	ptr_data->angle_y = -(45 + 90) * PI / 180;
	set_rot_y(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	//ptr_data->angle_x = 45 * PI / 180;
	ptr_data->angle_x = 45 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	// for x rotation test :
	// for y rotation test :
	// go back y_cam aligned with z_map
	ptr_data->angle_x = -45 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	// to align x_cam with y_map; 
	ptr_data->angle_y = -(45 + 90) * PI / 180;
	set_rot_y(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	// rota
	ptr_data->angle_x = ptr_data->delta_y;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	// go back to correct position : 
	ptr_data->angle_y = +(45 + 90) * PI / 180;
	set_rot_y(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	ptr_data->angle_x = +45 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	// for z rotation test :
	ptr_data->angle_x = -45 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	ptr_data->angle_y = ptr_data->delta_z;
	set_rot_y(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	ptr_data->angle_x = 45 * PI / 180;
	set_rot_x(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	//calc_points_axis(ptr_data, ptr_data->rot_mat);
	resize_points_calc(ptr_data);
	return ;
}

static void	init_points_calc(t_data *ptr_data)
{
	size_t	y_i;
	size_t	x_i;

	ptr_data->axis.pt_axis_x = ptr_data->axis.pt_axis_x_init;
	ptr_data->axis.pt_axis_y = ptr_data->axis.pt_axis_y_init;
	ptr_data->axis.pt_axis_z = ptr_data->axis.pt_axis_z_init;
	ptr_data->axis.pt_origin = ptr_data->axis.pt_origin_init;
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
	negate_x_values(ptr_data);
}

void	calc_points_axis(t_data *ptr_data, double rot[3][3])
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
	calc_axis(ptr_data, rot);
}

void	calc_new_val(size_t	x_i, size_t y_i,
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
		}
	}
	rescale_axis(ptr_data);
}

static void	negate_x_values(t_data *ptr_data)
{
	size_t	y_i;
	size_t	x_i;

	y_i = 0;
	while (y_i < ptr_data->map_c.size)
	{
		x_i = 0;
		while (x_i < ((t_vector *)ptr_data->map_c.data)[y_i].size)
		{
			((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x = \
		- ((t_point *)((t_vector *)ptr_data->map_c.data)[y_i].data)[x_i].x;
			x_i++;
		}
		y_i++;
	}
	ptr_data->axis.pt_axis_x.x = -ptr_data->axis.pt_axis_x.x;
	ptr_data->axis.pt_axis_y.x = -ptr_data->axis.pt_axis_y.x;
	ptr_data->axis.pt_axis_z.x = -ptr_data->axis.pt_axis_z.x;
	ptr_data->axis.pt_origin.x = -ptr_data->axis.pt_origin.x;
}

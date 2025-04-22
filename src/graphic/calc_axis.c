/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_axis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:29:48 by jweber            #+#    #+#             */
/*   Updated: 2025/04/17 13:42:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_points_rot(t_point old_point, double rot[3][3]);

void calc_axis(t_data *ptr_data, double rot[3][3])
{
	ptr_data->axis.pt_axis_x = new_points_rot(ptr_data->axis.pt_axis_x, rot);
	ptr_data->axis.pt_axis_y = new_points_rot(ptr_data->axis.pt_axis_y, rot);
	ptr_data->axis.pt_axis_z = new_points_rot(ptr_data->axis.pt_axis_z, rot);
	ptr_data->axis.pt_origin = new_points_rot(ptr_data->axis.pt_origin, rot);
}

t_point	new_points_rot(t_point old_point, double rot[3][3])
{
	t_point	ret;

	ret.x = old_point.x * rot[0][0] + \
			old_point.y * rot[0][1] + \
			old_point.z * rot[0][2];
	ret.y = old_point.x * rot[1][0] + \
			old_point.y * rot[1][1] + \
			old_point.z * rot[1][2];
	ret.z = old_point.x * rot[2][0] + \
			old_point.y * rot[2][1] + \
			old_point.z * rot[2][2];
	return (ret);
}

t_point	new_points_rescale(t_data *ptr_data, t_point old_point);

void rescale_axis(t_data *ptr_data)
{
	ptr_data->axis.pt_axis_x = new_points_rescale(ptr_data, ptr_data->axis.pt_axis_x);
	ptr_data->axis.pt_axis_y = new_points_rescale(ptr_data, ptr_data->axis.pt_axis_y);
	ptr_data->axis.pt_axis_z = new_points_rescale(ptr_data, ptr_data->axis.pt_axis_z);
	ptr_data->axis.pt_origin = new_points_rescale(ptr_data, ptr_data->axis.pt_origin);
}

t_point	new_points_rescale(t_data *ptr_data, t_point old_point)
{
	t_point	ret;

	ret.x = old_point.x * ptr_data->default_scale_factor * \
			ptr_data->zoom_factor + ptr_data->trans_x;
	ret.y = old_point.y * ptr_data->default_scale_factor * \
			ptr_data->zoom_factor + ptr_data->trans_y ;
	ret.z = old_point.z * ptr_data->default_scale_factor * \
			ptr_data->zoom_factor + ptr_data->trans_x;
	return (ret);
}

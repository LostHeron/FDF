/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_rot_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:35:52 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 10:48:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "calculation.h"

void	modify_rot_x_neg(t_data *ptr_data)
{
	ptr_data->angle_x -= PI_OVER_16;
	if (ptr_data->angle_x < -2 * PI)
		ptr_data->angle_x += 2 * PI;
	set_rot_x(ptr_data);
	set_rot_mat(ptr_data);
}

void	modify_rot_y_neg(t_data *ptr_data)
{
	ptr_data->angle_y -= PI_OVER_16;
	if (ptr_data->angle_y < -2 * PI)
		ptr_data->angle_y += 2 * PI;
	set_rot_y(ptr_data);
	set_rot_mat(ptr_data);
}

void	modify_rot_z_neg(t_data *ptr_data)
{
	ptr_data->angle_z -= PI_OVER_16;
	if (ptr_data->angle_z < -2 * PI)
		ptr_data->angle_z += 2 * PI;
	set_rot_z(ptr_data);
	set_rot_mat(ptr_data);
}

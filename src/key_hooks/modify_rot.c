/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:49:08 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 10:39:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"

void	modify_rot_x(t_data *ptr_data)
{
	ptr_data->angle_x += PI_OVER_16;
	if (ptr_data->angle_x > 2 * PI)
		ptr_data->angle_x += 2 * PI;
	set_rot_x(ptr_data);
}

void	modify_rot_y(t_data *ptr_data)
{
	ptr_data->angle_y += PI_OVER_16;
	if (ptr_data->angle_x > 2 * PI)
		ptr_data->angle_x += 2 * PI;
	set_rot_y(ptr_data);
}

void	modify_rot_z(t_data *ptr_data)
{
	ptr_data->angle_z += PI_OVER_16;
	if (ptr_data->angle_x > 2 * PI)
		ptr_data->angle_x += 2 * PI;
	set_rot_z(ptr_data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:31:27 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 18:31:37 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void	set_rot_x(t_data *ptr_data)
{
	double	angle;

	angle = ptr_data->angle_x;
	ptr_data->rot_x[0][0] = 1;
	ptr_data->rot_x[0][1] = 0;
	ptr_data->rot_x[0][2] = 0;
	ptr_data->rot_x[1][0] = 0;
	ptr_data->rot_x[1][1] = cos(angle);
	ptr_data->rot_x[1][2] = -sin(angle);
	ptr_data->rot_x[2][0] = 0;
	ptr_data->rot_x[2][1] = sin(angle);
	ptr_data->rot_x[2][2] = cos(angle);
}

void	set_rot_y(t_data *ptr_data)
{
	double	angle;

	angle = ptr_data->angle_y;
	ptr_data->rot_y[0][0] = cos(angle);
	ptr_data->rot_y[0][1] = 0;
	ptr_data->rot_y[0][2] = sin(angle);
	ptr_data->rot_y[1][0] = 0;
	ptr_data->rot_y[1][1] = 1;
	ptr_data->rot_y[1][2] = 0;
	ptr_data->rot_y[2][0] = -sin(angle);
	ptr_data->rot_y[2][1] = 0;
	ptr_data->rot_y[2][2] = cos(angle);
}

void	set_rot_z(t_data *ptr_data)
{
	double	angle;

	angle = ptr_data->angle_z;
	ptr_data->rot_z[0][0] = cos(angle);
	ptr_data->rot_z[0][1] = -sin(angle);
	ptr_data->rot_z[0][2] = 0;
	ptr_data->rot_z[1][0] = sin(angle);
	ptr_data->rot_z[1][1] = cos(angle);
	ptr_data->rot_z[1][2] = 0;
	ptr_data->rot_z[2][0] = 0;
	ptr_data->rot_z[2][1] = 0;
	ptr_data->rot_z[2][2] = 1;
}

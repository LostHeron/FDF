/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_no_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:33:22 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 12:08:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "calculation.h"
#include "mlx.h"
#include "key_hooks.h"
#define XK_MISCELLANY
#include <X11/keysym.h>

static int	rotations(int keycode, t_data *ptr_data);
static int	other_views(int keycode, t_data *ptr_data);

int	key_hook_no_shift(int keycode, t_data *ptr_data)
{
	if (keycode == XK_c)
	{
		clear_image(ptr_data);
		mlx_clear_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
		return (0);
	}
	if (rotations(keycode, ptr_data) == 0)
		return (0);
	if (zooms(keycode, ptr_data) == 0)
		return (0);
	if (displacements(keycode, ptr_data) == 0)
		return (0);
	if (heights(keycode, ptr_data) == 0)
		return (0);
	if (other_views(keycode, ptr_data) == 0)
		return (0);
	return (0);
}

static int	rotations(int keycode, t_data *ptr_data)
{
	if (keycode == XK_k)
	{
		modify_rot_x(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_l)
	{
		ptr_data->delta_y += PI_OVER_16;
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == 59)
	{
		//modify_rot_z_neg(ptr_data);
		ptr_data->delta_z += PI_OVER_16;
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

static int	other_views(int keycode, t_data *ptr_data)
{
	if (keycode == XK_w)
	{
		ptr_data->angle_x = PI * 90 / 180;
		ptr_data->angle_y = 0;
		ptr_data->angle_z = 0;
		set_rot_x(ptr_data);
		set_rot_y(ptr_data);
		set_rot_z(ptr_data);
		set_rot_mat(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_e)
	{
		ptr_data->angle_x = 0;
		ptr_data->angle_y = PI * 90 / 180;
		ptr_data->angle_z = 0;
		set_rot_x(ptr_data);
		set_rot_y(ptr_data);
		set_rot_z(ptr_data);
		set_rot_mat(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_r)
	{
		ptr_data->angle_x = 0;
		ptr_data->angle_y = 0;
		ptr_data->angle_z = PI * 90 / 180;
		set_rot_x(ptr_data);
		set_rot_y(ptr_data);
		set_rot_z(ptr_data);
		set_rot_mat(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

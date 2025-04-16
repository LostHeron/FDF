/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_shift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:35:02 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 18:36:02 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"
#include "mlx.h"
#include "key_hooks.h"
#define XK_MISCELLANY
#include <X11/keysym.h>

static int	rotations(int keycode, t_data *ptr_data);

int	key_hook_shift(int keycode, t_data *ptr_data)
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
	return (0);
}

static int	rotations(int keycode, t_data *ptr_data)
{
	if (keycode == XK_k)
	{
		modify_rot_x_neg(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_l)
	{
		modify_rot_y_neg(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == 59)
	{
		modify_rot_z_neg(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

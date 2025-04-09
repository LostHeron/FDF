/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 18:56:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "graphic.h"
#define XK_LATIN1
#include <X11/keysymdef.h>

#include <stdio.h>
int	key_hooks(int keycode, t_data *ptr_data)
{
	printf("keycode = %i\n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(ptr_data->ptr_mlx);
		mlx_destroy_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
		ptr_data->ptr_win = NULL;
	}
	if (keycode == XK_c)
	{
		clear_image(ptr_data);
		mlx_clear_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
	}
	if (keycode == 59) // 59 is for 'm' keytouch
	{
		modify_rot_x(ptr_data);
	}
	if (keycode == XK_d)
	{
		calc_points(ptr_data, ptr_data->rot_y);
		draw_points(ptr_data);
		mlx_put_image_to_window(ptr_data->ptr_mlx, ptr_data->ptr_win, ptr_data->ptr_img, 0, 0);
	}
	return (0);
}

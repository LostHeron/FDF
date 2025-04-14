/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 16:59:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "graphic.h"
#include "ft_vectors.h"
#define XK_LATIN1
#include <X11/keysymdef.h>

#include <stdio.h>

int	key_hooks(int keycode, t_data *ptr_data)
{
	printf("keycode = %i\n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(ptr_data->ptr_mlx);
		return (0);
	}
	if (keycode == XK_c)
	{
		printf("clear win\n");
		clear_image(ptr_data);
		mlx_clear_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
	}
	if (keycode == XK_k)
	{
		printf("mod rot x\n");
		modify_rot_x(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == XK_l)
	{
		printf("mod rot y\n");
		modify_rot_y(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == 59)
	{
		printf("zoom out\n");
		modify_rot_z(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == XK_i)
	{
		printf("zoom in\n");
		zoom_in(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == XK_o)
	{
		printf("zoom out \n");
		zoom_out(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == XK_d)
	{
		printf("heigt factor down\n");
		modify_height_factor_down(ptr_data);
		clear_and_print(ptr_data);
	}
	if (keycode == XK_u)
	{
		printf("heigt factor up\n");
		modify_height_factor_up(ptr_data);
		clear_and_print(ptr_data);
	}
	return (0);
}

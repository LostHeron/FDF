/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 10:49:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_hooks.h"
#define XK_LATIN1
#define XK_MISCELLANY
#include <X11/keysymdef.h>

int	key_press(int keycode, t_data *ptr_data)
{
	if (keycode == ESC)
	{
		mlx_loop_end(ptr_data->ptr_mlx);
		return (0);
	}
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
	{
		ptr_data->hook_func = &key_hook_shift;
	}
	ptr_data->hook_func(keycode, ptr_data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:56:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 10:50:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_hooks.h"
#define XK_LATIN1
#include <X11/keysymdef.h>

#include <stdio.h>

int	key_press(int keycode, t_data *ptr_data)
{
	printf("dans key_press\n");
	printf("keycode = %i\n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(ptr_data->ptr_mlx);
		return (0);
	}
	if (keycode == SHIFT)
	{
		ptr_data->hook_func = &key_hook_shift;
	}
	printf("avant hook_func\n");
	ptr_data->hook_func(keycode, ptr_data);
	return (0);
}

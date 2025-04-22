/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:43:26 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 10:49:02 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_hooks.h"
#define XK_MISCELLANY
#include <X11/keysym.h>

#include <stdio.h>

int	key_release(int keycode, t_data *ptr_data)
{
	printf("keycode == %i\n", keycode);
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
	{
		ptr_data->hook_func = &key_hook_no_shift;
	}
	return (0);
}

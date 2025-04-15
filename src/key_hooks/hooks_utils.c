/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:27:43 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 11:49:25 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"
#include <X11/keysym.h>
#include "key_hooks.h"

int	zooms(int keycode, t_data *ptr_data)
{
	if (keycode == XK_i)
	{
		zoom_in(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_o)
	{
		zoom_out(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

int	displacements(int keycode, t_data *ptr_data)
{
	if (keycode == XK_Left)
	{
		ptr_data->trans_x -= 10;
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_Right)
	{
		ptr_data->trans_x += 10;
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_Up)
	{
		ptr_data->trans_y -= 10;
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_Down)
	{
		ptr_data->trans_y += 10;
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

int	heights(int keycode, t_data *ptr_data)
{
	if (keycode == XK_d)
	{
		modify_height_factor_down(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	if (keycode == XK_u)
	{
		modify_height_factor_up(ptr_data);
		clear_and_print(ptr_data);
		return (0);
	}
	return (1);
}

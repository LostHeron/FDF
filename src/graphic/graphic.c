/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:50:45 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 11:00:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "graphic.h"
#include "key_hooks.h"
#define XK_LATIN1
#include <X11/keysymdef.h>
#include <X11/X.h>

static void	init_rot(t_data *ptr_data);
static void	init_factor(t_data *ptr_data);
static void	free_mlx(t_data *ptr_data);

int	graphic(t_data	*ptr_data)
{
	int	ret;

	ret = init_mlx_data(ptr_data);
	if (ret != 0)
		return (ret);
	init_rot(ptr_data);
	init_factor(ptr_data);
	ptr_data->hook_func = &key_hook_no_shift;
	clear_and_print(ptr_data);
	mlx_hook(ptr_data->ptr_win, KeyRelease, KeyReleaseMask, \
		&key_release, ptr_data);
	mlx_hook(ptr_data->ptr_win, KeyPress, KeyPressMask, \
		&key_press, ptr_data);
	mlx_hook(ptr_data->ptr_win, DestroyNotify, NoEventMask, \
		&mlx_loop_end, ptr_data->ptr_mlx);
	mlx_loop(ptr_data->ptr_mlx);
	free_mlx(ptr_data);
	return (0);
}

static void	init_factor(t_data *ptr_data)
{
	ptr_data->height_factor = 0.1;
	ptr_data->zoom_factor = 1.0;
	get_scale_factor(ptr_data);
	ptr_data->trans_x = (double) DEF_W / 2;
	ptr_data->trans_y = (double) DEF_H / 2;
}

void	init_rot(t_data *ptr_data)
{
	ptr_data->angle_x = 35.264 * PI / 180;
	ptr_data->angle_y = -35.264 * PI / 180;
	ptr_data->angle_z = 0;
	set_rot_x(ptr_data);
	set_rot_y(ptr_data);
	set_rot_z(ptr_data);
}

static void	free_mlx(t_data *ptr_data)
{
	mlx_destroy_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
	ptr_data->ptr_win = NULL;
	mlx_destroy_image(ptr_data->ptr_mlx, ptr_data->ptr_img);
	ptr_data->ptr_img = NULL;
	mlx_destroy_display(ptr_data->ptr_mlx);
	free(ptr_data->ptr_mlx);
	ptr_data->ptr_mlx = NULL;
	return ;
}

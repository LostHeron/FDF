/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:50:45 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 15:09:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "graphic.h"
#define XK_LATIN1
#include <X11/keysymdef.h>

static void	free_mlx(t_data *ptr_data);
void		try_draw_line(t_data *ptr_data);
void		init_points(t_data *ptr_data);
void		init_rot(t_data *ptr_data);

int	graphic(t_data	*ptr_data)
{
	int	ret;

	ret = init_mlx_data(ptr_data);
	if (ret != 0)
		return (ret);
	init_rot(ptr_data);
	init_points(ptr_data);
	mlx_key_hook(ptr_data->ptr_win, &key_hooks, ptr_data);
	mlx_loop(ptr_data->ptr_mlx);
	free_mlx(ptr_data);
	return (0);
}

void	init_points(t_data *ptr_data)
{
	ptr_data->points_init[0][0].x = -1;
	ptr_data->points_init[0][0].y = -1;
	ptr_data->points_init[0][0].z = 0;
	ptr_data->points_init[0][1].x = -1;
	ptr_data->points_init[0][1].y = 0;
	ptr_data->points_init[0][1].z = 0;
	ptr_data->points_init[0][2].x = -1;
	ptr_data->points_init[0][2].y = 1;
	ptr_data->points_init[0][2].z = 0;
	ptr_data->points_init[1][0].x = 0;
	ptr_data->points_init[1][0].y = -1;
	ptr_data->points_init[1][0].z = 0;
	ptr_data->points_init[1][1].x = 0;
	ptr_data->points_init[1][1].y = 0;
	ptr_data->points_init[1][1].z = 1;
	ptr_data->points_init[1][2].x = 0;
	ptr_data->points_init[1][2].y = 1;
	ptr_data->points_init[1][2].z = 0;
	ptr_data->points_init[2][0].x = 1;
	ptr_data->points_init[2][0].y = -1;
	ptr_data->points_init[2][0].z = 0;
	ptr_data->points_init[2][1].x = 1;
	ptr_data->points_init[2][1].y = 0;
	ptr_data->points_init[2][1].z = 0;
	ptr_data->points_init[2][2].x = 1;
	ptr_data->points_init[2][2].y = 1;
	ptr_data->points_init[2][2].z = 0;
}

void	init_rot(t_data *ptr_data)
{
	ptr_data->angle_y = 0;
	ptr_data->angle_x = 0;
	ptr_data->angle_z = 0;
	set_rot_x(ptr_data);
	set_rot_y(ptr_data);
	set_rot_z(ptr_data);
}

static void	free_mlx(t_data *ptr_data)
{
	mlx_destroy_image(ptr_data->ptr_mlx, ptr_data->ptr_img);
	ptr_data->ptr_img = NULL;
	mlx_destroy_display(ptr_data->ptr_mlx);
	free(ptr_data->ptr_mlx);
	ptr_data->ptr_mlx = NULL;
}

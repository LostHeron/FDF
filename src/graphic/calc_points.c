/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:36:22 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 14:59:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_points_axis(t_data *ptr_data, double rot[3][3]);
static void	init_points_calc(t_data *ptr_data);
static void	resize_points_calc(t_data *ptr_data);

void	calc_points(t_data *ptr_data)
{
	init_points_calc(ptr_data);
	calc_points_axis(ptr_data, ptr_data->rot_x);
	calc_points_axis(ptr_data, ptr_data->rot_y);
	calc_points_axis(ptr_data, ptr_data->rot_z);
	resize_points_calc(ptr_data);
	return ;
}

static void	init_points_calc(t_data *ptr_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			ptr_data->points_calc[i][j].x = ptr_data->points_init[i][j].x;
			ptr_data->points_calc[i][j].y = ptr_data->points_init[i][j].y;
			ptr_data->points_calc[i][j].z = ptr_data->points_init[i][j].z;
			j++;
		}
		i++;
	}
}

static void	calc_points_axis(t_data *ptr_data, double rot[3][3])
{
	double	tmp_x;
	double	tmp_y;
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			tmp_x = ptr_data->points_calc[i][j].x * rot[0][0] + \
					ptr_data->points_calc[i][j].y * rot[0][1] + \
					ptr_data->points_calc[i][j].z * rot[0][2];
			tmp_y = ptr_data->points_calc[i][j].x * rot[1][0] + \
					ptr_data->points_calc[i][j].y * rot[1][1] + \
					ptr_data->points_calc[i][j].z * rot[1][2];
			ptr_data->points_calc[i][j].z = \
					ptr_data->points_calc[i][j].x * rot[2][0] + \
					ptr_data->points_calc[i][j].y * rot[2][1] + \
					ptr_data->points_calc[i][j].z * rot[2][2];
			ptr_data->points_calc[i][j].x = tmp_x;
			ptr_data->points_calc[i][j].y = tmp_y;
		}
	}
}

static void	resize_points_calc(t_data *ptr_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			ptr_data->points_calc[i][j].x = \
				ptr_data->points_calc[i][j].x * 375 + 562;
			ptr_data->points_calc[i][j].y = \
				ptr_data->points_calc[i][j].y * 375 + 562;
			ptr_data->points_calc[i][j].z = \
				ptr_data->points_calc[i][j].z * 375 + 562;
			j++;
		}
		i++;
	}
}

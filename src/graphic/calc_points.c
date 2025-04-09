/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:36:22 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 19:05:14 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_points(t_data *ptr_data, double rot[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ptr_data->points_calc[i][j].x = ptr_data->points_init[i][j].x * rot[0][0] + \
											ptr_data->points_init[i][j].y * rot[0][1] + \
											ptr_data->points_init[i][j].z * rot[0][2];
			ptr_data->points_calc[i][j].x = ptr_data->points_calc[i][j].x * 375 + 562;
			ptr_data->points_calc[i][j].y = ptr_data->points_init[i][j].x * rot[1][0] + \
											ptr_data->points_init[i][j].y * rot[1][1] + \
											ptr_data->points_init[i][j].z * rot[1][2];
			ptr_data->points_calc[i][j].x = ptr_data->points_calc[i][j].y * 375 + 562;
			ptr_data->points_calc[i][j].z = ptr_data->points_init[i][j].x * rot[2][0] + \
											ptr_data->points_init[i][j].y * rot[2][1] + \
											ptr_data->points_init[i][j].z * rot[2][2];
			ptr_data->points_calc[i][j].x = ptr_data->points_calc[i][j].z * 375 + 562;
		}
	}
	return ;
}

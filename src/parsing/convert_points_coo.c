/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points_coo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:43:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 17:07:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_points_coo(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;
	double	val_x;
	double	val_y;

	y_i = 0;
	val_y = (double)(ptr_data->map.size - 1) / 2;
	while (y_i < ptr_data->map.size)
	{
		x_i = 0;
		val_x = (double)(((t_vector *)ptr_data->map.data)->size - 1) / 2;
		while (x_i < ((t_vector *)ptr_data->map.data)[y_i].size)
		{
			((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x = \
				-val_x + x_i;
			((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].y = \
				-val_y + y_i;
			x_i++;
		}
		y_i++;
	}
	return ;
}

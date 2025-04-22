/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:34:39 by jweber            #+#    #+#             */
/*   Updated: 2025/04/18 14:34:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_point(t_point point)
{
	printf("%f, %f, %f || ", point.x, point.y, point.z);
	printf("\n");
}

void	print_points(t_data *ptr_data)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i < ptr_data->map.size)
	{
		x_i = 0;
		while (x_i < ((t_vector *)ptr_data->map.data)[y_i].size)
		{
			printf("%f, %f, %f || ", \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].x, \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].y, \
		((t_point *)((t_vector *)ptr_data->map.data)[y_i].data)[x_i].z);
			x_i++;
		}
		printf("\n");
		y_i++;
	}
}

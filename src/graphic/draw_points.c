/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:01:45 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 19:01:37 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"

void	draw_points(t_data *ptr_data)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i < 2)
				draw_line(ptr_data, ptr_data->points_calc[i][j], ptr_data->points_calc[i + 1][j]);
			if (j < 2)
				draw_line(ptr_data, ptr_data->points_calc[i][j], ptr_data->points_calc[i][j + 1]);
		}
	}
}

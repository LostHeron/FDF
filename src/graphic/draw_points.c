/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:01:45 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 15:12:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"

void	draw_points(t_data *ptr_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i < 2)
				draw_line(ptr_data, ptr_data->points_calc[i][j], \
					ptr_data->points_calc[i + 1][j]);
			if (j < 2)
				draw_line(ptr_data, ptr_data->points_calc[i][j], \
					ptr_data->points_calc[i][j + 1]);
			j++;
		}
		i++;
	}
}

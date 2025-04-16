/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_height_factor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:30:24 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 18:20:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"

void	modify_height_factor_down(t_data *ptr_data)
{
	if (ft_abs(ptr_data->height_factor) > 0.10001)
		ptr_data->height_factor -= 0.1;
	else
		ptr_data->height_factor -= 0.01;
}

void	modify_height_factor_up(t_data *ptr_data)
{
	if (ft_abs(ptr_data->height_factor) < 0.101)
		ptr_data->height_factor += 0.01;
	else
		ptr_data->height_factor += 0.1;
}

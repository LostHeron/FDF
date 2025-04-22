/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_zoom_factor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:19:01 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 10:48:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_data *ptr_data)
{
	ptr_data->zoom_factor += 0.1;
}

void	zoom_out(t_data *ptr_data)
{
	if (ptr_data->zoom_factor > 0.12)
		ptr_data->zoom_factor -= 0.1;
	else if (ptr_data->zoom_factor > 0.012)
		ptr_data->zoom_factor -= 0.01;
}

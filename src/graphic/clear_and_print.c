/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:58:23 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 16:04:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphic.h"
#include "mlx.h"

void	clear_and_print(t_data *ptr_data)
{
	clear_image(ptr_data);
	calc_points(ptr_data);
	draw_points(ptr_data);
	mlx_put_image_to_window(ptr_data->ptr_mlx, ptr_data->ptr_win, \
						ptr_data->ptr_img, 0, 0);
}

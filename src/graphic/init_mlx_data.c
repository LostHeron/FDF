/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:26:03 by jweber            #+#    #+#             */
/*   Updated: 2025/04/08 15:27:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	get_pixel_data(t_data *ptr_data);

int	init_mlx_data(t_data *ptr_data)
{
	int	ret;

	ptr_data->ptr_mlx = mlx_init();
	if (ptr_data->ptr_mlx == NULL)
		return (ERROR_MLX);
	ptr_data->ptr_win = mlx_new_window(ptr_data->ptr_mlx, DEF_W, DEF_H, "fdf");
	if (ptr_data->ptr_win == NULL)
	{
		mlx_destroy_display(ptr_data->ptr_mlx);
		free(ptr_data->ptr_mlx);
		return (ERROR_MLX);
	}
	ptr_data->ptr_img = mlx_new_image(ptr_data->ptr_mlx, DEF_W, DEF_H);
	if (ptr_data->ptr_img == NULL)
	{
		mlx_destroy_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
		mlx_destroy_display(ptr_data->ptr_mlx);
		free(ptr_data->ptr_mlx);
		return (ERROR_MLX);
	}
	ret = get_pixel_data(ptr_data);
	if (ret != 0)
		return (ret);
	return (0);
}

static int	get_pixel_data(t_data *ptr_data)
{
	ptr_data->pixels_data = mlx_get_data_addr(ptr_data->ptr_img, \
				&ptr_data->bits_pp, &ptr_data->bytes_pl, &ptr_data->endian);
	if (ptr_data->pixels_data == NULL)
	{
		mlx_destroy_image(ptr_data->ptr_mlx, ptr_data->ptr_img);
		mlx_destroy_window(ptr_data->ptr_mlx, ptr_data->ptr_win);
		mlx_destroy_display(ptr_data->ptr_mlx);
		free(ptr_data->ptr_mlx);
		return (ERROR_MLX);
	}
	return (0);
}

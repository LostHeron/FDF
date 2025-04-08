/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:22:23 by jweber            #+#    #+#             */
/*   Updated: 2025/04/08 18:41:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "graphic.h"
#include "math.h"

void	init_rot(t_data *ptr_data);

int	main(void)
{
	t_data	data;
	int		ret;

	ret = ft_vector_init(&data.map, 5, sizeof(char *), NULL);
	if (ret != 0)
		return (ret);
	free(data.map.data);
	init_rot(&data);
	ret = graphic(&data);
	return (ret);
}

void	init_rot_x(t_data *ptr_data);
void	init_rot_y(t_data *ptr_data);
void	init_rot_z(t_data *ptr_data);

void	init_rot(t_data *ptr_data)
{
	init_rot_x(ptr_data);
}

void	init_rot_x(t_data *ptr_data)
{
	double	rot;

	rot = 0.52359877559;
	ptr_data->rot_x[0][0] = 1;
	ptr_data->rot_x[0][1] = 0;
	ptr_data->rot_x[0][2] = 0;
	ptr_data->rot_x[1][0] = 0;
	ptr_data->rot_x[1][1] = cos(rot);
	ptr_data->rot_x[1][2] = sin(rot);
	ptr_data->rot_x[2][0] = 0;
	ptr_data->rot_x[2][1] = -sin(rot);
	ptr_data->rot_x[2][2] = cos(rot);
}

void	init_rot_y(t_data *ptr_data)
{
	double	rot;

	rot = 0.52359877559;
	ptr_data->rot_x[0][0] = cos(rot);
	ptr_data->rot_x[0][1] = 0;
	ptr_data->rot_x[0][2] = sin(rot);
	ptr_data->rot_x[1][0] = 0;
	ptr_data->rot_x[1][1] = 1;
	ptr_data->rot_x[1][2] = 0;
	ptr_data->rot_x[2][0] = -sin(rot);
	ptr_data->rot_x[2][1] = 0;
	ptr_data->rot_x[2][2] = cos(rot);
}

void	init_rot_z(t_data *ptr_data)
{
	double	rot;

	rot = 0.52359877559;
	ptr_data->rot_x[0][0] = cos(rot);
	ptr_data->rot_x[0][1] = sin(rot);
	ptr_data->rot_x[0][2] = 0;
	ptr_data->rot_x[1][0] = -sin(rot);
	ptr_data->rot_x[1][1] = cos(rot);
	ptr_data->rot_x[1][2] = 0;
	ptr_data->rot_x[2][0] = 0;
	ptr_data->rot_x[2][1] = 0;
	ptr_data->rot_x[2][2] = 1;
}

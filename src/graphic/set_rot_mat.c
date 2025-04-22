/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:41:20 by jweber            #+#    #+#             */
/*   Updated: 2025/04/18 14:33:02 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_rot_mat(t_data *ptr_data);
static void	mult_mat(double (*rot_a)[3][3], double (*rot_b)[3][3]);
static void	copy_mat(double (*rot_dest)[3][3], double (*rot_src)[3][3]);

void	set_rot_mat(t_data *ptr_data)
{
	init_rot_mat(ptr_data);
	mult_mat(&ptr_data->rot_mat, &ptr_data->rot_x);
	mult_mat(&ptr_data->rot_mat, &ptr_data->rot_y);
	mult_mat(&ptr_data->rot_mat, &ptr_data->rot_z);
}

static void	init_rot_mat(t_data *ptr_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == j)
				ptr_data->rot_mat[i][j] = 1;
			else
				ptr_data->rot_mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	mult_mat(double (*rot_a)[3][3], double (*rot_b)[3][3])
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	tmp_rot[3][3];

	copy_mat(&tmp_rot, rot_a);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			(*rot_a)[i][j] = 0;
			while (k < 3)
			{
				(*rot_a)[i][j] += tmp_rot[i][k] * (*rot_b)[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return ;
}

static void	copy_mat(double (*rot_dest)[3][3], double (*rot_src)[3][3])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			(*rot_dest)[i][j] = (*rot_src)[i][j];
			j++;
		}
		i++;
	}
	return ;
}

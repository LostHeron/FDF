/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:35:06 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 11:21:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "parsing.h"

static void	print_map(t_data *ptr_data);
static void	print_map_vec(t_data *ptr_data);
static void	print_map_vec_copy(t_data *ptr_data);

#include <stdio.h>

int	parsing(t_data *ptr_data, char *filename)
{
	int	ret;

	ret = read_map(ptr_data, filename);
	if (ret != 0)
		return (ret);
	print_map(ptr_data);
	ret = convert_map(ptr_data);
	if (ret != 0)
		return (ret);
	printf("map before change :\n");
	print_map_vec(ptr_data);
	convert_points_coo(ptr_data);
	printf("map after change :\n");
	print_map_vec(ptr_data);
	copy_map_vec(ptr_data);
	printf("map copy :\n");
	fflush(stdout);
	print_map_vec_copy(ptr_data);
	//ft_vector_free(&ptr_data->map);
	return (0);
}

static void	print_map_vec_copy(t_data *ptr_data)
{
	for (size_t i = 0; i < ptr_data->map_c.size; i++)
	{
		for (size_t j = 0; j < ((t_vector *)ptr_data->map_c.data)->size; j++)
		{
			printf("%f, %f, %f || ", \
			((t_point *)((t_vector *)ptr_data->map_c.data)[i].data)[j].x, \
			((t_point *)((t_vector *)ptr_data->map_c.data)[i].data)[j].y, \
			((t_point *)((t_vector *)ptr_data->map_c.data)[i].data)[j].z);
		}
		printf("\n");
	}
}

static void	print_map_vec(t_data *ptr_data)
{
	for (size_t i = 0; i < ptr_data->map.size; i++)
	{
		for (size_t j = 0; j < ((t_vector *)ptr_data->map.data)->size; j++)
		{
			printf("%f, %f, %f || ", \
			((t_point *)((t_vector *)ptr_data->map.data)[i].data)[j].x, \
			((t_point *)((t_vector *)ptr_data->map.data)[i].data)[j].y, \
			((t_point *)((t_vector *)ptr_data->map.data)[i].data)[j].z);
		}
		printf("\n");
	}
}

static void	print_map(t_data *ptr_data)
{
	size_t	i;

	i = 0;
	while (i < ptr_data->map.size)
	{
		printf("%s\n", ((char **)ptr_data->map.data)[i]);
		i++;
	}
}

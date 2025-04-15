/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:32:04 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 16:52:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "parsing.h"

static void	my_free(t_vector *ptr_vec);

int	convert_map(t_data *ptr_data)
{
	int			ret;
	t_vector	map_copy;

	ft_vector_copy(&map_copy, &ptr_data->map);
	ret = ft_vector_init(&ptr_data->map, map_copy.size, \
						sizeof(t_vector), &my_free);
	if (ret != 0)
	{
		ft_vector_free(&map_copy);
		return (ret);
	}
	ret = fill_new_vec(ptr_data, map_copy);
	if (ret != 0)
	{
		ft_vector_free(&ptr_data->map);
		return (ret);
	}
	return (0);
}

static void	my_free(t_vector *ptr_vec)
{
	size_t	i;

	i = 0;
	while (i < ptr_vec->size)
	{
		ft_vector_free(((t_vector *)ptr_vec->data) + i);
		i++;
	}
	free(ptr_vec->data);
}

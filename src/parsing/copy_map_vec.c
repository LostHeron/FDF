/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:59:48 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 11:22:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_memory.h"
#include "ft_vectors.h"

/*
 * So idea here :
 * this function should : 
 * In case of success :
	* have ptr_data->map_c be a duplicate of ptr_data->map
 * In case of failure :
	* ptr_data->map_c be correctly cleared before function return !
 */
int	copy_map_vec(t_data *ptr_data)
{
	int			ret;
	size_t		i;
	t_vector	vec_tmp;

	ret = ft_vector_init(&ptr_data->map_c, ptr_data->map.capacity, \
				ptr_data->map.data_size, ptr_data->map.del);
	if (ret != 0)
		return (ret);
	i = 0;
	while (i < ptr_data->map.size)
	{
		ret = ft_vector_init(&vec_tmp, \
							((t_vector *)ptr_data->map.data)[i].capacity, \
							((t_vector *)ptr_data->map.data)[i].data_size, \
							((t_vector *)ptr_data->map.data)[i].del);
		if (ret != 0)
		{
			ft_vector_free(&ptr_data->map_c);
			return (ret);
		}
		ft_memcpy(vec_tmp.data, ((t_vector *)ptr_data->map.data)[i].data, \
			((t_vector *)ptr_data->map.data)[i].data_size * \
			((t_vector *)ptr_data->map.data)[i].size);
		vec_tmp.size = ((t_vector *)ptr_data->map.data)[i].size;
		ret = ft_vector_add_single(&ptr_data->map_c, &vec_tmp);
		if (ret != 0)
		{
			ft_vector_free(&ptr_data->map_c);
			return (ret);
		}
		i++;
	}
	return (SUCCESS);
}

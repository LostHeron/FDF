/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:59:48 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 17:21:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_memory.h"
#include "ft_vectors.h"

static int	vec_free_and_ret(t_data *ptr_data, t_vector *p_vec_tmp, int ret);
static int	my_vec_init(t_vector *ptr_vec, t_data *ptr_data, int i);

/*
 * So idea here :
 * this function should : 
 * In case of success :
	* have ptr_data->map_c be a duplicate of ptr_data->map
 * In case of failure :
	* ptr_data->map_c be correctly cleared before function return !
 */

/* check fail first ft_vector_init : checked */
/* check_fail my_vec_init : checked */
/* check ft_vector_add_single faile : checked */
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
		ret = my_vec_init(&vec_tmp, ptr_data, i);
		if (ret != 0)
			return (vec_free_and_ret(ptr_data, NULL, ret));
		ft_memcpy(vec_tmp.data, ((t_vector *)ptr_data->map.data)[i].data, \
			((t_vector *)ptr_data->map.data)[i].data_size * \
			((t_vector *)ptr_data->map.data)[i].size);
		vec_tmp.size = ((t_vector *)ptr_data->map.data)[i].size;
		ret = ft_vector_add_single(&ptr_data->map_c, &vec_tmp);
		if (ret != 0)
			return (vec_free_and_ret(ptr_data, &vec_tmp, ret));
		i++;
	}
	return (SUCCESS);
}

static int	my_vec_init(t_vector *ptr_vec, t_data *ptr_data, int i)
{
	int	ret;

	ret = ft_vector_init(ptr_vec, \
		((t_vector *)ptr_data->map.data)[i].capacity, \
		((t_vector *)ptr_data->map.data)[i].data_size, \
		((t_vector *)ptr_data->map.data)[i].del);
	return (ret);
}

static int	vec_free_and_ret(t_data *ptr_data, t_vector *p_vec_tmp, int ret)
{
	ft_vector_free(&ptr_data->map_c);
	if (p_vec_tmp != NULL)
		ft_vector_free(p_vec_tmp);
	return (ret);
}

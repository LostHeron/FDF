/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vec_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:48:36 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 17:04:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "ft_standard.h"

/* check ft_vector_add_single fail : checked */
int	fill_vec_tmp(int line_i, t_vector *vec_tmp, char **split_tmp)
{
	int		i;
	t_point	val;
	int		ret;

	i = 0;
	while (split_tmp[i] != NULL)
	{
		val.x = i;
		val.y = line_i;
		val.z = ft_atoi(split_tmp[i]);
		ret = ft_vector_add_single(vec_tmp, &val);
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}

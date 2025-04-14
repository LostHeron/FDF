/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:01:04 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 09:39:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_standard.h"
#include "fdf.h"
#include "parsing.h"
#define WHITE_SPACES " \t\n\v\f\r"

static void	free_split(char **str);
static void	free_vec_pt(t_vector *ptr_vec_pt);

/*
 * ok so idea :
 * this function should :
 * in case of success :
	* return 0
	* return a ptr_data->map filled correctly 
 * in case of failure :
	* return a non 0 integer 
	* have a ptr_data->map = NULL
	* and freed all memory allocation created in this function !
 */
int	fill_new_vec(t_data *ptr_data, t_vector map_copy)
{
	int			ret;
	char		**split_tmp;
	t_vector	vec_tmp;
	size_t		line_i;

	line_i = 0;
	while (line_i < map_copy.size)
	{
		split_tmp = ft_split(((char **)map_copy.data)[line_i], WHITE_SPACES);
		if (split_tmp == NULL)
		{
			ft_vector_free(&map_copy);
			ft_vector_free(&ptr_data->map);
			return (ERROR_MALLOC);
		}
		ret = ft_vector_init(&vec_tmp, 5, sizeof(t_point), &free_vec_pt);
		if (ret != SUCCESS)
		{
			ft_vector_free(&map_copy);
			ft_vector_free(&ptr_data->map);
			free_split(split_tmp);
			return (ret);
		}
		ret = fill_vec_tmp(line_i, &vec_tmp, split_tmp);
		if (ret != 0)
		{
			ft_vector_free(&map_copy);
			ft_vector_free(&ptr_data->map);
			free_split(split_tmp);
		}
		ret = ft_vector_add_single(&ptr_data->map, &vec_tmp);
		if (ret != SUCCESS)
		{
			ft_vector_free(&map_copy);
			ft_vector_free(&ptr_data->map);
			free_split(split_tmp);
			return (ret);
		}
		free_split(split_tmp);
		line_i++;
	}
	ft_vector_free(&map_copy);
	return (0);
}

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_vec_pt(t_vector *ptr_vec_pt)
{
	free(ptr_vec_pt->data);
}

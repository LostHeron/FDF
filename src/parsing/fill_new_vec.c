/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:01:04 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 18:16:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_standard.h"
#include "fdf.h"
#define WHITE_SPACES " \t\n\v\f\r"

static void	free_split(char **str);
static void	free_vec_pt(t_vector *ptr_vec_pt);

int	fill_new_vec(t_data *ptr_data, t_vector map_copy)
{
	int			ret;
	char		**tmp;
	t_vector	*ptr_vec_tmp;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	while (i < map_copy.size)
	{
		tmp = ft_split(((char **)map_copy.data)[i], WHITE_SPACES);
		if (tmp == NULL)
		{
			ft_vector_free(&map_copy);
			// MAY BE MISSING CLEARING STUFF
			// should be more stuff like 
			// ft_vector_free(&ptr_data->map)
			// this may be sufficient tho !
			return (ERROR_MALLOC);
		}
		ptr_vec_tmp = malloc(1 * sizeof(t_vector));
		if (ptr_vec_tmp == NULL)
		{
			ft_vector_free(&map_copy);
			free_split(tmp);
			// MAY BE MISSING CLEARING STUFF
			// should be more stuff like 
			// ft_vector_free(&ptr_data->map)
			// this may be sufficient tho !
			return (ERROR_MALLOC);
		}
		ret = ft_vector_init(ptr_vec_tmp, 5, sizeof(t_point), &free_vec_pt);
		if (ret != SUCCESS)
		{
			ft_vector_free(&map_copy);
			free_split(tmp);
			// MAY BE MISSING CLEARING STUFF
			// should be more stuff like 
			// ft_vector_free(&ptr_data->map)
			// this may be sufficient tho !
			return (ret);
		}
		// while loop to fill ptr_vec_tmp of the informations on current line
		k = 0;
		while (tmp[k] != NULL)
		{
			/*
			 * should be something like that here :
			ft_vector_add_single(ptr_vec_tmp, ft_atoi(tmp[k]);
			*/
			k++;
		}
		ret = ft_vector_add_single(&ptr_data->map, ptr_vec_tmp);
		if (ret != SUCCESS)
		{
			free_split(tmp);
			ft_vector_free(&ptr_data->map);
			// MAY BE MISSING CLEARING STUFF
			// should be more stuff like 
			// ft_vector_free(&ptr_data->map)
			// this may be sufficient tho !
			return (ret);
		}
	}
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

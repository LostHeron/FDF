/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:35:06 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 17:11:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "parsing.h"

static void	print_map(t_data *ptr_data);

int	parsing(t_data *ptr_data, char *filename)
{
	int	ret;

	ret = read_map(ptr_data, filename);
	if (ret != 0)
		return (ret);
	print_map(ptr_data);
	/*
	convert_map(ptr_data);
	*/
	ft_vector_free(&ptr_data->map);
	return (0);
}

#include <stdio.h>

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

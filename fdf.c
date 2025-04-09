/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:22:23 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 18:51:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_vectors.h"
#include "graphic.h"

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

int	main(void)
{
	t_data	data;
	int		ret;

	ret = ft_vector_init(&data.map, 5, sizeof(char *), NULL);
	if (ret != 0)
		return (ret);
	free(data.map.data);
	ret = graphic(&data);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:35:06 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 14:48:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parsing.h"

int	parsing(t_data *ptr_data, char *filename)
{
	int	ret;

	ret = read_map(ptr_data, filename);
	if (ret != 0)
		return (ret);
	ret = convert_map(ptr_data);
	if (ret != 0)
		return (ret);
	convert_points_coo(ptr_data);
	copy_map_vec(ptr_data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:55:01 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 18:44:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_memory.h"

void	clear_image(t_data *ptr_data)
{
	ft_bzero(ptr_data->pixels_data, ptr_data->nb_pixels_tot);
}

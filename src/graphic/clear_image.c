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
	size_t				i;
	unsigned long long	*s_c;
	size_t				nb_pixel_tot;
	size_t				nb_zeroed;

	s_c = (unsigned long long *) ptr_data->pixels_data;
	i = 0;
	nb_zeroed = 0;
	nb_pixel_tot = ptr_data->nb_pixels_tot - 8;
	while (nb_zeroed < nb_pixel_tot)
	{
		*(s_c + i) = 0;
		i++;
		nb_zeroed += 8;
	}
	while (nb_zeroed < ptr_data->nb_pixels_tot)
	{
		*(((char *)s_c) + nb_zeroed) = 0;
		nb_zeroed += 1;
	}
}

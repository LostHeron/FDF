/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:08:12 by jweber            #+#    #+#             */
/*   Updated: 2025/04/08 17:31:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "fdf.h"

int		graphic(t_data	*ptr_data);
int		init_mlx_data(t_data *ptr_data);
void	draw_line(t_data *ptr_data, t_point start, t_point end);

#endif

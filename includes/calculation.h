/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:36:36 by jweber            #+#    #+#             */
/*   Updated: 2025/04/21 12:04:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATION_H
# define CALCULATION_H

# include "fdf.h"

int		init_mlx_data(t_data *ptr_data);
void	set_rot_x(t_data *ptr_data);
void	set_rot_y(t_data *ptr_data);
void	set_rot_z(t_data *ptr_data);
void	set_rot_mat(t_data *ptr_data);
void	get_scale_factor(t_data *ptr_data);
void	calc_points(t_data *ptr_data);
void	calc_points_axis(t_data *ptr_data, double rot[3][3]);
void	calc_new_val(size_t	x_i, size_t y_i,
			t_data *ptr_data, double rot[3][3]);
void	calc_axis(t_data *ptr_data, double rot[3][3]);
void	rescale_axis(t_data *ptr_data);
void	draw_line(t_data *ptr_data, t_point start, t_point end, t_col color);
void	draw_points(t_data *ptr_data);
void	clear_image(t_data *ptr_data);
void	clear_and_print(t_data *ptr_data);

#endif

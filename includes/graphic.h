/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:08:12 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 18:51:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "fdf.h"

int		graphic(t_data	*ptr_data);
int		init_mlx_data(t_data *ptr_data);
void	draw_line(t_data *ptr_data, t_point start, t_point end);
void	draw_points(t_data *ptr_data);
void	clear_image(t_data *ptr_data);
void	calc_points(t_data *ptr_data, double rot[3][3]);
int		key_hooks(int keycode, t_data *ptr_data);
void	set_rot_x(t_data *ptr_data);
void	set_rot_y(t_data *ptr_data);
void	set_rot_z(t_data *ptr_data);
void	modify_rot_x(t_data *ptr_data);
void	modify_rot_y(t_data *ptr_data);
void	modify_rot_z(t_data *ptr_data);
#endif

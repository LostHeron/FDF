/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:46:53 by jweber            #+#    #+#             */
/*   Updated: 2025/04/16 10:42:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOKS_BONUS_H
# define KEY_HOOKS_BONUS_H

# include "fdf.h"

int		displacements(int keycode, t_data *ptr_data);
void	zoom_out(t_data *ptr_data);
void	zoom_in(t_data *ptr_data);
int		zooms(int keycode, t_data *ptr_data);
void	modify_rot_x(t_data *ptr_data);
void	modify_rot_y(t_data *ptr_data);
void	modify_rot_z(t_data *ptr_data);
void	modify_rot_x_neg(t_data *ptr_data);
void	modify_rot_y_neg(t_data *ptr_data);
void	modify_rot_z_neg(t_data *ptr_data);
void	modify_height_factor_down(t_data *ptr_data);
void	modify_height_factor_up(t_data *ptr_data);
int		key_hook_no_shift(int keycode, t_data *ptr_data);
int		key_hook_shift(int keycode, t_data *ptr_data);
int		key_press_bonus(int keycode, t_data *ptr_data);
int		key_release(int keycode, t_data *ptr_data);
int		heights(int keycode, t_data *ptr_data);

#endif

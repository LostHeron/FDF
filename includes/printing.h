/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:52:19 by jweber            #+#    #+#             */
/*   Updated: 2025/04/18 14:18:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H

#include "fdf.h"

void	print_error(int err_code);
void	print_error_mlx(void);
void	print_error_open(void);
void	print_error_read(void);
void	print_mat(double mat[3][3]);
void	print_points(t_data *ptr_data);
void	print_point(t_point point);

#endif

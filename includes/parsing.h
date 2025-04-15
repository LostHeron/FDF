/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:37:01 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 17:07:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

int		parsing(t_data *ptr_data, char *filename);
int		read_map(t_data *ptr_data, char *filename);
int		convert_map(t_data *ptr_data);
int		fill_new_vec(t_data *ptr_data, t_vector map_copy);
int		fill_vec_tmp(int line_i, t_vector *vec_tmp, char **split_tmp);
void	convert_points_coo(t_data *ptr_data);
int		copy_map_vec(t_data *ptr_data);

#endif

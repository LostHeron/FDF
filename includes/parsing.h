/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:37:01 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 17:37:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

int	parsing(t_data *ptr_data, char *filename);
int	read_map(t_data *ptr_data, char *filename);
int	convert_map(t_data *ptr_data);
int	fill_new_vec(t_data *ptr_data, t_vector map_copy);

#endif

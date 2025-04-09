/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:49 by jweber            #+#    #+#             */
/*   Updated: 2025/04/09 18:49:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_vectors.h"

# define ERROR_READ -1
# define ERROR_OPEN -2
# define ERROR_MALLOC -3
# define ERROR_MLX -9

# define DEFAULT_WIDTH 1000
# define DEFAULT_HEIGHT 1000
# define DEF_W DEFAULT_WIDTH
# define DEF_H DEFAULT_HEIGHT

# define ESC 65307

#define PI_OVER_8 0.39269908169

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}			t_point;

typedef t_point	t_pt;

/*
 * bits_pp -> bits per pixel
 * bytes_pl -> bytes per lines
*/
typedef struct s_data
{
	t_vector	map;
	void		*ptr_mlx;
	void		*ptr_win;
	void		*ptr_img;
	char		*pixels_data;
	double		rot_x[3][3];
	double		angle_x;
	double		rot_y[3][3];
	double		angle_y;
	double		rot_z[3][3];
	double		angle_z;
	t_point		points_init[3][3];
	t_point		points_calc[3][3];
	int			nb_pixels_tot;
	int			bits_pp;
	int			bytes_pl;
	int			endian;
}			t_data;

#endif

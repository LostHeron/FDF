/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:49 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 10:42:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_vectors.h"

# define SUCCESS 0
# define ERROR_READ -1
# define ERROR_OPEN -2
# define ERROR_MALLOC -3
# define ERROR_MLX -9
# define ERROR_NB_ARGUMENTS -10
# define ERROR_MAP_EXTENTION -11
# define ERROR_EMPTY_MAP -12

# define DEFAULT_WIDTH 2000 
# define DEFAULT_HEIGHT 500
# define DEF_W DEFAULT_WIDTH
# define DEF_H DEFAULT_HEIGHT

# define ESC 65307
# define SHIFT 65505

# define PI 3.14159265358979323846
# define PI_OVER_8 0.39269908169
# define PI_OVER_16 0.19634954084 

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}			t_point;

typedef t_point	t_pt;

/*
 * bits_pp -> bits per pixel
 * bytes_pl -> bytes per lines
*/
typedef struct s_data
{
	t_vector	map;
	t_vector	map_c;
	void		*ptr_mlx;
	void		*ptr_win;
	void		*ptr_img;
	char		*pixels_data;
	int			(*hook_func)(int, struct s_data *);
	double		rot_x[3][3];
	double		angle_x;
	double		rot_y[3][3];
	double		angle_y;
	double		rot_z[3][3];
	double		angle_z;
	double		zoom_factor;
	double		height_factor;
	double		default_scale_factor;
	double		trans_x;
	double		trans_y;
	t_point		points_init[3][3];
	t_point		points_calc[3][3];
	int			nb_pixels_tot;
	int			bits_pp;
	int			bytes_pl;
	int			endian;
}			t_data;

#endif

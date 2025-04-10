/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:51:27 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 17:21:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_io.h"
#include <stdio.h>

static void	print_error_nb_args(void);
static void	print_error_map_ext(void);
static void	print_error_open(void);

void	print_error(int err_code)
{
	ft_printf_fd(2, "Error\n");
	if (err_code == ERROR_NB_ARGUMENTS)
		print_error_nb_args();
	if (err_code == ERROR_MAP_EXTENTION)
		print_error_map_ext();
	if (err_code == ERROR_OPEN)
		print_error_open();
}

static void	print_error_open(void)
{
	ft_printf_fd(2, "Could not open file :\n");
	perror(NULL);
}

static void	print_error_nb_args(void)
{
	ft_printf_fd(2, "wrong number of arguments\n");
	ft_printf_fd(2, "usage : ./fdf <map.fdf>\n");
}

static void	print_error_map_ext(void)
{
	ft_printf_fd(2, "wrong file extention\n");
	ft_printf_fd(2, "usage : ./fdf <map.fdf>\n");
}

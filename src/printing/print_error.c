/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:51:27 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 15:27:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_io.h"
#include "printing.h"

static void	print_error_nb_args(void);
static void	print_error_map_ext(void);
static void	print_error_malloc(void);
static void	print_error_empty_map(void);

void	print_error(int err_code)
{
	ft_printf_fd(2, "Error\n");
	if (err_code == ERROR_NB_ARGUMENTS)
		print_error_nb_args();
	if (err_code == ERROR_MAP_EXTENTION)
		print_error_map_ext();
	if (err_code == ERROR_OPEN)
		print_error_open();
	if (err_code == ERROR_READ)
		print_error_read();
	if (err_code == ERROR_MALLOC)
		print_error_malloc();
	if (err_code == ERROR_EMPTY_MAP)
		print_error_empty_map();
}

static void	print_error_empty_map(void)
{
	ft_printf_fd(2, "Error map is empty!\n");
}

static void	print_error_malloc(void)
{
	ft_printf_fd(2, "Error while allocating memory :\n");
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

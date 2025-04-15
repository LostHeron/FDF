/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:22:23 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 18:11:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_string.h"
#include "graphic.h"
#include "parsing.h"
#include "printing.h"

static int	check_args(int argc, char **argv);
static int	print_err_return(int err_code, int return_val);

/* check check_args fail : checked */
/* check parsing fail : checked */
/* check graphic fail : TO DO */
int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = check_args(argc, argv);
	if (ret != 0)
		return (print_err_return(ret, 1));
	ret = parsing(&data, argv[1]);
	if (ret != 0)
		return (print_err_return(ret, 1));
	ret = graphic(&data);
	ft_vector_free(&data.map);
	ft_vector_free(&data.map_c);
	if (ret != 0)
	{
		print_error(ret);
		return (1);
	}
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		return (ERROR_NB_ARGUMENTS);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".fdf", 4) != 0)
	{
		return (ERROR_MAP_EXTENTION);
	}
	return (SUCCESS);
}

int	print_err_return(int err_code, int return_val)
{
	print_error(err_code);
	return (return_val);
}

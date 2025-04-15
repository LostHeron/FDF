/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:21 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 15:25:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdio.h>

void	print_error_open(void)
{
	ft_printf_fd(2, "Could not open file :\n");
	perror(NULL);
}

void	print_error_read(void)
{
	ft_printf_fd(2, "Error while reading\n");
	perror(NULL);
}

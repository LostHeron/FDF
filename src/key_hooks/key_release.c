/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:43:26 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 11:37:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_hooks.h"

#include <stdio.h>

int	key_release(int keycode, t_data *ptr_data)
{
	printf("dans key_release\n");
	if (keycode == SHIFT)
	{
		ptr_data->hook_func = &key_hook_no_shift;
	}
	return (0);
}

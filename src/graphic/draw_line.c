/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:21:51 by jweber            #+#    #+#             */
/*   Updated: 2025/04/08 18:58:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_vertical(t_data *ptr_data, t_point start, t_point end);
static void	put_white(t_data *ptr_data, int x, int y);
static void	a_less_than_one(t_data *ptr_data, t_pt start, t_pt end, double a);
static void	a_greater_one(t_data *ptr_data, t_pt start, t_pt end, double a);

#include <stdio.h>
void	draw_line(t_data *ptr_data, t_point start, t_point end)
{
	double	a;

	printf("point entre p1 : %i, %i et p2 : %i, %i\n", start.x, start.y, end.x, end.y);
	if ((end.x - start.x) == 0)
	{
		put_vertical(ptr_data, start, end);
		return ;
	}
	a = ((double)end.y - start.y) / (end.x - start.x);
	if (a < 1 && a > -1)
	{
		a_less_than_one(ptr_data, start, end, a);
	}
	else
	{
		a = ((double)end.x - start.x) / (end.y - start.y);
		a_greater_one(ptr_data, start, end, a);
	}
}

static void	a_less_than_one(t_data *ptr_data, t_pt start, t_pt end, double a)
{
	double	y;
	double	x;

	if (end.x > start.x)
	{
		y = start.y;
		x = start.x;
		while (x <= end.x)
		{
			put_white(ptr_data, x, y);
			x += 1;
			y = y + a;
		}
	}
	else
	{
		y = start.y;
		x = start.x;
		while (x >= end.x)
		{
			put_white(ptr_data, x, y);
			x -= 1;
			y = y - a;
		}
	}
}

static void	a_greater_one(t_data *ptr_data, t_pt start, t_pt end, double a)
{
	double	x;
	double	y;

	if (end.y > start.y)
	{
		y = start.y;
		x = start.x;
		while (y <= end.y)
		{
			put_white(ptr_data, x, y);
			y += 1;
			x = x + a;
		}
	}
	else
	{
		y = start.y;
		x = start.x;
		while (y >= end.y)
		{
			put_white(ptr_data, x, y);
			y -= 1;
			x = x - a;
		}
	}
}

static void	put_white(t_data *ptr_data, int x, int y)
{
	ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 0] = (char)255;
	ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 1] = (char)255;
	ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 2] = (char)255;
	ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 3] = (char)255;
}

static void	put_vertical(t_data *ptr_data, t_point start, t_point end)
{
	int	y;

	if (end.y > start.y)
	{
		y = start.y;
		while (y <= end.y)
		{
			put_white(ptr_data, start.x, y);
			y++;
		}
	}
	else
	{
		y = start.y;
		while (y >= end.y)
		{
			put_white(ptr_data, start.x, y);
			y--;
		}
	}
}

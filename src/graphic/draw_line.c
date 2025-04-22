/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:21:51 by jweber            #+#    #+#             */
/*   Updated: 2025/04/14 15:39:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_vertical(t_data *ptr_data, t_point start, t_point end, t_col color);
static void	put_color(t_data *ptr_data, int x, int y, t_col color);
static void	a_less_than_one(t_data *ptr_data, t_pt start, t_pt end, double a, t_col color);
static void	a_greater_one(t_data *ptr_data, t_pt start, t_pt end, double a, t_col color);

void	draw_line(t_data *ptr_data, t_point start, t_point end, t_col color)
{
	double	a;

	if ((end.x - start.x) == 0)
	{
		put_vertical(ptr_data, start, end, color);
		return ;
	}
	a = ((double)end.y - start.y) / (end.x - start.x);
	if (a < 1 && a > -1)
	{
		a_less_than_one(ptr_data, start, end, a, color);
	}
	else
	{
		a = ((double)end.x - start.x) / (end.y - start.y);
		a_greater_one(ptr_data, start, end, a, color);
	}
}

static void	a_less_than_one(t_data *ptr_data, t_pt start, t_pt end, double a, t_col color)
{
	double	y;
	double	x;

	x = start.x;
	y = start.y;
	if (end.x > start.x)
	{
		while (x <= end.x && x < DEFAULT_WIDTH)
		{
			put_color(ptr_data, x, y, color);
			x += 1;
			y = y + a;
		}
	}
	else
	{
		while (x >= end.x && x >= 0)
		{
			put_color(ptr_data, x, y, color);
			x -= 1;
			y = y - a;
		}
	}
}

static void	a_greater_one(t_data *ptr_data, t_pt start, t_pt end, double a, t_col color)
{
	double	x;
	double	y;

	x = start.x;
	y = start.y;
	if (end.y > start.y)
	{
		while (y <= end.y && y < DEFAULT_HEIGHT)
		{
			put_color(ptr_data, x, y, color);
			y += 1;
			x = x + a;
		}
	}
	else
	{
		while (y >= end.y && y >= 0)
		{
			put_color(ptr_data, x, y, color);
			y -= 1;
			x = x - a;
		}
	}
}

static void	put_color(t_data *ptr_data, int x, int y, t_col color)
{
	if (x >= 0 && y >= 0 && x < DEFAULT_WIDTH && y < DEFAULT_HEIGHT)
	{
		/*
		ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 0] = color.b;
		ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 1] = color.g;
		ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 2] = color.r;
		ptr_data->pixels_data[y * ptr_data->bytes_pl + x * 4 + 3] = color.trans;
		*/
		((int*) ptr_data->pixels_data)[y * ptr_data->bytes_pl / 4 + x] = color.all_col;
	}
}

static void	put_vertical(t_data *ptr_data, t_point start, t_point end, t_col color)
{
	int	y;

	if (end.y > start.y)
	{
		y = start.y;
		while (y <= end.y)
		{
			put_color(ptr_data, start.x, y, color);
			y++;
		}
	}
	else
	{
		y = start.y;
		while (y >= end.y)
		{
			put_color(ptr_data, start.x, y, color);
			y--;
		}
	}
}

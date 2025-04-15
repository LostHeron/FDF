/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:46:57 by jweber            #+#    #+#             */
/*   Updated: 2025/04/15 16:35:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "fdf.h"
#include "ft_vectors.h"
#include <unistd.h>
#include <fcntl.h>

static int	read_while(t_data *ptr_data, int fd, char *line, int *p_err_code);
static void	free_first(t_vector *ptr_vec);

int	read_map(t_data *ptr_data, char *filename)
{
	int		ret;
	int		fd;
	char	*line;
	int		err_code;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR_OPEN);
	ret = ft_vector_init(&ptr_data->map, 5, sizeof(char *), free_first);
	if (ret != 0)
	{
		close(fd);
		return (ret);
	}
	line = get_next_line(fd, &err_code);
	if (err_code != 0)
	{
		ft_vector_free(&ptr_data->map);
		close(fd);
		return (err_code);
	}
	ret = read_while(ptr_data, fd, line, &err_code);
	close(fd);
	return (ret);
}

/* fail get_next_line : checked ! */
/* fail ft_vector_add_single : checked ! */
static int	read_while(t_data *ptr_data, int fd, char *line, int *p_err_code)
{
	int	ret;

	while (line != NULL)
	{
		ret = ft_vector_add_single(&ptr_data->map, &line);
		if (ret != 0)
		{
			free(line);
			ft_vector_free(&ptr_data->map);
			return (ret);
		}
		line = get_next_line(fd, p_err_code);
		if (*p_err_code != 0)
		{
			ft_vector_free(&ptr_data->map);
			return (*p_err_code);
		}
	}
	return (0);
}

static void	free_first(t_vector *ptr_vec)
{
	size_t	i;

	i = 0;
	while (i < ptr_vec->size)
	{
		free(((char **)ptr_vec->data)[i]);
		i++;
	}
	free(ptr_vec->data);
}

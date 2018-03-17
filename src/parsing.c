/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:08:39 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 02:22:33 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static size_t			array_len(char **words)
{
	size_t	count;

	count = 0;
	while (words[count])
		count++;
	return count;
}

static t_fdf_point3d	*get_line_points(int fd, unsigned int *width, int line_index)
{
	char			*line;
	t_fdf_point3d	*points;
	char			**alt_strs;
	unsigned int	i;

	if ((get_next_line(fd, &line)) < 1)
		return (NULL);
	alt_strs = ft_strsplit(line, ' ');
	if (line_index == 0)
		*width = array_len(alt_strs);
	if (!(points = ft_memalloc(sizeof(t_fdf_point3d) * *width)))
		return (NULL);
	i = 0;
	while (i < *width && alt_strs[i])
	{
		points[i].x = i * FDF_POINT_SEP;
		points[i].y = line_index * FDF_POINT_SEP;
		points[i].z = (ft_atoi(alt_strs[i]) * 10 / FDF_ZMOD) * -1;
		i++;
	}
	ft_free_2d_array((void ***)&alt_strs, i);
	free(line);
	if (i < *width)
		fdf_shortline_error();
	return (points);
}

t_fdf_point3d			**fdf_parse_file(int fd, unsigned int *width,
									unsigned int *height)
{
	t_fdf_point3d 	*line_points;
	t_fdf_point3d	**points;
	size_t			arr_size_new;
	size_t			arr_size_old;
	
	if (!(points = ft_memalloc(sizeof(t_fdf_point3d *))))
		return (NULL);
	*height = 0;
	arr_size_old = 0;
	while ((line_points = get_line_points(fd, width, *height)))
	{
		arr_size_new = arr_size_old + sizeof(t_fdf_point3d *);
		if (!(points = ft_memrealloc((void *)points, arr_size_new, arr_size_old)))
			return (NULL);
		arr_size_old = arr_size_new;
		points[*height] = line_points;
		(*height)++;
	}
	return (points);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:08:39 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 21:45:23 by rhallste         ###   ########.fr       */
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
	return (count);
}

static t_fdf_point3d	set_point(unsigned int i, int line_index,
								char *alt_str)
{
	char			**param_split;
	t_fdf_point3d	point;

	point.x = i * FDF_POINT_SEP;
	point.y = line_index * FDF_POINT_SEP;
	param_split = ft_strsplit(alt_str, ',');
	point.z = ft_atoi(param_split[0]) * FDF_POINT_SEP;
	ft_free_2d_array((void ***)&param_split, (param_split[1]) ? 2 : 1);
	return (point);
}

static t_fdf_point3d	*get_line_points(int fd, unsigned int *width,
										int line_index)
{
	char			*line;
	t_fdf_point3d	*points;
	char			**alt_strs;
	unsigned int	i;

	if ((get_next_line(fd, &line)) < 1)
		return (NULL);
	alt_strs = ft_strsplit(line, ' ');
	free(line);
	if (line_index == 0)
		*width = array_len(alt_strs);
	if (!(points = ft_memalloc(sizeof(t_fdf_point3d) * *width)))
		return (NULL);
	i = 0;
	while (i < *width && alt_strs[i])
	{
		points[i] = set_point(i, line_index, alt_strs[i]);
		i++;
	}
	ft_free_2d_array((void ***)&alt_strs, i);
	if (i < *width)
		fdf_shortline_error();
	return (points);
}

t_fdf_point3d			**fdf_parse_file(int fd, unsigned int *width,
									unsigned int *height)
{
	t_fdf_point3d	*line_points;
	t_fdf_point3d	**points;
	size_t			arsz_new;
	size_t			arsz_old;

	if (!(points = ft_memalloc(sizeof(t_fdf_point3d *))))
		return (NULL);
	*height = 0;
	arsz_old = 0;
	while ((line_points = get_line_points(fd, width, *height)))
	{
		arsz_new = arsz_old + sizeof(t_fdf_point3d *);
		if (!(points = ft_memrealloc((void *)points, arsz_new, arsz_old)))
			return (NULL);
		arsz_old = arsz_new;
		points[*height] = line_points;
		(*height)++;
	}
	if (!line_points)
		fdf_nodata_error();
	return (points);
}

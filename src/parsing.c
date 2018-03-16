/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:08:39 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/16 00:47:46 by rhallste         ###   ########.fr       */
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

static t_fdf_point3d	*get_line(int fd, unsigned int *width, int line_index)
{
	char			*line;
	t_fdf_point3d	*points;
	char			**alt_strs;
	unsigned int	i;

	if ((get_next_line(fd, &line)) < 1)
		return (0);
	alt_strs = ft_strsplit(line, ' ');
	if (line_index == 0)
		*width = array_len(alt_strs);
	if (!(points = ft_memalloc(sizeof(t_fdf_point3d) * *width)))
		return (NULL);
	i = 0;
	while (i < *width && alt_strs[i])
	{
		points[i].x = i;
		points[i].y = line_index;
		points[i].z = ft_atoi(alt_strs[i]);
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
	t_fdf_point3d **points;

	if (!(points = ft_memalloc(sizeof(t_fdf_point3d *))))
		return (NULL);
	*height = 1;
	points[0] = get_line(fd, width, 0);
	
	for (unsigned int i = 0; i < *width; i++)
		ft_printf("%d ", points[0][i].z);
	ft_printf("\n");
	
	return (points);
	//get first line and set width;
	//get remaining lines
	//set height
}

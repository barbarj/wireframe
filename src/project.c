/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:11:03 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 19:11:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static t_fdf_point2d	calc_iso_proj(t_fdf_point3d point)
{
	t_fdf_point2d	proj;
	
	point = fdf_rot(point, 0.61547, 0, -M_PI / 4);
	proj.x = point.x;
	proj.y = point.y;
	proj.color = point.color;
	return (proj);
}

static t_fdf_point2d	calc_mil_proj(t_fdf_point3d point)
{
	t_fdf_point2d	proj;

	point = fdf_rot(point, 0, 0, -(M_PI / 4));
	proj.x = point.x;
	proj.y = point.y + point.z;
	proj.color = point.color;
	return (proj);
}

t_fdf_point2d	**fdf_proj(t_fdf_point3d **points3d, unsigned int width, unsigned int height, unsigned int proj)
{
	t_fdf_point2d	**points2d;
	t_fdf_point2d	(*calc_proj)(t_fdf_point3d);
	unsigned int	w;
	unsigned int	h;

	if (proj == FDF_PROJISO)
		calc_proj = &calc_iso_proj;
	else if (proj == FDF_PROJMIL)
		calc_proj = &calc_mil_proj;
	
	if(!(points2d = ft_memalloc(sizeof(t_fdf_point2d *) * height)))
		return (NULL);
	h = 0;
	while (h < height)
	{
		if (!(points2d[h] = ft_memalloc(sizeof(t_fdf_point2d) * width)))
			return (NULL);
		w = 0;
		while (w < width)
		{
			points2d[h][w] = calc_proj(points3d[h][w]);
			w++;
		}
		h++;
	}
	return (points2d);
}

double			fdf_calc_scale_factor(unsigned int width, unsigned int height, unsigned int proj)
{
	double ideal;
	double ideal_height;

	width *= FDF_POINT_SEP;
	height *= FDF_POINT_SEP;
	ideal = 1.0;
	if (proj == FDF_PROJISO)
	{
		ideal = ((double)FDF_WINWIDTH / 1.5) / (double)width;
		ideal_height= (double)FDF_WINHEIGHT / 1.2;
		if (height * ideal > ideal_height)
			ideal *= (ideal_height / (height * ideal));
	}
	else if (proj == FDF_PROJMIL)
	{
		ideal = 1.0;
	}
	return (ideal);
}

void			fdf_scale_to_window(t_fdf_point3d **points3d, double factor,
									unsigned int width, unsigned height)
{
	unsigned int w;	
	unsigned int h;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			points3d[h][w].x = points3d[h][w].x * factor;
			points3d[h][w].y = points3d[h][w].y * factor;
			points3d[h][w].z = points3d[h][w].z * factor;
			w++;
		}
		h++;
	}
}

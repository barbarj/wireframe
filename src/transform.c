/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:15:30 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 18:35:25 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static t_fdf_point2d	calc_iso_proj(t_fdf_point3d point3d)
{
	t_fdf_point2d	proj;
	static double	sqrt3;
	static double	sqrt6;
	double			tmp;
	
	if (!sqrt3)
	{
		sqrt3 = sqrt(3);
		sqrt6 = sqrt(6);
	}
	tmp = ((point3d.x * sqrt3) - (point3d.z * sqrt3)) / sqrt6;
	proj.x = ceil(tmp);
	tmp = (point3d.x + (2 * point3d.y) + point3d.z) / sqrt6;
	proj.y = ceil(tmp);
	proj.color = 0xffffff;
	return (proj);
}

static t_fdf_point2d	calc_mil_proj(t_fdf_point3d point3d)
{
	t_fdf_point2d	proj;
	static double	sinpi;
	static double	cospi;
	double			tmp;
	
	if (!sinpi)
	{
		sinpi = sin(-M_PI / 5);
		cospi = cos(-M_PI / 5);
	}
	tmp = (point3d.x * cospi) - (point3d.y * sinpi);
	proj.x = ceil(tmp) + (FDF_WINWIDTH / 10);
	tmp = (point3d.x * sinpi) + (point3d.y * cospi) + point3d.z  + (FDF_WINHEIGHT / 1.5);
	proj.y = ceil(tmp);
	proj.color = 0xffffff;
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

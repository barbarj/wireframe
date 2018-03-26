/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:27:15 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/25 19:08:49 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static t_fdf_point2d	calc_iso_proj(t_fdf_point3d point, double scale_factor)
{
	t_fdf_point2d	proj;

//	point = fdf_rot(point, 0, 0, -M_PI / 6.0);
//	point = fdf_rot(point, M_PI / 6.0, 0, 0);
	proj.x = point.x * scale_factor;
	proj.y = point.y * scale_factor;
	proj.zval = point.z;
	proj.color = point.color;
	return (proj);
}

void					fdf_proj(t_fdf_matrix *matrix)
{
	double			scale_factor;
	signed			offset[2];
	unsigned int	w;
	unsigned int	h;

	scale_factor = ((double)FDF_WINWIDTH * 5.0)
					/ (matrix->width * (double)FDF_POINT_SEP * 7.5);
	offset[0] = ((double)FDF_WINWIDTH / 2.0)
		- ((matrix->width - 1) * (double)FDF_POINT_SEP * scale_factor / 2.0);
	offset[1] = ((double)FDF_WINHEIGHT / 2.0)
		- ((matrix->height - 1) * (double)FDF_POINT_SEP * scale_factor / 2.0);
	h = 0;
	while (h < matrix->height)
	{
		w = 0;
		while (w < matrix->width)
		{
			matrix->points2d[h][w] = calc_iso_proj(matrix->points3d[h][w],
													scale_factor);
			matrix->points2d[h][w].x += offset[0];
			matrix->points2d[h][w].y += offset[1];
			w++;
		}
		h++;
	}
}

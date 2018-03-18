/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:11:03 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 22:13:45 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static t_fdf_point2d	calc_iso_proj(t_fdf_point3d point, double scale_factor)
{
	t_fdf_point2d	proj;

	point = fdf_rot(point, 0, 0, -M_PI / 6.0);
	point = fdf_rot(point, M_PI / 6.0, 0, 0);
	proj.x = point.x * scale_factor;
	proj.y = point.y * scale_factor;
	proj.color = point.color;
	return (proj);
}

void					fdf_proj(t_fdf_matrix *matrix)
{
	double			scale_factor;
	unsigned int	offset[2];
	unsigned int	w;
	unsigned int	h;

	scale_factor = (FDF_WINWIDTH * 7.5)
					/ (matrix->width * FDF_POINT_SEP * 10.0);
	offset[0] = (FDF_WINWIDTH / 2)
					- (matrix->width * FDF_POINT_SEP * scale_factor / 2.0);
	offset[1] = (FDF_WINHEIGHT * 2 / 3);
	h = 0;
	while (h < matrix->height)
	{
		w = 0;
		while (w < matrix->width)
		{
			matrix->points2d[h][w]
				= calc_iso_proj(matrix->points3d[h][w], scale_factor);
			matrix->points2d[h][w].x += offset[0];
			matrix->points2d[h][w].y += offset[1];
			w++;
		}
		h++;
	}
}

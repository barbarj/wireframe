/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:57:56 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/18 00:43:22 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static void	draw_line_vert(t_fdf_point2d p0, t_fdf_point2d p1, t_fdf_ctrl *ctrl)
{
	int				dx;
	int				dy;
	int				error;
	int				xi;
	unsigned long	color;

	color = (p1.zval >= p0.zval) ? p1.color : p0.color;
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	xi = (dx < 0) ? -1 : 1;
	dx *= xi;
	error = (2 * dx) - dy;
	while (p0.y <= p1.y)
	{
		mlx_pixel_put(ctrl->mlx, ctrl->win, p0.x, p0.y, color);
		if (error > 0)
		{
			p0.x += xi;
			error -= 2 * dy;
		}
		error += 2 * dx;
		p0.y++;
	}
}

static void	draw_line_hor(t_fdf_point2d p0, t_fdf_point2d p1, t_fdf_ctrl *ctrl)
{
	int				dx;
	int				dy;
	int				error;
	int				yi;
	unsigned long	color;

	color = (p1.zval >= p0.zval) ? p1.color : p0.color;
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	yi = (dy < 0) ? -1 : 1;
	dy *= yi;
	error = (2 * dy) - dx;
	while (p0.x <= p1.x)
	{
		mlx_pixel_put(ctrl->mlx, ctrl->win, p0.x, p0.y, color);
		if (error > 0)
		{
			p0.y += yi;
			error -= 2 * dx;
		}
		error += 2 * dy;
		p0.x++;
	}
}

void		fdf_draw_line(t_fdf_point2d p0, t_fdf_point2d p1, t_fdf_ctrl *ctrl)
{
	int tmpx;
	int tmpy;

	tmpx = p1.x - p0.x;
	tmpy = p1.y - p0.y;
	if (ABS(tmpy) < ABS(tmpx))
	{
		if (p0.x > p1.x)
			draw_line_hor(p1, p0, ctrl);
		else
			draw_line_hor(p0, p1, ctrl);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_vert(p1, p0, ctrl);
		else
			draw_line_vert(p0, p1, ctrl);
	}
}

void		fdf_draw_wireframe(t_fdf_ctrl *ctrl, t_fdf_matrix *matrix)
{
	unsigned int w;
	unsigned int h;

	h = 0;
	while (h < matrix->height)
	{
		w = 0;
		while (w < matrix->width)
		{
			if (w + 1 < matrix->width)
				fdf_draw_line(matrix->points2d[h][w],
								matrix->points2d[h][w + 1], ctrl);
			if (h + 1 < matrix->height)
				fdf_draw_line(matrix->points2d[h][w],
								matrix->points2d[h + 1][w], ctrl);
			w++;
		}
		h++;
	}
}

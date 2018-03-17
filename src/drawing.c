/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:57:56 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 00:43:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../minilibx/mlx.h"
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static void draw_line_vert(t_fdf_point2d p0, t_fdf_point2d p1, void *mlx_ptr, void *win_ptr)
{
	int				dx;
	int				dy;
	t_fdf_point2d	plot_pt;
	int				error;
	int				xi;

	dx = (p1.x - p0.x);
	dy = p1.y - p0.y;
	xi = (dx < 0) ? -1 : 1;
	dx *= xi;
	error = (2 * dx) - dy;
	plot_pt.x = p0.x;
	plot_pt.y = p0.y;
	while (plot_pt.y <= p1.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, plot_pt.x, plot_pt.y, 0xffffff);
		if (error > 0)
		{
			plot_pt.x += xi;
			error -= 2 * dy;
		}
		error += 2 * dx;
		plot_pt.y++;
	}
}

static void draw_line_horiz(t_fdf_point2d p0, t_fdf_point2d p1, void *mlx_ptr, void *win_ptr)
{
	int				dx;
	int				dy;
	t_fdf_point2d	plot_pt;
	int				error;
	int				yi;

	dx = (p1.x - p0.x);
	dy = p1.y - p0.y;
	yi = (dy < 0) ? -1 : 1;
	dy *= yi;
	error = (2 * dy) - dx;
	plot_pt.x = p0.x;
	plot_pt.y = p0.y;
	while (plot_pt.x <= p1.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, plot_pt.x, plot_pt.y, 0xffffff);
		if (error > 0)
		{
			plot_pt.y += yi;
			error -= 2 * dx;
		}
		error += 2 * dy;
		plot_pt.x++;
	}	
}

void	fdf_draw_line(t_fdf_point2d p0, t_fdf_point2d p1,
					  void *mlx_ptr, void *win_ptr)
{
	if (ABS(p1.y - p0.y) > ABS(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_line_horiz(p1, p0, mlx_ptr, win_ptr);
		else
			draw_line_vert(p0, p1, mlx_ptr, win_ptr);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_vert(p1, p0, mlx_ptr, win_ptr);
		else
			draw_line_horiz(p0, p1, mlx_ptr, win_ptr);
	}
}

void	fdf_draw_wireframe(t_fdf_ctrl *ctrl, t_fdf_matrix *matrix)
{
	fdf_draw_line(matrix->points2d[0][0], matrix->points2d[0][1], ctrl->mlx, ctrl->win);
}

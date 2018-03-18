/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:30:15 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 20:39:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_WINWIDTH 1200
# define FDF_WINHEIGHT 1200
# define FDF_POINT_SEP 10

typedef struct		s_fdf_point3d
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_fdf_point3d;

typedef struct		s_fdf_point2d
{
	double			x;
	double			y;
	unsigned long	color;
}					t_fdf_point2d;

typedef struct		s_fdf_window
{
	unsigned int	width;
	unsigned int	height;
}					t_fdf_window;

typedef struct		s_fdf_matrix
{
	unsigned int	width;
	unsigned int	height;
	t_fdf_point3d	**points3d;
	t_fdf_point2d	**points2d;
}					t_fdf_matrix;

typedef struct		s_fdf_ctrl
{
	void			*mlx;
	void			*win;
}					t_fdf_ctrl;

/*
** Parsing
*/
t_fdf_point3d	**fdf_parse_file(int fd, unsigned int *width, unsigned int *height);
/*
** Projections
*/
void			fdf_proj(t_fdf_matrix *matrix);

/*
** Rotations
*/
t_fdf_point3d	fdf_rot(t_fdf_point3d point, double ang_x, double ang_y, double ang_z);

/*
** Drawing
*/
void			fdf_draw_line(t_fdf_point2d p0, t_fdf_point2d p1, t_fdf_ctrl *ctrl);
void			fdf_draw_wireframe(t_fdf_ctrl *ctrl, t_fdf_matrix *matrix);

/*
** Errors
*/
void			fdf_usage_error(void);
void			fdf_fileopen_error(char *filename);
void			fdf_shortline_error();

#endif
